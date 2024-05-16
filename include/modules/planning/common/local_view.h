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

#pragma once

#include <memory>

#include "modules/canbus/proto/chassis.pb.h"
#include "modules/localization/proto/localization.pb.h"
#include "modules/map/relative_map/proto/navigation.pb.h"
#include "modules/perception/proto/traffic_light_detection.pb.h"
#include "modules/planning/proto/pad_msg.pb.h"
#include "modules/prediction/proto/prediction_obstacle.pb.h"
#include "modules/routing/proto/routing.pb.h"
#include "modules/storytelling/proto/story.pb.h"

namespace apollo {
namespace planning {

/**
 * @struct local_view
 * @brief LocalView contains all necessary data as planning input
 */

struct LocalView {
  std::shared_ptr<apollo_msgs::msg::ApollopredictionPredictionObstacles> prediction_obstacles;
  std::shared_ptr<apollo_msgs::msg::ApollocanbusChassis> chassis;
  std::shared_ptr<apollo_msgs::msg::ApollolocalizationLocalizationEstimate> localization_estimate;
  std::shared_ptr<apollo_msgs::msg::ApolloperceptionTrafficLightDetection> traffic_light;
  std::shared_ptr<apollo_msgs::msg::ApolloroutingRoutingResponse> routing;
  std::shared_ptr<apollo_msgs::msg::ApollorelativeMapMapMsg> relative_map;
  std::shared_ptr<PadMessage> pad_msg;
  std::shared_ptr<apollo_msgs::msg::ApollostorytellingStories> stories;
};

}  // namespace planning
}  // namespace apollo