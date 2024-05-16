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
#include "modules/perception/lidar/lib/map_manager/map_manager.h"

#include "cyber/cyber.h"

#include "modules/perception/lib/config_manager/config_manager.h"
#include "modules/perception/proto/map_manager_config.pb.h"

namespace apollo {
namespace perception {
namespace lidar {

using cyber::common::GetAbsolutePath;

bool MapManager::Init(const MapManagerInitOptions& options) {
  auto config_manager = lib::ConfigManager::Instance();
  const lib::ModelConfig* model_config = nullptr;
  ACHECK(config_manager->GetModelConfig(Name(), &model_config));
  UNUSED(options);
  //const std::string work_root = config_manager->work_root();
  //std::string config_file;
  //std::string root_path;
  //ACHECK(model_config->get_value("root_path", &root_path));
  //config_file = GetAbsolutePath(work_root, root_path);
  //config_file = GetAbsolutePath(config_file, "map_manager.json");
  MapManagerConfig config;
  //ACHECK(cyber::common::GetProtoFromFile(config_file, &config));
  auto currentNode = apollo::cyber::currentNode;
  config.updatepose = currentNode->declare_parameter<bool>("update_pose", false);
  config.roisearchdistance = currentNode->declare_parameter<float>("roi_search_distance", 120.0);
  
  update_pose_ = config.updatepose;
  roi_search_distance_ = config.roisearchdistance;
  hdmap_input_ = map::HDMapInput::Instance();
  if (!hdmap_input_->Init()) {
    AINFO_EVERY(60000) << "Failed to init hdmap input.";
    return false;
  }
  return true;
}

bool MapManager::Update(const MapManagerOptions& options, LidarFrame* frame) {
  UNUSED(options);
  if (!frame)
  {
    AINFO_EVERY(60000) << "Frame is nullptr.";
    return false;
  }
  if (!(frame->hdmap_struct)) {
    frame->hdmap_struct.reset(new base::HdmapStruct);
  }
  if (!hdmap_input_) {
    AINFO_EVERY(60000) << "Hdmap input is nullptr";
    return false;
  }
  if (update_pose_) {
    if (!QueryPose(&(frame->lidar2world_pose))) {
      AINFO_EVERY(60000) << "Failed to query updated pose.";
    }
  }
  base::PointD point;
  point.x = frame->lidar2world_pose.translation()(0);
  point.y = frame->lidar2world_pose.translation()(1);
  point.z = frame->lidar2world_pose.translation()(2);
  if (!hdmap_input_->GetRoiHDMapStruct(point, roi_search_distance_,
                                       frame->hdmap_struct)) {
    frame->hdmap_struct->road_polygons.clear();
    frame->hdmap_struct->road_boundary.clear();
    frame->hdmap_struct->hole_polygons.clear();
    frame->hdmap_struct->junction_polygons.clear();
    AINFO_EVERY(60000) << "Failed to get roi from hdmap.";
  }
  return true;
}
bool MapManager::QueryPose(Eigen::Affine3d* sensor2world_pose) const {
  // TODO(...): map-based alignment to refine pose
  UNUSED(sensor2world_pose);
  return false;
}

}  // namespace lidar
}  // namespace perception
}  // namespace apollo
