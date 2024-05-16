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
#include "modules/perception/onboard/msg_serializer/msg_serializer.h"

#include <limits>

#include "cyber/cyber.h"

#include "modules/perception/onboard/common_flags/common_flags.h"
#include "modules/prediction/proto/feature.pb.h"

using Clock = apollo::cyber::Clock;

namespace {
constexpr float kFloatMax = std::numeric_limits<float>::max();
}  // namespace

namespace apollo {
namespace perception {
namespace onboard {

bool MsgSerializer::SerializeMsg(double timestamp, uint64_t lidar_timestamp,
                                 int seq_num,
                                 const std::vector<base::ObjectPtr> &objects,
                                 const apollo::common::ErrorCode &error_code,
                                 PerceptionObstacles *obstacles) {
  UNUSED(seq_num);
  //ACHECK(timestamp > 0);
  ::apollo::common::Header header;
  header.timestampsec=(int)lidar_timestamp;

  obstacles->errorcode=error_code;
  for (const auto &obj : objects) {
    apollo_msgs::msg::ApolloperceptionPerceptionObstacle obstacle; //= obstacles->add_perception_obstacle();
    if (!ConvertObjectToPb(obj, &obstacle)) {
      AERROR_EVERY(60000) << "ConvertObjectToPb failed, Object:" << obj->ToString();
      return false;
    }
    
    obstacles->perceptionobstacle.push_back(obstacle);
    
  }
  return true;
}

bool MsgSerializer::ConvertObjectToPb(const base::ObjectPtr &object_ptr,
                                      apollo_msgs::msg::ApolloperceptionPerceptionObstacle *pb_msg) {
  if (object_ptr == nullptr || pb_msg == nullptr) {
    return false;
  }

  pb_msg->id=object_ptr->track_id;
  pb_msg->theta=object_ptr->theta;

  apollo::common::Point3D *obj_center = &pb_msg->position;
  obj_center->x=object_ptr->center[0];
  obj_center->y=object_ptr->center[1];
  obj_center->z=object_ptr->center[2];

  apollo::common::Point3D *obj_velocity = &pb_msg->velocity;
  obj_velocity->x=object_ptr->velocity[0];
  obj_velocity->y=object_ptr->velocity[1];
  obj_velocity->z=object_ptr->velocity[2];

  apollo::common::Point3D *obj_acceleration = &pb_msg->acceleration;
  obj_acceleration->x=object_ptr->acceleration[0];
  obj_acceleration->y=object_ptr->acceleration[1];
  obj_acceleration->z=object_ptr->acceleration[2];

  pb_msg->length=object_ptr->size[0];
  pb_msg->width=object_ptr->size[1];
  pb_msg->height=object_ptr->size[2];

  for (size_t i = 0; i < object_ptr->polygon.size(); ++i) {
    auto &pt = object_ptr->polygon.at(i);
    apollo::common::Point3D p; //= pb_msg->add_polygon_point();
    p.x=pt.x;
    p.y=pt.y;
    p.z=pt.z;
    
    pb_msg->polygonpoint.push_back(p);
    
  }

  if (FLAGS_obs_benchmark_mode) {
    for (auto &point : object_ptr->lidar_supplement.cloud.points()) {
      pb_msg->pointcloud.push_back(point.x);
      pb_msg->pointcloud.push_back(point.y);
      pb_msg->pointcloud.push_back(point.z);
    }
  }

  apollo::common::Point3D *obj_anchor_point = &pb_msg->anchorpoint;
  obj_anchor_point->x=object_ptr->anchor_point[0];
  obj_anchor_point->y=object_ptr->anchor_point[1];
  obj_anchor_point->z=object_ptr->anchor_point[2];

  BBox2D *obj_bbox2d = &pb_msg->bbox2d;
  const base::BBox2DF &box = object_ptr->camera_supplement.box;
  obj_bbox2d->xmin=box.xmin;
  obj_bbox2d->ymin=box.ymin;
  obj_bbox2d->xmax=box.xmax;
  obj_bbox2d->ymax=box.ymax;

  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      pb_msg->positioncovariance.push_back(object_ptr->center_uncertainty(i, j));
      pb_msg->velocitycovariance.push_back(object_ptr->velocity_uncertainty(i, j));
      pb_msg->accelerationcovariance.push_back(
          object_ptr->acceleration_uncertainty(i, j));
    }
  }

