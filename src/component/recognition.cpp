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
#include "component/recognition.h"

#include "cyber/cyber.h"
#include "modules/common/util/perf_util.h"
#include "modules/perception/base/object_pool_types.h"
#include "modules/perception/common/sensor_manager/sensor_manager.h"
#include "modules/perception/lidar/common/lidar_error_code.h"
#include "modules/perception/lidar/common/lidar_log.h"
#include "modules/perception/common/perception_gflags.h"
#include "modules/perception/onboard/internal_messages/inner_component_messages.h"
#include "modules/perception/onboard/internal_messages/lidar_inner_component_messages.h"
#include "modules/perception/factories.h"
#include "modules/prediction/common/prediction_gflags.h"

using Clock = apollo::cyber::Clock;

namespace apollo
{
  namespace perception
  {
    namespace onboard
    {

      bool RecognitionComponent::Init()
      {
        InitFactories();

        AINFO << "Setting gflags";

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
        apollo::PredictionGFlags(this);
        AINFO << "Gflags set";

        LidarRecognitionComponentConfig comp_config;
        /*if (!GetProtoConfig(&comp_config)) {
          return false;
        }*/

        lidar_enabled = declare_parameter<bool>("lidar_enabled", false);

        comp_config.mainsensorname = declare_parameter<std::string>("main_sensor_name", "velodyne128");
        comp_config.outputchannelname = declare_parameter<std::string>("output_channel_name", "/apollo/perception/inner/PrefusedObjects");

        AINFO << "Lidar Component Configs: ";
        output_channel_name_ = comp_config.outputchannelname;
        main_sensor_name_ = comp_config.mainsensorname;
        writer_ = node_->CreateWriterJson<SensorFrameMessage>(output_channel_name_);

        std::string recoginchannel;
        recoginchannel = declare_parameter<std::string>("recog_in_channel", "/apollo/perception/inner/SegmentationObjects");
        reader_ = node_->CreateReaderJson<LidarFrameMessage>(recoginchannel, std::bind(&RecognitionComponent::Proc, this, std::placeholders::_1));

        if (!InitAlgorithmPlugin())
        {
          AERROR << "Failed to init recongnition component algorithm plugin.";
          return false;
        }
        return true;
      }

      bool RecognitionComponent::Proc(
          const std::shared_ptr<LidarFrameMessage> &message)
      {
        if (!lidar_enabled)
          return false;
        // AINFO << std::setprecision(16)
        AINFO << "Enter Tracking component, message timestamp: "
              << message->timestamp_
              << " current timestamp: " << Clock::NowInSeconds();

        auto out_message = std::make_shared<SensorFrameMessage>();

        if (InternalProc(message, out_message))
        {
          auto j = apollo_msgs::msg::to_json(*out_message);
          // j.dump();
          writer_->Write(j);
          AINFO << "Send lidar recognition output message.";
          return true;
        }
        return false;
      }

      bool RecognitionComponent::InitAlgorithmPlugin()
      {
        tracker_.reset(new lidar::LidarObstacleTracking);
        if (tracker_ == nullptr)
        {
          AERROR << "Failed to get tracking instance.";
          return false;
        }
        lidar::LidarObstacleTrackingInitOptions init_options;
        init_options.sensor_name = main_sensor_name_;
        if (!tracker_->Init(init_options))
        {
          AERROR << "Failed to init tracking.";
          return false;
        }
        return true;
      }

      bool RecognitionComponent::InternalProc(
          const std::shared_ptr<const LidarFrameMessage> &in_message,
          const std::shared_ptr<SensorFrameMessage> &out_message)
      {
        auto &sensor_name = in_message->lidar_frame_->sensor_info.name;
        PERF_FUNCTION_WITH_INDICATOR(sensor_name);
        out_message->timestamp_ = in_message->timestamp_;
        out_message->lidar_timestamp_ = in_message->lidar_timestamp_;
        out_message->seq_num_ = in_message->seq_num_;
        out_message->process_stage_ = ProcessStage::LIDAR_RECOGNITION;
        out_message->sensor_id_ = sensor_name;

        if (in_message->error_code_ != apollo::common::ErrorCode::OK)
        {
          out_message->error_code_ = in_message->error_code_;
          AERROR << "Lidar recognition receive message with error code, skip it.";
          return true;
        }

        PERF_BLOCK_START();
        auto &lidar_frame = in_message->lidar_frame_;
        lidar::LidarObstacleTrackingOptions track_options;
        track_options.sensor_name = sensor_name;
        lidar::LidarProcessResult ret =
            tracker_->Process(track_options, lidar_frame.get());
        PERF_BLOCK_END_WITH_INDICATOR(sensor_name, "recognition_1::track_obstacle");
        if (ret.error_code != lidar::LidarErrorCode::Succeed)
        {
          out_message->error_code_ =
              apollo::common::ErrorCode::PERCEPTION_ERROR_PROCESS;
          AERROR << "Lidar recognition process error, " << ret.log;
          return true;
        }
        // TODO(shigintmin)
        out_message->hdmap_ = lidar_frame->hdmap_struct;
        auto &frame = out_message->frame_;
        frame = base::FramePool::Instance().Get();
        frame->sensor_info = lidar_frame->sensor_info;
        frame->timestamp = in_message->timestamp_;
        frame->objects = lidar_frame->tracked_objects;
        frame->sensor2world_pose = lidar_frame->lidar2world_pose;
        frame->lidar_frame_supplement.on_use = true;
        frame->lidar_frame_supplement.cloud_ptr = lidar_frame->cloud;
        PERF_BLOCK_END_WITH_INDICATOR(sensor_name, "recognition_2::fill_out_message");

        const double end_timestamp = Clock::NowInSeconds();
        const double end_latency = (end_timestamp - in_message->timestamp_) * 1e3;
        // AINFO << std::setprecision(16)
        AINFO_EVERY(60000) << "FRAME_STATISTICS:Lidar:End:msg_time["
                           << in_message->timestamp_ << "]:cur_time[" << end_timestamp
                           << "]:cur_latency[" << end_latency << "]";
        return true;
      }

    } // namespace onboard
  }   // namespace perception
} // namespace apollo

CYBER_REGISTER_COMPONENT(RecognitionComponent);
