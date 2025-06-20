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
#include "modules/perception/lidar/app/lidar_obstacle_tracking.h"

#include "cyber/cyber.h"
#include "modules/common/util/perf_util.h"
#include "modules/perception/lib/config_manager/config_manager.h"
#include "modules/perception/lidar/app/proto/lidar_obstacle_tracking_config.pb.h"
#include "modules/perception/lidar/common/lidar_log.h"

namespace apollo {
namespace perception {
namespace lidar {

bool LidarObstacleTracking::Init(
    const LidarObstacleTrackingInitOptions& options) {
  auto& sensor_name = options.sensor_name;
  auto config_manager = lib::ConfigManager::Instance();
  const lib::ModelConfig* model_config = nullptr;
  ADEBUG << ":::" << Name();
  ACHECK(config_manager->GetModelConfig(Name(), &model_config));

  const std::string work_root = config_manager->work_root();
  std::string config_file;
  std::string root_path;
  ACHECK(model_config->get_value("root_path", &root_path));
  config_file = cyber::common::GetAbsolutePath(work_root, root_path);
  config_file = cyber::common::GetAbsolutePath(config_file, sensor_name);
  config_file = cyber::common::GetAbsolutePath(config_file,
                                               "lidar_obstacle_tracking.json");

  LidarObstacleTrackingConfig config;
  //ACHECK(cyber::common::GetProtoFromFile(config_file, &config));
  auto currentNode = apollo::cyber::currentNode;
  config.multitargettracker = currentNode->declare_parameter<std::string>("multi_target_tracker","MlfEngine");
  config.fusionclassifier = currentNode->declare_parameter<std::string>("fusion_classifier","FusedClassifier");
  
  multi_target_tracker_name_ = config.multitargettracker;
  fusion_classifier_name_ = config.fusionclassifier;

  multi_target_tracker_ = BaseMultiTargetTrackerRegisterer::GetInstanceByName(
      multi_target_tracker_name_);
  CHECK_NOTNULL(multi_target_tracker_);
  MultiTargetTrackerInitOptions tracker_init_options;
  ACHECK(multi_target_tracker_->Init(tracker_init_options));

  fusion_classifier_ =
      BaseClassifierRegisterer::GetInstanceByName(fusion_classifier_name_);
  CHECK_NOTNULL(fusion_classifier_);
  ClassifierInitOptions fusion_classifier_init_options;
  ACHECK(fusion_classifier_->Init(fusion_classifier_init_options));
  return true;
}

LidarProcessResult LidarObstacleTracking::Process(
    const LidarObstacleTrackingOptions& options, LidarFrame* frame) {
  const auto& sensor_name = options.sensor_name;

  PERF_FUNCTION_WITH_INDICATOR(sensor_name);

  PERF_BLOCK_START();
  MultiTargetTrackerOptions tracker_options;
  if (!multi_target_tracker_->Track(tracker_options, frame)) {
    return LidarProcessResult(LidarErrorCode::TrackerError,
                              "Fail to track objects.");
  }
  PERF_BLOCK_END_WITH_INDICATOR(sensor_name, "tracker");

  ClassifierOptions fusion_classifier_options;
  if (!fusion_classifier_->Classify(fusion_classifier_options, frame)) {
    return LidarProcessResult(LidarErrorCode::ClassifierError,
                              "Fail to fuse object types.");
  }
  PERF_BLOCK_END_WITH_INDICATOR(sensor_name, "type_fusion");

  return LidarProcessResult(LidarErrorCode::Succeed);
}

}  // namespace lidar
}  // namespace perception
}  // namespace apollo
