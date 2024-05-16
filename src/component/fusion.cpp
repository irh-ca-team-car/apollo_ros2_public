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
#include "component/fusion.h"

#include "cyber/cyber.h"
#include "modules/common/util/perf_util.h"
#include "modules/perception/base/object_pool_types.h"
#include "modules/perception/onboard/common_flags/common_flags.h"
#include "modules/perception//common/perception_gflags.h"
#include "modules/perception/onboard/msg_serializer/msg_serializer.h"
#include "modules/perception/onboard/internal_messages/inner_component_messages.h"
#include "modules/perception/factories.h"
#include "modules/common/util/perf_util.h"
#include "modules/perception/base/object_pool_types.h"
#include "modules/perception/onboard/common_flags/common_flags.h"
#include "modules/perception/onboard/msg_serializer/msg_serializer.h"

namespace apollo
{
  namespace perception
  {
    namespace onboard
    {

      uint32_t FusionComponent::s_seq_num_ = 0;
      std::mutex FusionComponent::s_mutex_;
      std::vector<std::string> split(const std::string &s, char delimiter)
      {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter))
        {
          tokens.push_back(token);
        }
        return tokens;
      }

      bool FusionComponent::Init()
      {
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

        AINFO << "Gflags set";
        
        FusionComponentConfig comp_config;
        /*if (!GetProtoConfig(&comp_config)) {
         return false;
       }*/
        comp_config.fusionmethod = declare_parameter<std::string>("fusion_method", "ProbabilisticFusion");
        comp_config.fusionmainsensors = split(declare_parameter<std::string>("fusion_main_sensors", "velodyne128"), ',');
        comp_config.objectinroicheck = declare_parameter<bool>("object_in_roi_check", true);
        comp_config.radiusforroiobjectcheck = declare_parameter<double>("radius_for_roi_object_check", 120);
        comp_config.outputobstacleschannelname = declare_parameter<std::string>("output_obstacles_channel_name", "/apollo/perception/obstacles");
        comp_config.outputvizfusedcontentchannelname = declare_parameter<std::string>("output_viz_fused_content_channel_name", "/apollo/perception/inner/visualization/FusedObjects");
        AINFO << "Fusion Component Configs: ";
        AINFO << "Fusion Component Configs: " << comp_config;

        // to load component configs
        fusion_method_ = comp_config.fusionmethod;
        for (int i = 0; i < comp_config.fusionmainsensors.size(); ++i)
        {
          fusion_main_sensors_.push_back(comp_config.fusionmainsensors.at(i));
        }
        object_in_roi_check_ = comp_config.objectinroicheck;
        radius_for_roi_object_check_ = comp_config.radiusforroiobjectcheck;

        // init algorithm plugin
        ACHECK(InitAlgorithmPlugin()) << "Failed to init algorithm plugin.";
        writer_ = node_->CreateWriter<PerceptionObstacles>(
            comp_config.outputobstacleschannelname);
        inner_writer_ = node_->CreateWriterJson<SensorFrameMessage>(
            comp_config.outputvizfusedcontentchannelname);
        sensframe_reader_ = node_->CreateReaderJson<SensorFrameMessage>("/apollo/perception/inner/PrefusedObjects", std::bind(&FusionComponent::Proc, this, std::placeholders::_1));
        return true;
      }

      bool FusionComponent::Proc(const std::shared_ptr<SensorFrameMessage> &message)
      {
        if (message->process_stage_ == ProcessStage::SENSOR_FUSION)
        {
          return true;
        }
        std::shared_ptr<PerceptionObstacles> out_message(new (std::nothrow)
                                                             PerceptionObstacles);
        std::shared_ptr<SensorFrameMessage> viz_message(new (std::nothrow)
                                                            SensorFrameMessage);

        // TODO(convert sensor id)
        const auto &itr = std::find(fusion_main_sensors_.begin(),
                                    fusion_main_sensors_.end(), message->sensor_id_);
        if (itr == fusion_main_sensors_.end())
        {
          AINFO << "Fusion receives message from " << message->sensor_id_
                << " which is not in main sensors. Skip sending.";
          return true;
        }

        bool status = InternalProc(message, out_message, viz_message);
        if (status)
        {
          writer_->Write(out_message);
          AINFO << "Send fusion processing output message.";
          // send msg for visualization
          if (FLAGS_obs_enable_visualization)
          {
            // Send("/apollo/perception/inner/PrefusedObjects", viz_message);
            inner_writer_->Write(apollo_msgs::msg::to_json(*viz_message));
          }
        }

        return status;
      }

      bool FusionComponent::InitAlgorithmPlugin()
      {
        fusion_.reset(new fusion::ObstacleMultiSensorFusion());
        fusion::ObstacleMultiSensorFusionParam param;
        param.main_sensors = fusion_main_sensors_;
        param.fusion_method = fusion_method_;
        ACHECK(fusion_->Init(param)) << "Failed to init ObstacleMultiSensorFusion";

        if (FLAGS_obs_enable_hdmap_input && object_in_roi_check_)
        {
          hdmap_input_ = map::HDMapInput::Instance();
          ACHECK(hdmap_input_->Init()) << "Failed to init hdmap input.";
        }
        AINFO << "Init algorithm successfully, onboard fusion: " << fusion_method_;
        return true;
      }

