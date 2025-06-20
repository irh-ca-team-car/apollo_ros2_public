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

#include <string>
#include <mutex>
#include "cyber/common/util.h"
// #include "modules/common/monitor_log/monitor_log_buffer.h"
#include "modules/common/status/status.h"
#include "modules/common/vehicle_state/vehicle_state_provider.h"
#include "modules/map/relative_map/navigation_lane.h"
#include "modules/map/relative_map/proto/navigation.pb.h"
#include "modules/map/relative_map/proto/relative_map_config.pb.h"
#include "modules/perception/proto/perception_obstacle.pb.h"

namespace apollo {
namespace relative_map {

class RelativeMap {
 public:
  RelativeMap();

  /**
   * @brief module name
   */
  std::string Name() const { return "RelativeMap"; }

  /**
   * @brief module initialization function
   * @return initialization status
   */
  apollo::common::Status Init(
      common::VehicleStateProvider* vehicle_state_provider);

  /**
   * @brief module start function
   * @return start status
   */
  apollo::common::Status Start();

  /**
   * @brief module stop function
   */
  void Stop();

  /**
   * @brief destructor
   */
  virtual ~RelativeMap() = default;

  /**
   * @brief main logic of the relative_map module, runs periodically triggered
   * by timer.
   */
  bool Process(apollo_msgs::msg::ApollorelativeMapMapMsg * const  map_msg);

  void OnPerception(
      apollo_msgs::msg::ApolloperceptionPerceptionObstacles::SharedPtr perception_obstacles);
  void OnChassis(  apollo_msgs::msg::ApollocanbusChassis::SharedPtr  chassis);
  void OnLocalization( apollo_msgs::msg::ApollolocalizationLocalizationEstimate::SharedPtr  localization);
  void OnNavigationInfo( apollo_msgs::msg::ApollorelativeMapNavigationInfo::SharedPtr  navigation_info);

 private:

  bool CreateMapFromNavigationLane(apollo_msgs::msg::ApollorelativeMapMapMsg * map_msg);
  apollo_msgs::msg::ApollorelativeMapRelativeMapConfig config_;
//   apollo::common::monitor::MonitorLogBuffer monitor_logger_buffer_;

  NavigationLane navigation_lane_;
  apollo_msgs::msg::ApolloperceptionPerceptionObstacles::SharedPtr perception_obstacles_;
  apollo_msgs::msg::ApollocanbusChassis::SharedPtr  chassis_;
  apollo_msgs::msg::ApollolocalizationLocalizationEstimate::SharedPtr  localization_;

  std::mutex navigation_lane_mutex_;
  common::VehicleStateProvider* vehicle_state_provider_;
};

}  // namespace relative_map
}  // namespace apollo