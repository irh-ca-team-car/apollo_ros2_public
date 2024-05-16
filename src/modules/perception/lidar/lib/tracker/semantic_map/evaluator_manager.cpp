/******************************************************************************
 * Copyright 2020 The Apollo Authors. All Rights Reserved.
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

#include "modules/perception/lidar/lib/tracker/semantic_map/evaluator_manager.h"

#include <algorithm>

#include "modules/common/configs/vehicle_config_helper.h"
#include "modules/prediction/common/feature_output.h"
#include "modules/prediction/common/semantic_map.h"
#include "modules/prediction/container/obstacles/obstacles_container.h"

namespace apollo {
namespace perception {

using apollo::prediction::Feature;
using apollo::prediction::Obstacle;
using apollo::prediction::ObstacleHistory;
using apollo::prediction::ObstaclesContainer;
using apollo::prediction::SemanticLSTMEvaluator;
using apollo::prediction::SemanticMap;
using IdObstacleListMap = std::unordered_map<int, std::list<Obstacle*>>;

bool IsTrainable(const Feature& feature) {
  if (feature.id == FLAGS_ego_vehicle_id) {
    return false;
  }
  if (feature.priority.priority == apollo::prediction::ObstaclePriority::IGNORE ||
      feature.isstill || feature.type != apollo::perception::PerceptionObstacle::VEHICLE) {
    return false;
  }
  return true;
}

void EvaluatorManager::Init() {
  semantic_map_.reset(new SemanticMap());
  semantic_map_->Init();
  evaluator_.reset(new SemanticLSTMEvaluator(semantic_map_.get()));
  AINFO_EVERY(60000) << "Init SemanticMap instance.";
}

void EvaluatorManager::Run(ObstaclesContainer* obstacles_container) {
  BuildObstacleIdHistoryMap(obstacles_container);
  semantic_map_->RunCurrFrame(obstacle_id_history_map_);
  AINFO_EVERY(60000) << "starting evaluating objects in semantic map";
  std::vector<Obstacle*> dynamic_env;
  for (int id : obstacles_container->curr_frame_considered_obstacle_ids()) {
    Obstacle* obstacle = obstacles_container->GetObstacle(id);
    if (obstacle == nullptr) {
      continue;
    }
    if (obstacle->IsStill()) {
      ADEBUG << "Ignore still obstacle [" << id << "] in evaluator_manager";
      continue;
    }
    EvaluateObstacle(obstacle, obstacles_container, dynamic_env);
  }
}

void EvaluatorManager::EvaluateObstacle(Obstacle* obstacle,
                                        ObstaclesContainer* obstacles_container,
                                        std::vector<Obstacle*> dynamic_env) {
  UNUSED(dynamic_env);
  // Select different evaluators depending on the obstacle's type.
  switch (obstacle->type()) {
    case apollo::perception::PerceptionObstacle::VEHICLE: {
      evaluator_->Evaluate(obstacle, obstacles_container);
      break;
    }
    default:
      break;
  }
}

void EvaluatorManager::EvaluateObstacle(
    Obstacle* obstacle, ObstaclesContainer* obstacles_container) {
  std::vector<Obstacle*> dummy_dynamic_env;
  EvaluateObstacle(obstacle, obstacles_container, dummy_dynamic_env);
}

void EvaluatorManager::BuildObstacleIdHistoryMap(
    ObstaclesContainer* obstacles_container) {
  obstacle_id_history_map_.clear();
  std::vector<int> obstacle_ids =
      obstacles_container->curr_frame_movable_obstacle_ids();
  obstacle_ids.push_back(FLAGS_ego_vehicle_id);
  for (int id : obstacle_ids) {
    Obstacle* obstacle = obstacles_container->GetObstacle(id);
    if (obstacle == nullptr || obstacle->history_size() == 0) {
      continue;
    }
    size_t num_frames =
        std::min(static_cast<size_t>(10), obstacle->history_size());
    for (size_t i = 0; i < num_frames; ++i) {
      const Feature& obstacle_feature = obstacle->feature(i);
      Feature feature;
      feature.id=obstacle_feature.id;
      feature.timestamp=obstacle_feature.timestamp;
      feature.position=obstacle_feature.position;
      feature.theta=obstacle_feature.velocityheading;
      if (obstacle_feature.id != FLAGS_ego_vehicle_id) {
        feature.polygonpoint=
            obstacle_feature.polygonpoint;
        feature.length=obstacle_feature.length;
        feature.width=obstacle_feature.width;
      } else {
        const auto& vehicle_config =
            common::VehicleConfigHelper::Instance()->GetConfig();
        feature.length=vehicle_config.vehicleparam.length;
        feature.width=vehicle_config.vehicleparam.width;
      }
      obstacle_id_history_map_[id].feature.push_back(feature);
    }
    obstacle_id_history_map_[id].istrainable=
        IsTrainable(obstacle->latest_feature());
  }
}

}  // namespace perception
}  // namespace apollo
