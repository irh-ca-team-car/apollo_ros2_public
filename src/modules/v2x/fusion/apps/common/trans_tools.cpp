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

#include "modules/v2x/fusion/apps/common/trans_tools.h"

#include <limits>

namespace apollo {
namespace v2x {
namespace ft {

void Pb2Object(const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &obstacle, base::Object *object,
               const std::string &frame_id, double timestamp_object) {
  UNUSED(timestamp_object);
  Eigen::Vector3d value;
  Eigen::Matrix3d variance;
  variance.setIdentity();
  object->type_probs.push_back(0.85);
  object->sub_type_probs.push_back(0.85);
  object->type = static_cast<base::ObjectType>(obstacle.type);
  variance = variance * 1;
  switch (obstacle.subtype) {
    case apollo::perception::PerceptionObstacle::ST_UNKNOWN:
      object->sub_type = base::ObjectSubType::UNKNOWN;
      variance = variance * 3;
      break;

    case apollo::perception::PerceptionObstacle::ST_UNKNOWN_MOVABLE:
      object->sub_type = base::ObjectSubType::UNKNOWN_MOVABLE;
      variance = variance * 2;
      break;

    case apollo::perception::PerceptionObstacle::ST_CAR:
      object->sub_type = base::ObjectSubType::CAR;
      variance = variance * 0.8;
      break;

    case apollo::perception::PerceptionObstacle::ST_VAN:
      object->sub_type = base::ObjectSubType::VAN;
      variance = variance * 1;
      break;

    case apollo::perception::PerceptionObstacle::ST_TRUCK:
      object->sub_type = base::ObjectSubType::TRUCK;
      variance = variance * 3;
      break;

    case apollo::perception::PerceptionObstacle::ST_BUS:
      object->sub_type = base::ObjectSubType::BUS;
      variance = variance * 3;
      break;

    case apollo::perception::PerceptionObstacle::ST_CYCLIST:
      object->sub_type = base::ObjectSubType::CYCLIST;
      variance = variance * 0.8;
      break;

    case apollo::perception::PerceptionObstacle::ST_MOTORCYCLIST:
      object->sub_type = base::ObjectSubType::MOTORCYCLIST;
      variance = variance * 0.8;
      break;

    case apollo::perception::PerceptionObstacle::ST_TRICYCLIST:
      object->sub_type = base::ObjectSubType::TRICYCLIST;
      variance = variance * 0.8;
      break;

    case apollo::perception::PerceptionObstacle::ST_PEDESTRIAN:
      object->sub_type = base::ObjectSubType::PEDESTRIAN;
      variance = variance * 0.8;
      break;

    case apollo::perception::PerceptionObstacle::ST_TRAFFICCONE:
      object->sub_type = base::ObjectSubType::TRAFFICCONE;
      variance = variance * 0.8;
      break;

    default:
      break;
  }
  
   if (obstacle==apollo_msgs::msg::ApolloperceptionPerceptionObstacle()) {
     object->timestamp = obstacle.timestamp;
   } else {
     object->timestamp = timestamp_object;
   }
  value << obstacle.position.x, obstacle.position.y, 0.0;
  object->position.Set(value, variance);
  value << obstacle.velocity.x, obstacle.velocity.y,
      obstacle.velocity.z;
  object->velocity.Set(value, variance);
  object->theta.Set(obstacle.theta, 0.5);
  object->sensor_type = base::SensorType::MONOCULAR_CAMERA;
  object->track_id = obstacle.id;
  object->frame_id = frame_id;
  variance.setIdentity();
  value << obstacle.length, obstacle.width, obstacle.height;
  object->size.Set(value, variance);
  std::vector<base::Info3d> polygon_info3d;
  for (auto &polygon_point : obstacle.polygonpoint) {
    base::Info3d point;
    value << polygon_point.x, polygon_point.y, polygon_point.z;
    point.Set(value, variance);
    polygon_info3d.push_back(point);
  }
  object->polygon = polygon_info3d;
}

void V2xPb2Object(const apollo::v2x::V2XObstacle &obstacle,
                  base::Object *object, const std::string &frame_id,
                  double timestamp_object) {
  Pb2Object(obstacle.perceptionobstacle, object, frame_id, timestamp_object);
  if (
  obstacle.v2xinfo.v2xtype.size() > 0 &&
      obstacle.v2xinfo.v2xtype[0] ==
          ::apollo::v2x::V2XInformation::ZOMBIES_CAR) {
    object->v2x_type = base::V2xType::ZOMBIES_CAR;
  }
}

base::Object Pb2Object(const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &obstacle,
                       const std::string &frame_id) {
  base::Object object;
  Eigen::Vector3d value;
  Eigen::Matrix3d variance;
  variance.setIdentity();
  object.timestamp = obstacle.timestamp;
  // object
  value << obstacle.position.x, obstacle.position.y,
      obstacle.position.z;

  object.position.Set(value, variance);
  value << obstacle.velocity.x, obstacle.velocity.y,
      obstacle.velocity.z;
  object.velocity.Set(value, variance);
  object.theta.Set(obstacle.theta, 0.5);
  object.sensor_type = base::SensorType::MONOCULAR_CAMERA;
  object.track_id = obstacle.id;
  object.frame_id = frame_id;
  value << obstacle.length, obstacle.width, obstacle.height;
  object.size.Set(value, variance);
  object.type_probs.push_back(0.85);
  object.sub_type_probs.push_back(0.85);
  object.type = static_cast<base::ObjectType>(obstacle.type);
  switch (obstacle.subtype) {
    case apollo::perception::PerceptionObstacle::ST_UNKNOWN:
      object.sub_type = base::ObjectSubType::UNKNOWN;
      break;

    case apollo::perception::PerceptionObstacle::ST_UNKNOWN_MOVABLE:
      object.sub_type = base::ObjectSubType::UNKNOWN_MOVABLE;
      break;

    case apollo::perception::PerceptionObstacle::ST_CAR:
      object.sub_type = base::ObjectSubType::CAR;
      break;

    case apollo::perception::PerceptionObstacle::ST_VAN:
      object.sub_type = base::ObjectSubType::VAN;
      break;

    case apollo::perception::PerceptionObstacle::ST_TRUCK:
      object.sub_type = base::ObjectSubType::TRUCK;
      break;

    case apollo::perception::PerceptionObstacle::ST_BUS:
      object.sub_type = base::ObjectSubType::BUS;
      break;

    case apollo::perception::PerceptionObstacle::ST_CYCLIST:
      object.sub_type = base::ObjectSubType::CYCLIST;
      break;

    case apollo::perception::PerceptionObstacle::ST_MOTORCYCLIST:
      object.sub_type = base::ObjectSubType::MOTORCYCLIST;
      break;

    case apollo::perception::PerceptionObstacle::ST_TRICYCLIST:
      object.sub_type = base::ObjectSubType::TRICYCLIST;
      break;

    case apollo::perception::PerceptionObstacle::ST_PEDESTRIAN:
      object.sub_type = base::ObjectSubType::PEDESTRIAN;
      break;

    case apollo::perception::PerceptionObstacle::ST_TRAFFICCONE:
      object.sub_type = base::ObjectSubType::TRAFFICCONE;
      break;

    default:
      break;
  }
  return object;
}

apollo_msgs::msg::ApolloperceptionPerceptionObstacle Object2Pb(const base::Object &object) {
  apollo_msgs::msg::ApolloperceptionPerceptionObstacle obstacle;
  // times
  obstacle.timestamp=(object.timestamp);
  // id
  obstacle.id=(object.track_id);
  // position
  obstacle.position.x=(object.position.x());
  obstacle.position.y=(object.position.y());
  obstacle.position.z=(object.position.z());
  // velocity
  obstacle.velocity.x=(object.velocity.x());
  obstacle.velocity.y=(object.velocity.y());
  obstacle.velocity.z=(object.velocity.z());
  // yaw
  obstacle.theta=(object.theta.Value());
  // lwh
  obstacle.length=(object.size.length());
  obstacle.width=(object.size.width());
  obstacle.height=(object.size.height());
  obstacle.type=(static_cast<apollo::perception::PerceptionObstacle::Type>(object.type));
  switch (object.sub_type) {
    case base::ObjectSubType::UNKNOWN:
      obstacle.subtype=(apollo::perception::PerceptionObstacle::ST_UNKNOWN);
      break;

    case base::ObjectSubType::UNKNOWN_MOVABLE:
      obstacle.subtype=(apollo::perception::PerceptionObstacle::ST_UNKNOWN_MOVABLE);
      break;

    case base::ObjectSubType::CAR:
      obstacle.subtype=(apollo::perception::PerceptionObstacle::ST_CAR);
      break;

    case base::ObjectSubType::VAN:
      obstacle.subtype=(apollo::perception::PerceptionObstacle::ST_VAN);
      break;

    case base::ObjectSubType::TRUCK:
      obstacle.subtype=(apollo::perception::PerceptionObstacle::ST_TRUCK);
      break;

    case base::ObjectSubType::BUS:
      obstacle.subtype=(apollo::perception::PerceptionObstacle::ST_BUS);
      break;

    case base::ObjectSubType::CYCLIST:
      obstacle.subtype=(apollo::perception::PerceptionObstacle::ST_CYCLIST);
      break;

    case base::ObjectSubType::MOTORCYCLIST:
      obstacle.subtype=(apollo::perception::PerceptionObstacle::ST_MOTORCYCLIST);
      break;

    case base::ObjectSubType::TRICYCLIST:
      obstacle.subtype=(apollo::perception::PerceptionObstacle::ST_TRICYCLIST);
      break;

    case base::ObjectSubType::PEDESTRIAN:
      obstacle.subtype=(apollo::perception::PerceptionObstacle::ST_PEDESTRIAN);
      break;

    case base::ObjectSubType::TRAFFICCONE:
      obstacle.subtype=(apollo::perception::PerceptionObstacle::ST_TRAFFICCONE);
      break;

    default:
      break;
  }
  return obstacle;
}

void FillObjectPolygonFromBBox3D(apollo_msgs::msg::ApolloperceptionPerceptionObstacle *object_ptr) {
  struct PolygoPoint {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
  };

  if (!object_ptr) {
    return;
  }
  const double length = object_ptr->length;
  const double width = object_ptr->width;
  double hl = length / 2;
  double hw = width / 2;
  double cos_theta = std::cos(object_ptr->theta);
  double sin_theta = std::sin(object_ptr->theta);
  PolygoPoint polygon[4];
  polygon[0].x = hl * cos_theta - hw * sin_theta + object_ptr->position.x;
  polygon[0].y = hl * sin_theta + hw * cos_theta + object_ptr->position.y;
  polygon[0].z = object_ptr->position.z;
  polygon[1].x = hl * cos_theta + hw * sin_theta + object_ptr->position.x;
  polygon[1].y = hl * sin_theta - hw * cos_theta + object_ptr->position.y;
  polygon[1].z = object_ptr->position.z;
  polygon[2].x = -hl * cos_theta + hw * sin_theta + object_ptr->position.x;
  polygon[2].y = -hl * sin_theta - hw * cos_theta + object_ptr->position.y;
  polygon[2].z = object_ptr->position.z;
  polygon[3].x = -hl * cos_theta - hw * sin_theta + object_ptr->position.x;
  polygon[3].y = -hl * sin_theta + hw * cos_theta + object_ptr->position.y;
  polygon[3].z = object_ptr->position.z;
  for (PolygoPoint point : polygon) {
    auto * polygon_point=&    object_ptr->polygonpoint.emplace_back();
    polygon_point->x=(point.x);
    polygon_point->y=(point.y);
    polygon_point->z=(point.z);
  }
}

void Object2Pb(const base::Object &object, apollo_msgs::msg::ApolloperceptionPerceptionObstacle *obstacle) {
  // times
  obstacle->timestamp=(object.timestamp);
  // id
  obstacle->id=(object.track_id);
  // position
  obstacle->position.x=(object.position.x());
  obstacle->position.y=(object.position.y());
  obstacle->position.z=(object.position.z());
  // velocity
  obstacle->velocity.x=(object.velocity.x());
  obstacle->velocity.y=(object.velocity.y());
  obstacle->velocity.z=(object.velocity.z());
  // yaw
  obstacle->theta=(object.theta.Value());
  // lwh
  obstacle->length=(object.size.length());
  obstacle->width=(object.size.width());
  obstacle->height=(object.size.height());
  FillObjectPolygonFromBBox3D(obstacle);
  obstacle->type=(static_cast<apollo::perception::PerceptionObstacle::Type>(object.type));
  switch (object.sub_type) {
    case base::ObjectSubType::UNKNOWN:
      obstacle->subtype=(apollo::perception::PerceptionObstacle::ST_UNKNOWN);
      break;

    case base::ObjectSubType::UNKNOWN_MOVABLE:
      obstacle->subtype=(apollo::perception::PerceptionObstacle::ST_UNKNOWN_MOVABLE);
      break;

    case base::ObjectSubType::UNKNOWN_UNMOVABLE:
      obstacle->subtype=(apollo::perception::PerceptionObstacle::ST_UNKNOWN_UNMOVABLE);
      break;

    case base::ObjectSubType::CAR:
      obstacle->subtype=(apollo::perception::PerceptionObstacle::ST_CAR);
      break;

    case base::ObjectSubType::VAN:
      obstacle->subtype=(apollo::perception::PerceptionObstacle::ST_VAN);
      break;

    case base::ObjectSubType::TRUCK:
      obstacle->subtype=(apollo::perception::PerceptionObstacle::ST_TRUCK);
      break;

    case base::ObjectSubType::BUS:
      obstacle->subtype=(apollo::perception::PerceptionObstacle::ST_BUS);
      break;

    case base::ObjectSubType::CYCLIST:
      obstacle->subtype=(apollo::perception::PerceptionObstacle::ST_CYCLIST);
      break;

    case base::ObjectSubType::MOTORCYCLIST:
      obstacle->subtype=(apollo::perception::PerceptionObstacle::ST_MOTORCYCLIST);
      break;

    case base::ObjectSubType::TRICYCLIST:
      obstacle->subtype=(apollo::perception::PerceptionObstacle::ST_TRICYCLIST);
      break;

    case base::ObjectSubType::PEDESTRIAN:
      obstacle->subtype=(apollo::perception::PerceptionObstacle::ST_PEDESTRIAN);
      break;

    case base::ObjectSubType::TRAFFICCONE:
      obstacle->subtype=(apollo::perception::PerceptionObstacle::ST_TRAFFICCONE);
      break;

    default:
      break;
  }
  obstacle->source=(apollo::perception::PerceptionObstacle::HOST_VEHICLE);
  if (object.v2x_type == base::V2xType::ZOMBIES_CAR) {
    obstacle->v2xinfo.v2xtype.push_back(1);
    obstacle->source=(apollo::perception::PerceptionObstacle::V2X);
  }
  if (object.v2x_type == base::V2xType::BLIND_ZONE) {
    obstacle->v2xinfo.v2xtype.push_back(2);
    obstacle->source=(apollo::perception::PerceptionObstacle::V2X);
  }
}

void Object2V2xPb(const base::Object &object, V2XObstacle *obstacle) {
  apollo_msgs::msg::ApolloperceptionPerceptionObstacle perception_obstacle;
  Object2Pb(object, &perception_obstacle);
  obstacle->perceptionobstacle=(perception_obstacle);
}

double Pbs2Objects(const apollo_msgs::msg::ApolloperceptionPerceptionObstacles &obstacles,
                   std::vector<base::Object> *objects,
                   const std::string &frame_id) {
  double timestamp = std::numeric_limits<double>::max();
  objects->clear();
  double timestamp_object = 0.0;
  if (obstacles.perceptionobstacle.size() > 0 &&
      obstacles.perceptionobstacle[0].timestamp !=0) {
    if (
        obstacles.apolloheader.timestampsec  > 10.0) {
      timestamp_object = obstacles.apolloheader.timestampsec  / 1.0e9;
    } else {
      timestamp_object = obstacles.apolloheader.timestampsec  / 1.0e9;
    }
  }
  for (size_t j = 0; j < obstacles.perceptionobstacle.size(); ++j) {
    base::Object object;
    Pb2Object(obstacles.perceptionobstacle[j], &object, frame_id,
              timestamp_object);
    objects->push_back(object);
    if (timestamp > object.timestamp) {
      timestamp = object.timestamp;
    }
  }

  return timestamp;
}

void CarstatusPb2Object(const LocalizationEstimate &carstatus,
                        base::Object *object, const std::string &frame_id) {
  Eigen::Vector3d value;
  Eigen::Matrix3d variance;
  variance.setIdentity();
  object->type_probs.push_back(0.85);
  object->sub_type_probs.push_back(0.85);
  object->type = base::ObjectType::VEHICLE;
  object->sub_type = base::ObjectSubType::CAR;
  object->v2x_type = base::V2xType::HOST_VEHICLE;
  variance = variance * 0.8;
  value << carstatus.pose.position.x, carstatus.pose.position.y,
      0.0;
  object->position.Set(value, variance);
  value << carstatus.pose.linearvelocity.x,
      carstatus.pose.linearvelocity.y,
      carstatus.pose.linearvelocity.z;
  object->velocity.Set(value, variance);
  object->theta.Set(carstatus.pose.heading, 0.5);
  object->sensor_type = base::SensorType::MONOCULAR_CAMERA;
  object->track_id = 0;
  object->frame_id = frame_id;
  variance.setIdentity();
  value << 5.02203, 2.13135, 2.17711;
  object->size.Set(value, variance);
  object->timestamp = carstatus.apolloheader.timestampsec ;
}

double V2xPbs2Objects(const V2XObstacles &obstacles,
                      std::vector<base::Object> *objects,
                      const std::string &frame_id) {
  double timestamp = std::numeric_limits<double>::max();
  objects->clear();
  double timestamp_object = 0.0;
  if (obstacles.v2xobstacle.size() > 0 &&
      obstacles.v2xobstacle[0].perceptionobstacle.timestamp!=0) {
    if (obstacles.apolloheader.timestampsec!=0) {
      timestamp_object = obstacles.apolloheader.timestampsec / 1000000000.0;
    } else {
      timestamp_object = obstacles.apolloheader.timestampsec / 1000000000.0;
    }
  }
  for (size_t j = 0; j < obstacles.v2xobstacle.size(); ++j) {
    base::Object object;
    V2xPb2Object(obstacles.v2xobstacle[j], &object, frame_id,
                 timestamp_object);
    objects->push_back(object);
    if (timestamp > object.timestamp) {
      timestamp = object.timestamp;
    }
  }

  return timestamp;
}

void Objects2Pbs(const std::vector<base::Object> &objects,
                 std::shared_ptr<apollo::perception::PerceptionObstacles> obstacles) {
  obstacles->perceptionobstacle.clear();
  if (objects.size() < 1) {
    return;
  }
  obstacles->apolloheader.frameid = objects[0].frame_id;
  for (const auto &object : objects) {
    if (object.v2x_type == base::V2xType::HOST_VEHICLE) {
      continue;
    }
    apollo_msgs::msg::ApolloperceptionPerceptionObstacle obstacle;
    Object2Pb(object, &obstacle);
    obstacles->perceptionobstacle.push_back(obstacle);
  }
}

void Objects2V2xPbs(const std::vector<base::Object> &objects,
                    std::shared_ptr<V2XObstacles> obstacles) {
  obstacles->v2xobstacle.clear();
  if (objects.size() < 1) {
    return;
  }
  for (const auto &object : objects) {
    if (object.v2x_type == base::V2xType::HOST_VEHICLE) {
      continue;
    }
    V2XObstacle obstacle;
    Object2V2xPb(object, &obstacle);
    obstacles->v2xobstacle.push_back(obstacle);
  }
}

}  // namespace ft
}  // namespace v2x
}  // namespace apollo