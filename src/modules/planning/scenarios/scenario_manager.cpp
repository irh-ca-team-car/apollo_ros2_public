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

#include "modules/planning/scenarios/scenario_manager.h"

#include <string>
#include <vector>

#include "modules/common/configs/vehicle_config_helper.h"
#include "modules/common/util/point_factory.h"
#include "modules/common/vehicle_state/vehicle_state_provider.h"
#include "modules/map/pnc_map/path.h"
#include "modules/map/proto/map_lane.pb.h"
#include "modules/planning/common/planning_context.h"
#include "modules/planning/common/planning_gflags.h"
#include "modules/planning/common/util/util.h"
#include "modules/planning/scenarios/bare_intersection/unprotected/bare_intersection_unprotected_scenario.h"
#include "modules/planning/scenarios/emergency/emergency_pull_over/emergency_pull_over_scenario.h"
#include "modules/planning/scenarios/emergency/emergency_stop/emergency_stop_scenario.h"
#include "modules/planning/scenarios/lane_follow/lane_follow_scenario.h"
#include "modules/planning/scenarios/learning_model/learning_model_sample_scenario.h"
#include "modules/planning/scenarios/park/pull_over/pull_over_scenario.h"
#include "modules/planning/scenarios/park/valet_parking/valet_parking_scenario.h"
#include "modules/planning/scenarios/park_and_go/park_and_go_scenario.h"
#include "modules/planning/scenarios/stop_sign/unprotected/stop_sign_unprotected_scenario.h"
#include "modules/planning/scenarios/traffic_light/protected/traffic_light_protected_scenario.h"
#include "modules/planning/scenarios/traffic_light/unprotected_left_turn/traffic_light_unprotected_left_turn_scenario.h"
#include "modules/planning/scenarios/traffic_light/unprotected_right_turn/traffic_light_unprotected_right_turn_scenario.h"
#include "modules/planning/scenarios/util/util.h"
#include "modules/planning/scenarios/yield_sign/yield_sign_scenario.h"