      bool FusionComponent::InternalProc(
          const std::shared_ptr<SensorFrameMessage const> &in_message,
          std::shared_ptr<PerceptionObstacles> out_message,
          std::shared_ptr<SensorFrameMessage> viz_message)
      {
        {
          std::unique_lock<std::mutex> lock(s_mutex_);
          s_seq_num_++;
        }

        PERF_BLOCK_START();
        const double timestamp = in_message->timestamp_;
        const uint64_t lidar_timestamp = in_message->lidar_timestamp_;
        std::vector<base::ObjectPtr> valid_objects;
        if (in_message->error_code_ != apollo::common::ErrorCode::OK)
        {
          if (!MsgSerializer::SerializeMsg(
                  timestamp, lidar_timestamp, in_message->seq_num_, valid_objects,
                  in_message->error_code_, out_message.get()))
          {
            AERROR << "Failed to gen PerceptionObstacles object.";
            return false;
          }

          if (FLAGS_obs_enable_visualization)
          {
            viz_message->process_stage_ = ProcessStage::SENSOR_FUSION;
            viz_message->error_code_ = in_message->error_code_;
          }
          AERROR << "Fusion receive message with error code, skip it.";
          return true;
        }
        base::FramePtr frame = in_message->frame_;
        frame->timestamp = in_message->timestamp_;

        std::vector<base::ObjectPtr> fused_objects;
        if (!fusion_->Process(frame, &fused_objects))
        {
          AERROR << "Failed to call fusion plugin.";
          return false;
        }
        PERF_BLOCK_END_WITH_INDICATOR("fusion_process", in_message->sensor_id_);

        Eigen::Matrix4d sensor2world_pose =
            in_message->frame_->sensor2world_pose.matrix();
        if (object_in_roi_check_ && FLAGS_obs_enable_hdmap_input)
        {
          // get hdmap
          base::HdmapStructPtr hdmap(new base::HdmapStruct());
          if (hdmap_input_)
          {
            base::PointD position;
            position.x = sensor2world_pose(0, 3);
            position.y = sensor2world_pose(1, 3);
            position.z = sensor2world_pose(2, 3);
            hdmap_input_->GetRoiHDMapStruct(position, radius_for_roi_object_check_,
                                            hdmap);
            // TODO(use check)
            // ObjectInRoiSlackCheck(hdmap, fused_objects, &valid_objects);
            valid_objects.assign(fused_objects.begin(), fused_objects.end());
          }
          else
          {
            valid_objects.assign(fused_objects.begin(), fused_objects.end());
          }
        }
        else
        {
          valid_objects.assign(fused_objects.begin(), fused_objects.end());
        }
        PERF_BLOCK_END_WITH_INDICATOR("fusion_roi_check", in_message->sensor_id_);

        // produce visualization msg
        if (FLAGS_obs_enable_visualization)
        {
          viz_message->timestamp_ = in_message->timestamp_;
          viz_message->seq_num_ = in_message->seq_num_;
          viz_message->frame_ = base::FramePool::Instance().Get();
          viz_message->frame_->sensor2world_pose =
              in_message->frame_->sensor2world_pose;
          viz_message->sensor_id_ = in_message->sensor_id_;
          viz_message->hdmap_ = in_message->hdmap_;
          viz_message->process_stage_ = ProcessStage::SENSOR_FUSION;
          viz_message->error_code_ = in_message->error_code_;
          viz_message->frame_->objects = fused_objects;
        }
        // produce pb output msg
        apollo::common::ErrorCode error_code = apollo::common::ErrorCode::OK;
        if (!MsgSerializer::SerializeMsg(timestamp, lidar_timestamp,
                                         in_message->seq_num_, valid_objects,
                                         error_code, out_message.get()))
        {
          AERROR << "Failed to gen PerceptionObstacles object.";
          return false;
        }

        PERF_BLOCK_END_WITH_INDICATOR("fusion_serialize_message",
                                      in_message->sensor_id_);

        const double cur_time = ::apollo::cyber::Clock::NowInSeconds();
        const double latency = (cur_time - timestamp) * 1e3;
        AINFO_EVERY(60000) << std::setprecision(16) << "FRAME_STATISTICS:Obstacle:End:msg_time["
                           << timestamp << "]:cur_time[" << cur_time << "]:cur_latency[" << latency
                           << "]:obj_cnt[" << valid_objects.size() << "]";
        AINFO << "publish_number: " << valid_objects.size() << " obj";
        return true;
      }
    } // namespace onboard
  }   // namespace perception
} // namespace apollo
CYBER_REGISTER_COMPONENT(FusionComponent);
