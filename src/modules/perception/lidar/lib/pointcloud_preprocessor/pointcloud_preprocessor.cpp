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
#include "modules/perception/lidar/lib/pointcloud_preprocessor/pointcloud_preprocessor.h"

#include <limits>

#include "cyber/cyber.h"
#include "cyber/common/log_advanced.h"
#include "modules/common/configs/vehicle_config_helper.h"
#include "modules/perception/base/object_pool_types.h"
#include "modules/perception/lib/config_manager/config_manager.h"
#include "modules/perception/lidar/common/lidar_log.h"
#include "modules/perception/lidar/lib/pointcloud_preprocessor/proto/pointcloud_preprocessor_config.pb.h"

namespace apollo
{
  namespace perception
  {
    namespace lidar
    {

      using apollo::cyber::common::GetAbsolutePath;

      const float PointCloudPreprocessor::kPointInfThreshold = 1e3;

      bool PointCloudPreprocessor::Init(
          const PointCloudPreprocessorInitOptions &options)
      {
        auto config_manager = lib::ConfigManager::Instance();
        const lib::ModelConfig *model_config = nullptr;
        ACHECK(config_manager->GetModelConfig(Name(), &model_config));
        UNUSED(options);
        // const std::string work_root = config_manager->work_root();
        // std::string config_file;
        // std::string root_path;
        // ACHECK(model_config->get_value("root_path", &root_path));
        // config_file = GetAbsolutePath(work_root, root_path);
        // config_file = GetAbsolutePath(config_file, options.sensor_name);
        // config_file = GetAbsolutePath(config_file, "pointcloud_preprocessor.json");
        PointCloudPreprocessorConfig config;
        // ACHECK(apollo::cyber::common::GetProtoFromFile(config_file, &config));
        auto currentNode = apollo::cyber::currentNode;
        config.filternaninfpoints = currentNode->declare_parameter<bool>("filter_naninf_points", false);
        config.filternearbyboxpoints = currentNode->declare_parameter<bool>("filter_nearby_box_points", true);
        config.boxforwardx = currentNode->declare_parameter<float>("box_forward_x", 2.0);
        config.boxbackwardx = currentNode->declare_parameter<float>("box_backward_x", -2.0);
        config.boxforwardy = currentNode->declare_parameter<float>("box_forward_y", 3.0);
        config.boxbackwardy = currentNode->declare_parameter<float>("box_backward_y", -5.0);
        config.filterhighzpoints = currentNode->declare_parameter<bool>("filter_high_z_points", false);
        config.zthreshold = currentNode->declare_parameter<float>("z_threshold", 500.0);

        filter_naninf_points_ = config.filternaninfpoints;
        filter_nearby_box_points_ = config.filternearbyboxpoints;
        box_forward_x_ = config.boxforwardx;
        box_backward_x_ = config.boxbackwardx;
        box_forward_y_ = config.boxforwardy;
        box_backward_y_ = config.boxbackwardy;
        /*const auto &vehicle_param =
          common::VehicleConfigHelper::GetConfig().vehicle_param();
        box_forward_x_ = static_cast<float>(vehicle_param.right_edge_to_center());
        box_backward_x_ = static_cast<float>(-vehicle_param.left_edge_to_center());
        box_forward_y_ = static_cast<float>(vehicle_param.front_edge_to_center());
        box_backward_y_ = static_cast<float>(-vehicle_param.back_edge_to_center());*/
        filter_high_z_points_ = config.filterhighzpoints;
        z_threshold_ = config.zthreshold;
        return true;
      }

