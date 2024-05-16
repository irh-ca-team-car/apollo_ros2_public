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
#include "modules/map/relative_map/common/relative_map_gflags.h"
#include "gflags/gflags.h"
#include "modules/common/vehicle_state/vehicle_state_provider.h"
#include "modules/map/relative_map/relative_map.h"
#include "modules/map/relative_map/proto/navigator_config.pb.h"

namespace apollo {
namespace relative_map {

class RelativeMapComponent final : public ::apollo::cyber::TimerComponent {
 public:
 RelativeMapComponent(): TimerComponent("RelativeMapComponent") {};

  bool Init() override;
  bool Proc() override;
  long IntervalMilliseconds();
 private:
  bool InitReaders();


  std::shared_ptr<::apollo::cyber::Writer<apollo_msgs::msg::ApollorelativeMapMapMsg>> relative_map_writer_ =
      nullptr;
  std::shared_ptr<cyber::Reader<apollo_msgs::msg::ApolloperceptionPerceptionObstacles>>
      perception_reader_ = nullptr;
  std::shared_ptr<cyber::Reader<apollo_msgs::msg::ApollocanbusChassis>> chassis_reader_ = nullptr;
  std::shared_ptr<cyber::Reader<apollo_msgs::msg::ApollolocalizationLocalizationEstimate>>
      localization_reader_ = nullptr;
  std::shared_ptr<cyber::Reader<apollo_msgs::msg::ApollorelativeMapNavigationInfo>> navigation_reader_ = nullptr;

  std::shared_ptr<common::VehicleStateProvider> vehicle_state_provider_;
  RelativeMap relative_map_;
};


}  // namespace relative_map
}  // namespace apollo