namespace apollo {
namespace planning {
namespace scenario {

using apollo::hdmap::HDMapUtil;
using apollo::hdmap::PathOverlap;

ScenarioManager::ScenarioManager(
    const std::shared_ptr<DependencyInjector>& injector)
    : injector_(injector) {}

bool ScenarioManager::Init(const apollo_msgs::msg::ApolloplanningPlanningConfig& planning_config) {
  planning_config_=(planning_config);
  RegisterScenarios();
  default_scenario_type_ = ScenarioConfig::LANE_FOLLOW;
  current_scenario_ = CreateScenario(default_scenario_type_);
  return true;
}

std::unique_ptr<Scenario> ScenarioManager::CreateScenario(
    ScenarioConfig::ScenarioType scenario_type) {
  std::unique_ptr<Scenario> ptr;

  switch (scenario_type) {
    case ScenarioConfig::BARE_INTERSECTION_UNPROTECTED:
      ptr.reset(
          new scenario::bare_intersection::BareIntersectionUnprotectedScenario(
              config_map_[scenario_type], &scenario_context_, injector_));
      break;
    case ScenarioConfig::EMERGENCY_PULL_OVER:
      ptr.reset(new emergency_pull_over::EmergencyPullOverScenario(
          config_map_[scenario_type], &scenario_context_, injector_));
      break;
    case ScenarioConfig::EMERGENCY_STOP:
      ptr.reset(new emergency_stop::EmergencyStopScenario(
          config_map_[scenario_type], &scenario_context_, injector_));
      break;
    case ScenarioConfig::LANE_FOLLOW:
      ptr.reset(new lane_follow::LaneFollowScenario(
          config_map_[scenario_type], &scenario_context_, injector_));
      break;
    case ScenarioConfig::LEARNING_MODEL_SAMPLE:
      ptr.reset(new scenario::LearningModelSampleScenario(
          config_map_[scenario_type], &scenario_context_, injector_));
      break;
    case ScenarioConfig::PARK_AND_GO:
      ptr.reset(new scenario::park_and_go::ParkAndGoScenario(
          config_map_[scenario_type], &scenario_context_, injector_));
      break;
    case ScenarioConfig::PULL_OVER:
      ptr.reset(new scenario::pull_over::PullOverScenario(
          config_map_[scenario_type], &scenario_context_, injector_));
      break;
    case ScenarioConfig::STOP_SIGN_UNPROTECTED:
      ptr.reset(new scenario::stop_sign::StopSignUnprotectedScenario(
          config_map_[scenario_type], &scenario_context_, injector_));
      break;
    case ScenarioConfig::TRAFFIC_LIGHT_PROTECTED:
      ptr.reset(new scenario::traffic_light::TrafficLightProtectedScenario(
          config_map_[scenario_type], &scenario_context_, injector_));
      break;
    case ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN:
      ptr.reset(
          new scenario::traffic_light::TrafficLightUnprotectedLeftTurnScenario(
              config_map_[scenario_type], &scenario_context_, injector_));
      break;
    case ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN:
      ptr.reset(
          new scenario::traffic_light::TrafficLightUnprotectedRightTurnScenario(
              config_map_[scenario_type], &scenario_context_, injector_));
      break;
    case ScenarioConfig::VALET_PARKING:
      ptr.reset(new scenario::valet_parking::ValetParkingScenario(
          config_map_[scenario_type], &scenario_context_, injector_));
      break;
    case ScenarioConfig::YIELD_SIGN:
      ptr.reset(new scenario::yield_sign::YieldSignScenario(
          config_map_[scenario_type], &scenario_context_, injector_));
      break;
    default:
      return nullptr;
  }

  if (ptr != nullptr) {
    ptr->Init();
  }
  return ptr;
}

void ScenarioManager::RegisterScenarios() {
  // lane_follow
  if (planning_config_.learningmode == PlanningConfig::HYBRID ||
      planning_config_.learningmode == PlanningConfig::HYBRID_TEST) {
    // HYBRID or HYBRID_TEST
    ACHECK(Scenario::LoadConfig(FLAGS_scenario_lane_follow_hybrid_config_file,
                                &config_map_[ScenarioConfig::LANE_FOLLOW]));
  } else {
    ACHECK(Scenario::LoadConfig(FLAGS_scenario_lane_follow_config_file,
                                &config_map_[ScenarioConfig::LANE_FOLLOW]));
  }

  // bare_intersection
  ACHECK(Scenario::LoadConfig(
      FLAGS_scenario_bare_intersection_unprotected_config_file,
      &config_map_[ScenarioConfig::BARE_INTERSECTION_UNPROTECTED]));

  // emergency_pull_over
  ACHECK(
      Scenario::LoadConfig(FLAGS_scenario_emergency_pull_over_config_file,
                           &config_map_[ScenarioConfig::EMERGENCY_PULL_OVER]));

  // emergency_stop
  ACHECK(Scenario::LoadConfig(FLAGS_scenario_emergency_stop_config_file,
                              &config_map_[ScenarioConfig::EMERGENCY_STOP]));

  // learning model
  ACHECK(Scenario::LoadConfig(
      FLAGS_scenario_learning_model_sample_config_file,
      &config_map_[ScenarioConfig::LEARNING_MODEL_SAMPLE]));

  // park_and_go
  ACHECK(Scenario::LoadConfig(FLAGS_scenario_park_and_go_config_file,
                              &config_map_[ScenarioConfig::PARK_AND_GO]));

  // pull_over
  ACHECK(Scenario::LoadConfig(FLAGS_scenario_pull_over_config_file,
                              &config_map_[ScenarioConfig::PULL_OVER]));

  // stop_sign
  ACHECK(Scenario::LoadConfig(
      FLAGS_scenario_stop_sign_unprotected_config_file,
      &config_map_[ScenarioConfig::STOP_SIGN_UNPROTECTED]));

  // traffic_light
  ACHECK(Scenario::LoadConfig(
      FLAGS_scenario_traffic_light_protected_config_file,
      &config_map_[ScenarioConfig::TRAFFIC_LIGHT_PROTECTED]));
  ACHECK(Scenario::LoadConfig(
      FLAGS_scenario_traffic_light_unprotected_left_turn_config_file,
      &config_map_[ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN]));
  ACHECK(Scenario::LoadConfig(
      FLAGS_scenario_traffic_light_unprotected_right_turn_config_file,
      &config_map_[ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN]));

  // valet parking
  ACHECK(Scenario::LoadConfig(FLAGS_scenario_valet_parking_config_file,
                              &config_map_[ScenarioConfig::VALET_PARKING]));

  // yield_sign
  ACHECK(Scenario::LoadConfig(FLAGS_scenario_yield_sign_config_file,
                              &config_map_[ScenarioConfig::YIELD_SIGN]));
}

ScenarioConfig::ScenarioType ScenarioManager::SelectPullOverScenario(
    const Frame& frame) {
  const auto& scenario_config =
      config_map_[ScenarioConfig::PULL_OVER].scenarioconfig.pulloverconfig;

  const auto& routing = frame.local_view().routing;
  const auto& routing_end = *(routing->routingrequest.waypoint.rbegin());

  common::SLPoint dest_sl;
  const auto& reference_line_info = frame.reference_line_info().front();
  const auto& reference_line = reference_line_info.reference_line();
  reference_line.XYToSLPB(routing_end.pose, &dest_sl);
  const double adc_front_edge_s = reference_line_info.AdcSlBoundary().ends;

  const double adc_distance_to_dest = dest_sl.s - adc_front_edge_s;
  ADEBUG << "adc_distance_to_dest[" << adc_distance_to_dest
         << "] destination_s[" << dest_sl.s << "] adc_front_edge_s["
         << adc_front_edge_s << "]";

  bool pull_over_scenario =
      (frame.reference_line_info().size() == 1 &&  // NO, while changing lane
       adc_distance_to_dest >=
           scenario_config.pullovermindistancebuffer &&
       adc_distance_to_dest <=
           scenario_config.startpulloverscenariodistance);

  // too close to destination + not found pull-over position
  if (pull_over_scenario) {
    const auto& pull_over_status =
        injector_->planning_context()->planning_status().pullover;
    if (adc_distance_to_dest < scenario_config.maxdistancestopsearch &&
        pull_over_status.position == apollo_msgs::msg::ApollocommonPointENU())
    {
      pull_over_scenario = false;
    }
  }

  // check around junction
  if (pull_over_scenario) {
    static constexpr double kDistanceToAvoidJunction = 8.0;  // meter
    for (const auto& overlap : first_encountered_overlap_map_) {
      if (overlap.first == ReferenceLineInfo::PNC_JUNCTION ||
          overlap.first == ReferenceLineInfo::SIGNAL ||
          overlap.first == ReferenceLineInfo::STOP_SIGN ||
          overlap.first == ReferenceLineInfo::YIELD_SIGN) {
        const double distance_to = overlap.second.start_s - dest_sl.s;
        const double distance_passed = dest_sl.s - overlap.second.end_s;
        if ((distance_to > 0.0 && distance_to < kDistanceToAvoidJunction) ||
            (distance_passed > 0.0 &&
             distance_passed < kDistanceToAvoidJunction)) {
          pull_over_scenario = false;
          break;
        }
      }
    }
  }

  // check rightmost driving lane along pull-over path
  if (pull_over_scenario) {
    double check_s = adc_front_edge_s;
    static constexpr double kDistanceUnit = 5.0;
    while (check_s < dest_sl.s) {
      check_s += kDistanceUnit;

      std::vector<hdmap::LaneInfoConstPtr> lanes;
      reference_line.GetLaneFromS(check_s, &lanes);
      if (lanes.empty()) {
        ADEBUG << "check_s[" << check_s << "] can't find a lane";
        continue;
      }
      const hdmap::LaneInfoConstPtr lane = lanes[0];
      const std::string lane_id = lane->lane().id.id;
      ADEBUG << "check_s[" << check_s << "] lane[" << lane_id << "]";

      // check neighbor lanes type: NONE/CITY_DRIVING/BIKING/SIDEWALK/PARKING
      bool rightmost_driving_lane = true;
      for (const auto& neighbor_lane_id :
           lane->lane().rightneighborforwardlaneid) {
        const auto hdmap_ptr = HDMapUtil::BaseMapPtr();
        CHECK_NOTNULL(hdmap_ptr);
        const auto neighbor_lane = hdmap_ptr->GetLaneById(neighbor_lane_id);
        if (neighbor_lane == nullptr) {
          ADEBUG << "Failed to find neighbor lane[" << neighbor_lane_id.id
                 << "]";
          continue;
        }
        const auto& lane_type = neighbor_lane->lane().type;
        if (lane_type == hdmap::Lane::CITY_DRIVING) {
          ADEBUG << "lane[" << lane_id << "]'s right neighbor forward lane["
                 << neighbor_lane_id.id << "] type["
                 << hdmap::Lane::LaneType_Name((hdmap::Lane::LaneType)lane_type) << "] can't pull over";
          rightmost_driving_lane = false;
          break;
        }
      }
      if (!rightmost_driving_lane) {
        pull_over_scenario = false;
        break;
      }
    }
  }

  switch (current_scenario_->scenario_type()) {
    case ScenarioConfig::LANE_FOLLOW:
      if (pull_over_scenario) {
        return ScenarioConfig::PULL_OVER;
      }
      break;
    case ScenarioConfig::BARE_INTERSECTION_UNPROTECTED:
    case ScenarioConfig::EMERGENCY_PULL_OVER:
    case ScenarioConfig::PARK_AND_GO:
    case ScenarioConfig::PULL_OVER:
    case ScenarioConfig::STOP_SIGN_PROTECTED:
    case ScenarioConfig::STOP_SIGN_UNPROTECTED:
    case ScenarioConfig::TRAFFIC_LIGHT_PROTECTED:
    case ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN:
    case ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN:
    case ScenarioConfig::VALET_PARKING:
    case ScenarioConfig::YIELD_SIGN:
      if (current_scenario_->GetStatus() !=
          Scenario::ScenarioStatus::STATUS_DONE) {
        return (apollo::planning::ScenarioConfig::ScenarioType)current_scenario_->scenario_type();
      }
      break;
    default:
      break;
  }

  return default_scenario_type_;
}

ScenarioConfig::ScenarioType ScenarioManager::SelectPadMsgScenario(
    const Frame& frame) {
  const auto& pad_msg_driving_action = frame.GetPadMsgDrivingAction();

  switch (pad_msg_driving_action) {
    case DrivingAction::PULL_OVER:
      if (FLAGS_enable_scenario_emergency_pull_over) {
        return ScenarioConfig::EMERGENCY_PULL_OVER;
      }
      break;
    case DrivingAction::STOP:
      if (FLAGS_enable_scenario_emergency_stop) {
        return ScenarioConfig::EMERGENCY_STOP;
      }
      break;
    case DrivingAction::RESUME_CRUISE:
      if (current_scenario_->scenario_type() ==
              ScenarioConfig::EMERGENCY_PULL_OVER ||
          current_scenario_->scenario_type() ==
              ScenarioConfig::EMERGENCY_STOP) {
        return ScenarioConfig::PARK_AND_GO;
      }
      break;
    default:
      break;
  }

  return default_scenario_type_;
}

ScenarioConfig::ScenarioType ScenarioManager::SelectInterceptionScenario(
    const Frame& frame) {
  ScenarioConfig::ScenarioType scenario_type = default_scenario_type_;

  hdmap::PathOverlap* traffic_sign_overlap = nullptr;
  hdmap::PathOverlap* pnc_junction_overlap = nullptr;
  ReferenceLineInfo::OverlapType overlap_type;

  const auto& reference_line_info = frame.reference_line_info().front();
  const auto& first_encountered_overlaps =
      reference_line_info.FirstEncounteredOverlaps();
  // note: first_encountered_overlaps already sorted
  for (const auto& overlap : first_encountered_overlaps) {
    if (overlap.first == ReferenceLineInfo::SIGNAL ||
        overlap.first == ReferenceLineInfo::STOP_SIGN ||
        overlap.first == ReferenceLineInfo::YIELD_SIGN) {
      overlap_type = overlap.first;
      traffic_sign_overlap = const_cast<hdmap::PathOverlap*>(&overlap.second);
      break;
    } else if (overlap.first == ReferenceLineInfo::PNC_JUNCTION) {
      pnc_junction_overlap = const_cast<hdmap::PathOverlap*>(&overlap.second);
    }
  }

  // pick a closer one between consecutive bare_intersection and traffic_sign
  if (traffic_sign_overlap && pnc_junction_overlap) {
    static constexpr double kJunctionDelta = 10.0;
    double s_diff = std::fabs(traffic_sign_overlap->start_s -
                              pnc_junction_overlap->start_s);
    if (s_diff >= kJunctionDelta) {
      if (pnc_junction_overlap->start_s > traffic_sign_overlap->start_s) {
        pnc_junction_overlap = nullptr;
      } else {
        traffic_sign_overlap = nullptr;
      }
    }
  }

  if (traffic_sign_overlap) {
    switch (overlap_type) {
      case ReferenceLineInfo::STOP_SIGN:
        if (FLAGS_enable_scenario_stop_sign) {
          scenario_type = SelectStopSignScenario(frame, *traffic_sign_overlap);
        }
        break;
      case ReferenceLineInfo::SIGNAL:
        if (FLAGS_enable_scenario_traffic_light) {
          scenario_type =
              SelectTrafficLightScenario(frame, *traffic_sign_overlap);
        }
        break;
      case ReferenceLineInfo::YIELD_SIGN:
        if (FLAGS_enable_scenario_yield_sign) {
          scenario_type = SelectYieldSignScenario(frame, *traffic_sign_overlap);
        }
        break;
      default:
        break;
    }
  } else if (pnc_junction_overlap) {
    // bare intersection
    if (FLAGS_enable_scenario_bare_intersection) {
      scenario_type =
          SelectBareIntersectionScenario(frame, *pnc_junction_overlap);
    }
  }

  return scenario_type;
}

ScenarioConfig::ScenarioType ScenarioManager::SelectStopSignScenario(
    const Frame& frame, const hdmap::PathOverlap& stop_sign_overlap) {
  const auto& scenario_config =
      config_map_[ScenarioConfig::STOP_SIGN_UNPROTECTED].scenarioconfig
          .stopsignunprotectedconfig;

  const auto& reference_line_info = frame.reference_line_info().front();
  const double adc_front_edge_s = reference_line_info.AdcSlBoundary().ends;
  const double adc_distance_to_stop_sign =
      stop_sign_overlap.start_s - adc_front_edge_s;
  ADEBUG << "adc_distance_to_stop_sign[" << adc_distance_to_stop_sign
         << "] stop_sign[" << stop_sign_overlap.object_id
         << "] stop_sign_overlap_start_s[" << stop_sign_overlap.start_s << "]";

  const bool stop_sign_scenario =
      (adc_distance_to_stop_sign > 0.0 &&
       adc_distance_to_stop_sign <=
           scenario_config.startstopsignscenariodistance);
  const bool stop_sign_all_way = false;  // TODO(all)

  switch (current_scenario_->scenario_type()) {
    case ScenarioConfig::LANE_FOLLOW:
    case ScenarioConfig::PARK_AND_GO:
    case ScenarioConfig::PULL_OVER:
      if (stop_sign_scenario) {
        return stop_sign_all_way ? ScenarioConfig::STOP_SIGN_PROTECTED
                                 : ScenarioConfig::STOP_SIGN_UNPROTECTED;
      }
      break;
    case ScenarioConfig::BARE_INTERSECTION_UNPROTECTED:
    case ScenarioConfig::EMERGENCY_PULL_OVER:
    case ScenarioConfig::STOP_SIGN_PROTECTED:
    case ScenarioConfig::STOP_SIGN_UNPROTECTED:
    case ScenarioConfig::TRAFFIC_LIGHT_PROTECTED:
    case ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN:
    case ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN:
    case ScenarioConfig::YIELD_SIGN:
    case ScenarioConfig::VALET_PARKING:
      if (current_scenario_->GetStatus() !=
          Scenario::ScenarioStatus::STATUS_DONE) {
        return (apollo::planning::ScenarioConfig::ScenarioType)current_scenario_->scenario_type();
      }
      break;
    default:
      break;
  }

  return default_scenario_type_;
}

ScenarioConfig::ScenarioType ScenarioManager::SelectTrafficLightScenario(
    const Frame& frame, const hdmap::PathOverlap& traffic_light_overlap) {
  // some scenario may need start sooner than the others
  const double start_check_distance = std::max(
      {config_map_[ScenarioConfig::TRAFFIC_LIGHT_PROTECTED].scenarioconfig.trafficlightprotectedconfig.starttrafficlightscenariodistance,
       config_map_[ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN].scenarioconfig.trafficlightunprotectedleftturnconfig.starttrafficlightscenariodistance,
       config_map_[ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN].scenarioconfig.trafficlightunprotectedrightturnconfig.starttrafficlightscenariodistance});

  const auto& reference_line_info = frame.reference_line_info().front();
  const double adc_front_edge_s = reference_line_info.AdcSlBoundary().ends;

  // find all the traffic light belong to
  // the same group as first encountered traffic light
  std::vector<hdmap::PathOverlap> next_traffic_lights;
  static constexpr double kTrafficLightGroupingMaxDist = 2.0;  // unit: m
  const std::vector<PathOverlap>& traffic_light_overlaps =
      reference_line_info.reference_line().map_path().signal_overlaps();
  for (const auto& overlap : traffic_light_overlaps) {
    const double dist = overlap.start_s - traffic_light_overlap.start_s;
    if (fabs(dist) <= kTrafficLightGroupingMaxDist) {
      next_traffic_lights.push_back(overlap);
    }
  }

  bool traffic_light_scenario = false;
  bool red_light = false;

  // note: need iterate all lights to check no RED/YELLOW/UNKNOWN
  for (const auto& traffic_light_overlap : next_traffic_lights) {
    const double adc_distance_to_traffic_light =
        traffic_light_overlap.start_s - adc_front_edge_s;
    ADEBUG << "traffic_light[" << traffic_light_overlap.object_id
           << "] start_s[" << traffic_light_overlap.start_s
           << "] adc_distance_to_traffic_light["
           << adc_distance_to_traffic_light << "]";

    // enter traffic-light scenarios: based on distance only
    if (adc_distance_to_traffic_light <= 0.0 ||
        adc_distance_to_traffic_light > start_check_distance) {
      continue;
    }

    traffic_light_scenario = true;

    const auto& signal_color =
        frame.GetSignal(traffic_light_overlap.object_id).color;
    ADEBUG << "traffic_light_id[" << traffic_light_overlap.object_id
           << "] start_s[" << traffic_light_overlap.start_s << "] color["
           << signal_color << "]";

    if (signal_color != perception::TrafficLight::GREEN) {
      red_light = true;
      break;
    }
  }

  bool traffic_light_protected_scenario = false;
  bool traffic_light_unprotected_left_turn_scenario = false;
  bool traffic_light_unprotected_right_turn_scenario = false;
  if (traffic_light_scenario) {
    const auto& turn_type =
        reference_line_info.GetPathTurnType(traffic_light_overlap.start_s);
    const bool right_turn = (turn_type == hdmap::Lane::RIGHT_TURN);
    const bool left_turn = (turn_type == hdmap::Lane::LEFT_TURN);
    const double adc_distance_to_traffic_light =
        traffic_light_overlap.start_s - adc_front_edge_s;

    if (right_turn && red_light) {
      // check TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN
      const auto &scenario_config =
          config_map_[ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN].scenarioconfig.trafficlightunprotectedrightturnconfig;
      if (adc_distance_to_traffic_light <
          scenario_config.starttrafficlightscenariodistance) {
        traffic_light_unprotected_right_turn_scenario = true;
      }
    } else if (left_turn) {
      // check TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN
      const auto& scenario_config =
          config_map_[ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN].scenarioconfig
              .trafficlightunprotectedleftturnconfig;
      if (adc_distance_to_traffic_light <
          scenario_config.starttrafficlightscenariodistance) {
        traffic_light_unprotected_left_turn_scenario = true;
      }
    } else {
      // check TRAFFIC_LIGHT_PROTECTED
      const auto& scenario_config =
          config_map_[ScenarioConfig::TRAFFIC_LIGHT_PROTECTED].scenarioconfig
              .trafficlightprotectedconfig;
      if (adc_distance_to_traffic_light <
          scenario_config.starttrafficlightscenariodistance) {
        traffic_light_protected_scenario = true;
      }
    }
  }

  switch (current_scenario_->scenario_type()) {
    case ScenarioConfig::LANE_FOLLOW:
    case ScenarioConfig::PARK_AND_GO:
    case ScenarioConfig::PULL_OVER:
      if (traffic_light_unprotected_left_turn_scenario) {
        return ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN;
      } else if (traffic_light_unprotected_right_turn_scenario) {
        return ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN;
      } else if (traffic_light_protected_scenario) {
        return ScenarioConfig::TRAFFIC_LIGHT_PROTECTED;
      }
      break;
    case ScenarioConfig::BARE_INTERSECTION_UNPROTECTED:
    case ScenarioConfig::EMERGENCY_PULL_OVER:
    case ScenarioConfig::STOP_SIGN_PROTECTED:
    case ScenarioConfig::STOP_SIGN_UNPROTECTED:
    case ScenarioConfig::TRAFFIC_LIGHT_PROTECTED:
    case ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN:
    case ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN:
    case ScenarioConfig::YIELD_SIGN:
    case ScenarioConfig::VALET_PARKING:
      if (current_scenario_->GetStatus() !=
          Scenario::ScenarioStatus::STATUS_DONE) {
        return (apollo::planning::ScenarioConfig::ScenarioType)current_scenario_->scenario_type();
      }
      break;

    default:
      break;
  }

  return default_scenario_type_;
}

ScenarioConfig::ScenarioType ScenarioManager::SelectYieldSignScenario(
    const Frame& frame, const hdmap::PathOverlap& yield_sign_overlap) {
  const auto& scenario_config =
      config_map_[ScenarioConfig::YIELD_SIGN].scenarioconfig.yieldsignconfig;

  const auto& reference_line_info = frame.reference_line_info().front();
  const double adc_front_edge_s = reference_line_info.AdcSlBoundary().ends;
  const double adc_distance_to_yield_sign =
      yield_sign_overlap.start_s - adc_front_edge_s;
  ADEBUG << "adc_distance_to_yield_sign[" << adc_distance_to_yield_sign
         << "] yield_sign[" << yield_sign_overlap.object_id
         << "] yield_sign_overlap_start_s[" << yield_sign_overlap.start_s
         << "]";

  const bool yield_sign_scenario =
      (adc_distance_to_yield_sign > 0.0 &&
       adc_distance_to_yield_sign <=
           scenario_config.startyieldsignscenariodistance);

  switch (current_scenario_->scenario_type()) {
    case ScenarioConfig::LANE_FOLLOW:
    case ScenarioConfig::PARK_AND_GO:
    case ScenarioConfig::PULL_OVER:
      if (yield_sign_scenario) {
        return ScenarioConfig::YIELD_SIGN;
      }
      break;
    case ScenarioConfig::BARE_INTERSECTION_UNPROTECTED:
    case ScenarioConfig::EMERGENCY_PULL_OVER:
    case ScenarioConfig::STOP_SIGN_PROTECTED:
    case ScenarioConfig::STOP_SIGN_UNPROTECTED:
    case ScenarioConfig::TRAFFIC_LIGHT_PROTECTED:
    case ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN:
    case ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN:
    case ScenarioConfig::YIELD_SIGN:
    case ScenarioConfig::VALET_PARKING:
      if (current_scenario_->GetStatus() !=
          Scenario::ScenarioStatus::STATUS_DONE) {
        return (apollo::planning::ScenarioConfig::ScenarioType)current_scenario_->scenario_type();
      }
      break;
    default:
      break;
  }

  return default_scenario_type_;
}

ScenarioConfig::ScenarioType ScenarioManager::SelectBareIntersectionScenario(
    const Frame& frame, const hdmap::PathOverlap& pnc_junction_overlap) {
  const auto& reference_line_info = frame.reference_line_info().front();
  if (reference_line_info.GetIntersectionRightofWayStatus(
          pnc_junction_overlap)) {
    return default_scenario_type_;
  }

  const auto& scenario_config =
      config_map_[ScenarioConfig::BARE_INTERSECTION_UNPROTECTED].scenarioconfig.bareintersectionunprotectedconfig;

  const double adc_front_edge_s = reference_line_info.AdcSlBoundary().ends;
  const double adc_distance_to_pnc_junction =
      pnc_junction_overlap.start_s - adc_front_edge_s;
  ADEBUG << "adc_distance_to_pnc_junction[" << adc_distance_to_pnc_junction
         << "] pnc_junction[" << pnc_junction_overlap.object_id
         << "] pnc_junction_overlap_start_s[" << pnc_junction_overlap.start_s
         << "]";

  const bool bare_junction_scenario =
      (adc_distance_to_pnc_junction > 0.0 &&
       adc_distance_to_pnc_junction <=
           scenario_config.startbareintersectionscenariodistance);

  switch (current_scenario_->scenario_type()) {
    case ScenarioConfig::LANE_FOLLOW:
    case ScenarioConfig::PARK_AND_GO:
    case ScenarioConfig::PULL_OVER:
      if (bare_junction_scenario) {
        return ScenarioConfig::BARE_INTERSECTION_UNPROTECTED;
      }
      break;
    case ScenarioConfig::BARE_INTERSECTION_UNPROTECTED:
    case ScenarioConfig::EMERGENCY_PULL_OVER:
    case ScenarioConfig::STOP_SIGN_PROTECTED:
    case ScenarioConfig::STOP_SIGN_UNPROTECTED:
    case ScenarioConfig::TRAFFIC_LIGHT_PROTECTED:
    case ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN:
    case ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN:
    case ScenarioConfig::YIELD_SIGN:
    case ScenarioConfig::VALET_PARKING:
      if (current_scenario_->GetStatus() !=
          Scenario::ScenarioStatus::STATUS_DONE) {
        return (apollo::planning::ScenarioConfig::ScenarioType)current_scenario_->scenario_type();
      }
      break;
    default:
      break;
  }

  return default_scenario_type_;
}

ScenarioConfig::ScenarioType ScenarioManager::SelectValetParkingScenario(
    const Frame& frame) {
  const auto& scenario_config =
      config_map_[ScenarioConfig::VALET_PARKING].scenarioconfig.valetparkingconfig;

  // TODO(All) trigger valet parking by route message definition as of now
  double parking_spot_range_to_start =
      scenario_config.parkingspotrangetostart;
  if (scenario::valet_parking::ValetParkingScenario::IsTransferable(
          frame, parking_spot_range_to_start)) {
    return ScenarioConfig::VALET_PARKING;
  }

  return default_scenario_type_;
}

ScenarioConfig::ScenarioType ScenarioManager::SelectParkAndGoScenario(
    const Frame& frame) {
  bool park_and_go = false;
  const auto& scenario_config =
      config_map_[ScenarioConfig::PARK_AND_GO].scenarioconfig.parkandgoconfig;
  const auto vehicle_state_provider = injector_->vehicle_state();
  common::VehicleState vehicle_state = vehicle_state_provider->vehicle_state();
  auto adc_point = common::util::PointFactory::ToPointENU(vehicle_state);
  // TODO(SHU) might consider gear == GEAR_PARKING
  double adc_speed = vehicle_state_provider->linear_velocity();
  double s = 0.0;
  double l = 0.0;
  const double max_abs_speed_when_stopped =
      common::VehicleConfigHelper::Instance()
          ->GetConfig()
          .vehicleparam
          .maxabsspeedwhenstopped;

  hdmap::LaneInfoConstPtr lane;

  // check ego vehicle distance to destination
  const auto& routing = frame.local_view().routing;
  const auto& routing_end = *(routing->routingrequest.waypoint.rbegin());
  common::SLPoint dest_sl;
  const auto& reference_line_info = frame.reference_line_info().front();
  const auto& reference_line = reference_line_info.reference_line();
  reference_line.XYToSLPB(routing_end.pose, &dest_sl);
  const double adc_front_edge_s = reference_line_info.AdcSlBoundary().ends;

  const double adc_distance_to_dest = dest_sl.s - adc_front_edge_s;
  ADEBUG << "adc_distance_to_dest:" << adc_distance_to_dest;
  // if vehicle is static, far enough to destination and (off-lane or not on
  // city_driving lane)
  if (std::fabs(adc_speed) < max_abs_speed_when_stopped &&
      adc_distance_to_dest > scenario_config.mindisttodest &&
      (HDMapUtil::BaseMap().GetNearestLaneWithHeading(
           adc_point, 2.0, vehicle_state.heading, M_PI / 3.0, &lane, &s,
           &l) != 0 ||
       lane->lane().type != hdmap::Lane::CITY_DRIVING)) {
    park_and_go = true;
  }

  if (park_and_go) {
    return ScenarioConfig::PARK_AND_GO;
  }

  return default_scenario_type_;
}

void ScenarioManager::Observe(const Frame& frame) {
  // init first_encountered_overlap_map_
  first_encountered_overlap_map_.clear();
  const auto& reference_line_info = frame.reference_line_info().front();
  const auto& first_encountered_overlaps =
      reference_line_info.FirstEncounteredOverlaps();
  for (const auto& overlap : first_encountered_overlaps) {
    if (overlap.first == ReferenceLineInfo::PNC_JUNCTION ||
        overlap.first == ReferenceLineInfo::SIGNAL ||
        overlap.first == ReferenceLineInfo::STOP_SIGN ||
        overlap.first == ReferenceLineInfo::YIELD_SIGN) {
      first_encountered_overlap_map_[overlap.first] = overlap.second;
    }
  }
}

void ScenarioManager::Update(const common::TrajectoryPoint& ego_point,
                             const Frame& frame) {
  ACHECK(!frame.reference_line_info().empty());
  UNUSED(ego_point);
  Observe(frame);

  ScenarioDispatch(frame);
}

void ScenarioManager::ScenarioDispatch(const Frame& frame) {
  ACHECK(!frame.reference_line_info().empty());
  ScenarioConfig::ScenarioType scenario_type;

  int history_points_len = 0;
  if (injector_->learning_based_data() &&
      injector_->learning_based_data()->GetLatestLearningDataFrame()) {
    history_points_len = injector_->learning_based_data()
                                  ->GetLatestLearningDataFrame()
                                  ->adctrajectorypoint.size();
  }
  if ((planning_config_.learningmode == PlanningConfig::E2E ||
       planning_config_.learningmode == PlanningConfig::E2E_TEST) &&
      history_points_len >= FLAGS_min_past_history_points_len) {
    scenario_type = ScenarioDispatchLearning();
  } else {
    scenario_type = ScenarioDispatchNonLearning(frame);
  }

  ADEBUG << "select scenario: "
         << ScenarioConfig::ScenarioType_Name(scenario_type);

  // update PlanningContext
  UpdatePlanningContext(frame, scenario_type);

  if (current_scenario_->scenario_type() != scenario_type) {
    current_scenario_ = CreateScenario(scenario_type);
  }
}

ScenarioConfig::ScenarioType ScenarioManager::ScenarioDispatchLearning() {
  ////////////////////////////////////////
  // learning model scenario
  ScenarioConfig::ScenarioType scenario_type =
      ScenarioConfig::LEARNING_MODEL_SAMPLE;
  return scenario_type;
}

ScenarioConfig::ScenarioType ScenarioManager::ScenarioDispatchNonLearning(
    const Frame& frame) {
  ////////////////////////////////////////
  // default: LANE_FOLLOW
  ScenarioConfig::ScenarioType scenario_type = default_scenario_type_;

  ////////////////////////////////////////
  // Pad Msg scenario
  scenario_type = SelectPadMsgScenario(frame);

  if (scenario_type == default_scenario_type_) {
    // check current_scenario (not switchable)
    switch (current_scenario_->scenario_type()) {
      case ScenarioConfig::LANE_FOLLOW:
      case ScenarioConfig::PULL_OVER:
        break;
      case ScenarioConfig::BARE_INTERSECTION_UNPROTECTED:
      case ScenarioConfig::EMERGENCY_PULL_OVER:
      case ScenarioConfig::PARK_AND_GO:
      case ScenarioConfig::STOP_SIGN_PROTECTED:
      case ScenarioConfig::STOP_SIGN_UNPROTECTED:
      case ScenarioConfig::TRAFFIC_LIGHT_PROTECTED:
      case ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN:
      case ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN:
      case ScenarioConfig::VALET_PARKING:
      case ScenarioConfig::YIELD_SIGN:
        // must continue until finish
        if (current_scenario_->GetStatus() !=
            Scenario::ScenarioStatus::STATUS_DONE) {
          scenario_type = (apollo::planning::ScenarioConfig::ScenarioType)current_scenario_->scenario_type();
        }
        break;
      default:
        break;
    }
  }

  ////////////////////////////////////////
  // ParkAndGo / starting scenario
  if (scenario_type == default_scenario_type_) {
    if (FLAGS_enable_scenario_park_and_go) {
      scenario_type = SelectParkAndGoScenario(frame);
    }
  }

  ////////////////////////////////////////
  // intersection scenarios
  if (scenario_type == default_scenario_type_) {
    scenario_type = SelectInterceptionScenario(frame);
  }

  ////////////////////////////////////////
  // pull-over scenario
  if (scenario_type == default_scenario_type_) {
    if (FLAGS_enable_scenario_pull_over) {
      scenario_type = SelectPullOverScenario(frame);
    }
  }

  ////////////////////////////////////////
  // VALET_PARKING scenario
  if (scenario_type == default_scenario_type_) {
    scenario_type = SelectValetParkingScenario(frame);
  }

  return scenario_type;
}

bool ScenarioManager::IsBareIntersectionScenario(
    const ScenarioConfig::ScenarioType& scenario_type) {
  return (scenario_type == ScenarioConfig::BARE_INTERSECTION_UNPROTECTED);
}

bool ScenarioManager::IsStopSignScenario(
    const ScenarioConfig::ScenarioType& scenario_type) {
  return (scenario_type == ScenarioConfig::STOP_SIGN_PROTECTED ||
          scenario_type == ScenarioConfig::STOP_SIGN_UNPROTECTED);
}

bool ScenarioManager::IsTrafficLightScenario(
    const ScenarioConfig::ScenarioType& scenario_type) {
  return (
      scenario_type == ScenarioConfig::TRAFFIC_LIGHT_PROTECTED ||
      scenario_type == ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN ||
      scenario_type == ScenarioConfig::TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN);
}

bool ScenarioManager::IsYieldSignScenario(
    const ScenarioConfig::ScenarioType& scenario_type) {
  return (scenario_type == ScenarioConfig::YIELD_SIGN);
}

void ScenarioManager::UpdatePlanningContext(
    const Frame& frame, const ScenarioConfig::ScenarioType& scenario_type) {
  // BareIntersection scenario
  UpdatePlanningContextBareIntersectionScenario(frame, scenario_type);

  // EmergencyStop scenario
  UpdatePlanningContextEmergencyStopcenario(frame, scenario_type);

  // PullOver & EmergencyPullOver scenarios
  UpdatePlanningContextPullOverScenario(frame, scenario_type);

  // StopSign scenario
  UpdatePlanningContextStopSignScenario(frame, scenario_type);

  // TrafficLight scenario
  UpdatePlanningContextTrafficLightScenario(frame, scenario_type);

  // YieldSign scenario
  UpdatePlanningContextYieldSignScenario(frame, scenario_type);
}

// update: bare_intersection status in PlanningContext
void ScenarioManager::UpdatePlanningContextBareIntersectionScenario(
    const Frame& frame, const ScenarioConfig::ScenarioType& scenario_type) {
  auto *bare_intersection = &injector_->planning_context()
                                ->mutable_planning_status()
                                ->bareintersection;
  UNUSED(frame);
  if (!IsBareIntersectionScenario(scenario_type))
  {
    *bare_intersection = apollo_msgs::msg::ApolloplanningBareIntersectionStatus();
    return;
  }

  if (scenario_type == current_scenario_->scenario_type()) {
    return;
  }

  // set to first_encountered pnc_junction
  const auto map_itr =
      first_encountered_overlap_map_.find(ReferenceLineInfo::PNC_JUNCTION);
  if (map_itr != first_encountered_overlap_map_.end()) {
    bare_intersection->set__currentpncjunctionoverlapid(
        map_itr->second.object_id);
    ADEBUG << "Update PlanningContext with first_encountered pnc_junction["
           << map_itr->second.object_id << "] start_s["
           << map_itr->second.start_s << "]";
  }
}

// update: emergency_stop status in PlanningContext
void ScenarioManager::UpdatePlanningContextEmergencyStopcenario(
    const Frame& frame, const ScenarioConfig::ScenarioType& scenario_type) {
  auto *emergency_stop = &injector_->planning_context()
                             ->mutable_planning_status()
                             ->emergencystop;
  UNUSED(frame);
  if (scenario_type != ScenarioConfig::EMERGENCY_STOP)
  {
    *emergency_stop=apollo_msgs::msg::ApolloplanningEmergencyStopStatus();
  }
}

// update: stop_sign status in PlanningContext
void ScenarioManager::UpdatePlanningContextStopSignScenario(
    const Frame& frame, const ScenarioConfig::ScenarioType& scenario_type) {
  UNUSED(frame);
  if (!IsStopSignScenario(scenario_type))
  {
    injector_->planning_context()
        ->mutable_planning_status()
        ->stopsign = apollo_msgs::msg::ApolloplanningStopSignStatus();
    return;
  }

  if (scenario_type == current_scenario_->scenario_type()) {
    return;
  }

  // set to first_encountered stop_sign
  const auto map_itr =
      first_encountered_overlap_map_.find(ReferenceLineInfo::STOP_SIGN);
  if (map_itr != first_encountered_overlap_map_.end()) {
    injector_->planning_context()
        ->mutable_planning_status()->stopsign.set__currentstopsignoverlapid(map_itr->second.object_id);
    ADEBUG << "Update PlanningContext with first_encountered stop sign["
           << map_itr->second.object_id << "] start_s["
           << map_itr->second.start_s << "]";
  }
}

// update: traffic_light(s) status in PlanningContext
void ScenarioManager::UpdatePlanningContextTrafficLightScenario(
    const Frame& frame, const ScenarioConfig::ScenarioType& scenario_type) {
  if (!IsTrafficLightScenario(scenario_type)) {
    injector_->planning_context()
        ->mutable_planning_status()
        ->trafficlight = apollo_msgs::msg::ApolloplanningTrafficLightStatus();
    return;
  }

  if (scenario_type == current_scenario_->scenario_type()) {
    return;
  }

  // get first_encountered traffic_light
  std::string current_traffic_light_overlap_id;
  const auto map_itr =
      first_encountered_overlap_map_.find(ReferenceLineInfo::SIGNAL);
  if (map_itr != first_encountered_overlap_map_.end()) {
    current_traffic_light_overlap_id = map_itr->second.object_id;
  }

  if (current_traffic_light_overlap_id.empty()) {
    injector_->planning_context()
        ->mutable_planning_status()
        ->trafficlight = apollo_msgs::msg::ApolloplanningTrafficLightStatus();
    return;
  }

  // find all the traffic light at/within the same location/group
  const auto& reference_line_info = frame.reference_line_info().front();
  const std::vector<PathOverlap>& traffic_light_overlaps =
      reference_line_info.reference_line().map_path().signal_overlaps();
  auto traffic_light_overlap_itr = std::find_if(
      traffic_light_overlaps.begin(), traffic_light_overlaps.end(),
      [&current_traffic_light_overlap_id](const hdmap::PathOverlap& overlap) {
        return overlap.object_id == current_traffic_light_overlap_id;
      });
  if (traffic_light_overlap_itr == traffic_light_overlaps.end()) {
    injector_->planning_context()
        ->mutable_planning_status()
        ->trafficlight = apollo_msgs::msg::ApolloplanningTrafficLightStatus();

    return;
  }

  static constexpr double kTrafficLightGroupingMaxDist = 2.0;  // unit: m
  const double current_traffic_light_overlap_start_s =
      traffic_light_overlap_itr->start_s;
  for (const auto& traffic_light_overlap : traffic_light_overlaps) {
    const double dist =
        traffic_light_overlap.start_s - current_traffic_light_overlap_start_s;
    if (fabs(dist) <= kTrafficLightGroupingMaxDist) {
      injector_->planning_context()
          ->mutable_planning_status()->trafficlight.currenttrafficlightoverlapid.push_back(
              traffic_light_overlap.object_id);
      ADEBUG << "Update PlanningContext with first_encountered traffic_light["
             << traffic_light_overlap.object_id << "] start_s["
             << traffic_light_overlap.start_s << "]";
    }
  }
}

// update: yield_sign status in PlanningContext
void ScenarioManager::UpdatePlanningContextYieldSignScenario(
    const Frame& frame, const ScenarioConfig::ScenarioType& scenario_type) {
  if (!IsYieldSignScenario(scenario_type)) {
    injector_->planning_context()
        ->mutable_planning_status()
        ->yieldsign = apollo_msgs::msg::ApolloplanningYieldSignStatus();
    return;
  }

  if (scenario_type == current_scenario_->scenario_type()) {
    return;
  }

  // get first_encountered yield_sign
  std::string current_yield_sign_overlap_id;
  const auto map_itr =
      first_encountered_overlap_map_.find(ReferenceLineInfo::YIELD_SIGN);
  if (map_itr != first_encountered_overlap_map_.end()) {
    current_yield_sign_overlap_id = map_itr->second.object_id;
  }

  if (current_yield_sign_overlap_id.empty()) {
    injector_->planning_context()
        ->mutable_planning_status()
        ->yieldsign = apollo_msgs::msg::ApolloplanningYieldSignStatus();
    return;
  }

  // find all the yield_sign at/within the same location/group
  const auto& reference_line_info = frame.reference_line_info().front();
  const std::vector<PathOverlap>& yield_sign_overlaps =
      reference_line_info.reference_line().map_path().yield_sign_overlaps();
  auto yield_sign_overlap_itr = std::find_if(
      yield_sign_overlaps.begin(), yield_sign_overlaps.end(),
      [&current_yield_sign_overlap_id](const hdmap::PathOverlap& overlap) {
        return overlap.object_id == current_yield_sign_overlap_id;
      });
  if (yield_sign_overlap_itr == yield_sign_overlaps.end()) {
    injector_->planning_context()
        ->mutable_planning_status()
        ->yieldsign = apollo_msgs::msg::ApolloplanningYieldSignStatus();
    return;
  }

  static constexpr double kTrafficLightGroupingMaxDist = 2.0;  // unit: m
  const double current_yield_sign_overlap_start_s =
      yield_sign_overlap_itr->start_s;
  for (const auto& yield_sign_overlap : yield_sign_overlaps) {
    const double dist =
        yield_sign_overlap.start_s - current_yield_sign_overlap_start_s;
    if (fabs(dist) <= kTrafficLightGroupingMaxDist) {
      injector_->planning_context()
          ->mutable_planning_status()->yieldsign.currentyieldsignoverlapid.push_back(yield_sign_overlap.object_id);
      ADEBUG << "Update PlanningContext with first_encountered yield_sign["
             << yield_sign_overlap.object_id << "] start_s["
             << yield_sign_overlap.start_s << "]";
    }
  }
}

// update: pull_over status in PlanningContext
void ScenarioManager::UpdatePlanningContextPullOverScenario(
    const Frame& frame, const ScenarioConfig::ScenarioType& scenario_type) {
  auto *pull_over = &injector_->planning_context()
                         ->mutable_planning_status()
                         ->pullover;
  if (scenario_type == ScenarioConfig::PULL_OVER)
  {
    pull_over->set__pullovertype(PullOverStatus::PULL_OVER);
    pull_over->set__planpulloverpath(true);
    return;
  }
  else if (scenario_type == ScenarioConfig::EMERGENCY_PULL_OVER)
  {
    pull_over->set__pullovertype(PullOverStatus::EMERGENCY_PULL_OVER);
    return;
  }

  pull_over->set__planpulloverpath(false);

  // check pull_over_status left behind
  // keep it if close to destination, to keep stop fence
  const auto& pull_over_status =
      injector_->planning_context()->planning_status().pullover;
  if (pull_over_status.position != apollo_msgs::msg::ApollocommonPointENU() && pull_over_status.position.x !=0 &&
      pull_over_status.position.y != 0) {
    const auto& routing = frame.local_view().routing;
    if (routing->routingrequest.waypoint.size() >= 2) {
      // keep pull-over stop fence if destination not changed
      const auto& reference_line_info = frame.reference_line_info().front();
      const auto& reference_line = reference_line_info.reference_line();

      common::SLPoint dest_sl;
      const auto& routing_end =
          *(routing->routingrequest.waypoint.rbegin());
      reference_line.XYToSLPB(routing_end.pose, &dest_sl);

      common::SLPoint pull_over_sl;
      reference_line.XYToSLPB(pull_over_status.position, &pull_over_sl);

      static constexpr double kDestMaxDelta = 30.0;  // meter
      if (std::fabs(dest_sl.s - pull_over_sl.s) > kDestMaxDelta) {
        injector_->planning_context()
            ->mutable_planning_status()
            ->pullover = apollo_msgs::msg::ApolloplanningPullOverStatus();
      }
    }
  }
}

}  // namespace scenario
}  // namespace planning
}  // namespace apollo