  pb_msg->trackingtime=object_ptr->tracking_time;
  pb_msg->type=static_cast<PerceptionObstacle::Type>(object_ptr->type);
  pb_msg->subtype=
      static_cast<PerceptionObstacle::SubType>(object_ptr->sub_type);
  pb_msg->timestamp=object_ptr->latest_tracked_time;  // in seconds.

  if (object_ptr->lidar_supplement.height_above_ground != kFloatMax) {
    pb_msg->heightaboveground=
        object_ptr->lidar_supplement.height_above_ground;
  } else {
    pb_msg->heightaboveground=std::numeric_limits<double>::quiet_NaN();
  }

  if (object_ptr->type == base::ObjectType::VEHICLE) {
    LightStatus *light_status = &pb_msg->lightstatus;
    const base::CarLight &car_light = object_ptr->car_light;
    light_status->brakevisible=car_light.brake_visible;
    light_status->brakeswitchon=car_light.brake_switch_on;

    light_status->leftturnvisible=car_light.left_turn_visible;
    light_status->leftturnswitchon=car_light.left_turn_switch_on;

    light_status->rightturnvisible=car_light.right_turn_visible;
    light_status->rightturnswitchon=car_light.right_turn_switch_on;
  }

  if (FLAGS_obs_save_fusion_supplement &&
      object_ptr->fusion_supplement.on_use) {
    for (const auto &measurement : object_ptr->fusion_supplement.measurements) {
      SensorMeasurement pb_measurement; //= pb_msg->add_measurements();
      pb_measurement.sensorid=measurement.sensor_id;
      pb_measurement.id=measurement.track_id;

      apollo::common::Point3D *pb_position = &pb_measurement.position;
      pb_position->x=measurement.center[0];
      pb_position->y=measurement.center[1];
      pb_position->z=measurement.center[2];

      pb_measurement.theta=measurement.theta;
      pb_measurement.length=measurement.size[0];
      pb_measurement.width=measurement.size[1];
      pb_measurement.height=measurement.size[2];

      apollo::common::Point3D *pb_velocity = &pb_measurement.velocity;
      pb_velocity->x=measurement.velocity[0];
      pb_velocity->y=measurement.velocity[1];
      pb_velocity->z=measurement.velocity[2];

      pb_measurement.type=
          static_cast<PerceptionObstacle::Type>(measurement.type);
      // pb_measurement->set_sub_type();
      pb_measurement.timestamp=measurement.timestamp;

      BBox2D *pb_box = &pb_measurement.box;
      pb_box->xmin=measurement.box.xmin;
      pb_box->ymin=measurement.box.ymin;
      pb_box->xmax=measurement.box.xmax;
      pb_box->ymax=measurement.box.ymax;
      
      pb_msg->measurements.push_back(pb_measurement);
      
    }
  }

// TODO(all): semantic map related, for debugging
//  // record the best prediction trajectory
//  if (object_ptr->feature.get() &&
//      object_ptr->feature->predicted_trajectory_size() > 0) {
//    apollo::perception::DebugMessage *dmsg = pb_msg->mutable_msg();
//    apollo::perception::Trajectory *target_traj = dmsg->add_trajectory();
//    const apollo::prediction::Trajectory &src_traj =
//        object_ptr->feature->predicted_trajectory(0);
//  (*target_traj->mutable_trajectory_point()) = (src_traj.trajectory_point());
//    ADEBUG << "Inserting Trajectores in PB with point size "
//           << src_traj.trajectory_point_size();
//  }

  return true;
}

}  // namespace onboard
}  // namespace perception
}  // namespace apollo
