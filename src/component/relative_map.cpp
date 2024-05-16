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


#include "component/relative_map.h"
#include "modules/common/adapters/adapter_gflags.h"
#include "modules/common/configs/config_gflags.h"
#include "modules/prediction/common/prediction_system_gflags.h"

namespace apollo {
namespace relative_map {

using apollo_msgs::msg::ApollocanbusChassis;
using apollo_msgs::msg::ApollolocalizationLocalizationEstimate;
using apollo_msgs::msg::ApolloperceptionPerceptionObstacles;

bool RelativeMapComponent::Init() {
  apollo::common::gflags::init_common(node_);
  apollo::common::gflags::init_common_adapter(node_);
  apollo::prediction::load_system_flags(node_);
  
  vehicle_state_provider_ = std::make_shared<common::VehicleStateProvider>();
  
  INIT_FLAG_string(
      relative_map_config_filename,
      "<root>/conf/map/relative_map/relative_map_config.json",
      "Relative map configuration file");

  INIT_FLAG_string(navigator_config_filename,
                   "<root>/conf/map/relative_map/navigator_config.json",
                   "navigator config file name.");

  INIT_FLAG_int32(relative_map_loop_rate, 10, "Loop rate for relative_map node");

  INIT_FLAG_bool(enable_cyclic_rerouting, false,
                 "Enable auto rerouting in a in a cyclic/circular navigaton line.");

  INIT_FLAG_bool(relative_map_generate_left_boundray, true,
                 "Generate left boundary for detected lanes.");



  InitReaders();
  AINFO << "Readers initialized";
  return relative_map_.Init(vehicle_state_provider_.get()).ok() &&
         relative_map_.Start().ok();
}
long RelativeMapComponent::IntervalMilliseconds(){return 100;}
bool RelativeMapComponent::Proc() {
  auto map_msg = std::make_shared<apollo_msgs::msg::ApollorelativeMapMapMsg>();
  if (!relative_map_.Process(map_msg.get())) {
    AINFO_EVERY(60000)<<"relative_map_.Process failure";
    //return false;
    return true;
  }
  node_->FillHeader(node_->get_name (), map_msg->apolloheader);
  relative_map_writer_->Write(map_msg);
  return true;
}

bool RelativeMapComponent::InitReaders() {
  ADEBUG<<"Initializing "<<FLAGS_perception_obstacle_topic;
  perception_reader_ = node_->CreateReader<apollo_msgs::msg::ApolloperceptionPerceptionObstacles>(
      FLAGS_perception_obstacle_topic,
      [this]( auto perception_obstacles) {
        ADEBUG << "Received perception data: run perception callback.";
        relative_map_.OnPerception(perception_obstacles);
      });
ADEBUG<<"Initializing "<<FLAGS_chassis_topic;
  chassis_reader_ = node_->CreateReader<apollo_msgs::msg::ApollocanbusChassis>(
      FLAGS_chassis_topic, [this]( auto chassis) {
        ADEBUG << "Received chassis data: run chassis callback.";
        relative_map_.OnChassis(chassis);
      });
ADEBUG<<"Initializing "<<FLAGS_localization_topic;
  localization_reader_ = node_->CreateReader<apollo_msgs::msg::ApollolocalizationLocalizationEstimate>(
      FLAGS_localization_topic,
      [this]( auto localization) {
        ADEBUG << "Received chassis data: run chassis callback.";
        //GPS heading is different than the format that apollo requires.
        localization->pose.heading *= -1;
        localization->pose.heading += M_PI;
        relative_map_.OnLocalization(localization);
      });
ADEBUG<<"Initializing "<<FLAGS_navigation_topic;
  navigation_reader_ = node_->CreateReader<apollo_msgs::msg::ApollorelativeMapNavigationInfo>(
      FLAGS_navigation_topic,
      [this]( auto navigation_info) {
        ADEBUG << "Received navigation_info data: run navigation_info callback.";
        relative_map_.OnNavigationInfo(navigation_info);
      });

  relative_map_writer_ = node_->CreateWriter<apollo_msgs::msg::ApollorelativeMapMapMsg>(FLAGS_relative_map_topic);
  return true;
}

}  // namespace relative_map
}  // namespace apollo
CYBER_REGISTER_COMPONENT(RelativeMapComponent)
