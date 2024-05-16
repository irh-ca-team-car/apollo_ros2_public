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
#include "component/segmentation.h"
#include "modules/perception/factories.h"

#include "cyber/cyber.h"
#include "modules/common/util/perf_util.h"
#include "modules/perception/common/sensor_manager/sensor_manager.h"
#include "modules/perception/lidar/common/lidar_error_code.h"
#include "modules/perception/lidar/common/lidar_frame_pool.h"
#include "modules/perception/lidar/common/lidar_log.h"
#include "modules/perception/onboard/common_flags/common_flags.h"
#include "modules/perception/onboard/internal_messages/lidar_inner_component_messages.h"

#include "modules/common/configs/config_gflags.h"

#include <iomanip>

namespace apollo {
namespace perception {
namespace onboard {

uint32_t SegmentationComponent::s_seq_num_ = 0;
//std::mutex SegmentationComponent::s_mutex_;

bool SegmentationComponent::Init() {
  

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
InitFactories();
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
  LidarSegmentationComponentConfig comp_config;
  comp_config.sensorname=declare_parameter<std::string>("sensor_name","velodyne128");
  comp_config.enablehdmap=declare_parameter<bool>("enable_hdmap",true);
  comp_config.lidarquerytfoffset=declare_parameter<float>("lidar_query_tf_offset",0);
  comp_config.lidar2novateltf2childframeid=declare_parameter<std::string>("lidar2novatel_tf2_child_frame_id","velodyne128");
  comp_config.outputchannelname=declare_parameter<std::string>("output_channel_name","/apollo/perception/inner/SegmentationObjects");
  
  RCLCPP_INFO(get_logger(),"BEGIN CONFIG:Segmentation");
  
  ADEBUG << "Lidar Component Configs: ";
  
  output_channel_name_ = comp_config.outputchannelname;
  sensor_name_ = comp_config.sensorname;
  lidar2novatel_tf2_child_frame_id_ =
      comp_config.lidar2novateltf2childframeid;
  lidar_query_tf_offset_ =
      static_cast<float>(comp_config.lidarquerytfoffset);
  enable_hdmap_ = comp_config.enablehdmap;
  writer_ = node_->CreateWriterJson<LidarFrameMessage>(output_channel_name_);
  pointcloud_reader_ = node_->CreateReader<apollo_msgs::msg::ApollodriversPointCloud>("/apollo/sensor/lidar128/compensator/PointCloud2", std::bind(&SegmentationComponent::Proc, this, std::placeholders::_1));

  if (!InitAlgorithmPlugin()) {
    AERROR << "Failed to init segmentation component algorithm plugin.";
    return false;
  }

  lidar_enabled = declare_parameter<bool>("lidar_enabled", false);
  if(!lidar_enabled)
    AERROR << "module in disabled state, will not process message";
  return true;
}

bool SegmentationComponent::Proc(const std::shared_ptr<apollo_msgs::msg::ApollodriversPointCloud>& message) {
  if(!lidar_enabled)
    return false;
  // AINFO << std::setprecision(16)
  AINFO << "Enter segmentation component, message timestamp: "
        << message->measurementtime << " current timestamp: "
        << apollo::cyber::Clock::NowInSeconds();

  std::shared_ptr<LidarFrameMessage> out_message(new (std::nothrow)
                                                     LidarFrameMessage);

  bool status = InternalProc(message, out_message);
  if (status) {
    writer_->Write(apollo_msgs::msg::to_json(*out_message));
    AINFO << "Send lidar segment output message.";
  }
  return status;
}

bool SegmentationComponent::InitAlgorithmPlugin() {
  ACHECK(common::SensorManager::Instance()->GetSensorInfo(sensor_name_,
                                                          &sensor_info_));

  segmentor_.reset(new lidar::LidarObstacleSegmentation);
  if (segmentor_ == nullptr) {
    AERROR << "sensor_name_ "
           << "Failed to get segmentation instance";
    return false;
  }
  lidar::LidarObstacleSegmentationInitOptions init_options;
  init_options.sensor_name = sensor_name_;
  init_options.enable_hdmap_input =
      FLAGS_obs_enable_hdmap_input && enable_hdmap_;
  if (!segmentor_->Init(init_options)) {
    AINFO << "sensor_name_ "
          << "Failed to init segmentation.";
    return false;
  }

  lidar2world_trans_.Init(lidar2novatel_tf2_child_frame_id_);
  return true;
}

bool SegmentationComponent::InternalProc(
    const std::shared_ptr<const drivers::PointCloud>& in_message,
    const std::shared_ptr<LidarFrameMessage>& out_message) {
  PERF_FUNCTION_WITH_INDICATOR(sensor_name_);
  {
    //std::unique_lock<std::mutex> lock(s_mutex_);
    s_seq_num_++;
  }
  const double timestamp = in_message->measurementtime;
  const double cur_time = apollo::cyber::Clock::NowInSeconds();
  const double start_latency = (cur_time - timestamp) * 1e3;
  AINFO_EVERY(60000) << std::setprecision(16) << "FRAME_STATISTICS:Lidar:Start:msg_time["
        << timestamp << "]:sensor[" << sensor_name_ << "]:cur_time[" << cur_time
        << "]:cur_latency[" << start_latency << "]";
  
  //apollo::common::Header in_message_header;

  out_message->timestamp_ = timestamp;

  out_message->lidar_timestamp_ = in_message->apolloheader.lidartimestamp;
  //out_message->lidar_timestamp_ = in_message->apolloheader.lidartimestamp;
  
  out_message->seq_num_ = s_seq_num_;
  out_message->process_stage_ = ProcessStage::LIDAR_SEGMENTATION;
  out_message->error_code_ = apollo::common::ErrorCode::OK;

  auto& frame = out_message->lidar_frame_;
  frame = lidar::LidarFramePool::Instance().Get();
  frame->cloud = base::PointFCloudPool::Instance().Get();
  frame->timestamp = timestamp;
  frame->sensor_info = sensor_info_;

  PERF_BLOCK_START();
  Eigen::Affine3d pose = Eigen::Affine3d::Identity();
  Eigen::Affine3d pose_novatel = Eigen::Affine3d::Identity();
  const double lidar_query_tf_timestamp =
      timestamp - lidar_query_tf_offset_ * 0.001;
  if (!lidar2world_trans_.GetSensor2worldTrans(lidar_query_tf_timestamp, &pose,
                                               &pose_novatel)) {
    out_message->error_code_ = apollo::common::ErrorCode::PERCEPTION_ERROR_TF;
    AWARN << "Failed to get pose at time: " << lidar_query_tf_timestamp;
    return false;
  }
  PERF_BLOCK_END_WITH_INDICATOR(sensor_name_,
                                "segmentation_1::get_lidar_to_world_pose");

  frame->lidar2world_pose = pose;
  frame->novatel2world_pose = pose_novatel;

  lidar::LidarObstacleSegmentationOptions segment_opts;
  segment_opts.sensor_name = sensor_name_;
  lidar2world_trans_.GetExtrinsics(&segment_opts.sensor2novatel_extrinsics);
  lidar::LidarProcessResult ret =
      segmentor_->Process(segment_opts, in_message, frame.get());
  if (ret.error_code != lidar::LidarErrorCode::Succeed) {
    out_message->error_code_ =
        apollo::common::ErrorCode::PERCEPTION_ERROR_PROCESS;
    AERROR << "Lidar segmentation process error, " << ret.log;
    return false;
  }
  PERF_BLOCK_END_WITH_INDICATOR(sensor_name_,
                                "segmentation_2::segment_obstacle");

  return true;
}


}  // namespace onboard
}  // namespace perception
}  // namespace apollo

CYBER_REGISTER_COMPONENT(SegmentationComponent);