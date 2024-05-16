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
#include "component/trafficlights_perception.h"

#include <limits>
#include <map>
#include <utility>

#include <boost/algorithm/string.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include "absl/strings/str_cat.h"

#include "cyber/cyber.h"
#include "modules/common/util/util.h"
#include "modules/common/math/math_utils.h"
#include "modules/common/util/perf_util.h"
#include "modules/common/util/string_util.h"
#include "modules/perception/camera/common/data_provider.h"
#include "modules/perception/common/sensor_manager/sensor_manager.h"
#include "modules/perception/onboard/common_flags/common_flags.h"
#include "modules/transform/proto/transform.pb.h"
#include "modules/perception/factories.h"

namespace apollo {
namespace perception {
namespace onboard {

using TLCamID = apollo::perception::TrafficLightDetection::CameraID;
using apollo::cyber::common::GetAbsolutePath;
using apollo::cyber::Clock;
using apollo::perception::common::SensorManager;

class TLInfo {
 public:
  cv::Scalar tl_color_;
  std::string tl_string_;
  std::string tl_string_ex_;
};

std::map<base::TLColor, TLInfo> s_tl_infos = {
    {base::TLColor::TL_UNKNOWN_COLOR,
     {cv::Scalar(255, 255, 255), "UNKNOWN", "UNKNOWN traffic light"}},
    {base::TLColor::TL_RED,
     {cv::Scalar(0, 0, 255), "RED", "RED traffic light"}},
    {base::TLColor::TL_GREEN,
     {cv::Scalar(0, 255, 0), "GREEN", "GREEN traffic light"}},
    {base::TLColor::TL_YELLOW,
     {cv::Scalar(0, 255, 255), "YELLOW", "YELLOW traffic light"}}};

static int GetGpuId(
    const apollo::perception::camera::CameraPerceptionInitOptions& options) {
  apollo::perception::camera::app::TrafficLightParam trafficlight_param;
  apollo_msgs::msg::ApolloperceptioncameraappDetectorParam interparam;
  std::string work_root = apollo::perception::camera::GetCyberWorkRoot();
  std::string config_file =
      GetAbsolutePath(options.root_dir, options.conf_file);
  config_file = GetAbsolutePath(work_root, config_file);
  /*if (!cyber::common::GetProtoFromFile(config_file, &trafficlight_param)) {
    AERROR << "Read config failed: " << config_file;
    return -1;
  }*/
  auto currentNode = apollo::cyber::currentNode;
  trafficlight_param.gpuid = currentNode->declare_parameter<int>("gpu_id", 0);
  
  interparam.pluginparam.name = currentNode->declare_parameter<std::string>("name", "TrafficLightDetection");
  interparam.pluginparam.rootdir = currentNode->declare_parameter<std::string>("root_dir", "data/perception/production/data/perception/camera/models/traffic_light_detection");
  interparam.pluginparam.configfile = currentNode->declare_parameter<std::string>("config_file", "detection.pt");
  trafficlight_param.detectorparam.push_back(interparam);
  
  interparam.pluginparam.name = currentNode->declare_parameter<std::string>("name", "TrafficLightRecognition");
  interparam.pluginparam.rootdir = currentNode->declare_parameter<std::string>("root_dir", "data/perception/production/data/perception/camera/models/traffic_light_recognition");
  interparam.pluginparam.configfile = currentNode->declare_parameter<std::string>("config_file", "recognition.pt");
  trafficlight_param.detectorparam.push_back(interparam);
  
  trafficlight_param.trackerparam.pluginparam.name = currentNode->declare_parameter<std::string>("name", "SemanticReviser");
  trafficlight_param.trackerparam.pluginparam.rootdir = currentNode->declare_parameter<std::string>("root_dir", "data/perception/production/data/perception/camera/models/traffic_light_tracker");
  trafficlight_param.trackerparam.pluginparam.configfile = currentNode->declare_parameter<std::string>("config_file", "semantic.pt");
  
  if (trafficlight_param.detectorparam.empty()) {
    AERROR << "get gpu id failed. detector_param().empty()";
    return -1;
  }
  if (trafficlight_param.gpuid==0) {
    AINFO << "gpu id not found.";
    return -1;
  }
  return trafficlight_param.gpuid;
}

bool TrafficLightsPerceptionComponent::Init() {
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
  
  apollo::common::gflags::init_common(node_);
  AINFO << "Gflags set";
  
  frame_.reset(new camera::CameraFrame);
  writer_ = node_->CreateWriter<apollo_msgs::msg::ApolloperceptionTrafficLightDetection>(
      "/apollo/perception/traffic_light");

  if (InitConfig() != cyber::SUCC) {
    AERROR << "TrafficLightsPerceptionComponent InitConfig failed.";
    return false;
  }

  if (InitAlgorithmPlugin() != cyber::SUCC) {
    AERROR << "TrafficLightsPerceptionComponent InitAlgorithmPlugin failed.";
    return false;
  }

  if (InitCameraFrame() != cyber::SUCC) {
    AERROR << "TrafficLightsPerceptionComponent InitCameraFrame failed.";
    return false;
  }

  if (InitCameraListeners() != cyber::SUCC) {
    AERROR << "TrafficLightsPerceptionComponent InitCameraListeners failed.";
    return false;
  }

  if (InitV2XListener() != cyber::SUCC) {
    AERROR << "TrafficLightsPerceptionComponent InitV2XListener failed.";
    return false;
  }

  if (FLAGS_start_visualizer) {
    AINFO << "TrafficLight Visualizer is ON";
  } else {
    AINFO << "TrafficLight Visualizer is OFF";
  }

  AINFO << "TrafficLight Preproc Init Success";
  return true;
}

int TrafficLightsPerceptionComponent::InitConfig() {
  apollo::perception::onboard::TrafficLight traffic_light_param;
  
  /*if (!GetProtoConfig(&traffic_light_param)) {
    AINFO << "load trafficlights perception component proto param failed";
    return cyber::FAIL;
  }*/
  #define DUMP(A) ADEBUG << #A " = " << A
  traffic_light_param.tltf2frameid = declare_parameter<std::string>("tl_tf2_frame_id", "world");
  DUMP(traffic_light_param.tltf2frameid);
  traffic_light_param.tltf2childframeid = declare_parameter<std::string>("tl_tf2_child_frame_id", "novatel");
  DUMP(traffic_light_param.tltf2childframeid);
  traffic_light_param.tf2timeoutsecond = declare_parameter<float>("tf2_timeout_second", 0.01);
  DUMP(traffic_light_param.tf2timeoutsecond);
  traffic_light_param.cameranames = declare_parameter<std::string>("camera_names", "front_6mm,front_12mm");
  DUMP(traffic_light_param.cameranames);
  traffic_light_param.camerachannelnames = declare_parameter<std::string>("camera_channel_names", "/apollo/sensor/camera/front_6mm/image,/apollo/sensor/camera/front_12mm/image");
  DUMP(traffic_light_param.camerachannelnames);
  traffic_light_param.tlimagetimestampoffset = declare_parameter<float>("tl_image_timestamp_offset", 0.0);
  DUMP(traffic_light_param.tlimagetimestampoffset);
  traffic_light_param.maxprocessimagefps = declare_parameter<int>("max_process_image_fps", 8);
  DUMP(traffic_light_param.maxprocessimagefps);
  traffic_light_param.querytfintervalseconds = declare_parameter<float>("query_tf_interval_seconds", 0.3);
  DUMP(traffic_light_param.querytfintervalseconds);
  traffic_light_param.validhdmapinterval = declare_parameter<float>("valid_hdmap_interval", 1.5);
  DUMP(traffic_light_param.validhdmapinterval);
  traffic_light_param.imagesystsdiffthreshold = declare_parameter<float>("image_sys_ts_diff_threshold", 0.5);
  DUMP(traffic_light_param.imagesystsdiffthreshold);
  traffic_light_param.syncintervalseconds = declare_parameter<float>("sync_interval_seconds", 0.5);
  DUMP(traffic_light_param.syncintervalseconds);
  traffic_light_param.cameratrafficlightperceptionconfdir = declare_parameter<std::string>("camera_traffic_light_perception_conf_dir", "data/perception/production/conf/perception/camera");
  apollo::cyber::ComponentBase::instance()->replaceRoot(traffic_light_param.cameratrafficlightperceptionconfdir);
  DUMP(traffic_light_param.cameratrafficlightperceptionconfdir);
  traffic_light_param.cameratrafficlightperceptionconffile = declare_parameter<std::string>("camera_traffic_light_perception_conf_file", "trafficlight.pt");
  DUMP(traffic_light_param.cameratrafficlightperceptionconffile);
  traffic_light_param.defaultimagebordersize = declare_parameter<int>("default_image_border_size", 100);
  DUMP(traffic_light_param.defaultimagebordersize);
  traffic_light_param.trafficlightoutputchannelname = declare_parameter<std::string>("traffic_light_output_channel_name", "/apollo/perception/traffic_light");
  DUMP(traffic_light_param.trafficlightoutputchannelname);
  traffic_light_param.simulationchannelname = declare_parameter<std::string>("simulation_channel_name", "/apollo/perception/traffic_light_simulation");
  DUMP(traffic_light_param.simulationchannelname);
  traffic_light_param.v2xtrafficlightsinputchannelname = declare_parameter<std::string>("tv2x_trafficlights_input_channel_name", "/apollo/v2x/traffic_light");
  DUMP(traffic_light_param.v2xtrafficlightsinputchannelname);
  traffic_light_param.v2xsyncintervalseconds = declare_parameter<float>("v2x_sync_interval_seconds", 0.1);
  DUMP(traffic_light_param.v2xsyncintervalseconds);
  traffic_light_param.maxv2xmsgbuffsize = declare_parameter<int>("max_v2x_msg_buff_size", 50);
  DUMP(traffic_light_param.maxv2xmsgbuffsize);

  tf2_frame_id_ = traffic_light_param.tltf2frameid;
  tf2_child_frame_id_ = traffic_light_param.tltf2childframeid;
  tf2_timeout_second_ = traffic_light_param.tf2timeoutsecond;
  AINFO << "tl_tf2_frame_id: " << tf2_frame_id_
        << " tl_tf2_child_frame_id: " << tf2_child_frame_id_
        << " tf2_buff_size: " << tf2_timeout_second_;

  std::string camera_names_str = "";
  camera_names_str = traffic_light_param.cameranames;
  boost::algorithm::split(camera_names_, camera_names_str,
                          boost::algorithm::is_any_of(","));

  std::string camera_channel_names_str = "";
  camera_channel_names_str = traffic_light_param.camerachannelnames;
  boost::algorithm::split(input_camera_channel_names_, camera_channel_names_str,
                          boost::algorithm::is_any_of(","));

  query_tf_interval_seconds_ = traffic_light_param.querytfintervalseconds;
  valid_hdmap_interval_ = traffic_light_param.validhdmapinterval;
  image_timestamp_offset_ = traffic_light_param.tlimagetimestampoffset;
  AINFO << " _image_timestamp_offset: " << image_timestamp_offset_;

  max_process_image_fps_ = traffic_light_param.maxprocessimagefps;
  proc_interval_seconds_ = 1.0 / max_process_image_fps_;
  AINFO << "_proc_interval_seconds: " << proc_interval_seconds_;

  image_sys_ts_diff_threshold_ =
      traffic_light_param.imagesystsdiffthreshold;
  preprocessor_init_options_.sync_interval_seconds =
      static_cast<float>(traffic_light_param.syncintervalseconds);
  camera_perception_init_options_.root_dir =
      traffic_light_param.cameratrafficlightperceptionconfdir;
  camera_perception_init_options_.conf_file =
      traffic_light_param.cameratrafficlightperceptionconffile;
  default_image_border_size_ = traffic_light_param.defaultimagebordersize;

  simulation_channel_name_ = traffic_light_param.simulationchannelname;
  traffic_light_output_channel_name_ =
      traffic_light_param.trafficlightoutputchannelname;

  // v2x params
  v2x_trafficlights_input_channel_name_ =
      traffic_light_param.v2xtrafficlightsinputchannelname;
  v2x_sync_interval_seconds_ = traffic_light_param.v2xsyncintervalseconds;
  max_v2x_msg_buff_size_ = traffic_light_param.maxv2xmsgbuffsize;
  v2x_msg_buffer_.set_capacity(max_v2x_msg_buff_size_);
  return cyber::SUCC;
}

int TrafficLightsPerceptionComponent::InitAlgorithmPlugin() {
  // init preprocessor
  preprocessor_.reset(new camera::TLPreprocessor);
  if (!preprocessor_) {
    AERROR << "TrafficLightsPerceptionComponent new preprocessor failed";
    return cyber::FAIL;
  }

  preprocessor_init_options_.camera_names = camera_names_;
  if (!preprocessor_->Init(preprocessor_init_options_)) {
    AERROR << "TrafficLightsPerceptionComponent init preprocessor failed";
    return cyber::FAIL;
  }
  const auto camera_names_by_descending_focal_len =
      preprocessor_->GetCameraNamesByDescendingFocalLen();
  if (camera_names_by_descending_focal_len.empty()) {
    AERROR << "empty camera_names in preprocessor";
    return cyber::FAIL;
  }
  if (camera_names_.size() != input_camera_channel_names_.size() ||
      camera_names_.empty()) {
    AERROR << "invalid camera_names config";
    return cyber::FAIL;
  }
  SensorManager* sensor_manager = SensorManager::Instance();
  for (size_t i = 0; i < camera_names_.size(); ++i) {
    if (!sensor_manager->IsSensorExist(camera_names_[i])) {
      AERROR << ("sensor_name: " + camera_names_[i] + " not exists.");
      return cyber::FAIL;
    }

    // init transform wrappers
    std::string tf2_camera_child_frame_id =
        sensor_manager->GetFrameId(camera_names_[i]);
    std::shared_ptr<TransformWrapper> trans_wrapper(new TransformWrapper);
    trans_wrapper->Init(tf2_camera_child_frame_id);
    camera2world_trans_wrapper_map_[camera_names_[i]] = trans_wrapper;

    if (camera_names_[i] == camera_names_by_descending_focal_len.back()) {
      image_border_sizes_[camera_names_[i]] = 0;
    } else {
      image_border_sizes_[camera_names_[i]] = default_image_border_size_;
    }
  }

  // init hdmaps
  hd_map_ = map::HDMapInput::Instance();
  if (hd_map_ == nullptr) {
    AERROR << "PreprocessComponent get hdmap failed.";
    return cyber::FAIL;
  }

  if (!hd_map_->Init()) {
    AERROR << "PreprocessComponent init hd-map failed.";
    return cyber::FAIL;
  }

  camera_perception_init_options_.use_cyber_work_root = true;
  traffic_light_pipeline_.reset(new camera::TrafficLightCameraPerception);
  if (!traffic_light_pipeline_->Init(camera_perception_init_options_)) {
    AERROR << "camera_obstacle_pipeline_->Init() failed";
    return cyber::FAIL;
  }

  return cyber::SUCC;
}

int TrafficLightsPerceptionComponent::InitCameraListeners() {
  // init camera listeners
  for (size_t i = 0; i < camera_names_.size(); ++i) {
    const auto& camera_name = camera_names_[i];
    const auto& camera_channel_name = input_camera_channel_names_[i];
    const std::string camera_listener_name = "tl_" + camera_name + "_listener";

    //typedef const std::shared_ptr<apollo::drivers::Image> ImageMsgType;
    //std::function<void(const ImageMsgType&)> sub_camera_callback =
    //    std::bind(&TrafficLightsPerceptionComponent::OnReceiveImage, this,
    //              std::placeholders::_1, camera_name);
    sub_camera_reader =
        node_->CreateReader<apollo::drivers::Image>(camera_channel_name, std::bind(&TrafficLightsPerceptionComponent::OnReceiveImage, this,
                  std::placeholders::_1, camera_name));
    camera_listener_.push_back(sub_camera_reader);
    last_sub_camera_image_ts_[camera_name] = 0.0;
  }

  return cyber::SUCC;
}

int TrafficLightsPerceptionComponent::InitV2XListener() {
  //typedef const std::shared_ptr<apollo::v2x::IntersectionTrafficLightData>
  //    V2XTrafficLightsMsgType;
  //std::function<void(const V2XTrafficLightsMsgType&)> sub_v2x_tl_callback =
  //    std::bind(&TrafficLightsPerceptionComponent::OnReceiveV2XMsg, this,
  //              std::placeholders::_1);
  sub_v2x_reader = node_->CreateReader<apollo::v2x::IntersectionTrafficLightData>(
      v2x_trafficlights_input_channel_name_, std::bind(&TrafficLightsPerceptionComponent::OnReceiveV2XMsg, this,
                std::placeholders::_1));
  return cyber::SUCC;
}

int TrafficLightsPerceptionComponent::InitCameraFrame() {
  data_provider_init_options_.image_height = image_height_;
  data_provider_init_options_.image_width = image_width_;
  int gpu_id = GetGpuId(camera_perception_init_options_);
  if (gpu_id == -1) {
    return cyber::FAIL;
  }
  data_provider_init_options_.device_id = gpu_id;
  AINFO << "trafficlights data_provider_init_options_.device_id: "
        << data_provider_init_options_.device_id;
  data_provider_init_options_.do_undistortion = enable_undistortion_;

  // init data_providers for each camrea
  for (const auto& camera_name : camera_names_) {
    data_provider_init_options_.sensor_name = camera_name;
    std::shared_ptr<camera::DataProvider> data_provider(
        new camera::DataProvider);
    if (!data_provider->Init(data_provider_init_options_)) {
      AERROR << "trafficlights init data_provider failed. "
             << " camera_name: " << camera_name;
      return cyber::FAIL;
    }
    data_providers_map_[camera_name] = data_provider;
  }

  return cyber::SUCC;
}

void TrafficLightsPerceptionComponent::OnReceiveImage(
    const std::shared_ptr<apollo::drivers::Image> msg,
    const std::string& camera_name) {
  double receive_img_timestamp = Clock::NowInSeconds();
  double image_msg_ts = msg->measurementtime;
  image_msg_ts += image_timestamp_offset_;
  last_sub_camera_image_ts_[camera_name] = image_msg_ts;

  {
    const double cur_time = Clock::NowInSeconds();
    const double start_latency = (cur_time - msg->measurementtime) * 1e3;
    AINFO_EVERY(60000) << "FRAME_STATISTICS:TrafficLights:Start:msg_time["
          << FORMAT_TIMESTAMP(msg->measurementtime) << "]:cur_time["
          << FORMAT_TIMESTAMP(cur_time) << "]:cur_latency[" << start_latency
          << "]";
  }

  const std::string perf_indicator = "trafficlights";
  if (!CheckCameraImageStatus(image_msg_ts, check_image_status_interval_thresh_,
                              camera_name)) {
    AERROR << "CheckCameraImageStatus failed";
    return;
  }

  camera::TLPreprocessorOption preprocess_option;
  preprocess_option.image_borders_size = &image_border_sizes_;

  // query pose and signals, add cached camera selection by lights' projections
  if (!UpdateCameraSelection(image_msg_ts, preprocess_option, frame_.get())) {
    AWARN << "add_cached_camera_selection failed, ts: " << image_msg_ts;
  }

  // skipping frame according to last proc image timestamp
  if (last_proc_image_ts_ > 0.0 &&
      receive_img_timestamp - last_proc_image_ts_ < proc_interval_seconds_) {
    AINFO << "skip current image, img_ts: " << image_msg_ts
          << " , receive_img_timestamp: " << receive_img_timestamp
          << " ,_last_proc_image_ts: " << last_proc_image_ts_
          << " , _proc_interval_seconds: " << proc_interval_seconds_;
    return;
  }
  // sync image with cached projections
  bool sync_image_ok =
      preprocessor_->SyncInformation(image_msg_ts, camera_name);

  if (!sync_image_ok) {
    AINFO << "PreprocessComponent not publish image, ts:" << image_msg_ts
          << ", camera_name: " << camera_name;
    //    SendSimulationMsg();
    return;
  }

  // Fill camera frame
  camera::DataProvider::ImageOptions image_options;
  image_options.target_color = base::Color::RGB;
  frame_->data_provider = data_providers_map_.at(camera_name).get();
  frame_->data_provider->FillImageData(
      image_height_, image_width_,
      reinterpret_cast<const uint8_t*>(msg->data.data.data()), msg->encoding);
  frame_->timestamp = image_msg_ts;
  // caros monitor -- image system time diff
  const auto& diff_image_sys_ts = image_msg_ts - receive_img_timestamp;
  if (fabs(diff_image_sys_ts) > image_sys_ts_diff_threshold_) {
    const std::string metric_name = "perception traffic_light exception";
    const std::string debug_string =
        absl::StrCat("diff_image_sys_ts:", diff_image_sys_ts,
                     ",camera_id:", camera_name, ",camera_ts:", image_msg_ts);
    AWARN << "image_ts - system_ts(in seconds): " << diff_image_sys_ts
          << ". Check if image timestamp drifts."
          << ", camera_id: " + camera_name
          << ", debug_string: " << debug_string;
  }

  if (!VerifyLightsProjection(image_msg_ts, preprocess_option, camera_name,
                              frame_.get())) {
    AINFO << "VerifyLightsProjection on image failed, ts: " << image_msg_ts
          << ", camera_name: " << camera_name
          << " last_query_tf_ts_: " << last_query_tf_ts_
          << " need update_camera_selection immediately,"
          << " reset last_query_tf_ts_ to -1";
    last_query_tf_ts_ = -1.0;
  }
  last_proc_image_ts_ = Clock::NowInSeconds();

  AINFO << "start proc.";
  traffic_light_pipeline_->Perception(camera_perception_options_, frame_.get());

  for (auto light : frame_->traffic_lights) {
    AINFO << "after tl pipeline " << light->id << " color "
          << static_cast<int>(light->status.color);
  }

  SyncV2XTrafficLights(frame_.get());

  std::shared_ptr<apollo_msgs::msg::ApolloperceptionTrafficLightDetection> out_msg(new apollo_msgs::msg::ApolloperceptionTrafficLightDetection);
  if (!TransformOutputMessage(frame_.get(), camera_name, &out_msg)) {
    AERROR << "transform_output_message failed, msg_time: "
           << FORMAT_TIMESTAMP(msg->measurementtime);
    return;
  }

  // send msg
  writer_->Write(out_msg);

  //  SendSimulationMsg();

  {
    const double end_timestamp = Clock::NowInSeconds();
    const double end_latency = (end_timestamp - msg->measurementtime) * 1e3;
    AINFO_EVERY(60000) << "FRAME_STATISTICS:TrafficLights:End:msg_time["
          << FORMAT_TIMESTAMP(msg->measurementtime) << "]:cur_time["
          << FORMAT_TIMESTAMP(end_timestamp) << "]:cur_latency[" << end_latency
          << "]";
  }
}

void TrafficLightsPerceptionComponent::OnReceiveV2XMsg(
    const std::shared_ptr<apollo::v2x::IntersectionTrafficLightData> v2x_msg) {
  v2x_msg_buffer_.push_back(*v2x_msg);
}

void TrafficLightsPerceptionComponent::GenerateTrafficLights(
    const std::vector<apollo_msgs::msg::ApollohdmapSignal>& signals,
    std::vector<base::TrafficLightPtr>* traffic_lights) {
  traffic_lights->clear();
  for (auto signal : signals) {
    base::TrafficLightPtr light;
    light.reset(new base::TrafficLight);
    light->id = signal.id.id;
    for (size_t i = 0; i < signal.boundary.point.size(); ++i) {
      base::PointXYZID point;
      point.x = signal.boundary.point[i].x;
      point.y = signal.boundary.point[i].y;
      point.z = signal.boundary.point[i].z;
      light->region.points.push_back(point);
    }

    int cur_semantic = 0;
    // for (int i = 0; i < signal.control_direction_size(); i++) {
    //   cur_semantic |= 1 << signal.control_direction(i);
    // }
    light->semantic = cur_semantic;
    traffic_lights->push_back(light);
    stoplines_ = signal.stopline;
  }
}

bool TrafficLightsPerceptionComponent::QueryPoseAndSignals(
    const double ts, camera::CarPose* pose,
    std::vector<apollo_msgs::msg::ApollohdmapSignal>* signals) {
  PERF_FUNCTION();
  // get pose
  if (!GetCarPose(ts, pose)) {
    AINFO << "query_pose_and_signals failed to get car pose, ts:" << ts;
    return false;
  }
  auto pos_x = std::to_string(pose->getCarPose()(0, 3));
  auto pos_y = std::to_string(pose->getCarPose()(1, 3));
  AINFO << "query_pose_and_signals get position (x, y): "
        << " (" << pos_x << ", " << pos_y << ").";

  if (!hd_map_) {
    AERROR << "hd_map_ not init.";
    return false;
  }
  // get signals
  Eigen::Vector3d car_position = pose->getCarPosition();
  if (!hd_map_->GetSignals(car_position, forward_distance_to_query_signals,
                           signals)) {
    if (ts - last_signals_ts_ < valid_hdmap_interval_) {
      *signals = last_signals_;
      AWARN << "query_pose_and_signals failed to get signals info. "
            << "Now use last info. ts:" << ts << " pose:" << *pose
            << " signals.size(): " << signals->size();
    } else {
      AERROR << "query_pose_and_signals failed to get signals info. "
             << "ts:" << ts << " pose:" << *pose;
    }
  } else {
    AINFO << "query_pose_and_signals succeeded, signals.size(): "
          << signals->size();
    // here need mutex lock_guard, added at the beginning of OnReceiveImage()
    last_signals_ts_ = ts;
    last_signals_ = *signals;
  }
  return true;
}

bool TrafficLightsPerceptionComponent::VerifyLightsProjection(
    const double& ts, const camera::TLPreprocessorOption& option,
    const std::string& camera_name, camera::CameraFrame* frame) {
  PERF_FUNCTION();
  camera::CarPose pose;
  std::vector<apollo_msgs::msg::ApollohdmapSignal> signals;
  if (!QueryPoseAndSignals(ts, &pose, &signals)) {
    AERROR << "query_pose_and_signals failed, ts: " << ts;
    // (*image_lights)->debug_info.is_pose_valid = false;
    return false;
  }

  GenerateTrafficLights(signals, &frame->traffic_lights);

  if (!preprocessor_->UpdateLightsProjection(pose, option, camera_name,
                                             &frame->traffic_lights)) {
    AWARN << "verify_lights_projection failed to update_lights_projection, "
          << " ts: " << ts;
    return false;
  }

  AINFO << "VerifyLightsProjection success " << frame->traffic_lights.size();

  return true;
}

bool TrafficLightsPerceptionComponent::UpdateCameraSelection(
    double timestamp, const camera::TLPreprocessorOption& option,
    camera::CameraFrame* frame) {
  PERF_FUNCTION();
  const double current_ts = Clock::NowInSeconds();
  if (last_query_tf_ts_ > 0.0 &&
      current_ts - last_query_tf_ts_ < query_tf_interval_seconds_) {
    AINFO << "skip current tf msg, img_ts: " << timestamp
          << " , last_query_tf_ts_: " << last_query_tf_ts_;
    return true;
  }
  AINFO << "start select camera";

  camera::CarPose pose;
  std::vector<apollo_msgs::msg::ApollohdmapSignal> signals;
  if (!QueryPoseAndSignals(timestamp, &pose, &signals)) {
    AINFO << "query_pose_and_signals failed, ts: " << timestamp;
    return false;
  }
  last_query_tf_ts_ = current_ts;

  GenerateTrafficLights(signals, &frame->traffic_lights);
  AINFO << "hd map signals " << frame->traffic_lights.size();

  if (!preprocessor_->UpdateCameraSelection(pose, option,
                                            &frame->traffic_lights)) {
    AERROR << "add_cached_lights_projections failed, ts: " << timestamp;
  } else {
    AINFO << "add_cached_lights_projections succeed, ts: " << timestamp;
  }

  for (auto& light : frame->traffic_lights) {
    AINFO << "x " << light->region.projection_roi.x << " y "
          << light->region.projection_roi.y << " w "
          << light->region.projection_roi.width << " h "
          << light->region.projection_roi.height;
  }
  return true;
}

bool TrafficLightsPerceptionComponent::CheckCameraImageStatus(
    double timestamp, double interval, const std::string& camera_name) {
  PERF_FUNCTION();
  bool camera_ok = true;
  std::string no_image_camera_names = "";
  for (const auto& pr : last_sub_camera_image_ts_) {
    const auto cam_name = pr.first;
    double last_sub_camera_ts = pr.second;
    // should be 0.0, change to 1 in case of float precision
    if (last_sub_camera_ts < 1.0 || timestamp - last_sub_camera_ts > interval) {
      preprocessor_->SetCameraWorkingFlag(cam_name, false);
      AWARN << "camera is probably not working"
            << " , current ts: " << timestamp
            << " , last_sub_camera_ts: " << last_sub_camera_ts
            << " , camera_name: " << cam_name;
      camera_ok = false;
      AINFO << "camera status:" << camera_ok;
      no_image_camera_names += (" " + cam_name);
    }
  }

  bool is_camera_working = false;
  if (!preprocessor_->GetCameraWorkingFlag(camera_name, &is_camera_working)) {
    AERROR << "get_camera_is_working_flag ts: " << timestamp
           << " camera_name: " << camera_name;
    return false;
  }
  if (!is_camera_working) {
    if (!preprocessor_->SetCameraWorkingFlag(camera_name, true)) {
      AERROR << "set_camera_is_working_flag ts: " << timestamp
             << " camera_name: " << camera_name;
      return false;
    }
  }
  return true;
}

bool TrafficLightsPerceptionComponent::GetCarPose(const double timestamp,
                                                  camera::CarPose* pose) {
  PERF_FUNCTION();
  Eigen::Matrix4d pose_matrix;
  // get pose car(gps) to world
  if (!GetPoseFromTF(timestamp, tf2_frame_id_, tf2_child_frame_id_,
                     &pose_matrix)) {
    AERROR << "get pose from tf failed, child_frame_id: "
           << tf2_child_frame_id_;
    return false;
  }
  pose->timestamp_ = timestamp;
  pose->pose_ = pose_matrix;

  int state = 0;
  bool ret = true;
  Eigen::Affine3d affine3d_trans;
  for (const auto& camera_name : camera_names_) {
    const auto trans_wrapper = camera2world_trans_wrapper_map_[camera_name];
    ret = trans_wrapper->GetSensor2worldTrans(timestamp, &affine3d_trans);
    pose_matrix = affine3d_trans.matrix();
    if (!ret) {
      pose->ClearCameraPose(camera_name);
      AERROR << "get pose from tf failed, camera_name: " << camera_name;
    } else {
      pose->c2w_poses_[camera_name] = pose_matrix;
      state += 1;
    }
  }
  return state > 0;
}

bool TrafficLightsPerceptionComponent::GetPoseFromTF(
    const double timestamp, const std::string& frame_id,
    const std::string& child_frame_id, Eigen::Matrix4d* pose_matrix) {
  PERF_FUNCTION();
  rclcpp::Time query_time(timestamp);
  std::string err_string;
  if (!tf2_buffer_->canTransform(frame_id, child_frame_id, query_time,
                                 rclcpp::Duration(tf2_timeout_second_),
                                 &err_string)) {
    AERROR << "Can not find transform. " << timestamp
           << " frame_id: " << frame_id << " child_frame_id: " << child_frame_id
           << " Error info: " << err_string;
    return false;
  }
  geometry_msgs::msg::TransformStamped stamped_transform;
  try {
    stamped_transform =
        tf2_buffer_->lookupTransform(frame_id, child_frame_id, query_time);
    Eigen::Translation3d translation(
        stamped_transform.transform.translation.x,
        stamped_transform.transform.translation.y,
        stamped_transform.transform.translation.z);
    Eigen::Quaterniond rotation(stamped_transform.transform.rotation.w,
                                stamped_transform.transform.rotation.x,
                                stamped_transform.transform.rotation.y,
                                stamped_transform.transform.rotation.z);
    *pose_matrix = (translation * rotation).matrix();
    ADEBUG << "get pose: " << *pose_matrix;
  } catch (tf2::TransformException& ex) {
    AERROR << ex.what();
    return false;
  }
  return true;
}

bool TrafficLightsPerceptionComponent::TransformOutputMessage(
    camera::CameraFrame* frame, const std::string& camera_name,
    std::shared_ptr<apollo_msgs::msg::ApolloperceptionTrafficLightDetection>* out_msg) {
  PERF_FUNCTION();
  const std::map<std::string, TLCamID> CAMERA_ID_TO_TLCAMERA_ID = {
      {"front_24mm", TrafficLightDetection::CAMERA_FRONT_LONG},
      {"front_12mm", TrafficLightDetection::CAMERA_FRONT_NARROW},
      {"front_6mm", TrafficLightDetection::CAMERA_FRONT_SHORT},
      {"front_fisheye", TrafficLightDetection::CAMERA_FRONT_WIDE}};

  auto& lights = frame->traffic_lights;
  apollo::common::Header* header = &(*out_msg)->apolloheader;
  double publish_time = Clock::NowInSeconds();
  header->timestampsec=publish_time;  // message publishing time
  AINFO << "set header time sec:" << frame->timestamp;

  // Set traffic light color to unknown before the process
  detected_trafficlight_color_ = base::TLColor::TL_UNKNOWN_COLOR;

  // sec -> nano-sec
  uint64_t ts_int64 = static_cast<uint64_t>(frame->timestamp * 1e9);
  header->cameratimestamp=ts_int64;

  if (CAMERA_ID_TO_TLCAMERA_ID.find(camera_name) ==
      CAMERA_ID_TO_TLCAMERA_ID.end()) {
    AERROR << "unknown camera_name: " << camera_name;
    return false;
  }
  (*out_msg)->cameraid=CAMERA_ID_TO_TLCAMERA_ID.at(camera_name);

  // Do voting from multiple traffic light detections
  cnt_r_ = 0;
  int max_r_id = -1;
  double max_r_conf = 0;

  cnt_g_ = 0;
  int max_g_id = -1;
  double max_g_conf = 0;

  cnt_y_ = 0;
  int max_y_id = -1;
  double max_y_conf = 0;

  cnt_u_ = 0;

  int max_n_id = -1;

  for (int i = 0; i < static_cast<int>(lights.size()); i++) {
    switch (lights.at(i)->status.color) {
      case base::TLColor::TL_RED:
        // quick fix for 0 confidence color decision
        if (std::abs(lights.at(i)->status.confidence) <
            std::numeric_limits<double>::min()) {
          lights.at(i)->status.color = base::TLColor::TL_UNKNOWN_COLOR;
          max_n_id = i;
          break;
        }
        cnt_r_ += lights.at(i)->status.confidence;
        if (lights.at(i)->status.confidence >= max_r_conf) {
          max_r_id = i;
          max_r_conf = lights.at(i)->status.confidence;
        }
        break;
      case base::TLColor::TL_GREEN:
        // quick fix for 0 confidence color decision
        if (std::abs(lights.at(i)->status.confidence) <
            std::numeric_limits<double>::min()) {
          lights.at(i)->status.color = base::TLColor::TL_UNKNOWN_COLOR;
          max_n_id = i;
          break;
        }
        cnt_g_ += lights.at(i)->status.confidence;
        if (lights.at(i)->status.confidence >= max_g_conf) {
          max_g_id = i;
          max_g_conf = lights.at(i)->status.confidence;
        }
        break;
      case base::TLColor::TL_YELLOW:
        // quick fix for 0 confidence color decision
        if (std::abs(lights.at(i)->status.confidence) <
            std::numeric_limits<double>::min()) {
          lights.at(i)->status.color = base::TLColor::TL_UNKNOWN_COLOR;
          max_n_id = i;
          break;
        }
        cnt_y_ += lights.at(i)->status.confidence;
        if (lights.at(i)->status.confidence >= max_y_conf) {
          max_y_id = i;
          max_y_conf = lights.at(i)->status.confidence;
        }
        break;
      case base::TLColor::TL_UNKNOWN_COLOR:
        cnt_u_ += lights.at(i)->status.confidence;
        max_n_id = i;
        break;
      default:
        max_n_id = i;
        break;
    }
  }

  int max_light_id = -1;
  if (cnt_r_ >= cnt_g_ && cnt_r_ >= cnt_y_ && cnt_r_ > 0) {
    max_light_id = max_r_id;
  } else if (cnt_y_ > cnt_r_ && cnt_y_ >= cnt_g_) {
    max_light_id = max_y_id;
  } else if (cnt_g_ > cnt_r_ && cnt_g_ > cnt_y_) {
    max_light_id = max_g_id;
  } else if (cnt_r_ == 0 && cnt_g_ == 0 && cnt_y_ == 0) {
    max_light_id = max_n_id;
  }

  // swap the final output light to the first place
  if (max_light_id > 0) {
    std::swap(lights[0], lights[max_light_id]);
  }

  if (max_light_id >= 0) {
    for (size_t i = 0; i < lights.size(); i++) {
      apollo_msgs::msg::ApolloperceptionTrafficLight light_result; //= (*out_msg)->add_traffic_light();
      light_result.id=lights.at(i)->id;
      light_result.confidence=lights.at(0)->status.confidence;
      light_result.color=
          static_cast<apollo::perception::TrafficLight::Color>(
              lights.at(0)->status.color);
      light_result.blink=lights.at(0)->status.blink;
      
      (*out_msg)->trafficlight.push_back(light_result);
    }
    // set contain_lights
    (*out_msg)->containlights=lights.size() > 0;
    detected_trafficlight_color_ = lights.at(0)->status.color;
  }
  // add traffic light debug info
  if (!TransformDebugMessage(frame, out_msg)) {
    AERROR << "ProcComponent::Proc failed to transform debug msg.";
    return false;
  }

  return true;
}

void TrafficLightsPerceptionComponent::TransRect2Box(
    const base::RectI& rect, apollo::perception::TrafficLightBox* box) {
  box->x=rect.x;
  box->y=rect.y;
  box->width=rect.width;
  box->height=rect.height;
}

double TrafficLightsPerceptionComponent::stopline_distance(
    const Eigen::Matrix4d& cam_pose) {
  if (stoplines_.empty()) {
    AWARN << "compute car to stopline's distance failed(no stopline). "
          << "cam_pose:" << cam_pose;
    return -1;
  }
  const apollo::hdmap::Curve& stopline = stoplines_.at(0);
  if (stopline.segment.empty()) {
    AWARN << "compute car to stopline's distance"
          << " failed(stopline has no segment line). "
          << "cam_pose:" << cam_pose
          << " stopline:";
    return -1;
  }
  if (stopline.segment[0].curvetype.linesegment==apollo_msgs::msg::ApollohdmapLineSegment()) {
    AWARN << "compute car to stopline's distance "
          << "failed(stopline has no segment). "
          << "cam_pose:" << cam_pose
          << " stopline:";
    return -1;
  }

  if (stopline.segment[0].curvetype.linesegment.point.empty()) {
    AWARN << "compute car to stopline's distance "
          << "failed(stopline has no point). "
          << "cam_pose:" << cam_pose
          << " stopline:";
    return -1;
  }

  Eigen::Vector3d stopline_pt(stopline.segment[0].curvetype.linesegment.point[0].x,
                              stopline.segment[0].curvetype.linesegment.point[0].y,
                              stopline.segment[0].curvetype.linesegment.point[0].z);
  Eigen::Vector3d stopline_pt_cam =
      (cam_pose.inverse() *
       Eigen::Vector4d(stopline_pt(0), stopline_pt(1), stopline_pt(2), 1.0))
          .head(3);

  return stopline_pt_cam(2);
}

bool TrafficLightsPerceptionComponent::TransformDebugMessage(
    const camera::CameraFrame* frame,
    std::shared_ptr<apollo_msgs::msg::ApolloperceptionTrafficLightDetection>* out_msg) {
  PERF_FUNCTION();
  const auto& lights = frame->traffic_lights;
  // add traffic light debug info
  TrafficLightDebug* light_debug = &(*out_msg)->trafficlightdebug;

  // signal number
  light_debug->signalnum=static_cast<int>(lights.size());

  if (!lights.empty() && !lights[0]->region.debug_roi.empty()) {
    const auto& debug_roi = lights[0]->region.debug_roi;
    // Crop ROI
    TransRect2Box(debug_roi[0], &light_debug->cropbox);

    // debug ROI (candidate detection boxes)
    for (auto iter = debug_roi.begin() + 1; iter != debug_roi.end(); ++iter) {
      apollo::perception::TrafficLightBox box;
      apollo::perception::TrafficLightBox debugroi;
      
      TransRect2Box(*iter, &box);
      light_debug->box.push_back(box);
      TransRect2Box(*iter, &debugroi);
      light_debug->box.push_back(box);
    }
  }

  for (const auto& light : lights) {
    // Detection ROI
    apollo::perception::TrafficLightBox box; //= light_debug->add_box();
    apollo::perception::TrafficLightBox boxprime;
    apollo::perception::TrafficLightBox projectedroi;
    apollo::perception::TrafficLightBox croproi;
    
    TransRect2Box(light->region.detection_roi, &box);
    box.color=static_cast<apollo::perception::TrafficLight::Color>(light->status.color);
    box.selected=true;
    light_debug->box.push_back(box);

    // Projection ROI
    TransRect2Box(light->region.projection_roi, &boxprime);
    TransRect2Box(light->region.projection_roi,
                  &projectedroi);
    light_debug->box.push_back(boxprime);
    light_debug->box.push_back(projectedroi);

    // Crop ROI
    TransRect2Box(light->region.debug_roi[0], &croproi);
    light_debug->box.push_back(croproi);

    // Rectified ROI
    apollo::perception::TrafficLightBox rectifiedroi; //= light_debug->add_rectified_roi();
    TransRect2Box(light->region.detection_roi, &rectifiedroi);
    rectifiedroi.color=
        static_cast<apollo::perception::TrafficLight::Color>(light->status.color);
    rectifiedroi.selected=true;
    light_debug->box.push_back(rectifiedroi);
  }

  if (lights.size() > 0) {
    camera::CarPose pose;
    if (GetCarPose(frame->timestamp, &pose)) {
      Eigen::Matrix4d cam_pose;
      cam_pose = pose.c2w_poses_.at("front_6mm");
      light_debug->distancetostopline=stopline_distance(cam_pose);
    } else {
      AERROR << "error occurred in calc distance to stop line";
    }
  }

  if (FLAGS_start_visualizer) {
    Visualize(*frame, lights);
  }

  return true;
}

void TrafficLightsPerceptionComponent::Visualize(
    const camera::CameraFrame& frame,
    const std::vector<base::TrafficLightPtr>& lights) const {
  char str[100];
  std::string tl_string;
  cv::Scalar tl_color;

  if (lights.empty()) {
    return;
  }
  cv::Mat output_image(image_height_, image_width_, CV_8UC3,
                       cv::Scalar(0, 0, 0));
  base::Image8U out_image(image_height_, image_width_, base::Color::RGB);
  camera::DataProvider::ImageOptions image_options;
  image_options.target_color = base::Color::BGR;
  frame.data_provider->GetImage(image_options, &out_image);
  memcpy(output_image.data, out_image.cpu_data(),
         out_image.total() * sizeof(uint8_t));

  for (const auto& light : lights) {
    // Crop ROI
    const auto& crop_roi = light->region.debug_roi[0];
    const cv::Rect rect_crop(crop_roi.x, crop_roi.y, crop_roi.width,
                             crop_roi.height);
    if (light == lights[0])
      cv::rectangle(output_image, rect_crop, cv::Scalar(255, 255, 255), 2);
    else
      cv::rectangle(output_image, rect_crop, cv::Scalar(255, 255, 255));

    // Project lights
    const auto& projection_roi = light->region.projection_roi;
    const cv::Rect projection_rect(projection_roi.x, projection_roi.y,
                                   projection_roi.width, projection_roi.height);
    cv::rectangle(output_image, projection_rect, cv::Scalar(255, 0, 0), 3);

    // Detect lights
    const auto& rectified_roi = light->region.detection_roi;
    const cv::Rect rectified_rect(rectified_roi.x, rectified_roi.y,
                                  rectified_roi.width, rectified_roi.height);
    cv::Scalar tl_color;
    std::map<base::TLColor, TLInfo>::iterator itor =
        s_tl_infos.find(light->status.color);
    if (itor != s_tl_infos.end()) {
      tl_color = itor->second.tl_color_;
      tl_string = itor->second.tl_string_;
    } else {
      tl_color = cv::Scalar(255, 255, 255);
      tl_string = "UNKNOWN";
    }
    snprintf(str, sizeof(str), "ID:%s C:%.3lf", light->id.c_str(),
             light->status.confidence);
    cv::rectangle(output_image, rectified_rect, tl_color, 2);
    cv::putText(output_image, str,
                cv::Point(rectified_roi.x + 30,
                          rectified_roi.y + rectified_roi.height + 30),
                cv::FONT_HERSHEY_DUPLEX, 1.0, tl_color, 2);
  }

  // Show text of voting results
  std::map<base::TLColor, TLInfo>::iterator itor =
      s_tl_infos.find(detected_trafficlight_color_);
  if (itor != s_tl_infos.end()) {
    tl_color = itor->second.tl_color_;
    tl_string = itor->second.tl_string_ex_;
  } else {
    tl_color = cv::Scalar(255, 255, 255);
    tl_string = "UNKNOWN traffic light";
  }
  double all = cnt_r_ + cnt_g_ + cnt_y_ + cnt_u_;
  if (all < 0.0001) {
    all = 1.0;
  }
  cv::putText(output_image, tl_string, cv::Point(10, 90),
              cv::FONT_HERSHEY_DUPLEX, 2.0, tl_color, 3);

  snprintf(str, sizeof(str), "Red lights:%.2f", cnt_r_ / all);
  cv::putText(output_image, str, cv::Point(10, 150), cv::FONT_HERSHEY_DUPLEX,
              1.5, cv::Scalar(0, 0, 255), 3);
  snprintf(str, sizeof(str), "Green lights:%.2f", cnt_g_ / all);
  cv::putText(output_image, str, cv::Point(10, 200), cv::FONT_HERSHEY_DUPLEX,
              1.5, cv::Scalar(0, 255, 0), 3);
  snprintf(str, sizeof(str), "Yellow lights:%.2f", cnt_y_ / all);
  cv::putText(output_image, str, cv::Point(10, 250), cv::FONT_HERSHEY_DUPLEX,
              1.5, cv::Scalar(0, 255, 255), 3);
  snprintf(str, sizeof(str), "Unknown lights:%.2f", cnt_u_ / all);
  cv::putText(output_image, str, cv::Point(10, 300), cv::FONT_HERSHEY_DUPLEX,
              1.5, cv::Scalar(255, 255, 255), 3);

  cv::resize(output_image, output_image, cv::Size(), 0.5, 0.5);
  cv::imshow("Traffic Light", output_image);
  cv::imwrite(absl::StrCat("/apollo/debug_vis/", frame.timestamp, ".jpg"),
              output_image);
  cv::waitKey(30);
}

void TrafficLightsPerceptionComponent::SyncV2XTrafficLights(
    camera::CameraFrame* frame) {
  const double camera_frame_timestamp = frame->timestamp;
  auto sync_single_light = [&](base::TrafficLightPtr light) {
    for (auto itr = v2x_msg_buffer_.rbegin(); itr != v2x_msg_buffer_.rend();
         ++itr) {
      double v2x_timestamp = itr->apolloheader.timestampsec;
      // find close enough v2x msg
      if (std::fabs(camera_frame_timestamp - v2x_timestamp) <
          v2x_sync_interval_seconds_) {
        const int v2x_lights_num =
            itr->roadtrafficlight[0].singletrafficlight.size();
        const auto& v2x_lights = itr->roadtrafficlight[0];
        for (int i = 0; i < v2x_lights_num; ++i) {
          const auto& v2x_light = v2x_lights.singletrafficlight[i];
          // check signal id
          if (light->id != v2x_light.id) {
            continue;
          }
          base::TLColor v2x_color = base::TLColor::TL_UNKNOWN_COLOR;
          bool blink = false;
          switch (v2x_light.color) {
            default:
            case apollo::v2x::SingleTrafficLight::UNKNOWN:
              v2x_color = base::TLColor::TL_UNKNOWN_COLOR;
              break;
            case apollo::v2x::SingleTrafficLight::RED:
              v2x_color = base::TLColor::TL_RED;
              break;
            case apollo::v2x::SingleTrafficLight::YELLOW:
              v2x_color = base::TLColor::TL_YELLOW;
              break;
            case apollo::v2x::SingleTrafficLight::GREEN:
              v2x_color = base::TLColor::TL_GREEN;
              break;
            case apollo::v2x::SingleTrafficLight::BLACK:
              v2x_color = base::TLColor::TL_BLACK;
              break;
            case apollo::v2x::SingleTrafficLight::FLASH_GREEN:
              v2x_color = base::TLColor::TL_GREEN;
              blink = true;
              break;
          }
          // use v2x result directly
          AINFO << "Sync V2X success. update color from "
                << static_cast<int>(light->status.color) << " to "
                << static_cast<int>(v2x_color) << "; signal id: " << light->id;
          light->status.color = v2x_color;
          light->status.blink = blink;
        }
        break;
      }
    }
  };
  for (auto& light : frame->traffic_lights) {
    sync_single_light(light);
  }
}

void TrafficLightsPerceptionComponent::SendSimulationMsg() {
  apollo_msgs::msg::ApolloperceptionTrafficLightDetection out_msg;
  writer_->Write(out_msg);
}

}  // namespace onboard
}  // namespace perception
}  // namespace apollo

CYBER_REGISTER_COMPONENT(TrafficLightsPerceptionComponent);
