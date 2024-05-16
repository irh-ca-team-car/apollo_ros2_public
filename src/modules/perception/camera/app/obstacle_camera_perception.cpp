/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include "modules/perception/camera/app/obstacle_camera_perception.h"

#include <utility>

#include "absl/strings/str_cat.h"
#include "cyber/cyber.h"
#include "modules/common/util/perf_util.h"
#include "modules/perception/base/object.h"
#include "modules/perception/camera/app/debug_info.h"
#include "modules/perception/camera/common/global_config.h"
#include "modules/perception/camera/common/util.h"
#include "modules/perception/common/io/io_util.h"
#include "modules/perception/inference/utils/cuda_util.h"

namespace apollo {
namespace perception {
namespace camera {

using cyber::common::EnsureDirectory;
using cyber::common::GetAbsolutePath;

bool ObstacleCameraPerception::Init(
    const CameraPerceptionInitOptions &options) {
  ADEBUG;
  std::string work_root = "";
 
  std::string config_file =
      GetAbsolutePath(options.root_dir, options.conf_file);
  config_file = GetAbsolutePath(work_root, config_file);
  ADEBUG << config_file;
  apollo::cyber::common::GetProtoFromASCIIFile(config_file, &perception_param_);

  ADEBUG << "set_device_id";
  ACHECK(inference::CudaUtil::set_device_id(perception_param_.gpuid));

  ADEBUG << "Init detector";
  ACHECK(perception_param_.detectorparam.size() > 0)
      << "Failed to init detector.";
  ADEBUG << "Init detector";
  base::BaseCameraModelPtr model;
  for (size_t i = 0; i < perception_param_.detectorparam.size(); ++i) {
    ADEBUG << "perception_param_.detectorparam.size()::"<<i;
    ObstacleDetectorInitOptions detector_init_options;
    app::DetectorParam detector_param = perception_param_.detectorparam[i];
    auto plugin_param = detector_param.pluginparam;
    detector_init_options.root_dir =
        GetAbsolutePath(work_root, plugin_param.rootdir);
    detector_init_options.conf_file = plugin_param.configfile;
    detector_init_options.gpu_id = perception_param_.gpuid;

    model = common::SensorManager::Instance()->GetUndistortCameraModel(
        detector_param.cameraname);
    auto pinhole = static_cast<base::PinholeCameraModel *>(model.get());
    name_intrinsic_map_.insert(std::pair<std::string, Eigen::Matrix3f>(
        detector_param.cameraname, pinhole->get_intrinsic_params()));
    detector_init_options.base_camera_model = model;
    std::shared_ptr<BaseObstacleDetector> detector_ptr(
        BaseObstacleDetectorRegisterer::GetInstanceByName(plugin_param.name));
    AINFO_EVERY(60000) << detector_param.cameraname << detector_ptr;
    name_detector_map_.insert(
        std::pair<std::string, std::shared_ptr<BaseObstacleDetector>>(
            detector_param.cameraname, detector_ptr));
    ADEBUG << "perception_param_.detectorparam.size()::"<<plugin_param.name;

    ACHECK(name_detector_map_.at(detector_param.cameraname) != nullptr);
    ACHECK(name_detector_map_.at(detector_param.cameraname)
               ->Init(detector_init_options))
        << "Failed to init: " << plugin_param.name;
    ADEBUG << "perception_param_.detectorparam.size()::"<<plugin_param.name << "inited";

  }

  ADEBUG << "Init tracker";
  ACHECK(perception_param_.trackerparam!=app::TrackerParam()) << "Failed to init tracker.";
  {
    ObstacleTrackerInitOptions tracker_init_options;
    tracker_init_options.image_width = static_cast<float>(model->get_width());
    tracker_init_options.image_height = static_cast<float>(model->get_height());
    tracker_init_options.gpu_id = perception_param_.gpuid;
    auto plugin_param = perception_param_.trackerparam.pluginparam;
    tracker_init_options.root_dir =
        GetAbsolutePath(work_root, plugin_param.rootdir);
    tracker_init_options.conf_file = plugin_param.configfile;
    tracker_.reset(
        BaseObstacleTrackerRegisterer::GetInstanceByName(plugin_param.name));
    ACHECK(tracker_ != nullptr);
    ACHECK(tracker_->Init(tracker_init_options))
        << "Failed to init: " << plugin_param.name;
  }

  // Init transformer
  ACHECK(perception_param_.transformerparam!=app::TransformerParam())
      << "Failed to init transformer.";
  {
    ObstacleTransformerInitOptions transformer_init_options;
    auto plugin_param = perception_param_.transformerparam.pluginparam;
    transformer_init_options.root_dir =
        GetAbsolutePath(work_root, plugin_param.rootdir);
    transformer_init_options.conf_file = plugin_param.configfile;
    transformer_.reset(BaseObstacleTransformerRegisterer::GetInstanceByName(
        plugin_param.name));
    ACHECK(transformer_ != nullptr);
    ACHECK(transformer_->Init(transformer_init_options))
        << "Failed to init: " << plugin_param.name;
  }

  // Init obstacle postprocessor
  ACHECK(perception_param_.postprocessorparam!=app::PostprocessorParam())
      << "Failed to init obstacle postprocessor.";
  {
    ObstaclePostprocessorInitOptions obstacle_postprocessor_init_options;
    auto plugin_param = perception_param_.postprocessorparam.pluginparam;
    obstacle_postprocessor_init_options.root_dir =
        GetAbsolutePath(work_root, plugin_param.rootdir);
    obstacle_postprocessor_init_options.conf_file = plugin_param.configfile;
    obstacle_postprocessor_.reset(
        BaseObstaclePostprocessorRegisterer::GetInstanceByName(
            plugin_param.name));
    ACHECK(obstacle_postprocessor_ != nullptr);
    ACHECK(obstacle_postprocessor_->Init(obstacle_postprocessor_init_options))
        << "Failed to init: " << plugin_param.name;
  }
  AINFO_EVERY(60000) << "perception_param_.featureparam "<<perception_param_.featureparam;

  // Init feature_extractor
  if (perception_param_.featureparam==app::FeatureParam()) {
    AINFO_EVERY(60000) << "No feature config found.";
    extractor_ = nullptr;
  } else 
  {
    FeatureExtractorInitOptions init_options;
    auto plugin_param = perception_param_.featureparam.pluginparam;
    init_options.root_dir = GetAbsolutePath(work_root, plugin_param.rootdir);
    init_options.conf_file = plugin_param.configfile;
    extractor_.reset(
        BaseFeatureExtractorRegisterer::GetInstanceByName(plugin_param.name));
    ACHECK(extractor_ != nullptr);
    ACHECK(extractor_->Init(init_options))
        << "Failed to init: " << plugin_param.name;
  }

  lane_calibration_working_sensor_name_ =
      options.lane_calibration_working_sensor_name;

  // Init lane
  InitLane(work_root, perception_param_);

  // Init calibration service
  InitCalibrationService(work_root, model, perception_param_);

  // Init debug_param
  if (perception_param_.debugparam!=app::DebugParam()) {
    // Init debug info
    if (perception_param_.debugparam.trackoutfile!=std::string()) {
      out_track_.open(perception_param_.debugparam.trackoutfile,
                      std::ofstream::out);
    }
    if (perception_param_.debugparam.camera2worldoutfile!=std::string()) {
      out_pose_.open(perception_param_.debugparam.camera2worldoutfile,
                     std::ofstream::out);
    }
  }

  // Init object template
  if (perception_param_.objecttemplateparam!=app::ObjectTemplateParam()) {
    ObjectTemplateManagerInitOptions init_options;
    auto plugin_param =
        perception_param_.objecttemplateparam.pluginparam;
    init_options.root_dir = GetAbsolutePath(work_root, plugin_param.rootdir);
    init_options.conf_file = plugin_param.configfile;
    ACHECK(ObjectTemplateManager::Instance()->Init(init_options));
  }
  return true;
}

void ObstacleCameraPerception::InitLane(
    const std::string &work_root,
    const app::PerceptionParam &perception_param) {
  // Init lane
  CHECK_GT(perception_param.laneparam.size(), 0)
      << "Failed to include lane_param";
  for (size_t i = 0; i < perception_param.laneparam.size(); ++i) {
    // Initialize lane detector
    const auto &lane_param = perception_param.laneparam[i];
    ACHECK(lane_param.lanedetectorparam!=app::DetectorParam())
        << "Failed to include lane_detector_param.";
    LaneDetectorInitOptions lane_detector_init_options;
    const auto &lane_detector_param = lane_param.lanedetectorparam;
    const auto &lane_detector_plugin_param = lane_detector_param.pluginparam;
    lane_detector_init_options.conf_file =
        lane_detector_plugin_param.configfile;
    lane_detector_init_options.root_dir =
        GetAbsolutePath(work_root, lane_detector_plugin_param.rootdir);
    lane_detector_init_options.gpu_id = perception_param.gpuid;
    base::BaseCameraModelPtr model =
        common::SensorManager::Instance()->GetUndistortCameraModel(
            lane_detector_param.cameraname);
    lane_detector_init_options.base_camera_model = model;
    AINFO_EVERY(60000) << "lane_detector_name: " << lane_detector_plugin_param.name;
    lane_detector_.reset(BaseLaneDetectorRegisterer::GetInstanceByName(
        lane_detector_plugin_param.name));
    ACHECK(lane_detector_ != nullptr);
    ACHECK(lane_detector_->Init(lane_detector_init_options))
        << "Failed to init: " << lane_detector_plugin_param.name;
    AINFO_EVERY(60000) << "Detector: " << lane_detector_->Name();

    // Initialize lane postprocessor
    const auto &lane_postprocessor_param =
        lane_param.lanepostprocessorparam;
    LanePostprocessorInitOptions postprocessor_init_options;
    postprocessor_init_options.detect_config_root =
        GetAbsolutePath(work_root, lane_detector_plugin_param.rootdir);
    postprocessor_init_options.detect_config_name =
        lane_detector_plugin_param.configfile;
    postprocessor_init_options.root_dir =
        GetAbsolutePath(work_root, lane_postprocessor_param.rootdir);
    postprocessor_init_options.conf_file =
        lane_postprocessor_param.configfile;
    lane_postprocessor_.reset(
        BaseLanePostprocessorRegisterer::GetInstanceByName(
            lane_postprocessor_param.name));
    ACHECK(lane_postprocessor_ != nullptr);
    ACHECK(lane_postprocessor_->Init(postprocessor_init_options))
        << "Failed to init: " << lane_postprocessor_param.name;
    AINFO_EVERY(60000) << "lane_postprocessor: " << lane_postprocessor_->Name();

    // Init output file folder
    if (perception_param.debugparam!=app::DebugParam() &&
        perception_param.debugparam.laneoutdir!=std::string()) {
      write_out_lane_file_ = true;
      out_lane_dir_ = perception_param.debugparam.laneoutdir;
      EnsureDirectory(out_lane_dir_);
    }

    if (perception_param.debugparam!=app::DebugParam() &&
        perception_param.debugparam.calibrationoutdir!=std::string()) {
      write_out_calib_file_ = true;
      out_calib_dir_ = perception_param.debugparam.calibrationoutdir;
      EnsureDirectory(out_calib_dir_);
    }
  }
}

void ObstacleCameraPerception::InitCalibrationService(
    const std::string &work_root, const base::BaseCameraModelPtr model,
    const app::PerceptionParam &perception_param) {
  UNUSED(work_root);
  // Init calibration service
  ACHECK(perception_param.calibrationserviceparam!=app::CalibrationServiceParam())
      << "Failed to include calibration_service_param.";
  {
    auto calibration_service_param =
        perception_param.calibrationserviceparam;
    CalibrationServiceInitOptions calibration_service_init_options;
    calibration_service_init_options.calibrator_working_sensor_name =
        lane_calibration_working_sensor_name_;
    calibration_service_init_options.name_intrinsic_map = name_intrinsic_map_;
    calibration_service_init_options.calibrator_method =
        calibration_service_param.calibratormethod;
    calibration_service_init_options.image_height =
        static_cast<int>(model->get_height());
    calibration_service_init_options.image_width =
        static_cast<int>(model->get_width());
    calibration_service_.reset(
        BaseCalibrationServiceRegisterer::GetInstanceByName(
            calibration_service_param.pluginparam.name));
    ACHECK(calibration_service_ != nullptr);
    ACHECK(calibration_service_->Init(calibration_service_init_options))
        << "Failed to init: "
        << calibration_service_param.pluginparam.name;
    AINFO_EVERY(60000) << "calibration_service: " << calibration_service_->Name();
  }
}

void ObstacleCameraPerception::SetCameraHeightAndPitch(
    const std::map<std::string, float> &name_camera_ground_height_map,
    const std::map<std::string, float> &name_camera_pitch_angle_diff_map,
    const float &pitch_angle_calibrator_working_sensor) {
  if (calibration_service_ == nullptr) {
    AERROR_EVERY(60000) << "Calibraion service is not available";
    return;
  }
  calibration_service_->SetCameraHeightAndPitch(
      name_camera_ground_height_map, name_camera_pitch_angle_diff_map,
      pitch_angle_calibrator_working_sensor);
}

void ObstacleCameraPerception::SetIm2CarHomography(
    Eigen::Matrix3d homography_im2car) {
  if (calibration_service_ == nullptr) {
    AERROR_EVERY(60000) << "Calibraion service is not available";
    return;
  }
  lane_postprocessor_->SetIm2CarHomography(homography_im2car);
}

bool ObstacleCameraPerception::GetCalibrationService(
    BaseCalibrationService **calibration_service) {
  *calibration_service = calibration_service_.get();
  return true;
}

bool ObstacleCameraPerception::Perception(
    const CameraPerceptionOptions &options, CameraFrame *frame) {
  UNUSED(options);
  PERF_FUNCTION();
  inference::CudaUtil::set_device_id(perception_param_.gpuid);
  ObstacleDetectorOptions detector_options;
  ObstacleTransformerOptions transformer_options;
  ObstaclePostprocessorOptions obstacle_postprocessor_options;
  ObstacleTrackerOptions tracker_options;
  FeatureExtractorOptions extractor_options;
  PERF_BLOCK_START();
  frame->camera_k_matrix =
      name_intrinsic_map_.at(frame->data_provider->sensor_name());
  if (frame->calibration_service == nullptr) {
    AERROR_EVERY(60000) << "Calibraion service is not available";
    return false;
  }

  LaneDetectorOptions lane_detetor_options;
  LanePostprocessorOptions lane_postprocessor_options;
  if (!lane_detector_->Detect(lane_detetor_options, frame)) {
    AERROR_EVERY(60000) << "Failed to detect lane.";
    return false;
  }
  PERF_BLOCK_END_WITH_INDICATOR(frame->data_provider->sensor_name(),
                                "LaneDetector");

  if (!lane_postprocessor_->Process2D(lane_postprocessor_options, frame)) {
    AERROR_EVERY(60000) << "Failed to postprocess lane 2D.";
    return false;
  }
  PERF_BLOCK_END_WITH_INDICATOR(frame->data_provider->sensor_name(),
                                "LanePostprocessor2D");

  // Calibration service
  frame->calibration_service->Update(frame);
  PERF_BLOCK_END_WITH_INDICATOR(frame->data_provider->sensor_name(),
                                "CalibrationService");

  if (!lane_postprocessor_->Process3D(lane_postprocessor_options, frame)) {
    AERROR_EVERY(60000) << "Failed to postprocess lane 3D.";
    return false;
  }
  PERF_BLOCK_END_WITH_INDICATOR(frame->data_provider->sensor_name(),
                                "LanePostprocessor3D");

  if (write_out_lane_file_) {
    std::string lane_file_path =
        absl::StrCat(out_lane_dir_, "/", frame->frame_id, ".txt");
    WriteLanelines(write_out_lane_file_, lane_file_path, frame->lane_objects);
  }

  if (write_out_calib_file_) {
    std::string calib_file_path =
        absl::StrCat(out_calib_dir_, "/", frame->frame_id, ".txt");
    WriteCalibrationOutput(write_out_calib_file_, calib_file_path, frame);
  }

  // Obstacle prediction
  if (!tracker_->Predict(tracker_options, frame)) {
    AERROR_EVERY(60000) << "Failed to predict.";
    return false;
  }
  PERF_BLOCK_END_WITH_INDICATOR(frame->data_provider->sensor_name(), "Predict");

  std::shared_ptr<BaseObstacleDetector> detector =
      name_detector_map_.at(frame->data_provider->sensor_name());

  if (!detector->Detect(detector_options, frame)) {
    AERROR_EVERY(60000) << "Failed to detect.";
    return false;
  }
  PERF_BLOCK_END_WITH_INDICATOR(frame->data_provider->sensor_name(), "detect");

  // Save all detections results as kitti format
  WriteDetections(
      perception_param_.debugparam.detectionoutdir!=std::string(),
      absl::StrCat(perception_param_.debugparam.detectionoutdir, "/",
                   frame->frame_id, ".txt"),
      frame->detected_objects);
  if (extractor_ && !extractor_->Extract(extractor_options, frame)) {
    AERROR_EVERY(60000) << "Failed to extractor";
    return false;
  }
  PERF_BLOCK_END_WITH_INDICATOR(frame->data_provider->sensor_name(),
                                "external_feature");

  // Save detection results with bbox, detection_feature
  WriteDetections(
      perception_param_.debugparam.detectfeaturedir!=std::string(),
      absl::StrCat(perception_param_.debugparam.detectfeaturedir, "/",
                   frame->frame_id, ".txt"),
      frame);
  // Set the sensor name of each object
  for (size_t i = 0; i < frame->detected_objects.size(); ++i) {
    frame->detected_objects[i]->camera_supplement.sensor_name =
        frame->data_provider->sensor_name();
  }
  if (!tracker_->Associate2D(tracker_options, frame)) {
    AERROR_EVERY(60000) << "Failed to associate2d.";
    return false;
  }
  PERF_BLOCK_END_WITH_INDICATOR(frame->data_provider->sensor_name(),
                                "Associate2D");

  if (!transformer_->Transform(transformer_options, frame)) {
    AERROR_EVERY(60000) << "Failed to transform.";
    return false;
  }
  PERF_BLOCK_END_WITH_INDICATOR(frame->data_provider->sensor_name(),
                                "Transform");

  // Obstacle postprocessor
  obstacle_postprocessor_options.do_refinement_with_calibration_service =
      frame->calibration_service != nullptr;
  if (!obstacle_postprocessor_->Process(obstacle_postprocessor_options,
                                        frame)) {
    AERROR_EVERY(60000) << "Failed to post process obstacles.";
    return false;
  }
  PERF_BLOCK_END_WITH_INDICATOR(frame->data_provider->sensor_name(),
                                "PostprocessObsacle");

  if (!tracker_->Associate3D(tracker_options, frame)) {
    AERROR_EVERY(60000) << "Failed to Associate3D.";
    return false;
  }
  PERF_BLOCK_END_WITH_INDICATOR(frame->data_provider->sensor_name(),
                                "Associate3D");

  if (!tracker_->Track(tracker_options, frame)) {
    AERROR_EVERY(60000) << "Failed to track.";
    return false;
  }
  PERF_BLOCK_END_WITH_INDICATOR(frame->data_provider->sensor_name(), "Track");

  if (perception_param_.debugparam!=app::DebugParam()) {
    if (perception_param_.debugparam.camera2worldoutfile!=std::string()) {
      WriteCamera2World(out_pose_, frame->frame_id, frame->camera2world_pose);
    }
    if (perception_param_.debugparam.trackoutfile!=std::string()) {
      WriteTracking(out_track_, frame->frame_id, frame->tracked_objects);
    }
  }
  // Save tracked detections results as kitti format
  WriteDetections(
      perception_param_.debugparam.trackeddetectionoutdir!=std::string(),
      absl::StrCat(perception_param_.debugparam.trackeddetectionoutdir,
                   "/", frame->frame_id, ".txt"),
      frame->tracked_objects);

  // Fill polygon and set anchor point
  for (auto &obj : frame->tracked_objects) {
    FillObjectPolygonFromBBox3D(obj.get());
    obj->anchor_point = obj->center;
  }

  return true;
}
}  // namespace camera
}  // namespace perception
}  // namespace apollo
