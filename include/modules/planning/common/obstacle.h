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

#pragma once

#include <list>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "modules/common/configs/proto/vehicle_config.pb.h"
#include "modules/common/math/box2d.h"
#include "modules/common/math/vec2d.h"
#include "modules/perception/proto/perception_obstacle.pb.h"
#include "modules/planning/common/indexed_list.h"
#include "modules/planning/common/speed/st_boundary.h"
#include "modules/planning/proto/decision.pb.h"
#include "modules/planning/proto/sl_boundary.pb.h"
#include "modules/planning/reference_line/reference_line.h"
#include "modules/prediction/proto/prediction_obstacle.pb.h"
#include "modules/planning/proto/enum.h"
namespace apollo {
namespace planning {

/**
 * @class Obstacle
 * @brief This is the class that associates an Obstacle with its path
 * properties. An obstacle's path properties relative to a path.
 * The `s` and `l` values are examples of path properties.
 * The decision of an obstacle is also associated with a path.
 *
 * The decisions have two categories: lateral decision and longitudinal
 * decision.
 * Lateral decision includes: nudge, ignore.
 * Lateral decision safety priority: nudge > ignore.
 * Longitudinal decision includes: stop, yield, follow, overtake, ignore.
 * Decision safety priorities order: stop > yield >= follow > overtake > ignore
 *
 * Ignore decision belongs to both lateral decision and longitudinal decision,
 * and it has the lowest priority.
 */
class Obstacle {
 public:
  Obstacle() = default;
  Obstacle(const std::string& id,
           const apollo_msgs::msg::ApolloperceptionPerceptionObstacle& perception_obstacle,
           const prediction::ObstaclePriority::Priority& obstacle_priority,
           const bool is_static);
  Obstacle(const std::string& id,
           const apollo_msgs::msg::ApolloperceptionPerceptionObstacle& perception_obstacle,
           const prediction::Trajectory& trajectory,
           const prediction::ObstaclePriority::Priority& obstacle_priority,
           const bool is_static);

  const std::string& Id() const { return id_; }
  void SetId(const std::string& id) { id_ = id; }

  double speed() const { return speed_; }

  int32_t PerceptionId() const { return perception_id_; }

  bool IsStatic() const { return is_static_; }
  bool IsVirtual() const { return is_virtual_; }

  common::TrajectoryPoint GetPointAtTime(const double time) const;

  common::math::Box2d GetBoundingBox(
      const common::TrajectoryPoint& point) const;

  const common::math::Box2d& PerceptionBoundingBox() const {
    return perception_bounding_box_;
  }
  const common::math::Polygon2d& PerceptionPolygon() const {
    return perception_polygon_;
  }
  const prediction::Trajectory& Trajectory() const { return trajectory_; }
  common::TrajectoryPoint* AddTrajectoryPoint() {
    apollo_msgs::msg::ApollocommonTrajectoryPoint rf;
    auto *pt=&rf;
    trajectory_.trajectorypoint.push_back(*pt);
    return pt;
  }
  bool HasTrajectory() const {
    return !(trajectory_.trajectorypoint.empty());
  }

  const apollo_msgs::msg::ApolloperceptionPerceptionObstacle& Perception() const {
    return perception_obstacle_;
  }

  /**
   * @brief This is a helper function that can create obstacles from prediction
   * data.  The original prediction may have multiple trajectories for each
   * obstacle. But this function will create one obstacle for each trajectory.
   * @param predictions The prediction results
   * @return obstacles The output obstacles saved in a list of unique_ptr.
   */
  static std::list<std::unique_ptr<Obstacle>> CreateObstacles(
      const prediction::PredictionObstacles& predictions);

  static std::unique_ptr<Obstacle> CreateStaticVirtualObstacles(
      const std::string& id, const common::math::Box2d& obstacle_box);

  static bool IsValidPerceptionObstacle(
      const apollo_msgs::msg::ApolloperceptionPerceptionObstacle& obstacle);

  static bool IsValidTrajectoryPoint(const common::TrajectoryPoint& point);

  inline bool IsCautionLevelObstacle() const {
    return is_caution_level_obstacle_;
  }

  // const Obstacle* obstacle() const;

  /**
   * return the merged lateral decision
   * Lateral decision is one of {Nudge, Ignore}
   **/
  const apollo_msgs::msg::ApolloplanningObjectDecisionType& LateralDecision() const;

  /**
   * @brief return the merged longitudinal decision
   * Longitudinal decision is one of {Stop, Yield, Follow, Overtake, Ignore}
   **/
  const apollo_msgs::msg::ApolloplanningObjectDecisionType& LongitudinalDecision() const;

  std::string DebugString() const;

  const SLBoundary& PerceptionSLBoundary() const;

  const STBoundary& reference_line_st_boundary() const;

  const STBoundary& path_st_boundary() const;

  const std::vector<std::string>& decider_tags() const;

  const std::vector<apollo_msgs::msg::ApolloplanningObjectDecisionType>& decisions() const;

  void AddLongitudinalDecision(const std::string& decider_tag,
                               const apollo_msgs::msg::ApolloplanningObjectDecisionType& decision);

  void AddLateralDecision(const std::string& decider_tag,
                          const apollo_msgs::msg::ApolloplanningObjectDecisionType& decision);
  bool HasLateralDecision() const;

