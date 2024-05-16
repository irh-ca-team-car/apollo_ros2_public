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

#include "modules/third_party_perception/common/third_party_perception_gflags.h"
#include "modules/third_party_perception/common/third_party_perception_util.h"
#include "modules/third_party_perception/tools/conversion_base.h"
#include "modules/third_party_perception/tools/conversion_mobileye.h"

/**
 * @namespace apollo::third_party_perception::conversion_mobileye
 * @brief apollo::third_party_perception
 */
namespace apollo {
namespace third_party_perception {
namespace conversion_mobileye {

  using Chassis =  apollo_msgs::msg::ApollocanbusChassis;
  using apollo::drivers::Mobileye;
  using apollo::localization::LocalizationEstimate;
  using PerceptionObstacle = apollo_msgs::msg::ApolloperceptionPerceptionObstacle;
  using apollo::perception::PerceptionObstacles;
  using Point = apollo::common::Point3D;

  PerceptionObstacles MobileyeToPerceptionObstacles(
      const Mobileye &mobileye, const LocalizationEstimate &localization,
      const Chassis &chassis)
  {
    PerceptionObstacles obstacles;
    // retrieve position and velocity of the main vehicle from the localization
    // position

    obstacles.apolloheader=(mobileye.apolloheader);

    // Fullfill lane_type information
    std::int32_t mob_left_lane_type = mobileye.lka768.lanetype;
    std::int32_t mob_right_lane_type = mobileye.lka768.lanetype;

    obstacles.lanemarker.leftlanemarker.set__lanetype(
        conversion_base::lane_conversion_map[mob_left_lane_type]);
    obstacles.lanemarker.rightlanemarker.set__lanetype(
        conversion_base::lane_conversion_map[mob_right_lane_type]);

    obstacles.lanemarker.leftlanemarker.set__quality(
        mobileye.lka766.quality / 4.0);
    obstacles.lanemarker.leftlanemarker.set__modeldegree(
        mobileye.lka766.modeldegree);

    // Convert everything to FLU
    obstacles.lanemarker.leftlanemarker.set__c0position(
        -mobileye.lka766.position);
    obstacles.lanemarker
        .leftlanemarker
        .set__c1headingangle(-mobileye.lka767.headingangle);
    obstacles.lanemarker.leftlanemarker.set__c2curvature(
        -mobileye.lka766.curvature);
    obstacles.lanemarker
        .leftlanemarker
        .set__c3curvaturederivative(-mobileye.lka766.curvaturederivative);
    obstacles.lanemarker.leftlanemarker.set__viewrange(
        mobileye.lka767.viewrange);

    obstacles.lanemarker.rightlanemarker.set__quality(
        mobileye.lka768.quality / 4.0);
    obstacles.lanemarker
        .rightlanemarker
        .set__modeldegree(mobileye.lka768.modeldegree);
    obstacles.lanemarker.rightlanemarker.set__c0position(
        -mobileye.lka768.position);
    obstacles.lanemarker
        .rightlanemarker
        .set__c1headingangle(-mobileye.lka769.headingangle);
    obstacles.lanemarker
        .rightlanemarker
        .set__c2curvature(-mobileye.lka768.curvature);
    obstacles.lanemarker
        .rightlanemarker
        .set__c3curvaturederivative(-mobileye.lka768.curvaturederivative);
    obstacles.lanemarker.rightlanemarker.set__viewrange(
        mobileye.lka769.viewrange);

    double adc_x = localization.pose.position.x;
    double adc_y = localization.pose.position.y;
    double adc_z = localization.pose.position.z;
    // heading
    auto adc_quaternion = localization.pose.orientation;
    double adc_theta = GetAngleFromQuaternion(adc_quaternion);
    // velocity
    double adc_vx = localization.pose.linearvelocity.x;
    double adc_vy = localization.pose.linearvelocity.y;
    double adc_velocity = Speed(adc_vx, adc_vy);

    for (size_t index = 0; index < (size_t)mobileye.details738.numobstacles &&
                        index < mobileye.details739.size();
         ++index)
    {
      auto &mob = obstacles.perceptionobstacle.emplace_back();
      const auto &data_739 = mobileye.details739.at(index);
      int mob_id = data_739.obstacleid + FLAGS_mobileye_id_offset;
      double mob_x = data_739.obstacleposx;
      double mob_y = -data_739.obstacleposy;
      double mob_vel_x = data_739.obstaclerelvelx;
      int mob_type = data_739.obstacletype;

      double mob_l = 0.0;
      double mob_w = 0.0;
      if (mobileye.details73a.size() <= index)
      {
        mob_l = GetDefaultObjectLength(mob_type);
        mob_w = GetDefaultObjectWidth(mob_type);
      } else {
      if (mobileye.details73a.at(index).obstaclelength >
          FLAGS_max_mobileye_obstacle_length) {
        mob_l = GetDefaultObjectLength(mob_type);
      } else {
        mob_l = mobileye.details73a.at(index).obstaclelength;
      }

      if (mobileye.details73a.at(index).obstaclewidth >
          FLAGS_max_mobileye_obstacle_width) {
        mob_w = GetDefaultObjectWidth(mob_type);
      } else {
        mob_w = mobileye.details73a.at(index).obstaclewidth;
      }
    }

    mob_x += FLAGS_mobileye_pos_adjust;  // offset: imu <-> mobileye
    mob_x += mob_l / 2.0;  // make x the middle point of the vehicle.

    Point xy_point = SLtoXY(mob_x, mob_y, adc_theta);

    // TODO(QiL) : Clean this up after data collection and validation
    double converted_x = 0.0;
    double converted_y = 0.0;
    double converted_speed = 0.0;
    double converted_vx = 0.0;
    double converted_vy = 0.0;

    double path_c1 = 0.0;
    double path_c2 = 0.0;
    double path_c3 = 0.0;

    if (obstacles.lanemarker.leftlanemarker.quality >=
        obstacles.lanemarker.rightlanemarker.quality) {
      path_c1 = obstacles.lanemarker.leftlanemarker.c1headingangle;
      path_c2 = obstacles.lanemarker.leftlanemarker.c2curvature;
      path_c3 =
          obstacles.lanemarker.leftlanemarker.c3curvaturederivative;
    } else {
      path_c1 = obstacles.lanemarker.rightlanemarker.c1headingangle;
      path_c2 = obstacles.lanemarker.rightlanemarker.c2curvature;
      path_c3 =
          obstacles.lanemarker.rightlanemarker.c3curvaturederivative;
    }

    if (!FLAGS_use_navigation_mode) {
      converted_x = adc_x + xy_point.x;
      converted_y = adc_y + xy_point.y;
      mob.set__theta(GetNearestLaneHeading(converted_x, converted_y, adc_z));
      converted_speed = adc_velocity + mob_vel_x;
      converted_vx = converted_speed * std::cos(mob.theta);
      converted_vy = converted_speed * std::sin(mob.theta);
    } else {
      converted_x = mobileye.details739.at(index).obstacleposx +
                    FLAGS_mobileye_pos_adjust;
      converted_y = mobileye.details739.at(index).obstacleposy;
      converted_vx = mob_vel_x + chassis.speedmps;
      converted_vy = 0.0;

      if (mobileye.details73b.size() <= index) {
        mob.set__theta(0.0);
      } else {
        if (!FLAGS_overwrite_mobileye_theta) {
          mob.set__theta(mobileye.details73b.at(index).obstacleangle / 180 *
                         M_PI);
        } else {
          double nearest_lane_heading =
              converted_vx > 0
                  ? std::atan2(3 * path_c3 * converted_x * converted_x +
                                   2 * path_c2 * converted_x + path_c1,
                               1)
                  : std::atan2(3 * path_c3 * converted_x * converted_x +
                                   2 * path_c2 * converted_x + path_c1,
                               1) +
                        M_PI;
          AINFO << "nearest lane heading is" << nearest_lane_heading;
          mob.set__theta(nearest_lane_heading);
        }
      }
    }

    mob.set__id(mob_id);
    mob.position.set__x(converted_x);
    mob.position.set__y(converted_y);

    switch (mob_type) {
      case 0:
      case 1: {
        mob.set__type(apollo::perception::PerceptionObstacle::VEHICLE);  // VEHICLE
        break;
      }
      case 2:
      case 4: {
        mob.set__type(apollo::perception::PerceptionObstacle::BICYCLE); // BIKE
        break;
      }
      case 3: {
        mob.set__type(apollo::perception::PerceptionObstacle::PEDESTRIAN); // PED
        break;
      }
      default: {
        mob.set__type(apollo::perception::PerceptionObstacle::UNKNOWN); // UNKNOWN
        break;
      }
    }

    mob.velocity.set__x(converted_vx);
    mob.velocity.set__y(converted_vy);
    mob.set__length(mob_l);
    mob.set__width(mob_w);
    mob.set__height(FLAGS_default_height);

    mob.polygonpoint.clear();

    // create polygon
    FillPerceptionPolygon(mob, mob.position.x, mob.position.y,
                          mob.position.z, mob.length, mob.width,
                          mob.height, mob.theta);

    mob.set__confidence(0.5);
  }

  return obstacles;
}

}  // namespace conversion_mobileye
}  // namespace third_party_perception
}  // namespace apollo
