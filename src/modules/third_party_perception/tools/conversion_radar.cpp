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

/**
 * @file
 */

#include <cmath>
#include <iostream>
#include <map>
#include <vector>

#include "cyber/common/log.h"
#include "modules/common/configs/config_gflags.h"
#include "modules/common/util/map_util.h"
#include "modules/third_party_perception/common/third_party_perception_gflags.h"
#include "modules/third_party_perception/common/third_party_perception_util.h"
#include "modules/third_party_perception/tools/conversion_radar.h"

/**
 * @namespace apollo::third_party_perception::conversion_radar
 * @brief apollo::third_party_perception
 */
namespace apollo {
namespace third_party_perception {
namespace conversion_radar {

using apollo_msgs::msg::ApollocanbusChassis;
using apollo::drivers::DelphiESR;
using apollo::localization::LocalizationEstimate;
using apollo_msgs::msg::ApolloperceptionPerceptionObstacle;
using apollo::perception::PerceptionObstacles;
using Point = apollo::common::Point3D;
using RadarObstacles = apollo_msgs::msg::ApollothirdPartyPerceptionRadarObstacles;

RadarObstacles
ContiToRadarObstacles(
    const apollo::drivers::ContiRadar &conti_radar,
    const apollo::localization::LocalizationEstimate &localization,
    const RadarObstacles &last_radar_obstacles, const ApollocanbusChassis &chassis)
{
  RadarObstacles obstacles;

  const double last_timestamp = last_radar_obstacles.apolloheader.timestampsec;
  const double current_timestamp = conti_radar.apolloheader.timestampsec;

  const auto adc_pos = localization.pose.position;
  const auto adc_quaternion = localization.pose.orientation;
  const double adc_theta = GetAngleFromQuaternion(adc_quaternion);

  for (size_t index = 0; index < conti_radar.contiobs.size(); ++index) {
    const auto& contiobs = conti_radar.contiobs[index];

    RadarObstacle rob;

    rob.set__id(contiobs.obstacleid);
    rob.set__rcs(contiobs.rcs);
    rob.set__length(GetDefaultObjectLength(4));
    rob.set__width(GetDefaultObjectWidth(4));
    rob.set__height(3.0);

    Point relative_pos_sl;

    // TODO(QiL): load the radar configs here
    relative_pos_sl.set__x(contiobs.longitudedist);
    relative_pos_sl.set__y(contiobs.lateraldist);
    rob.relativeposition=(relative_pos_sl);

    Point relative_pos_xy = SLtoXY(relative_pos_sl, adc_theta);
    Point absolute_pos;
    absolute_pos.set__x(adc_pos.x + relative_pos_xy.x);
    absolute_pos.set__y(adc_pos.y + relative_pos_xy.y);
    absolute_pos.set__z(adc_pos.z);
    rob.absoluteposition=(absolute_pos);

    rob.relativevelocity.set__x(contiobs.longitudevel);
    rob.relativevelocity.set__y(contiobs.lateralvel);

    const auto iter = last_radar_obstacles.radarobstacle.begin()+(index);
    Point absolute_vel;
    if (iter == last_radar_obstacles.radarobstacle.end()) {
      rob.set__count(0);
      rob.set__movable(false);
      rob.set__movingframescount(0);
      absolute_vel.set__x(0.0);
      absolute_vel.set__y(0.0);
      absolute_vel.set__z(0.0);
    } else if (!FLAGS_use_navigation_mode) {
      rob.set__count(iter->data.count + 1);
      rob.set__movable(iter->data.movable);
      absolute_vel.set__x(
          (absolute_pos.x - iter->data.absoluteposition.x) /
          (current_timestamp - last_timestamp));
      absolute_vel.set__y(
          (absolute_pos.y - iter->data.absoluteposition.y) /
          (current_timestamp - last_timestamp));
      absolute_vel.set__z(0.0);
      double v_heading = std::atan2(absolute_vel.y, absolute_vel.x);
      double heading_diff = HeadingDifference(v_heading, rob.theta);
      if (heading_diff < FLAGS_movable_heading_threshold &&
          Speed(absolute_vel) * std::cos(heading_diff) >
              FLAGS_movable_speed_threshold) {
        rob.set__movingframescount(iter->data.movingframescount + 1);
      } else {
        rob.set__movingframescount(0);
      }
    } else {
      rob.set__count(iter->data.count + 1);
      rob.set__movable(iter->data.movable);
      absolute_vel.set__x(contiobs.longitudevel + chassis.speedmps);
      absolute_vel.set__y(contiobs.lateralvel);
      absolute_vel.set__z(0.0);

      // Overwrite heading here with relative headings
      // TODO(QiL) : refind the logic here.
      if (contiobs.clusterortrack == 0) {
        rob.set__theta(contiobs.oritationangle / 180 * M_PI);
      } else {
        // in FLU
        rob.set__theta(std::atan2(rob.relativeposition.x,
                                 rob.relativeposition.y));
      }
    }

    rob.absolutevelocity=(absolute_vel);

    if (rob.movingframescount >= FLAGS_movable_frames_count_threshold) {
      rob.set__movable(true);
    }

    apollo::common::util::InsertAndDeleteExisting(obstacles.radarobstacle, (int)index, rob);

  }

  obstacles.apolloheader=(conti_radar.apolloheader);
  return obstacles;
}

RadarObstacles DelphiToRadarObstacles(
    const DelphiESR& delphi_esr, const LocalizationEstimate& localization,
    const RadarObstacles& last_radar_obstacles) {
  RadarObstacles obstacles;

  const double last_timestamp = last_radar_obstacles.apolloheader.timestampsec;
  const double current_timestamp = delphi_esr.apolloheader.timestampsec;

  // assign motion power from 540
  std::vector<apollo::drivers::Motionpower>
      motionpowers(64);
  for (const auto& esr_trackmotionpower_540 :
       delphi_esr.esrtrackmotionpower540) {
    if (esr_trackmotionpower_540.cantxtrackcanidgroup==0) {
      AERROR << "ESR track motion power 540 does not have "
                "can_tx_track_can_id_group()";
      continue;
    }
    const int can_tx_track_can_id_group =
        esr_trackmotionpower_540.cantxtrackcanidgroup;
    const int can_tx_track_motion_power_size =
        esr_trackmotionpower_540.cantxtrackmotionpower.size();
    for (int index = 0; index < (can_tx_track_can_id_group < 9 ? 7 : 1) &&
                        index < can_tx_track_motion_power_size;
         ++index) {
      std::size_t motion_powers_index = can_tx_track_can_id_group * 7 + index;
      if (motion_powers_index < motionpowers.size()) {
        motionpowers[index] = (esr_trackmotionpower_540.cantxtrackmotionpower[index]);
      }
    }
  }

  const auto adc_pos = localization.pose.position;
  const auto adc_quaternion = localization.pose.orientation;
  const double adc_theta = GetAngleFromQuaternion(adc_quaternion);

  for (size_t index = 0; index < delphi_esr.esrtrack01500.size() &&
                         index < motionpowers.size();
       ++index)
  {
    const auto &data_500 = delphi_esr.esrtrack01500.at(index);

    // ignore invalid target
    if (data_500.cantxtrackstatus ==
        apollo::drivers::Esr_track01_500::CAN_TX_TRACK_STATUS_NO_TARGET) {
      continue;
    }

    RadarObstacle rob;

    rob.set__id(index);
    rob.set__rcs(static_cast<double>(motionpowers[index].cantxtrackpower) -
                10.0);
    rob.set__length(GetDefaultObjectLength(4));
    rob.set__width(GetDefaultObjectWidth(4));
    rob.set__height(3.0);

    const double range = data_500.cantxtrackrange;
    const double angle = data_500.cantxtrackangle * M_PI / 180.0;
    Point relative_pos_sl;
    relative_pos_sl.set__x(range * std::cos(angle) +
                          FLAGS_radar_pos_adjust +  // offset: imu <-> mobileye
                          rob.length /
                              2.0);  // make x the middle point of the vehicle
    relative_pos_sl.set__y(range * std::sin(angle));
    rob.relativeposition=(relative_pos_sl);

    Point relative_pos_xy = SLtoXY(relative_pos_sl, adc_theta);
    Point absolute_pos;
    absolute_pos.set__x(adc_pos.x + relative_pos_xy.x);
    absolute_pos.set__y(adc_pos.y + relative_pos_xy.y);
    absolute_pos.set__z(adc_pos.z);
    rob.absoluteposition=(absolute_pos);

    double theta = GetNearestLaneHeading(rob.absoluteposition);
    rob.set__theta(theta);

    const double range_vel = data_500.cantxtrackrangerate;
    const double lateral_vel = data_500.cantxtracklatrate;
    rob.relativevelocity.set__x(range_vel * std::cos(angle) -
                                           lateral_vel * std::sin(angle));
    rob.relativevelocity.set__y(range_vel * std::sin(angle) +
                                           lateral_vel * std::cos(angle));

    const auto iter = last_radar_obstacles.radarobstacle.begin()+(index);
    Point absolute_vel;
    if (iter == last_radar_obstacles.radarobstacle.end()) {
      rob.set__count(0);
      rob.set__movable(false);
      rob.set__movingframescount(0);
      absolute_vel.set__x(0.0);
      absolute_vel.set__y(0.0);
      absolute_vel.set__z(0.0);
    } else {
      rob.set__count(iter->data.count + 1);
      rob.set__movable(iter->data.movable);
      absolute_vel.set__x(
          (absolute_pos.x - iter->data.absoluteposition.x) /
          (current_timestamp - last_timestamp));
      absolute_vel.set__y(
          (absolute_pos.y - iter->data.absoluteposition.y) /
          (current_timestamp - last_timestamp));
      absolute_vel.set__z(0.0);
      double v_heading = std::atan2(absolute_vel.y, absolute_vel.x);
      double heading_diff = HeadingDifference(v_heading, rob.theta);
      if (heading_diff < FLAGS_movable_heading_threshold &&
          Speed(absolute_vel) * std::cos(heading_diff) >
              FLAGS_movable_speed_threshold) {
        rob.set__movingframescount(iter->data.movingframescount + 1);
      } else {
        rob.set__movingframescount(0);
      }
    }

    rob.absolutevelocity=(absolute_vel);

    if (rob.movingframescount >= FLAGS_movable_frames_count_threshold) {
      rob.set__movable(true);
    }
    apollo::common::util::InsertAndDeleteExisting(obstacles.radarobstacle, (int)index, rob);
  }

  obstacles.apolloheader=(delphi_esr.apolloheader);
  return obstacles;
}

PerceptionObstacles RadarObstaclesToPerceptionObstacles(
    const RadarObstacles& radar_obstacles) {
  PerceptionObstacles obstacles;

  for (const auto& iter : radar_obstacles.radarobstacle) {
    auto& pob = obstacles.perceptionobstacle.emplace_back();
    const auto& radar_obstacle = iter.data;

    pob.set__id(radar_obstacle.id + FLAGS_radar_id_offset);

    pob.set__type( apollo::perception::PerceptionObstacle::VEHICLE);
    pob.set__length(radar_obstacle.length);
    pob.set__width(radar_obstacle.width);
    pob.set__height(radar_obstacle.height);

    if (!FLAGS_use_navigation_mode) {
      pob.position=(radar_obstacle.absoluteposition);
      pob.velocity=(radar_obstacle.absolutevelocity);
    } else {
      pob.position=(radar_obstacle.relativeposition);
      pob.velocity=(radar_obstacle.relativevelocity);
    }

    pob.set__theta(radar_obstacle.theta);

    // create polygon
    FillPerceptionPolygon(pob, pob.position.x, pob.position.y,
                          pob.position.z, pob.length, pob.width,
                          pob.height, pob.theta);
    pob.set__confidence(0.01);
  }

  obstacles.apolloheader=(radar_obstacles.apolloheader);

  return obstacles;
}

}  // namespace conversion_radar
}  // namespace third_party_perception
}  // namespace apollo
