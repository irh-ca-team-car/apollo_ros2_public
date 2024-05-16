/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include "component/radar_detection.h"

#include "cyber/cyber.h"
#include "modules/common/util/perf_util.h"
#include "modules/perception/common/sensor_manager/sensor_manager.h"
#include "modules/perception/onboard/internal_messages/inner_component_messages.h"
#include "modules/perception/factories.h"

using Clock = apollo::cyber::Clock;

namespace apollo {
namespace perception {
namespace onboard {

bool RadarDetectionComponent::Init() {
  InitFactories();

  AINFO << "Setting gflags";

  INIT_FLAG_bool(obs_enable_hdmap_input, true, "enable hdmap input for roi filter");
  INIT_FLAG_bool(obs_enable_visualization, false,
            "whether to send message for visualization");
  INIT_FLAG_string(obs_screen_output_dir, "./",
              "output dir. for saving visualization screenshots");
  INIT_FLAG_bool(obs_benchmark_mode, false,
            "whether open benchmark mode, default false");
  INIT_FLAG_bool(obs_save_fusion_supplement, false,
            "whether save fusion supplement data, default false");
  INIT_FLAG_bool(start_visualizer, false, "Whether to start visualizer");
  
  // sensor_manager
  INIT_FLAG_string(obs_sensor_intrinsic_path,
              "data/perception/params",
              "The intrinsics/extrinsics dir.");

  INIT_FLAG_string(obs_sensor_meta_path,
              "data/perception/production"
              "/data/perception/common/sensor_meta.pt",
              "The SensorManager config file.");

  INIT_FLAG_bool(enable_base_object_pool, false, "Enable base object pool.");

  // config_manager
  INIT_FLAG_string(config_manager_path, "./conf", "The ModelConfig config paths.");
  INIT_FLAG_string(work_root, "", "Project work root direcotry.");

  // lidar_point_pillars
  INIT_FLAG_int32(gpu_id, 0, "The id of gpu used for inference.");
  INIT_FLAG_string(pfe_torch_file,
              "data/perception/production/data/perception/lidar/"
              "models/detection/point_pillars/pts_voxel_encoder.zip",
              "The path of pillars feature extractor torch file.");
  INIT_FLAG_string(scattered_torch_file,
              "data/perception/production/data/perception/lidar/"
              "models/detection/point_pillars/pts_middle_encoder.zip",
              "The path of pillars feature scatter torch file.");
  INIT_FLAG_string(backbone_torch_file,
              "data/perception/production/data/perception/lidar/"
              "models/detection/point_pillars/pts_backbone.zip",
              "The path of pillars backbone torch file.");
  INIT_FLAG_string(fpn_torch_file,
              "data/perception/production/data/perception/lidar/"
              "models/detection/point_pillars/pts_neck.zip",
              "The path of pillars fpn torch file.");
  INIT_FLAG_string(bbox_head_torch_file,
              "data/perception/production/data/perception/lidar/"
              "models/detection/point_pillars/pts_bbox_head.zip",
              "The path of pillars bbox head torch file.");
  INIT_FLAG_double(normalizing_factor, 255,
              "Normalize intensity range to [0, 1] by this factor.");
  INIT_FLAG_int32(num_point_feature, 5,
             "Length of raw point feature. Features include x, y, z,"
             "intensity and delta of time.");
  INIT_FLAG_bool(enable_ground_removal, false, "Enable ground removal.");
  INIT_FLAG_double(ground_removal_height, -1.5, "Height for ground removal.");
  INIT_FLAG_bool(enable_downsample_beams, false,
            "Enable down sampling point cloud beams with a factor.");
  INIT_FLAG_int32(downsample_beams_factor, 4,
             "Down sample point cloud beams with this factor.");
  INIT_FLAG_bool(enable_downsample_pointcloud, false,
            "Enable down sampling point cloud into centroids of voxel grid.");
  INIT_FLAG_double(downsample_voxel_size_x, 0.01,
              "X-axis size of voxels used for down sampling point cloud.");
  INIT_FLAG_double(downsample_voxel_size_y, 0.01,
              "Y-axis size of voxels used for down sampling point cloud.");
  INIT_FLAG_double(downsample_voxel_size_z, 0.01,
              "Z-axis size of voxels used for down sampling point cloud.");
  INIT_FLAG_bool(enable_fuse_frames, false,
            "Enable fusing preceding frames' point cloud into current frame.");
  INIT_FLAG_int32(num_fuse_frames, 5,
             "Number of frames to fuse, including current frame.");
  INIT_FLAG_double(fuse_time_interval, 0.5,
              "Time interval in seconds of frames to fuse.");
  INIT_FLAG_bool(enable_shuffle_points, false,
            "Enable shuffling points before preprocessing.");
  INIT_FLAG_int32(max_num_points, std::numeric_limits<int>::max(),
             "Max number of points to preprocess.");
  INIT_FLAG_bool(reproduce_result_mode, false, "True if preprocess in CPU mode.");
  INIT_FLAG_double(score_threshold, 0.5, "Classification score threshold.");
  INIT_FLAG_double(nms_overlap_threshold, 0.5, "Nms overlap threshold.");
  INIT_FLAG_int32(num_output_box_feature, 7, "Length of output box feature.");

  // emergency detection onnx
  INIT_FLAG_string(onnx_obstacle_detector_model,
              "data/perception/camera"
              "/lib/obstacle/detector/yolov4/model/yolov4_1_3_416_416.onnx",
              "The onnx model file for emergency detection");
  INIT_FLAG_string(onnx_test_input_path,
              "data/perception/inference"
              "/onnx/testdata/dog.jpg",
              "The test input image file for onnx inference");
  INIT_FLAG_string(onnx_test_input_name_file,
              "data/perception/inference"
              "/onnx/testdata/coco.names",
              "The test input coco name file for onnx inference");
  INIT_FLAG_string(onnx_prediction_image_path,
              "data/perception/inference"
              "/onnx/testdata/prediction.jpg",
              "The prediction output image file for onnx inference");
  INIT_FLAG_int32(num_classes, 80, "number of classes for onnx inference");

  // emergency detection libtorch
  INIT_FLAG_string(torch_detector_model,
              "data/perception/camera"
              "/lib/obstacle/detector/yolov4/model/yolov4.pt",
              "The torch model file for emergency detection");
  
  //msg_buffer flags
  INIT_FLAG_int32(obs_msg_buffer_size, 200, "buffer size for odometry_subscriber");
  INIT_FLAG_double(obs_buffer_match_precision, 0.01,
              "match_precision for odometry_subscriber");
  
  AINFO << "Gflags set";

  
  
  comp_config.radarname = declare_parameter<std::string>("radar_name", "radar_front");
  comp_config.tfchildframeid = declare_parameter<std::string>("tf_child_frame_id", "radar_front");
  comp_config.radarforwarddistance = declare_parameter<float>("radar_forward_distance", 200.0);
  comp_config.radarpreprocessormethod = declare_parameter<std::string>("radar_preprocessor_method", "ContiArsPreprocessor");
  comp_config.radarperceptionmethod = declare_parameter<std::string>("radar_perception_method", "RadarObstaclePerception");
  comp_config.radarpipelinename = declare_parameter<std::string>("radar_pipeline_name", "FrontRadarPipeline");
  comp_config.odometrychannelname = declare_parameter<std::string>("rodometry_channel_name", "/apollo/localization/pose");
  comp_config.outputchannelname = declare_parameter<std::string>("output_channel_name", "/apollo/perception/inner/PrefusedObjects");
  
  AINFO << "Radar Component Configs: " << comp_config;

  // To load component configs
  //tf_child_frame_id_ = comp_config.tfchildframeid;
  //radar_forward_distance_ = comp_config.radarforwarddistance;
  //preprocessor_method_ = std::string(comp_config.radarpreprocessormethod);
  AINFO << comp_config.radarpreprocessormethod ;
  //perception_method_ = comp_config.radarperceptionmethod;
  //pipeline_name_ = comp_config.radarpipelinename;
  //odometry_channel_name_ = comp_config.odometrychannelname;
  if (!common::SensorManager::Instance()->GetSensorInfo(
          comp_config.radarname, &radar_info_)) {
    AERROR << "Failed to get sensor info, sensor name: "
           << comp_config.radarname;
    return false;
  }
  
  writer_ = node_->CreateWriterJson<SensorFrameMessage>(comp_config.outputchannelname);
  contiradar_reader_ = node_->CreateReader<ContiRadar>("/apollo/sensor/radar/front", std::bind(&RadarDetectionComponent::Proc, this, std::placeholders::_1));

  AINFO << comp_config.radarpreprocessormethod;
  // Init algorithm plugin
  ACHECK(InitAlgorithmPlugin()) << "Failed to init algorithm plugin.";
  radar2world_trans_.Init(comp_config.tfchildframeid);
  radar2novatel_trans_.Init(comp_config.tfchildframeid);
  localization_subscriber_.Init(
      comp_config.odometrychannelname,
      comp_config.odometrychannelname + '_' + comp_config.radarname);
  return true;
}

bool RadarDetectionComponent::Proc(const std::shared_ptr<ContiRadar>& message) {
  AINFO << "Enter radar preprocess, message timestamp: "
        << message->apolloheader.timestampsec << " current timestamp "
        << Clock::NowInSeconds();
  auto out_message = std::make_shared<SensorFrameMessage>();

  if (!InternalProc(message, out_message)) {
    return false;
  }
  writer_->Write(apollo_msgs::msg::to_json(*out_message));
  AINFO << "Send radar processing output message.";
  return true;
}

bool RadarDetectionComponent::InitAlgorithmPlugin() {
  AINFO << "onboard radar_preprocessor: " << comp_config.radarpreprocessormethod;
  if (FLAGS_obs_enable_hdmap_input) {
    hdmap_input_ = map::HDMapInput::Instance();
    ACHECK(hdmap_input_->Init()) << "Failed to init hdmap input.";
  }
  radar::BasePreprocessor* preprocessor =
      radar::BasePreprocessorRegisterer::GetInstanceByName(
          comp_config.radarpreprocessormethod);
  CHECK_NOTNULL(preprocessor);
  radar_preprocessor_.reset(preprocessor);
  ACHECK(radar_preprocessor_->Init()) << "Failed to init radar preprocessor.";
  radar::BaseRadarObstaclePerception* radar_perception =
      radar::BaseRadarObstaclePerceptionRegisterer::GetInstanceByName(
          comp_config.radarperceptionmethod);
  ACHECK(radar_perception != nullptr)
      << "No radar obstacle perception named: " << comp_config.radarperceptionmethod;
  radar_perception_.reset(radar_perception);
  ACHECK(radar_perception_->Init(comp_config.radarpipelinename))
      << "Failed to init radar perception.";
  AINFO << "Init algorithm plugin successfully.";
  return true;
}

bool RadarDetectionComponent::InternalProc(
    const std::shared_ptr<ContiRadar>& in_message,
    std::shared_ptr<SensorFrameMessage> out_message) {
  PERF_FUNCTION_WITH_INDICATOR(radar_info_.name);
  ContiRadar raw_obstacles = *in_message;
  {
    std::unique_lock<std::mutex> lock(_mutex);
    ++seq_num_;
  }
  double timestamp = in_message->apolloheader.timestampsec;
  const double cur_time = Clock::NowInSeconds();
  const double start_latency = (cur_time - timestamp) * 1e3;
  AINFO_EVERY(60000) << "FRAME_STATISTICS:Radar:Start:msg_time[" << timestamp
        << "]:cur_time[" << cur_time << "]:cur_latency[" << start_latency
        << "]";
  PERF_BLOCK_START();
  // Init preprocessor_options
  radar::PreprocessorOptions preprocessor_options;
  ContiRadar corrected_obstacles;
  radar_preprocessor_->Preprocess(raw_obstacles, preprocessor_options,
                                  &corrected_obstacles);
  PERF_BLOCK_END_WITH_INDICATOR(radar_info_.name, "radar_preprocessor");
  timestamp = corrected_obstacles.apolloheader.timestampsec;

  out_message->timestamp_ = timestamp;
  out_message->seq_num_ = seq_num_;
  out_message->process_stage_ = ProcessStage::LONG_RANGE_RADAR_DETECTION;
  out_message->sensor_id_ = radar_info_.name;

  // Init radar perception options
  radar::RadarPerceptionOptions options;
  options.sensor_name = radar_info_.name;
  // Init detector_options
  Eigen::Affine3d radar_trans;
  if (!radar2world_trans_.GetSensor2worldTrans(timestamp, &radar_trans)) {
    out_message->error_code_ = apollo::common::ErrorCode::PERCEPTION_ERROR_TF;
    AWARN << "Failed to get pose at time: " << timestamp;
    return true;
  }
  Eigen::Affine3d radar2novatel_trans;
  if (!radar2novatel_trans_.GetTrans(timestamp, &radar2novatel_trans, "novatel",
                                     comp_config.tfchildframeid)) {
    out_message->error_code_ = apollo::common::ErrorCode::PERCEPTION_ERROR_TF;
    AERROR << "Failed to get radar2novatel trans at time: " << timestamp;
    return true;
  }
  PERF_BLOCK_END_WITH_INDICATOR(radar_info_.name, "GetSensor2worldTrans");
  Eigen::Matrix4d radar2world_pose = radar_trans.matrix();
  options.detector_options.radar2world_pose = &radar2world_pose;
  Eigen::Matrix4d radar2novatel_trans_m = radar2novatel_trans.matrix();
  options.detector_options.radar2novatel_trans = &radar2novatel_trans_m;
  if (!GetCarLocalizationSpeed(timestamp,
                               &(options.detector_options.car_linear_speed),
                               &(options.detector_options.car_angular_speed))) {
    AERROR << "Failed to call get_car_speed. [timestamp: " << timestamp;
    // return false;
  }
  PERF_BLOCK_END_WITH_INDICATOR(radar_info_.name, "GetCarSpeed");
  // Init roi_filter_options
  base::PointD position;
  position.x = radar_trans(0, 3);
  position.y = radar_trans(1, 3);
  position.z = radar_trans(2, 3);
  options.roi_filter_options.roi.reset(new base::HdmapStruct());
  if (FLAGS_obs_enable_hdmap_input) {
    hdmap_input_->GetRoiHDMapStruct(position, radar_forward_distance_,
                                    options.roi_filter_options.roi);
  }
  PERF_BLOCK_END_WITH_INDICATOR(radar_info_.name, "GetRoiHDMapStruct");
  // Init object_filter_options
  // Init track_options
  // Init object_builder_options
  std::vector<base::ObjectPtr> radar_objects;
  if (!radar_perception_->Perceive(corrected_obstacles, options,
                                   &radar_objects)) {
    out_message->error_code_ =
        apollo::common::ErrorCode::PERCEPTION_ERROR_PROCESS;
    AERROR << "RadarDetector Proc failed.";
    return true;
  }
  out_message->frame_.reset(new base::Frame());
  out_message->frame_->sensor_info = radar_info_;
  out_message->frame_->timestamp = timestamp;
  out_message->frame_->sensor2world_pose = radar_trans;
  out_message->frame_->objects = radar_objects;

  const double end_timestamp = Clock::NowInSeconds();
  const double end_latency =
      (end_timestamp - in_message->apolloheader.timestampsec) * 1e3;
  AINFO_EVERY(60000) << "FRAME_STATISTICS:Radar:End:msg_time["
        << in_message->apolloheader.timestampsec << "]:cur_time["
        << end_timestamp << "]:cur_latency[" << end_latency << "]";
  PERF_BLOCK_END_WITH_INDICATOR(radar_info_.name, "radar_perception");

  return true;
}

bool RadarDetectionComponent::GetCarLocalizationSpeed(
    double timestamp, Eigen::Vector3f* car_linear_speed,
    Eigen::Vector3f* car_angular_speed) {
  if (car_linear_speed == nullptr) {
    AERROR << "car_linear_speed is not available";
    return false;
  }
  (*car_linear_speed) = Eigen::Vector3f::Zero();
  if (car_linear_speed == nullptr) {
    AERROR << "car_linear_speed is not available";
    return false;
  }
  (*car_angular_speed) = Eigen::Vector3f::Zero();
  std::shared_ptr<LocalizationEstimate const> loct_ptr;
  if (!localization_subscriber_.LookupNearest(timestamp, &loct_ptr)) {
    AERROR << "Cannot get car speed.";
    return false;
  }
  (*car_linear_speed)[0] =
      static_cast<float>(loct_ptr->pose.linearvelocity.x);
  (*car_linear_speed)[1] =
      static_cast<float>(loct_ptr->pose.linearvelocity.y);
  (*car_linear_speed)[2] =
      static_cast<float>(loct_ptr->pose.linearvelocity.z);
  (*car_angular_speed)[0] =
      static_cast<float>(loct_ptr->pose.angularvelocity.x);
  (*car_angular_speed)[1] =
      static_cast<float>(loct_ptr->pose.angularvelocity.y);
  (*car_angular_speed)[2] =
      static_cast<float>(loct_ptr->pose.angularvelocity.z);

  return true;
}


}  // namespace onboard
}  // namespace perception
}  // namespace apollo

CYBER_REGISTER_COMPONENT(RadarDetectionComponent);