  void set_path_st_boundary(const STBoundary& boundary);

  bool is_path_st_boundary_initialized() {
    return path_st_boundary_initialized_;
  }

  void SetStBoundaryType(const STBoundary::BoundaryType type);

  void EraseStBoundary();

  void SetReferenceLineStBoundary(const STBoundary& boundary);

  void SetReferenceLineStBoundaryType(const STBoundary::BoundaryType type);

  void EraseReferenceLineStBoundary();

  bool HasLongitudinalDecision() const;

  bool HasNonIgnoreDecision() const;

  /**
   * @brief Calculate stop distance with the obstacle using the ADC's minimum
   * turning radius
   */
  double MinRadiusStopDistance(const common::VehicleParam& vehicle_param) const;

  /**
   * @brief Check if this object can be safely ignored.
   * The object will be ignored if the lateral decision is ignore and the
   * longitudinal decision is ignore
   *  return longitudinal_decision_ == ignore && lateral_decision == ignore.
   */
  bool IsIgnore() const;
  bool IsLongitudinalIgnore() const;
  bool IsLateralIgnore() const;

  void BuildReferenceLineStBoundary(const ReferenceLine& reference_line,
                                    const double adc_start_s);

  void SetPerceptionSlBoundary(const SLBoundary& sl_boundary);

  /**
   * @brief check if an apollo_msgs::msg::ApolloplanningObjectDecisionType is a longitudinal decision.
   **/
  static bool IsLongitudinalDecision(const apollo_msgs::msg::ApolloplanningObjectDecisionType& decision);

  /**
   * @brief check if an apollo_msgs::msg::ApolloplanningObjectDecisionType is a lateral decision.
   **/
  static bool IsLateralDecision(const apollo_msgs::msg::ApolloplanningObjectDecisionType& decision);

  void SetBlockingObstacle(bool blocking) { is_blocking_obstacle_ = blocking; }
  bool IsBlockingObstacle() const { return is_blocking_obstacle_; }

  /*
   * @brief IsLaneBlocking is only meaningful when IsStatic() == true.
   */
  bool IsLaneBlocking() const { return is_lane_blocking_; }
  void CheckLaneBlocking(const ReferenceLine& reference_line);
  bool IsLaneChangeBlocking() const { return is_lane_change_blocking_; }
  void SetLaneChangeBlocking(const bool is_distance_clear);

 private:
  FRIEND_TEST(MergeLongitudinalDecision, AllDecisions);
  static apollo_msgs::msg::ApolloplanningObjectDecisionType MergeLongitudinalDecision(
      const apollo_msgs::msg::ApolloplanningObjectDecisionType& lhs, const apollo_msgs::msg::ApolloplanningObjectDecisionType& rhs);
  FRIEND_TEST(MergeLateralDecision, AllDecisions);
  static apollo_msgs::msg::ApolloplanningObjectDecisionType MergeLateralDecision(const apollo_msgs::msg::ApolloplanningObjectDecisionType& lhs,
                                                 const apollo_msgs::msg::ApolloplanningObjectDecisionType& rhs);

  bool BuildTrajectoryStBoundary(const ReferenceLine& reference_line,
                                 const double adc_start_s,
                                 STBoundary* const st_boundary);
  bool IsValidObstacle(
      const apollo_msgs::msg::ApolloperceptionPerceptionObstacle& perception_obstacle);

 private:
  std::string id_;
  int32_t perception_id_ = 0;
  bool is_static_ = false;
  bool is_virtual_ = false;
  double speed_ = 0.0;

  bool path_st_boundary_initialized_ = false;

  prediction::Trajectory trajectory_;
  apollo_msgs::msg::ApolloperceptionPerceptionObstacle perception_obstacle_;
  common::math::Box2d perception_bounding_box_;
  common::math::Polygon2d perception_polygon_;

  std::vector<apollo_msgs::msg::ApolloplanningObjectDecisionType> decisions_;
  std::vector<std::string> decider_tags_;
  SLBoundary sl_boundary_;

  STBoundary reference_line_st_boundary_;
  STBoundary path_st_boundary_;

  apollo_msgs::msg::ApolloplanningObjectDecisionType lateral_decision_;
  apollo_msgs::msg::ApolloplanningObjectDecisionType longitudinal_decision_;

  // for keep_clear usage only
  bool is_blocking_obstacle_ = false;

  bool is_lane_blocking_ = false;

  bool is_lane_change_blocking_ = false;

  bool is_caution_level_obstacle_ = false;

  double min_radius_stop_distance_ = -1.0;

  struct ObjectTagCaseHash {
    size_t operator()(
        const apollo::planning::ObjectDecisionType tag) const {
      return (int)tag;
    }
  };

  static const std::unordered_map<apollo::planning::ObjectDecisionType, int,
                                  ObjectTagCaseHash>
      s_lateral_decision_safety_sorter_;
  static const std::unordered_map<apollo::planning::ObjectDecisionType, int,
                                  ObjectTagCaseHash>
      s_longitudinal_decision_safety_sorter_;
};

typedef IndexedList<std::string, Obstacle> IndexedObstacles;
typedef ThreadSafeIndexedList<std::string, Obstacle> ThreadSafeIndexedObstacles;

}  // namespace planning
}  // namespace apollo