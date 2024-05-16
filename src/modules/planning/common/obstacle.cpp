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

#include "modules/planning/common/obstacle.h"

#include <algorithm>
#include <utility>

#include "cyber/common/log.h"
#include "modules/common/configs/vehicle_config_helper.h"
#include "modules/common/math/linear_interpolation.h"
#include "modules/common/util/map_util.h"
#include "modules/common/util/util.h"
#include "modules/planning/common/planning_gflags.h"
#include "modules/planning/common/speed/st_boundary.h"
#include "modules/planning/proto/enum.h"
namespace apollo {
namespace planning {

using apollo::common::VehicleConfigHelper;
using apollo::common::util::FindOrDie;
using apollo_msgs::msg::ApolloperceptionPerceptionObstacle;
using apollo_msgs::msg::ApollopredictionObstaclePriority;
using apollo_msgs::msg::ApolloplanningObjectDecisionType;

namespace {
const double kStBoundaryDeltaS = 0.2;        // meters
const double kStBoundarySparseDeltaS = 1.0;  // meters
const double kStBoundaryDeltaT = 0.05;       // seconds
}  // namespace
const std::unordered_map<apollo::planning::ObjectDecisionType, int,
                         Obstacle::ObjectTagCaseHash>
    Obstacle::s_longitudinal_decision_safety_sorter_ = {
        {apollo::planning::ObjectDecisionType::kIgnore, 0},
        {apollo::planning::ObjectDecisionType::kOvertake, 100},
        {apollo::planning::ObjectDecisionType::kFollow, 300},
        {apollo::planning::ObjectDecisionType::kYield, 400},
        {apollo::planning::ObjectDecisionType::kStop, 500}};

const std::unordered_map<apollo::planning::ObjectDecisionType, int,
                         Obstacle::ObjectTagCaseHash>
    Obstacle::s_lateral_decision_safety_sorter_ = {
        {apollo::planning::ObjectDecisionType::kIgnore, 0}, {apollo::planning::ObjectDecisionType::kNudge, 100}};

apollo::planning::ObjectDecisionType object_tag_case(apollo_msgs::msg::ApolloplanningObjectDecisionType t)
{
    if(t.objecttag.avoid!=0)
      return apollo::planning::ObjectDecisionType::kAvoid;
    if (t.objecttag.follow != apollo_msgs::msg::ApolloplanningObjectFollow())
      return apollo::planning::ObjectDecisionType::kFollow;
    if(t.objecttag.ignore !=0)
      return apollo::planning::ObjectDecisionType::kIgnore;
    if (t.objecttag.nudge != apollo_msgs::msg::ApolloplanningObjectNudge())
      return apollo::planning::ObjectDecisionType::kNudge;
    if(t.objecttag.overtake!= apollo_msgs::msg::ApolloplanningObjectOvertake())
      return apollo::planning::ObjectDecisionType::kOvertake;
    if (t.objecttag.sidepass != apollo_msgs::msg::ApolloplanningObjectSidePass())
      return apollo::planning::ObjectDecisionType::kSidePass;
    if (t.objecttag.stop != apollo_msgs::msg::ApolloplanningObjectStop())
      return apollo::planning::ObjectDecisionType::kStop;
    if (t.objecttag.yieldd != apollo_msgs::msg::ApolloplanningObjectYield())
      return apollo::planning::ObjectDecisionType::kYield;
    return apollo::planning::ObjectDecisionType::OBJECT_TAG_NOT_SET;
}

Obstacle::Obstacle(const std::string &id,
                   const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &perception_obstacle,
                   const apollo::prediction::ObstaclePriority::Priority &obstacle_priority,
                   const bool is_static)
    : id_(id),
      perception_id_(perception_obstacle.id),
      perception_obstacle_(perception_obstacle),
      perception_bounding_box_({perception_obstacle_.position.x,
                                perception_obstacle_.position.y},
                               perception_obstacle_.theta,
                               perception_obstacle_.length,
                               perception_obstacle_.width)
{
  is_caution_level_obstacle_ = (obstacle_priority == apollo::prediction::ObstaclePriority::CAUTION);
  std::vector<common::math::Vec2d> polygon_points;
  if (FLAGS_use_navigation_mode ||
      perception_obstacle.polygonpoint.size() <= 2) {
    perception_bounding_box_.GetAllCorners(&polygon_points);
  } else {
    ACHECK(perception_obstacle.polygonpoint.size() > 2)
        << "object " << id << "has less than 3 polygon points";
    for (const auto& point : perception_obstacle.polygonpoint) {
      polygon_points.emplace_back(point.x, point.y);
    }
  }
  ACHECK(common::math::Polygon2d::ComputeConvexHull(polygon_points,
                                                    &perception_polygon_))
      << "object[" << id << "] polygon is not a valid convex hull.\n"
      << perception_obstacle;

  is_static_ = (is_static || obstacle_priority == apollo::prediction::ObstaclePriority::IGNORE);
  is_virtual_ = (perception_obstacle.id < 0);
  speed_ = std::hypot(perception_obstacle.velocity.x,
                      perception_obstacle.velocity.y);
}

Obstacle::Obstacle(const std::string& id,
                   const apollo_msgs::msg::ApolloperceptionPerceptionObstacle& perception_obstacle,
                   const prediction::Trajectory& trajectory,
                   const apollo::prediction::ObstaclePriority::Priority& obstacle_priority,
                   const bool is_static)
    : Obstacle(id, perception_obstacle, obstacle_priority, is_static) {
  trajectory_ = trajectory;
  auto& trajectory_points = trajectory_.trajectorypoint;
  double cumulative_s = 0.0;
  if (trajectory_points.size() > 0) {
    trajectory_points[0].pathpoint.s=(0.0);
  }
  for (size_t i = 1; i < trajectory_points.size(); ++i) {
    const auto& prev = trajectory_points[i - 1];
    const auto& cur = trajectory_points[i];
    if (prev.relativetime >= cur.relativetime) {
      AERROR << "prediction time is not increasing."
             << "current point: " << cur
             << "previous point: " << prev;
    }
    cumulative_s +=
        common::util::DistanceXY(prev.pathpoint, cur.pathpoint);
    trajectory_points[i].pathpoint.s=(cumulative_s);
  }
}

common::TrajectoryPoint Obstacle::GetPointAtTime(
    const double relative_time) const {
  const auto& points = trajectory_.trajectorypoint;
  if (points.size() < 2) {
    common::TrajectoryPoint point;
    point.pathpoint.x=(perception_obstacle_.position.x);
    point.pathpoint.y=(perception_obstacle_.position.y);
    point.pathpoint.z=(perception_obstacle_.position.z);
    point.pathpoint.theta=(perception_obstacle_.theta);
    point.pathpoint.s=(0.0);
    point.pathpoint.kappa=(0.0);
    point.pathpoint.dkappa=(0.0);
    point.pathpoint.ddkappa=(0.0);
    point.v=(0.0);
    point.a=(0.0);
    point.relativetime=(0.0);
    return point;
  } else {
    auto comp = [](const common::TrajectoryPoint p, const double time) {
      return p.relativetime < time;
    };

    auto it_lower =
        std::lower_bound(points.begin(), points.end(), relative_time, comp);

    if (it_lower == points.begin()) {
      return *points.begin();
    } else if (it_lower == points.end()) {
      return *points.rbegin();
    }
    return common::math::InterpolateUsingLinearApproximation(
        *(it_lower - 1), *it_lower, relative_time);
  }
}

common::math::Box2d Obstacle::GetBoundingBox(
    const common::TrajectoryPoint& point) const {
  return common::math::Box2d({point.pathpoint.x, point.pathpoint.y},
                             point.pathpoint.theta,
                             perception_obstacle_.length,
                             perception_obstacle_.width);
}

bool Obstacle::IsValidPerceptionObstacle(const apollo_msgs::msg::ApolloperceptionPerceptionObstacle& obstacle) {
  if (obstacle.length <= 0.0) {
    AERROR << "invalid obstacle length:" << obstacle.length;
    return false;
  }
  if (obstacle.width <= 0.0) {
    AERROR << "invalid obstacle width:" << obstacle.width;
    return false;
  }
  if (obstacle.height <= 0.0) {
    AERROR << "invalid obstacle height:" << obstacle.height;
    return false;
  }
  if (obstacle.velocity != apollo_msgs::msg::ApollocommonPoint3D())
  {
    if (std::isnan(obstacle.velocity.x) ||
        std::isnan(obstacle.velocity.y)) {
      AERROR << "invalid obstacle velocity:" << obstacle.velocity;
      //  << obstacle.velocity.DebugString();
      return false;
    }
  }
  for (auto pt : obstacle.polygonpoint) {
    if (std::isnan(pt.x) || std::isnan(pt.y)) {
      AERROR << "invalid obstacle polygon point:" 
      // << pt.DebugString()
      ;
      return false;
    }
  }
  return true;
}

std::list<std::unique_ptr<Obstacle>> Obstacle::CreateObstacles(
    const prediction::PredictionObstacles &predictions)
{
  std::list<std::unique_ptr<Obstacle>> obstacles;
  for (const auto& prediction_obstacle : predictions.predictionobstacle) {
    if (!IsValidPerceptionObstacle(prediction_obstacle.perceptionobstacle)) {
      AERROR << "Invalid perception obstacle: "
             << prediction_obstacle.perceptionobstacle;
      continue;
    }
    const auto perception_id =
        std::to_string(prediction_obstacle.perceptionobstacle.id);
    if (prediction_obstacle.trajectory.empty()) {
      obstacles.emplace_back(
          new Obstacle(perception_id, prediction_obstacle.perceptionobstacle,
                       (apollo::prediction::ObstaclePriority::Priority)prediction_obstacle.priority.priority,
                       prediction_obstacle.isstatic));
      continue;
    }

    int trajectory_index = 0;
    for (const auto& trajectory : prediction_obstacle.trajectory) {
      bool is_valid_trajectory = true;
      for (const auto& point : trajectory.trajectorypoint) {
        if (!IsValidTrajectoryPoint(point)) {
          AERROR << "obj:" << perception_id
                 << " TrajectoryPoint: " << trajectory
                 << " is NOT valid.";
          is_valid_trajectory = false;
          break;
        }
      }
      if (!is_valid_trajectory) {
        continue;
      }

      const std::string obstacle_id =
          absl::StrCat(perception_id, "_", trajectory_index);
      obstacles.emplace_back(
          new Obstacle(obstacle_id, prediction_obstacle.perceptionobstacle,
                       trajectory, (apollo::prediction::ObstaclePriority::Priority)prediction_obstacle.priority.priority,
                       prediction_obstacle.isstatic));
      ++trajectory_index;
    }
  }
  return obstacles;
}

std::unique_ptr<Obstacle> Obstacle::CreateStaticVirtualObstacles(
    const std::string& id, const common::math::Box2d& obstacle_box) {
  // create a "virtual" perception_obstacle
  apollo_msgs::msg::ApolloperceptionPerceptionObstacle perception_obstacle;
  // simulator needs a valid integer
  size_t negative_id = std::hash<std::string>{}(id);
  // set the first bit to 1 so negative_id became negative number
  negative_id |= (0x1 << 31);
  perception_obstacle.id=(static_cast<int32_t>(negative_id));
  perception_obstacle.position.x=(obstacle_box.center().x());
  perception_obstacle.position.y=(obstacle_box.center().y());
  perception_obstacle.theta=(obstacle_box.heading());
  perception_obstacle.velocity.x=(0);
  perception_obstacle.velocity.y=(0);
  perception_obstacle.length=(obstacle_box.length());
  perception_obstacle.width=(obstacle_box.width());
  perception_obstacle.height=(FLAGS_virtual_stop_wall_height);
  perception_obstacle.type=(
      perception::PerceptionObstacle::UNKNOWN_UNMOVABLE);
  perception_obstacle.set__trackingtime(1.0);

  std::vector<common::math::Vec2d> corner_points;
  obstacle_box.GetAllCorners(&corner_points);
  for (const auto& corner_point : corner_points) {
    auto* point = &perception_obstacle.polygonpoint.emplace_back();
    point->x=(corner_point.x());
    point->y=(corner_point.y());
  }
  auto* obstacle =
      new Obstacle(id, perception_obstacle, apollo::prediction::ObstaclePriority::Priority::NORMAL, true);
  obstacle->is_virtual_ = true;
  return std::unique_ptr<Obstacle>(obstacle);
}

bool Obstacle::IsValidTrajectoryPoint(const common::TrajectoryPoint& point) {
  return !((point.pathpoint != apollo_msgs::msg::ApollocommonPathPoint()) || std::isnan(point.pathpoint.x) ||
           std::isnan(point.pathpoint.y) ||
           std::isnan(point.pathpoint.z) ||
           std::isnan(point.pathpoint.kappa) ||
           std::isnan(point.pathpoint.s) ||
           std::isnan(point.pathpoint.dkappa) ||
           std::isnan(point.pathpoint.ddkappa) || std::isnan(point.v) ||
           std::isnan(point.a) || std::isnan(point.relativetime));
}

void Obstacle::SetPerceptionSlBoundary(const SLBoundary& sl_boundary) {
  sl_boundary_ = sl_boundary;
}

double Obstacle::MinRadiusStopDistance(
    const common::VehicleParam& vehicle_param) const {
  if (min_radius_stop_distance_ > 0) {
    return min_radius_stop_distance_;
  }
  static constexpr double stop_distance_buffer = 0.5;
  const double min_turn_radius = VehicleConfigHelper::MinSafeTurnRadius();
  double lateral_diff =
      vehicle_param.width / 2.0 + std::max(std::fabs(sl_boundary_.startl),
                                             std::fabs(sl_boundary_.endl));
  const double kEpison = 1e-5;
  lateral_diff = std::min(lateral_diff, min_turn_radius - kEpison);
  double stop_distance =
      std::sqrt(std::fabs(min_turn_radius * min_turn_radius -
                          (min_turn_radius - lateral_diff) *
                              (min_turn_radius - lateral_diff))) +
      stop_distance_buffer;
  stop_distance -= vehicle_param.frontedgetocenter;
  stop_distance = std::min(stop_distance, FLAGS_max_stop_distance_obstacle);
  stop_distance = std::max(stop_distance, FLAGS_min_stop_distance_obstacle);
  return stop_distance;
}

void Obstacle::BuildReferenceLineStBoundary(const ReferenceLine& reference_line,
                                            const double adc_start_s) {
  const auto& adc_param =
      VehicleConfigHelper::Instance()->GetConfig().vehicleparam;
  const double adc_width = adc_param.width;
  if (is_static_ || trajectory_.trajectorypoint.empty()) {
    std::vector<std::pair<STPoint, STPoint>> point_pairs;
    double start_s = sl_boundary_.starts;
    double end_s = sl_boundary_.ends;
    if (end_s - start_s < kStBoundaryDeltaS) {
      end_s = start_s + kStBoundaryDeltaS;
    }
    if (!reference_line.IsBlockRoad(perception_bounding_box_, adc_width)) {
      return;
    }
    point_pairs.emplace_back(STPoint(start_s - adc_start_s, 0.0),
                             STPoint(end_s - adc_start_s, 0.0));
    point_pairs.emplace_back(STPoint(start_s - adc_start_s, FLAGS_st_max_t),
                             STPoint(end_s - adc_start_s, FLAGS_st_max_t));
    reference_line_st_boundary_ = STBoundary(point_pairs);
  } else {
    if (BuildTrajectoryStBoundary(reference_line, adc_start_s,
                                  &reference_line_st_boundary_)) {
      ADEBUG << "Found st_boundary for obstacle " << id_;
      ADEBUG << "st_boundary: min_t = " << reference_line_st_boundary_.min_t()
             << ", max_t = " << reference_line_st_boundary_.max_t()
             << ", min_s = " << reference_line_st_boundary_.min_s()
             << ", max_s = " << reference_line_st_boundary_.max_s();
    } else {
      ADEBUG << "No st_boundary for obstacle " << id_;
    }
  }
}

bool Obstacle::BuildTrajectoryStBoundary(const ReferenceLine& reference_line,
                                         const double adc_start_s,
                                         STBoundary* const st_boundary) {
  if (!IsValidObstacle(perception_obstacle_)) {
    AERROR << "Fail to build trajectory st boundary because object is not "
              "valid. PerceptionObstacle: "
          //  << perception_obstacle_.DebugString()
           ;
    return false;
  }
  const double object_width = perception_obstacle_.width;
  const double object_length = perception_obstacle_.length;
  const auto& trajectory_points = trajectory_.trajectorypoint;
  if (trajectory_points.empty()) {
    AWARN << "object " << id_ << " has no trajectory points";
    return false;
  }
  const auto& adc_param =
      VehicleConfigHelper::Instance()->GetConfig().vehicleparam;
  const double adc_length = adc_param.length;
  const double adc_half_length = adc_length / 2.0;
  const double adc_width = adc_param.width;
  common::math::Box2d min_box({0, 0}, 1.0, 1.0, 1.0);
  common::math::Box2d max_box({0, 0}, 1.0, 1.0, 1.0);
  std::vector<std::pair<STPoint, STPoint>> polygon_points;

  SLBoundary last_sl_boundary;
  int last_index = 0;

  for (size_t i = 1; i < trajectory_points.size(); ++i) {
    ADEBUG << "last_sl_boundary: " << last_sl_boundary;

    const auto& first_traj_point = trajectory_points[i - 1];
    const auto& second_traj_point = trajectory_points[i];
    const auto& first_point = first_traj_point.pathpoint;
    const auto& second_point = second_traj_point.pathpoint;

    double object_moving_box_length =
        object_length + common::util::DistanceXY(first_point, second_point);

    common::math::Vec2d center((first_point.x + second_point.x) / 2.0,
                               (first_point.y + second_point.y) / 2.0);
    common::math::Box2d object_moving_box(
        center, first_point.theta, object_moving_box_length, object_width);
    SLBoundary object_boundary;
    // NOTICE: this method will have errors when the reference line is not
    // straight. Need double loop to cover all corner cases.
    // roughly skip points that are too close to last_sl_boundary box
    const double distance_xy =
        common::util::DistanceXY(trajectory_points[last_index].pathpoint,
                                 trajectory_points[i].pathpoint);
    if (last_sl_boundary.startl > distance_xy ||
        last_sl_boundary.endl < -distance_xy) {
      continue;
    }

    const double mid_s =
        (last_sl_boundary.starts + last_sl_boundary.ends) / 2.0;
    const double start_s = std::fmax(0.0, mid_s - 2.0 * distance_xy);
    const double end_s = (i == 1) ? reference_line.Length()
                                  : std::fmin(reference_line.Length(),
                                              mid_s + 2.0 * distance_xy);

    if (!reference_line.GetApproximateSLBoundary(object_moving_box, start_s,
                                                 end_s, &object_boundary)) {
      AERROR << "failed to calculate boundary";
      return false;
    }

    // update history record
    last_sl_boundary = object_boundary;
    last_index = i;

    // skip if object is entirely on one side of reference line.
    static constexpr double kSkipLDistanceFactor = 0.4;
    const double skip_l_distance =
        (object_boundary.ends - object_boundary.starts) *
            kSkipLDistanceFactor +
        adc_width / 2.0;

    if (!IsCautionLevelObstacle() &&
        (std::fmin(object_boundary.startl, object_boundary.endl) >
             skip_l_distance ||
         std::fmax(object_boundary.startl, object_boundary.endl) <
             -skip_l_distance)) {
      continue;
    }

    if (!IsCautionLevelObstacle() && object_boundary.ends < 0) {
      // skip if behind reference line
      continue;
    }
    static constexpr double kSparseMappingS = 20.0;
    const double st_boundary_delta_s =
        (std::fabs(object_boundary.starts - adc_start_s) > kSparseMappingS)
            ? kStBoundarySparseDeltaS
            : kStBoundaryDeltaS;
    const double object_s_diff =
        object_boundary.ends - object_boundary.starts;
    if (object_s_diff < st_boundary_delta_s) {
      continue;
    }
    const double delta_t =
        second_traj_point.relativetime - first_traj_point.relativetime;
    double low_s = std::max(object_boundary.starts - adc_half_length, 0.0);
    bool has_low = false;
    double high_s =
        std::min(object_boundary.ends + adc_half_length, FLAGS_st_max_s);
    bool has_high = false;
    while (low_s + st_boundary_delta_s < high_s && !(has_low && has_high)) {
      if (!has_low) {
        auto low_ref = reference_line.GetReferencePoint(low_s);
        has_low = object_moving_box.HasOverlap(
            {low_ref, low_ref.heading(), adc_length,
             adc_width + FLAGS_nonstatic_obstacle_nudge_l_buffer});
        low_s += st_boundary_delta_s;
      }
      if (!has_high) {
        auto high_ref = reference_line.GetReferencePoint(high_s);
        has_high = object_moving_box.HasOverlap(
            {high_ref, high_ref.heading(), adc_length,
             adc_width + FLAGS_nonstatic_obstacle_nudge_l_buffer});
        high_s -= st_boundary_delta_s;
      }
    }
    if (has_low && has_high) {
      low_s -= st_boundary_delta_s;
      high_s += st_boundary_delta_s;
      double low_t =
          (first_traj_point.relativetime +
           std::fabs((low_s - object_boundary.starts) / object_s_diff) *
               delta_t);
      polygon_points.emplace_back(
          std::make_pair(STPoint{low_s - adc_start_s, low_t},
                         STPoint{high_s - adc_start_s, low_t}));
      double high_t =
          (first_traj_point.relativetime +
           std::fabs((high_s - object_boundary.starts) / object_s_diff) *
               delta_t);
      if (high_t - low_t > 0.05) {
        polygon_points.emplace_back(
            std::make_pair(STPoint{low_s - adc_start_s, high_t},
                           STPoint{high_s - adc_start_s, high_t}));
      }
    }
  }
  if (!polygon_points.empty()) {
    std::sort(polygon_points.begin(), polygon_points.end(),
              [](const std::pair<STPoint, STPoint>& a,
                 const std::pair<STPoint, STPoint>& b) {
                return a.first.t() < b.first.t();
              });
    auto last = std::unique(polygon_points.begin(), polygon_points.end(),
                            [](const std::pair<STPoint, STPoint>& a,
                               const std::pair<STPoint, STPoint>& b) {
                              return std::fabs(a.first.t() - b.first.t()) <
                                     kStBoundaryDeltaT;
                            });
    polygon_points.erase(last, polygon_points.end());
    if (polygon_points.size() > 2) {
      *st_boundary = STBoundary(polygon_points);
    }
  } else {
    return false;
  }
  return true;
}

const STBoundary& Obstacle::reference_line_st_boundary() const {
  return reference_line_st_boundary_;
}

const STBoundary& Obstacle::path_st_boundary() const {
  return path_st_boundary_;
}

const std::vector<std::string>& Obstacle::decider_tags() const {
  return decider_tags_;
}

const std::vector<apollo_msgs::msg::ApolloplanningObjectDecisionType>& Obstacle::decisions() const {
  return decisions_;
}

bool Obstacle::IsLateralDecision(const apollo_msgs::msg::ApolloplanningObjectDecisionType& decision) {
  return decision.objecttag.ignore != 0 || decision.objecttag.nudge != apollo_msgs::msg::ApolloplanningObjectNudge();
}

bool Obstacle::IsLongitudinalDecision(const apollo_msgs::msg::ApolloplanningObjectDecisionType& decision) {
  return decision.objecttag.ignore != 0 || decision.objecttag.stop != apollo_msgs::msg::ApolloplanningObjectStop() || decision.objecttag.yieldd != apollo_msgs::msg::ApolloplanningObjectYield() ||
         decision.objecttag.follow != apollo_msgs::msg::ApolloplanningObjectFollow() || decision.objecttag.overtake != apollo_msgs::msg::ApolloplanningObjectOvertake();
}

apollo_msgs::msg::ApolloplanningObjectDecisionType Obstacle::MergeLongitudinalDecision(
    const apollo_msgs::msg::ApolloplanningObjectDecisionType &lhs, const apollo_msgs::msg::ApolloplanningObjectDecisionType &rhs)
{
  if (object_tag_case(lhs) == ObjectDecisionType::OBJECT_TAG_NOT_SET) {
    return rhs;
  }
  if (object_tag_case(rhs) == ObjectDecisionType::OBJECT_TAG_NOT_SET) {
    return lhs;
  }
  const auto lhs_val =
      FindOrDie(s_longitudinal_decision_safety_sorter_, object_tag_case(lhs));
  const auto rhs_val =
      FindOrDie(s_longitudinal_decision_safety_sorter_, object_tag_case(rhs));
  if (lhs_val < rhs_val) {
    return rhs;
  } else if (lhs_val > rhs_val) {
    return lhs;
  } else {
    if (lhs.objecttag.ignore!=0) {
      return rhs;
    } else if (lhs.objecttag.stop!=apollo_msgs::msg::ApolloplanningObjectStop()) {
      return lhs.objecttag.stop.distances < rhs.objecttag.stop.distances ? lhs : rhs;
    }
    else if (lhs.objecttag.yieldd != apollo_msgs::msg::ApolloplanningObjectYield())
    {
      return lhs.objecttag.yieldd.distances < rhs.objecttag.yieldd.distances ? lhs : rhs;
    }
    else if (lhs.objecttag.follow != apollo_msgs::msg::ApolloplanningObjectFollow())
    {
      return lhs.objecttag.follow.distances < rhs.objecttag.follow.distances ? lhs : rhs;
    }
    else if (lhs.objecttag.overtake != apollo_msgs::msg::ApolloplanningObjectOvertake())
    {
      return lhs.objecttag.overtake.distances > rhs.objecttag.overtake.distances ? lhs
                                                                                 : rhs;
    }
    else
    {
      ACHECK(false) << "Unknown decision";
    }
  }
  return lhs;  // stop compiler complaining
}

const apollo_msgs::msg::ApolloplanningObjectDecisionType &Obstacle::LongitudinalDecision() const
{
  return longitudinal_decision_;
}

const apollo_msgs::msg::ApolloplanningObjectDecisionType& Obstacle::LateralDecision() const {
  return lateral_decision_;
}

bool Obstacle::IsIgnore() const {
  return IsLongitudinalIgnore() && IsLateralIgnore();
}

bool Obstacle::IsLongitudinalIgnore() const {
  return longitudinal_decision_.objecttag.ignore != 0;
}

bool Obstacle::IsLateralIgnore() const {
  return lateral_decision_.objecttag.ignore!=0;
}

ApolloplanningObjectDecisionType Obstacle::MergeLateralDecision(
    const ApolloplanningObjectDecisionType &lhs, const ApolloplanningObjectDecisionType &rhs)
{
  if (object_tag_case(lhs) == ObjectDecisionType::OBJECT_TAG_NOT_SET) {
    return rhs;
  }
  if (object_tag_case(rhs) == ObjectDecisionType::OBJECT_TAG_NOT_SET) {
    return lhs;
  }
  const auto lhs_val =
      FindOrDie(s_lateral_decision_safety_sorter_, object_tag_case(lhs));
  const auto rhs_val =
      FindOrDie(s_lateral_decision_safety_sorter_, object_tag_case(rhs));
  if (lhs_val < rhs_val) {
    return rhs;
  } else if (lhs_val > rhs_val) {
    return lhs;
  } else {
    if (lhs.objecttag.ignore!=0) {
      return rhs;
    }
    else if (lhs.objecttag.nudge != apollo_msgs::msg::ApolloplanningObjectNudge())
    {
      ACHECK(lhs.objecttag.nudge.type == rhs.objecttag.nudge.type)
          << "could not merge left nudge and right nudge";
      return std::fabs(lhs.objecttag.nudge.distancel) >
                     std::fabs(rhs.objecttag.nudge.distancel)
                 ? lhs
                 : rhs;
    }
  }
  ACHECK(false) << "Does not have rule to merge decision: "
                << lhs
                << " and decision: " << rhs;
  return lhs;
}

bool Obstacle::HasLateralDecision() const {
  return object_tag_case(lateral_decision_) !=
         ObjectDecisionType::OBJECT_TAG_NOT_SET;
}

bool Obstacle::HasLongitudinalDecision() const {
  return object_tag_case(longitudinal_decision_) !=
         ObjectDecisionType::OBJECT_TAG_NOT_SET;
}

bool Obstacle::HasNonIgnoreDecision() const {
  return (HasLateralDecision() && !IsLateralIgnore()) ||
         (HasLongitudinalDecision() && !IsLongitudinalIgnore());
}

void Obstacle::AddLongitudinalDecision(const std::string &decider_tag,
                                       const apollo_msgs::msg::ApolloplanningObjectDecisionType &decision)
{
  ACHECK(IsLongitudinalDecision(decision))
      << "Decision: " << decision
      << " is not a longitudinal decision";
  longitudinal_decision_ =
      MergeLongitudinalDecision(longitudinal_decision_, decision);
  ADEBUG << decider_tag << " added obstacle " << Id()
         << " longitudinal decision: " << decision
         << ". The merged decision is: "
         << longitudinal_decision_;
  decisions_.push_back(decision);
  decider_tags_.push_back(decider_tag);
}

void Obstacle::AddLateralDecision(const std::string& decider_tag,
                                  const apollo_msgs::msg::ApolloplanningObjectDecisionType& decision) {
  ACHECK(IsLateralDecision(decision))
      << "Decision: " << decision
      << " is not a lateral decision";
  lateral_decision_ = MergeLateralDecision(lateral_decision_, decision);
  ADEBUG << decider_tag << " added obstacle " << Id()
         << " a lateral decision: " << decision
         << ". The merged decision is: "
         << lateral_decision_;
  decisions_.push_back(decision);
  decider_tags_.push_back(decider_tag);
}

std::string Obstacle::DebugString() const {
  std::stringstream ss;
  ss << "Obstacle id: " << id_;
  for (size_t i = 0; i < decisions_.size(); ++i) {
    ss << " decision: " << decisions_[i] << ", made by "
       << decider_tags_[i];
  }
  if (object_tag_case(lateral_decision_) !=
      ObjectDecisionType::OBJECT_TAG_NOT_SET) {
    ss << "lateral decision: " << lateral_decision_;
  }
  if (object_tag_case(longitudinal_decision_) !=
      ObjectDecisionType::OBJECT_TAG_NOT_SET) {
    ss << "longitudinal decision: "
       << longitudinal_decision_;
  }
  return ss.str();
}

const SLBoundary& Obstacle::PerceptionSLBoundary() const {
  return sl_boundary_;
}

void Obstacle::set_path_st_boundary(const STBoundary& boundary) {
  path_st_boundary_ = boundary;
  path_st_boundary_initialized_ = true;
}

void Obstacle::SetStBoundaryType(const STBoundary::BoundaryType type) {
  path_st_boundary_.SetBoundaryType(type);
}

void Obstacle::EraseStBoundary() { path_st_boundary_ = STBoundary(); }

void Obstacle::SetReferenceLineStBoundary(const STBoundary& boundary) {
  reference_line_st_boundary_ = boundary;
}

void Obstacle::SetReferenceLineStBoundaryType(
    const STBoundary::BoundaryType type) {
  reference_line_st_boundary_.SetBoundaryType(type);
}

void Obstacle::EraseReferenceLineStBoundary() {
  reference_line_st_boundary_ = STBoundary();
}

bool Obstacle::IsValidObstacle(
    const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &perception_obstacle)
{
  const double object_width = perception_obstacle.width;
  const double object_length = perception_obstacle.length;

  const double kMinObjectDimension = 1.0e-6;
  return !std::isnan(object_width) && !std::isnan(object_length) &&
         object_width > kMinObjectDimension &&
         object_length > kMinObjectDimension;
}

void Obstacle::CheckLaneBlocking(const ReferenceLine& reference_line) {
  if (!IsStatic()) {
    is_lane_blocking_ = false;
    return;
  }
  ACHECK(sl_boundary_.starts!=0);
  ACHECK(sl_boundary_.ends != 0);
  ACHECK(sl_boundary_.startl!=0);
  ACHECK(sl_boundary_.endl!=0);

  if (sl_boundary_.startl * sl_boundary_.endl < 0.0) {
    is_lane_blocking_ = true;
    return;
  }

  const double driving_width = reference_line.GetDrivingWidth(sl_boundary_);
  auto vehicle_param = common::VehicleConfigHelper::GetConfig().vehicleparam;

  if (reference_line.IsOnLane(sl_boundary_) &&
      driving_width <
          vehicle_param.width + FLAGS_static_obstacle_nudge_l_buffer) {
    is_lane_blocking_ = true;
    return;
  }

  is_lane_blocking_ = false;
}

void Obstacle::SetLaneChangeBlocking(const bool is_distance_clear) {
  is_lane_change_blocking_ = is_distance_clear;
}

}  // namespace planning
}  // namespace apollo