      bool PointCloudPreprocessor::Preprocess(
          const PointCloudPreprocessorOptions &options,
          const std::shared_ptr<apollo::drivers::PointCloud const> &message,
          LidarFrame *frame) const
      {
        if (frame == nullptr)
        {
          return false;
        }
        if (frame->cloud == nullptr)
        {
          frame->cloud = base::PointFCloudPool::Instance().Get();
        }
        if (frame->world_cloud == nullptr)
        {
          frame->world_cloud = base::PointDCloudPool::Instance().Get();
        }
        frame->cloud->set_timestamp(message->measurementtime);
        std::once_flag flag;
        if (message->point.size() > 0)
        {
          frame->cloud->reserve(message->point.size());
          base::PointF point;
          for (size_t i = 0; i < message->point.size(); ++i)
          {
            const apollo::drivers::PointXYZIT &pt = message->point[i];
            if (filter_naninf_points_)
            {
              if (std::isnan(pt.x) || std::isnan(pt.y) || std::isnan(pt.z))
              {
                std::call_once(flag, []()
                               { AERROR_EVERY(60000) << "isnan\n"; });
                continue;
              }
              if (fabs(pt.x) > kPointInfThreshold ||
                  fabs(pt.y) > kPointInfThreshold ||
                  fabs(pt.z) > kPointInfThreshold)
              {
                std::call_once(flag, []()
                               { AERROR_EVERY(60000) << "isFalseInf\n"; });
                continue;
              }
            }
            Eigen::Vector3d vec3d_lidar(pt.x, pt.y, pt.z);
            Eigen::Vector3d vec3d_novatel =
                options.sensor2novatel_extrinsics * vec3d_lidar;
            if (filter_nearby_box_points_ && ( vec3d_novatel[0] > box_forward_x_ ||
                vec3d_novatel[0] < box_backward_x_ ||
                vec3d_novatel[1] > box_forward_y_ ||
                vec3d_novatel[1] < box_backward_y_))
            {
              std::call_once(flag, [vec3d_novatel]()
                             {
                              AERROR_EVERY(60000) <<  vec3d_novatel[0] << "," << vec3d_novatel[1];
                              AERROR_EVERY(60000) << "isOutOfBox\n"; });
              continue;
            }
            if (filter_high_z_points_ && pt.z > z_threshold_)
            {
              std::call_once(flag, []()
                             { AERROR_EVERY(60000) << "isHighZ\n"; });
              continue;
            }
            point.x = pt.x;
            point.y = pt.y;
            point.z = pt.z;
            point.intensity = static_cast<float>(pt.intensity);
            frame->cloud->push_back(point, static_cast<double>(pt.timestamp) * 1e-9,
                                    std::numeric_limits<float>::max(), i, 0);
          }
          TransformCloud(frame->cloud, frame->lidar2world_pose, frame->world_cloud);
        }
        return true;
      }

      bool PointCloudPreprocessor::Preprocess(
          const PointCloudPreprocessorOptions &options, LidarFrame *frame) const
      {
        if (frame == nullptr || frame->cloud == nullptr)
        {
          return false;
        }
        if (frame->world_cloud == nullptr)
        {
          frame->world_cloud = base::PointDCloudPool::Instance().Get();
        }
        if (frame->cloud->size() > 0)
        {
          size_t size = frame->cloud->size();
          size_t i = 0;
          while (i < size)
          {
            auto &pt = frame->cloud->at(i);
            if (filter_naninf_points_)
            {
              if (std::isnan(pt.x) || std::isnan(pt.y) || std::isnan(pt.z))
              {
                frame->cloud->SwapPoint(i, size--);
                continue;
              }
              if (fabs(pt.x) > kPointInfThreshold ||
                  fabs(pt.y) > kPointInfThreshold ||
                  fabs(pt.z) > kPointInfThreshold)
              {
                frame->cloud->SwapPoint(i, size--);
                continue;
              }
            }
            Eigen::Vector3d vec3d_lidar(pt.x, pt.y, pt.z);
            Eigen::Vector3d vec3d_novatel =
                options.sensor2novatel_extrinsics * vec3d_lidar;
            if (filter_nearby_box_points_ && vec3d_novatel[0] < box_forward_x_ &&
                vec3d_novatel[0] > box_backward_x_ &&
                vec3d_novatel[1] < box_forward_y_ &&
                vec3d_novatel[1] > box_backward_y_)
            {
              frame->cloud->SwapPoint(i, size--);
              continue;
            }
            if (filter_high_z_points_ && pt.z > z_threshold_)
            {
              frame->cloud->SwapPoint(i, size--);
              continue;
            }
            ++i;
          }
          frame->cloud->resize(i);
          TransformCloud(frame->cloud, frame->lidar2world_pose, frame->world_cloud);
          AINFO_EVERY(60000) << "Preprocessor filter points: " << size << " to " << i;
        }
        return true;
      }

      bool PointCloudPreprocessor::TransformCloud(
          const base::PointFCloudPtr &local_cloud, const Eigen::Affine3d &pose,
          base::PointDCloudPtr world_cloud) const
      {
        if (local_cloud == nullptr)
        {
          return false;
        }
        world_cloud->clear();
        world_cloud->reserve(local_cloud->size());
        for (size_t i = 0; i < local_cloud->size(); ++i)
        {
          auto &pt = local_cloud->at(i);
          Eigen::Vector3d trans_point(pt.x, pt.y, pt.z);
          trans_point = pose * trans_point;
          base::PointD world_point;
          world_point.x = trans_point(0);
          world_point.y = trans_point(1);
          world_point.z = trans_point(2);
          world_point.intensity = pt.intensity;
          world_cloud->push_back(world_point, local_cloud->points_timestamp(i),
                                 std::numeric_limits<float>::max(),
                                 local_cloud->points_beam_id()[i], 0);
        }
        return true;
      }

    } // namespace lidar
  }   // namespace perception
} // namespace apollo
