/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
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

/**
 * @file
 **/

#include "modules/planning/traffic_rules/backside_vehicle.h"

namespace apollo {
namespace planning {

using apollo::common::Status;

BacksideVehicle::BacksideVehicle(const apollo_msgs::msg::ApolloplanningTrafficRuleConfig &config)
    : TrafficRule(config) {}

void BacksideVehicle::MakeLaneKeepingObstacleDecision(
    const SLBoundary& adc_sl_boundary, PathDecision* path_decision) {
  apollo_msgs::msg::ApolloplanningObjectDecisionType ignore;
  ignore.objecttag.ignore=1;
  const double adc_length_s =
      adc_sl_boundary.ends - adc_sl_boundary.starts;
  for (const auto* obstacle : path_decision->obstacles().Items()) {
    if (obstacle->PerceptionSLBoundary().ends >= adc_sl_boundary.ends ||
        obstacle->IsCautionLevelObstacle()) {
      // don't ignore such vehicles.
      continue;
    }

    if (obstacle->reference_line_st_boundary().IsEmpty()) {
      path_decision->AddLongitudinalDecision("backside_vehicle/no-st-region",
                                             obstacle->Id(), ignore);
      path_decision->AddLateralDecision("backside_vehicle/no-st-region",
                                        obstacle->Id(), ignore);
      continue;
    }
    // Ignore the car comes from back of ADC
    if (obstacle->reference_line_st_boundary().min_s() < -adc_length_s) {
      path_decision->AddLongitudinalDecision("backside_vehicle/st-min-s < adc",
                                             obstacle->Id(), ignore);
      path_decision->AddLateralDecision("backside_vehicle/st-min-s < adc",
                                        obstacle->Id(), ignore);
      continue;
    }

    const double lane_boundary =
        config_.config.backsidevehicle.backsidelanewidth;
    if (obstacle->PerceptionSLBoundary().starts < adc_sl_boundary.ends) {
      if (obstacle->PerceptionSLBoundary().startl > lane_boundary ||
          obstacle->PerceptionSLBoundary().endl < -lane_boundary) {
        continue;
      }
      path_decision->AddLongitudinalDecision("backside_vehicle/sl < adc.end_s",
                                             obstacle->Id(), ignore);
      path_decision->AddLateralDecision("backside_vehicle/sl < adc.end_s",
                                        obstacle->Id(), ignore);
      continue;
    }
  }
}

Status BacksideVehicle::ApplyRule(
    Frame* const, ReferenceLineInfo* const reference_line_info) {
  auto* path_decision = reference_line_info->path_decision();
  const auto& adc_sl_boundary = reference_line_info->AdcSlBoundary();
  // The lane keeping reference line.
  if (reference_line_info->Lanes().IsOnSegment()) {
    MakeLaneKeepingObstacleDecision(adc_sl_boundary, path_decision);
  }
  return Status::OK();
}

}  // namespace planning
}  // namespace apollo