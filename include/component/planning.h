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

#include "cyber/cyber.h"
#include "cyber/component.h"
// #include "cyber/message/raw_message.h"
#include "modules/canbus/proto/chassis.pb.h"
#include "modules/localization/proto/localization.pb.h"
#include "modules/perception/proto/traffic_light_detection.pb.h"
#include "modules/planning/common/message_process.h"
#include "modules/planning/common/planning_gflags.h"
#include "modules/planning/planning_base.h"
#include "modules/planning/proto/learning_data.pb.h"
#include "modules/planning/proto/pad_msg.pb.h"
#include "modules/planning/proto/planning.pb.h"
#include "modules/planning/proto/planning_config.pb.h"
#include "modules/prediction/proto/prediction_obstacle.pb.h"
#include "modules/routing/proto/routing.pb.h"
#include "modules/storytelling/proto/story.pb.h"

namespace apollo {
namespace planning {

class PlanningComponent final
    : public cyber::Component
                                 {
 public:
  PlanningComponent():Component("PlanningComponent"){};

  ~PlanningComponent() = default;

 public:
  bool Init() override;

  bool Proc(const std::shared_ptr<apollo_msgs::msg::ApollocanbusChassis>& chassis,
            const std::shared_ptr<apollo_msgs::msg::ApollolocalizationLocalizationEstimate>&
                localization_estimate) ;

 private:
  void CheckRerouting();
  bool CheckInput();

 private:

  cyber::adapter::Sync<apollo_msgs::msg::ApollocanbusChassis,apollo_msgs::msg::ApollolocalizationLocalizationEstimate> sync_;
  std::shared_ptr<cyber::Reader<apollo_msgs::msg::ApollocanbusChassis>> r0_;
  std::shared_ptr<cyber::Reader<apollo_msgs::msg::ApollolocalizationLocalizationEstimate>> r1_;
  
  
  std::shared_ptr<cyber::Reader<apollo_msgs::msg::ApolloperceptionTrafficLightDetection>>
      traffic_light_reader_;
  std::shared_ptr<cyber::Reader<apollo_msgs::msg::ApolloroutingRoutingResponse>> routing_reader_;
  std::shared_ptr<cyber::Reader<apollo_msgs::msg::ApolloplanningPadMessage>> pad_msg_reader_;
  std::shared_ptr<cyber::Reader<apollo_msgs::msg::ApollorelativeMapMapMsg>> relative_map_reader_;
  std::shared_ptr<cyber::Reader<apollo_msgs::msg::ApollostorytellingStories>> story_telling_reader_;

  std::shared_ptr<cyber::Writer<apollo_msgs::msg::ApolloplanningADCTrajectory>> planning_writer_;
  std::shared_ptr<cyber::Writer<apollo_msgs::msg::ApolloroutingRoutingRequest>> rerouting_writer_;
  std::shared_ptr<cyber::Writer<apollo_msgs::msg::ApolloplanningPlanningLearningData>>
      planning_learning_data_writer_;
// à revoir 
  std::mutex mutex_;
  apollo_msgs::msg::ApolloperceptionTrafficLightDetection traffic_light_;
  apollo_msgs::msg::ApolloroutingRoutingResponse routing_;
  apollo_msgs::msg::ApolloplanningPadMessage pad_msg_;
  apollo_msgs::msg::ApollorelativeMapMapMsg relative_map_;
  apollo_msgs::msg::ApollostorytellingStories stories_;

  LocalView local_view_;

  std::unique_ptr<apollo::planning::PlanningBase> planning_base_;
  std::shared_ptr<apollo::planning::DependencyInjector> injector_;

  apollo_msgs::msg::ApolloplanningPlanningConfig config_;
  MessageProcess message_process_;
};


}  // namespace planning
}  // namespace apollo
