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

#include "modules/common/vehicle_state/vehicle_state_provider.h"

#include <cmath>
#include "eigen3/Eigen/Core"
#include "absl/strings/str_cat.h"
#include "cyber/cyber.h"
#include "modules/common/configs/config_gflags.h"
#include "modules/common/math/euler_angles_zxy.h"
#include "modules/common/math/quaternion.h"
#include "modules/localization/common/localization_gflags.h"

namespace apollo {
namespace common {
DEFINE_bool(enable_map_reference_unify, true,
            "enable IMU data convert to map reference");
Status VehicleStateProvider::Update(
       apollo_msgs::msg::ApollolocalizationLocalizationEstimate localization,
     apollo_msgs::msg::ApollocanbusChassis chassis) {
  original_localization_ = localization;
  if (!ConstructExceptLinearVelocity(localization)) {
    std::string msg = absl::StrCat(
        "Fail to update because ConstructExceptLinearVelocity error.",
        "localization:\n"
        // , localization.DebugString()
        );
    return Status(ErrorCode::LOCALIZATION_ERROR, msg);
  }
if (localization.measurementtime!=0) {
    vehicle_state_.timestamp=(localization.measurementtime);
  } else if (localization.apolloheader.timestampsec!=0) {
    vehicle_state_.timestamp=(localization.apolloheader.timestampsec);
  } else if (
    chassis.apolloheader!=apollo::common::Header() && 
  chassis.apolloheader.timestampsec!=0 ) {
    AERROR << "Unable to use location timestamp for vehicle state. Use chassis "
              "time instead.";
    vehicle_state_.timestamp=(chassis.apolloheader.timestampsec );
  }
  if (chassis.gearlocation!=0) {
    vehicle_state_.gear=(chassis.gearlocation);
  } else {
    vehicle_state_.gear=(0);
  }

  if (chassis.speedmps) {
    vehicle_state_.linearvelocity=(chassis.speedmps);
    if (!FLAGS_reverse_heading_vehicle_state &&
        vehicle_state_.gear==(2)) {
      vehicle_state_.linearvelocity=(-vehicle_state_.linearvelocity);
    }
  }

  if (chassis.steeringpercentage!=0) {
    vehicle_state_.steeringpercentage=(chassis.steeringpercentage);
  }

  static constexpr double kEpsilon = 1e-6;
  if (std::abs(vehicle_state_.linearvelocity) < kEpsilon) {
    vehicle_state_.kappa=(0.0);
  } else {
    vehicle_state_.kappa=(vehicle_state_.angularvelocity /
                             vehicle_state_.linearvelocity);
  }

  vehicle_state_.drivingmode=(chassis.drivingmode);

  return Status::OK();
}

bool VehicleStateProvider::ConstructExceptLinearVelocity(
      apollo_msgs::msg::ApollolocalizationLocalizationEstimate localization) {
  if (localization.pose==apollo_msgs::msg::ApollolocalizationPose()) {
    AERROR << "Invalid localization input.";
    return false;
  }

  // skip localization update when it is in use_navigation_mode.
  if (FLAGS_use_navigation_mode) {
    ADEBUG << "Skip localization update when it is in use_navigation_mode.";
    return true;
  }

  vehicle_state_.pose=localization.pose;
  if (localization.pose.position.x!=0) {
    vehicle_state_.x=(localization.pose.position.x);
    vehicle_state_.y=(localization.pose.position.y);
    vehicle_state_.z=(localization.pose.position.z);
  }

  const auto &orientation = localization.pose.orientation;

  if (localization.pose.heading) {
    vehicle_state_.heading=(localization.pose.heading);
  } else {
    vehicle_state_.heading=(
        math::QuaternionToHeading(orientation.qw, orientation.qx,
                                  orientation.qy, orientation.qz));
  }

  if (FLAGS_enable_map_reference_unify) {

    if (localization.pose.angularvelocityvrf==apollo_msgs::msg::ApollocommonPoint3D()) {
      AERROR << "localization->pose().has_angular_velocity_vrf() must be true "
                "when FLAGS_enable_map_reference_unify is true.";
      return false;
    }
    vehicle_state_.angularvelocity=(
        localization.pose.angularvelocityvrf.z);
      
    if (localization.pose.linearaccelerationvrf==apollo_msgs::msg::ApollocommonPoint3D()) {
      AERROR << "localization->pose().has_linear_acceleration_vrf() must be "
                "true when FLAGS_enable_map_reference_unify is true.";
      return false;
    }
    vehicle_state_.linearacceleration=(
        localization.pose.linearaccelerationvrf.y);
  } else {
     
    if (localization.pose.angularvelocity==apollo_msgs::msg::ApollocommonPoint3D()) {
      AERROR << "localization->pose() has no angular velocity.";
      return false;
    }
    vehicle_state_.angularvelocity=(
        localization.pose.angularvelocity.z);

    if (localization.pose.linearacceleration==apollo_msgs::msg::ApollocommonPoint3D()) {
      AERROR << "localization->pose() has no linear acceleration.";
      return false;
    }
    vehicle_state_.linearacceleration=(
        localization.pose.linearacceleration.y);
  }

  if (localization.pose.eulerangles.x) {
    vehicle_state_.roll=(localization.pose.eulerangles.x);
    vehicle_state_.pitch=(localization.pose.eulerangles.y);
    vehicle_state_.yaw=(localization.pose.eulerangles.z);
  } else {
    math::EulerAnglesZXYd euler_angle(orientation.qw, orientation.qx,
                                      orientation.qy, orientation.qz);
    vehicle_state_.roll=(euler_angle.roll());
    vehicle_state_.pitch=(euler_angle.pitch());
    vehicle_state_.yaw=(euler_angle.yaw());
  }

  return true;
}


double VehicleStateProvider::x() const {
  return vehicle_state_.x;
}

double VehicleStateProvider::y() const {
  return vehicle_state_.y;
}

double VehicleStateProvider::z() const {
  return vehicle_state_.z;
}

double VehicleStateProvider::roll() const {
  return vehicle_state_.roll;
}

double VehicleStateProvider::pitch() const {
  return vehicle_state_.pitch;
}

double VehicleStateProvider::yaw() const {
  return vehicle_state_.yaw;
}

double VehicleStateProvider::heading() const {
  return vehicle_state_.heading;
}

double VehicleStateProvider::kappa() const {
  return vehicle_state_.kappa;
}

double VehicleStateProvider::linear_velocity() const {
  return vehicle_state_.linearvelocity;
}

double VehicleStateProvider::angular_velocity() const {
  return vehicle_state_.angularvelocity;
}

double VehicleStateProvider::linear_acceleration() const {
  return vehicle_state_.linearacceleration;
}

double VehicleStateProvider::gear() const {
  return vehicle_state_.gear;
}

double VehicleStateProvider::steering_percentage() const {
  return vehicle_state_.steeringpercentage;
}

double VehicleStateProvider::timestamp() const {
  return vehicle_state_.timestamp;
}

const localization::Pose &VehicleStateProvider::pose() const {
  return vehicle_state_.pose;
}

const localization::Pose &VehicleStateProvider::original_pose() const {
  return original_localization_.pose;
}

void VehicleStateProvider::set_linear_velocity(const double linear_velocity) {
  vehicle_state_.linearvelocity=(linear_velocity);
}

const VehicleState &VehicleStateProvider::vehicle_state() const {
  return vehicle_state_;
}

math::Vec2d VehicleStateProvider::EstimateFuturePosition(const double t) const {
  Eigen::Vector3d vec_distance(0.0, 0.0, 0.0);
  double v = vehicle_state_.linearvelocity;
  // Predict distance travel vector
  if (std::fabs(vehicle_state_.angularvelocity) < 0.0001) {
    vec_distance[0] = 0.0;
    vec_distance[1] = v * t;
  } else {
    vec_distance[0] = -v / vehicle_state_.angularvelocity *
                      (1.0 - std::cos(vehicle_state_.angularvelocity * t));
    vec_distance[1] = std::sin(vehicle_state_.angularvelocity * t) * v /
                      vehicle_state_.angularvelocity;
  }

  // If we have rotation information, take it into consideration.
  if (vehicle_state_.pose.orientation.qx!=0) {
    const auto &orientation = vehicle_state_.pose.orientation;
    Eigen::Quaternion<double> quaternion(orientation.qw, orientation.qx,
                                         orientation.qy, orientation.qz);
    Eigen::Vector3d pos_vec(vehicle_state_.x, vehicle_state_.y,
                            vehicle_state_.z);
    const Eigen::Vector3d future_pos_3d =
        quaternion.toRotationMatrix() * vec_distance + pos_vec;
    return math::Vec2d(future_pos_3d[0], future_pos_3d[1]);
  }

  // If no valid rotation information provided from localization,
  // return the estimated future position without rotation.
  return math::Vec2d(vec_distance[0] + vehicle_state_.x,
                     vec_distance[1] + vehicle_state_.y);
}

math::Vec2d VehicleStateProvider::ComputeCOMPosition(
    const double rear_to_com_distance) const {
  // set length as distance between rear wheel and center of mass.
  Eigen::Vector3d v;
  if ((FLAGS_state_transform_to_com_reverse &&
       vehicle_state_.gear == 2) ||
      (FLAGS_state_transform_to_com_drive &&
       vehicle_state_.gear == 1)) {
    v << 0.0, rear_to_com_distance, 0.0;
  } else {
    v << 0.0, 0.0, 0.0;
  }
  Eigen::Vector3d pos_vec(vehicle_state_.x, vehicle_state_.y,
                          vehicle_state_.z);
  // Initialize the COM position without rotation
  Eigen::Vector3d com_pos_3d = v + pos_vec;

  // If we have rotation information, take it into consideration.
  if (vehicle_state_.pose.orientation.qx!=0) {
    const auto &orientation = vehicle_state_.pose.orientation;
    Eigen::Quaternion<double> quaternion(orientation.qw, orientation.qx,
                                         orientation.qy, orientation.qz);
    // Update the COM position with rotation
    com_pos_3d = quaternion.toRotationMatrix() * v + pos_vec;
  }
  return math::Vec2d(com_pos_3d[0], com_pos_3d[1]);
}

}  // namespace common
}  // namespace apollo