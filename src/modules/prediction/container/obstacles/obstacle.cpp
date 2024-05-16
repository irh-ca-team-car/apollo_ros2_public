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

#include "modules/prediction/container/obstacles/obstacle.h"

#include <algorithm>
#include <iomanip>
#include <limits>

#include "modules/common/util/util.h"
#include "modules/prediction/common/junction_analyzer.h"
#include "modules/prediction/common/prediction_constants.h"
#include "modules/prediction/common/prediction_system_gflags.h"
#include "modules/prediction/container/obstacles/obstacle_clusters.h"
#include "modules/prediction/network/rnn_model/rnn_model.h"

namespace apollo
{
  namespace prediction
  {
    namespace
    {

      using apollo::common::PathPoint;
      using apollo::common::Point3D;
      using apollo::hdmap::JunctionInfo;
      using apollo::hdmap::LaneInfo;
      using apollo_msgs::msg::ApolloperceptionPerceptionObstacle;

      double Damp(const double x, const double sigma)
      {
        return 1.0 / (1.0 + std::exp(1.0 / (std::fabs(x) + sigma)));
      }

      bool IsClosed(const double x0, const double y0, const double theta0,
                    const double x1, const double y1, const double theta1)
      {
        double angle_diff = std::fabs(common::math::AngleDiff(theta0, theta1));
        double distance = std::hypot(x0 - x1, y0 - y1);
        return distance < FLAGS_distance_threshold_to_junction_exit &&
               angle_diff < FLAGS_angle_threshold_to_junction_exit;
      }

    } // namespace

    apollo::perception::PerceptionObstacle::Type Obstacle::type() const { return type_; }

    bool Obstacle::IsPedestrian() const
    {
      return type_ == apollo::perception::PerceptionObstacle::PEDESTRIAN;
    }

    int Obstacle::id() const { return id_; }

    double Obstacle::timestamp() const
    {
      ACHECK(!feature_history_.empty());
      return feature_history_.front().timestamp;
    }

    const Feature &Obstacle::feature(const size_t i) const
    {
      ACHECK(i < feature_history_.size());
      return feature_history_[i];
    }

    Feature *Obstacle::mutable_feature(const size_t i)
    {
      ACHECK(!feature_history_.empty());
      ACHECK(i < feature_history_.size());
      return &feature_history_[i];
    }

    const Feature &Obstacle::latest_feature() const
    {
      ACHECK(!feature_history_.empty());
      return feature_history_.front();
    }

    const Feature &Obstacle::earliest_feature() const
    {
      ACHECK(!feature_history_.empty());
      return feature_history_.back();
    }

    Feature *Obstacle::mutable_latest_feature()
    {
      ACHECK(!feature_history_.empty());
      return &(feature_history_.front());
    }

    size_t Obstacle::history_size() const { return feature_history_.size(); }

    bool Obstacle::IsStill()
    {
      if (feature_history_.size() > 0)
      {
        return feature_history_.front().isstill;
      }
      return true;
    }

    bool Obstacle::IsSlow()
    {
      const Feature &feature = latest_feature();
      return feature.speed < FLAGS_slow_obstacle_speed_threshold;
    }

    bool Obstacle::IsOnLane() const
    {
      /*if (feature_history_.empty() || !latest_feature() ||
      latest_feature().lane.current_lane_feature().empty()) {
    return false;
  }
  for (const auto& curr_lane : latest_feature().lane().current_lane_feature()) {
    if (curr_lane.lane_type() != hdmap::Lane::CITY_DRIVING) {
      return false;
    }
  }*/
      //FIND WORK ARROUND MISSING LANE

      ADEBUG << "Obstacle [" << id_ << "] is on lane.";
      return true;
    }

    bool Obstacle::ToIgnore()
    {
      if (feature_history_.empty())
      {
        return true;
      }
      return latest_feature().priority.priority == ObstaclePriority::IGNORE;
    }

    bool Obstacle::IsNearJunction()
    {
      if (feature_history_.empty())
      {
        return false;
      }
      double pos_x = latest_feature().position.x;
      double pos_y = latest_feature().position.y;
      return PredictionMap::NearJunction({pos_x, pos_y},
                                         FLAGS_junction_search_radius);
    }

    bool Obstacle::Insert(const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &perception_obstacle,
                          const double timestamp,
                          const int prediction_obstacle_id)
    {

      if (ReceivedOlderMessage(timestamp))
      {
        AERROR << "Obstacle [" << id_ << "] received an older frame ["
               << std::setprecision(20) << timestamp
               << "] than the most recent timestamp [ " << this->timestamp()
               << "].";
        return false;
      }

      // Set ID, Type, and Status of the feature.
      Feature feature;
      if (!SetId(perception_obstacle, &feature, prediction_obstacle_id))
      {
        return false;
      }

      SetType(perception_obstacle, &feature);

      SetStatus(perception_obstacle, timestamp, &feature);

      // Set obstacle lane features
      if (type_ != apollo::perception::PerceptionObstacle::PEDESTRIAN)
      {
        SetCurrentLanes(&feature);
        SetNearbyLanes(&feature);
      }

      if (FLAGS_prediction_offline_mode ==
          PredictionConstants::kDumpDataForLearning)
      {
        SetSurroundingLaneIds(&feature, FLAGS_surrounding_lane_search_radius);
      }

      if (FLAGS_adjust_vehicle_heading_by_lane &&
          type_ == perception::PerceptionObstacle::VEHICLE)
      {
        AdjustHeadingByLane(&feature);
      }

      // Insert obstacle feature to history
      InsertFeatureToHistory(feature);

      // Set obstacle motion status
      if (FLAGS_use_navigation_mode)
      {
        SetMotionStatusBySpeed();
      }
      else
      {
        SetMotionStatus();
      }

      // Trim historical features
      DiscardOutdatedHistory();
      return true;
    }

    bool Obstacle::InsertFeature(const Feature &feature)
    {
      InsertFeatureToHistory(feature);
      type_ = (apollo::perception::PerceptionObstacle::Type)feature.type;
      id_ = feature.id;
      return true;
    }

    void Obstacle::ClearOldInformation()
    {
      if (feature_history_.size() <= 1)
      {
        return;
      }
      feature_history_[1].predictedtrajectory.clear();

      Lane &lane = feature_history_[1].lane;
      lane.currentlanefeature.clear();
      lane.nearbylanefeature.clear();
      lane.lanegraph.lanesequence.clear();
      lane.lanegraphordered.lanesequence.clear();
    }

    void Obstacle::TrimHistory(const size_t remain_size)
    {
      if (feature_history_.size() > remain_size)
      {
        feature_history_.resize(remain_size);
      }
    }

    bool Obstacle::IsInJunction(const std::string &junction_id) const
    {
      // TODO(all) Consider if need to use vehicle front rather than position
      if (feature_history_.empty())
      {
        AERROR << "Obstacle [" << id_ << "] has no history";
        return false;
      }
      if (junction_id.empty())
      {
        return false;
      }
      std::shared_ptr<const JunctionInfo> junction_info_ptr =
          PredictionMap::JunctionById(junction_id);
      if (junction_info_ptr == nullptr)
      {
        return false;
      }
      const auto &position = latest_feature().position;
      return PredictionMap::IsPointInJunction(position.x, position.y,
                                              junction_info_ptr);
    }

    void Obstacle::BuildJunctionFeature()
    {
      // If obstacle has no history at all, then exit.
      if (feature_history_.empty())
      {
        AERROR << "Obstacle [" << id_ << "] has no history";
        return;
      }
      // If obstacle is not in the given junction, then exit.
      const std::string &junction_id = junction_analyzer_->GetJunctionId();
      if (!IsInJunction(junction_id))
      {
        ADEBUG << "Obstacle [" << id_ << "] is not in junction [" << junction_id
               << "]";
        return;
      }

      // Set the junction features by calling SetJunctionFeatureWithoutEnterLane.
      Feature *latest_feature_ptr = mutable_latest_feature();
      if (feature_history_.size() == 1)
      {
        SetJunctionFeatureWithoutEnterLane(latest_feature_ptr);
        return;
      }
      const Feature &prev_feature = feature(1);
      if (prev_feature.junctionfeature.enterlane != apollo_msgs::msg::ApollopredictionLaneFeature())
      {
        ACHECK(prev_feature.junctionfeature.enterlane.laneid != std::string());
        std::string enter_lane_id =
            prev_feature.junctionfeature.enterlane.laneid;
        // TODO(all) use enter lane when tracking is better
        SetJunctionFeatureWithoutEnterLane(latest_feature_ptr);
      }
      else
      {
        SetJunctionFeatureWithoutEnterLane(latest_feature_ptr);
      }
    }

    bool Obstacle::IsCloseToJunctionExit() const
    {
      if (!HasJunctionFeatureWithExits())
      {
        AERROR << "No junction feature found";
        return false;
      }
      CHECK_GT(history_size(), 0U);
      const Feature &latest_feature = feature_history_.front();
      double position_x = latest_feature.position.x;
      double position_y = latest_feature.position.y;
      double raw_velocity_heading = std::atan2(latest_feature.rawvelocity.y,
                                               latest_feature.rawvelocity.x);
      for (const JunctionExit &junction_exit :
           latest_feature.junctionfeature.junctionexit)
      {
        double exit_x = junction_exit.exitposition.x;
        double exit_y = junction_exit.exitposition.y;
        double exit_heading = junction_exit.exitheading;
        if (IsClosed(position_x, position_y, raw_velocity_heading, exit_x, exit_y,
                     exit_heading))
        {
          return true;
        }
      }
      return false;
    }

    void Obstacle::SetJunctionFeatureWithEnterLane(const std::string &enter_lane_id,
                                                   Feature *const feature_ptr)
    {
      feature_ptr->junctionfeature = (junction_analyzer_->GetJunctionFeature(enter_lane_id));
    }

    void Obstacle::SetJunctionFeatureWithoutEnterLane(Feature *const feature_ptr)
    {
      // Sanity checks.
      (void)feature_ptr;
      if (feature_ptr->lane == Lane())
      {
        ADEBUG << "Obstacle [" << id_ << "] has no lane.";
        return;
      }

      // Get the possible lanes that the obstalce is on and their neighbor
      // lanes and treat them as the starting-lane-segments.
      std::vector<std::string> start_lane_ids;
      if (feature_ptr->lane.currentlanefeature.size() > 0)
      {
        for (const auto &lane_feature :
             feature_ptr->lane.currentlanefeature)
        {
          start_lane_ids.push_back(lane_feature.laneid);
        }
      }
      if (feature_ptr->lane.nearbylanefeature.size() > 0)
      {
        for (const auto &lane_feature : feature_ptr->lane.nearbylanefeature)
        {
          start_lane_ids.push_back(lane_feature.laneid);
        }
      }
      if (start_lane_ids.empty())
      {
        ADEBUG << "Obstacle [" << id_ << "] has no lane in junction";
        return;
      }
      // TODO(kechxu) Maybe output all exits if no start lane found
      feature_ptr->junctionfeature = (junction_analyzer_->GetJunctionFeature(start_lane_ids));
    }

    void Obstacle::SetStatus(const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &perception_obstacle,
                             const double timestamp, Feature *feature)
    {
      SetTimestamp(perception_obstacle, timestamp, feature);
      SetPolygonPoints(perception_obstacle, feature);
      SetPosition(perception_obstacle, feature);
      SetVelocity(perception_obstacle, feature);
      SetAcceleration(feature);
      SetTheta(perception_obstacle, feature);
      SetLengthWidthHeight(perception_obstacle, feature);
      SetIsNearJunction(perception_obstacle, feature);
    }

    bool Obstacle::SetId(const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &perception_obstacle,
                         Feature *feature, const int prediction_obstacle_id)
    {
      int id = prediction_obstacle_id > 0 ? prediction_obstacle_id
                                          : perception_obstacle.id;
      if (id_ < 0)
      {
        id_ = id;
        ADEBUG << "Obstacle has id [" << id_ << "].";
      }
      else
      {
        if (id_ != id)
        {
          AERROR << "Obstacle [" << id_ << "] has a mismatched ID [" << id
                 << "] from perception obstacle.";
          return false;
        }
      }
      feature->set__id(id);
      return true;
    }

    void Obstacle::SetType(const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &perception_obstacle,
                           Feature *feature)
    {
      type_ = (apollo::perception::PerceptionObstacle::Type)perception_obstacle.type;
      ADEBUG << "Obstacle [" << id_ << "] has type [" << type_ << "].";
      feature->set__type(type_);
    }

    void Obstacle::SetTimestamp(const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &perception_obstacle,
                                const double timestamp, Feature *feature)
    {
      (void)perception_obstacle;
      double ts = timestamp;
      feature->set__timestamp(ts);

      ADEBUG << "Obstacle [" << id_ << "] has timestamp [" << std::fixed
             << std::setprecision(6) << ts << "].";
    }

    void Obstacle::SetPolygonPoints(const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &perception_obstacle,
                                    Feature *feature)
    {
      for (const auto &polygon_point : perception_obstacle.polygonpoint)
      {
        feature->polygonpoint.push_back(polygon_point);
        ADEBUG << "Obstacle [" << id_
               << "] has new corner point:" << polygon_point;
      }
    }

    void Obstacle::SetPosition(const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &perception_obstacle,
                               Feature *feature)
    {
      feature->position = perception_obstacle.position;
      ADEBUG << "Obstacle [" << id_
             << "] has position:" << perception_obstacle.position;
    }

    void Obstacle::SetVelocity(const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &perception_obstacle,
                               Feature *feature)
    {
      double velocity_x = 0.0;
      double velocity_y = 0.0;
      double velocity_z = 0.0;

      velocity_x = perception_obstacle.velocity.x;
      if (std::isnan(velocity_x))
      {
        AERROR << "Found nan velocity_x from perception obstacle";
        velocity_x = 0.0;
      }
      else if (velocity_x > 50.0 || velocity_x < -50.0)
      {
        AERROR << "Found unreasonable velocity_x from perception obstacle";
      }
      velocity_y = perception_obstacle.velocity.y;
      if (std::isnan(velocity_y))
      {
        AERROR << "Found nan velocity_y from perception obstacle";
        velocity_y = 0.0;
      }
      else if (velocity_y > 50.0 || velocity_y < -50.0)
      {
        AERROR << "Found unreasonable velocity_y from perception obstacle";
      }
      velocity_z = perception_obstacle.velocity.z;
      if (std::isnan(velocity_z))
      {
        AERROR << "Found nan velocity z from perception obstacle";
        velocity_z = 0.0;
      }
      else if (velocity_z > 50.0 || velocity_z < -50.0)
      {
        AERROR << "Found unreasonable velocity_z from perception obstacle";
      }

      feature->rawvelocity.set__x(velocity_x);
      feature->rawvelocity.set__y(velocity_y);
      feature->rawvelocity.set__z(velocity_z);

      double speed = std::hypot(velocity_x, velocity_y);
      double velocity_heading = std::atan2(velocity_y, velocity_x);
      if (FLAGS_adjust_velocity_by_obstacle_heading || speed < 0.1)
      {
        velocity_heading = perception_obstacle.theta;
      }

      if (!FLAGS_use_navigation_mode && FLAGS_adjust_velocity_by_position_shift &&
          history_size() > 0)
      {
        double diff_x =
            feature->position.x - feature_history_.front().position.x;
        double diff_y =
            feature->position.y - feature_history_.front().position.y;
        double prev_obstacle_size = std::fmax(feature_history_.front().length,
                                              feature_history_.front().width);
        double obstacle_size =
            std::fmax(perception_obstacle.length, perception_obstacle.width);
        double size_diff = std::abs(obstacle_size - prev_obstacle_size);
        double shift_thred =
            std::fmax(obstacle_size * FLAGS_valid_position_diff_rate_threshold,
                      FLAGS_valid_position_diff_threshold);
        double size_diff_thred =
            FLAGS_split_rate * std::min(obstacle_size, prev_obstacle_size);
        if (std::fabs(diff_x) > shift_thred && std::fabs(diff_y) > shift_thred &&
            size_diff < size_diff_thred)
        {
          double shift_heading = std::atan2(diff_y, diff_x);
          double angle_diff =
              common::math::NormalizeAngle(shift_heading - velocity_heading);
          if (std::fabs(angle_diff) > FLAGS_max_lane_angle_diff)
          {
            ADEBUG << "Shift velocity heading to be " << shift_heading;
            velocity_heading = shift_heading;
          }
        }
        velocity_x = speed * std::cos(velocity_heading);
        velocity_y = speed * std::sin(velocity_heading);
      }

      feature->velocity.set__x(velocity_x);
      feature->velocity.set__y(velocity_y);
      feature->velocity.set__z(velocity_z);
      feature->set__velocityheading(velocity_heading);
      feature->set__speed(speed);

      ADEBUG << "Obstacle [" << id_ << "] has velocity [" << std::fixed
             << std::setprecision(6) << velocity_x << ", " << std::fixed
             << std::setprecision(6) << velocity_y << ", " << std::fixed
             << std::setprecision(6) << velocity_z << "]";
      ADEBUG << "Obstacle [" << id_ << "] has velocity heading [" << std::fixed
             << std::setprecision(6) << velocity_heading << "] ";
      ADEBUG << "Obstacle [" << id_ << "] has speed [" << std::fixed
             << std::setprecision(6) << speed << "].";
    }

    void Obstacle::AdjustHeadingByLane(Feature *feature)
    {
      (void)feature;

      if ((feature->lane == Lane()) || (feature->lane.lanefeature == LaneFeature()))
      {
        return;
      }
      double velocity_heading = feature->velocityheading;
      double lane_heading = feature->lane.lanefeature.laneheading;
      double angle_diff = feature->lane.lanefeature.anglediff;
      if (std::abs(angle_diff) < FLAGS_max_angle_diff_to_adjust_velocity)
      {
        velocity_heading = lane_heading;
        double speed = feature->speed;
        feature->velocity.set__x(speed * std::cos(velocity_heading));
        feature->velocity.set__y(speed * std::sin(velocity_heading));
        feature->set__velocityheading(velocity_heading);
      }
    }

    void Obstacle::UpdateVelocity(const double theta, double *velocity_x,
                                  double *velocity_y, double *velocity_heading,
                                  double *speed)
    {
      *speed = std::hypot(*velocity_x, *velocity_y);
      double angle_diff = common::math::NormalizeAngle(*velocity_heading - theta);
      if (std::fabs(angle_diff) <= FLAGS_max_lane_angle_diff)
      {
        *velocity_heading = theta;
        *velocity_x = *speed * std::cos(*velocity_heading);
        *velocity_y = *speed * std::sin(*velocity_heading);
      }
    }

    void Obstacle::SetAcceleration(Feature *feature)
    {
      double acc_x = 0.0;
      double acc_y = 0.0;
      double acc_z = 0.0;
      double acc = 0.0;

      if (feature_history_.size() > 0)
      {
        double curr_ts = feature->timestamp;
        double prev_ts = feature_history_.front().timestamp;

        const Point3D &curr_velocity = feature->velocity;
        const Point3D &prev_velocity = feature_history_.front().velocity;

        if (curr_ts > prev_ts)
        {
          // A damp function is to punish acc calculation for low speed
          double damping_x = Damp(curr_velocity.x, 0.001);
          double damping_y = Damp(curr_velocity.y, 0.001);
          double damping_z = Damp(curr_velocity.z, 0.001);

          acc_x = (curr_velocity.x - prev_velocity.x) / (curr_ts - prev_ts);
          acc_y = (curr_velocity.y - prev_velocity.y) / (curr_ts - prev_ts);
          acc_z = (curr_velocity.z - prev_velocity.z) / (curr_ts - prev_ts);

          acc_x *= damping_x;
          acc_y *= damping_y;
          acc_z *= damping_z;

          acc_x = common::math::Clamp(acc_x, FLAGS_vehicle_min_linear_acc,
                                      FLAGS_vehicle_max_linear_acc);
          acc_y = common::math::Clamp(acc_y, FLAGS_vehicle_min_linear_acc,
                                      FLAGS_vehicle_max_linear_acc);
          acc_z = common::math::Clamp(acc_z, FLAGS_vehicle_min_linear_acc,
                                      FLAGS_vehicle_max_linear_acc);

          double heading = feature->velocityheading;
          acc = acc_x * std::cos(heading) + acc_y * std::sin(heading);
        }
      }

      feature->acceleration.set__x(acc_x);
      feature->acceleration.set__y(acc_y);
      feature->acceleration.set__z(acc_z);
      feature->set__acc(acc);

      ADEBUG << "Obstacle [" << id_ << "] has acceleration [" << std::fixed
             << std::setprecision(6) << acc_x << ", " << std::fixed
             << std::setprecision(6) << acc_y << ", " << std::fixed
             << std::setprecision(6) << acc_z << "]";
      ADEBUG << "Obstacle [" << id_ << "] has acceleration value [" << std::fixed
             << std::setprecision(6) << acc << "].";
    }

    void Obstacle::SetTheta(const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &perception_obstacle,
                            Feature *feature)
    {
      double theta = 0.0;
      theta = perception_obstacle.theta;
      feature->set__theta(theta);

      ADEBUG << "Obstacle [" << id_ << "] has theta [" << std::fixed
             << std::setprecision(6) << theta << "].";
    }

    void Obstacle::SetLengthWidthHeight(
        const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &perception_obstacle, Feature *feature)
    {
      double length = 0.0;
      double width = 0.0;
      double height = 0.0;

      length = perception_obstacle.length;
      width = perception_obstacle.width;
      height = perception_obstacle.height;

      feature->set__length(length);
      feature->set__width(width);
      feature->set__height(height);

      ADEBUG << "Obstacle [" << id_ << "] has dimension [" << std::fixed
             << std::setprecision(6) << length << ", " << std::fixed
             << std::setprecision(6) << width << ", " << std::fixed
             << std::setprecision(6) << height << "].";
    }

    void Obstacle::SetIsNearJunction(const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &perception_obstacle,
                                     Feature *feature)
    {

      double x = perception_obstacle.position.x;
      double y = perception_obstacle.position.y;
      bool is_near_junction =
          PredictionMap::NearJunction({x, y}, FLAGS_junction_search_radius);
      feature->set__isnearjunction(is_near_junction);
    }

    bool Obstacle::HasJunctionFeatureWithExits() const
    {
      if (history_size() == 0)
      {
        return false;
      }
      return latest_feature().junctionfeature.junctionexit.size() > 0;
    }

    void Obstacle::SetCurrentLanes(Feature *feature)
    {
      Eigen::Vector2d point(feature->position.x, feature->position.y);
      double heading = feature->velocityheading;
      int max_num_lane = FLAGS_max_num_current_lane;
      double max_angle_diff = FLAGS_max_lane_angle_diff;
      double lane_search_radius = FLAGS_lane_search_radius;
      if (PredictionMap::InJunction(point, FLAGS_junction_search_radius))
      {
        max_num_lane = FLAGS_max_num_current_lane_in_junction;
        max_angle_diff = FLAGS_max_lane_angle_diff_in_junction;
        lane_search_radius = FLAGS_lane_search_radius_in_junction;
      }
      std::vector<std::shared_ptr<const LaneInfo>> current_lanes;
      PredictionMap::OnLane(current_lanes_, point, heading, lane_search_radius,
                            true, max_num_lane, max_angle_diff, &current_lanes);
      current_lanes_ = current_lanes;
      if (current_lanes_.empty())
      {
        ADEBUG << "Obstacle [" << id_ << "] has no current lanes.";
        return;
      }
      Lane lane;
      //if (feature->has_lane()) {
      //  lane = feature->lane();
      //}
      double min_heading_diff = std::numeric_limits<double>::infinity();
      for (std::shared_ptr<const LaneInfo> current_lane : current_lanes)
      {
        if (current_lane == nullptr)
        {
          continue;
        }

        int turn_type = PredictionMap::LaneTurnType(current_lane->id().id);
        std::string lane_id = current_lane->id().id;
        double s = 0.0;
        double l = 0.0;
        PredictionMap::GetProjection(point, current_lane, &s, &l);
        if (s < 0.0)
        {
          continue;
        }

        common::math::Vec2d vec_point(point[0], point[1]);
        double distance = 0.0;
        common::PointENU nearest_point =
            current_lane->GetNearestPoint(vec_point, &distance);
        double nearest_point_heading =
            PredictionMap::PathHeading(current_lane, nearest_point);
        double angle_diff = common::math::AngleDiff(heading, nearest_point_heading);
        double left = 0.0;
        double right = 0.0;
        current_lane->GetWidth(s, &left, &right);
        LaneFeature &lane_feature = lane.currentlanefeature.emplace_back();
        lane_feature.set__laneturntype(turn_type);
        lane_feature.set__laneid(lane_id);
        lane_feature.set__lanes(s);
        lane_feature.set__lanel(l);
        lane_feature.set__anglediff(angle_diff);
        lane_feature.set__laneheading(nearest_point_heading);
        lane_feature.set__disttoleftboundary(left - l);
        lane_feature.set__disttorightboundary(right + l);
        lane_feature.set__lanetype(current_lane->lane().type);
        if (std::fabs(angle_diff) < min_heading_diff)
        {
          lane.lanefeature = (lane_feature);
          min_heading_diff = std::fabs(angle_diff);
        }
        clusters_ptr_->AddObstacle(id_, lane_id, s, l);
        ADEBUG << "Obstacle [" << id_ << "] has current lanes ["
               << lane_feature << "].";
      }

      feature->lane = (lane);
    }

    void Obstacle::SetNearbyLanes(Feature *feature)
    {
      Eigen::Vector2d point(feature->position.x, feature->position.y);
      int max_num_lane = FLAGS_max_num_nearby_lane;
      double lane_search_radius = FLAGS_lane_search_radius;
      if (PredictionMap::InJunction(point, FLAGS_junction_search_radius))
      {
        max_num_lane = FLAGS_max_num_nearby_lane_in_junction;
        lane_search_radius = FLAGS_lane_search_radius_in_junction;
      }
      double theta = feature->velocityheading;
      std::vector<std::shared_ptr<const LaneInfo>> nearby_lanes;
      PredictionMap::NearbyLanesByCurrentLanes(point, theta, lane_search_radius,
                                               current_lanes_, max_num_lane,
                                               &nearby_lanes);
      if (nearby_lanes.empty())
      {
        ADEBUG << "Obstacle [" << id_ << "] has no nearby lanes.";
        return;
      }

      for (std::shared_ptr<const LaneInfo> nearby_lane : nearby_lanes)
      {
        if (nearby_lane == nullptr)
        {
          continue;
        }

        // Ignore bike and sidewalk lanes for vehicles
        if (type_ == perception::PerceptionObstacle::VEHICLE &&

            (nearby_lane->lane().type == ::apollo::hdmap::Lane::BIKING ||
             nearby_lane->lane().type == ::apollo::hdmap::Lane::SIDEWALK))
        {
          ADEBUG << "Obstacle [" << id_ << "] ignores disqualified lanes.";
          continue;
        }

        double s = -1.0;
        double l = 0.0;
        PredictionMap::GetProjection(point, nearby_lane, &s, &l);
        if (s < 0.0 || s >= nearby_lane->total_length())
        {
          continue;
        }
        int turn_type = PredictionMap::LaneTurnType(nearby_lane->id().id);
        (void)turn_type;
        double heading = feature->velocityheading;
        double angle_diff = 0.0;
        (void)angle_diff;
        hdmap::MapPathPoint nearest_point;
        if (PredictionMap::ProjectionFromLane(nearby_lane, s, &nearest_point))
        {
          angle_diff = common::math::AngleDiff(nearest_point.heading(), heading);
        }

        double left = 0.0;
        double right = 0.0;
        nearby_lane->GetWidth(s, &left, &right);
        LaneFeature &lane_feature =
            feature->lane.nearbylanefeature.emplace_back();

        lane_feature.set__laneturntype(turn_type);
        lane_feature.set__laneid(nearby_lane->id().id);
        lane_feature.set__lanes(s);
        lane_feature.set__lanel(l);
        lane_feature.set__anglediff(angle_diff);
        lane_feature.set__disttoleftboundary(left - l);
        lane_feature.set__disttorightboundary(right + l);
        lane_feature.set__lanetype(nearby_lane->lane().type);
        ADEBUG << "Obstacle [" << id_ << "] has nearby lanes ["
               << lane_feature << "]";
      }
    }

    void Obstacle::SetSurroundingLaneIds(Feature *feature, const double radius)
    {
      Eigen::Vector2d point(feature->position.x, feature->position.y);
      std::vector<std::string> lane_ids =
          PredictionMap::NearbyLaneIds(point, radius);
      for (const auto &lane_id : lane_ids)
      {
        feature->surroundinglaneid.push_back(lane_id);
        std::shared_ptr<const LaneInfo> lane_info =
            PredictionMap::LaneById(lane_id);
        if (lane_info->IsOnLane(
                {feature->position.x, feature->position.y}))
        {
          feature->withinlaneid.push_back(lane_id);
        }
      }
    }

    bool Obstacle::HasJunctionExitLane(
        const apollo_msgs::msg::ApollopredictionLaneSequence &lane_sequence,
        const std::unordered_set<std::string> &exit_lane_id_set)
    {
      const Feature &feature = latest_feature();
      (void)feature;
      for (const LaneSegment &lane_segment : lane_sequence.lanesegment)
      {
        if (exit_lane_id_set.find(lane_segment.laneid) !=
            exit_lane_id_set.end())
        {
          return true;
        }
      }
      return false;
    }

    void Obstacle::BuildLaneGraph()
    {
      // Sanity checks.
      if (history_size() == 0)
      {
        AERROR << "No feature found.";
        return;
      }

      Feature *feature = mutable_latest_feature();
      // No need to BuildLaneGraph for those non-moving obstacles.
      if (feature->isstill && id_ != FLAGS_ego_vehicle_id)
      {
        ADEBUG << "Not build lane graph for still obstacle";
        return;
      }
      if (feature->lane.lanegraph.lanesequence.size() > 0)
      {
        ADEBUG << "Not build lane graph for an old obstacle";
        return;
      }
      double speed = feature->speed;
      double t_max = FLAGS_prediction_trajectory_time_length;
      auto estimated_move_distance = speed * t_max;

      double road_graph_search_distance = std::fmax(
          estimated_move_distance, FLAGS_min_prediction_trajectory_spatial_length);
      (void)road_graph_search_distance;
      bool is_in_junction = HasJunctionFeatureWithExits();
      std::unordered_set<std::string> exit_lane_id_set;
      if (is_in_junction)
      {
        for (const auto &exit : feature->junctionfeature.junctionexit)
        {
          exit_lane_id_set.insert(exit.exitlaneid);
        }
      }

      // BuildLaneGraph for current lanes:
      // Go through all the LaneSegments in current_lane,
      // construct up to max_num_current_lane of them.
      int seq_id = 0;
      (void)seq_id;
      int curr_lane_count = 0;
      (void)curr_lane_count;
      for (auto &lane : feature->lane.currentlanefeature)
      {
        std::shared_ptr<const LaneInfo> lane_info =
            PredictionMap::LaneById(lane.laneid);
        LaneGraph lane_graph = clusters_ptr_->GetLaneGraph(
            lane.lanes, road_graph_search_distance, true, lane_info);
        if (lane_graph.lanesequence.size() > 0)
        {
          ++curr_lane_count;
        }
        for (const auto &lane_seq : lane_graph.lanesequence)
        {
          if (is_in_junction && !HasJunctionExitLane(lane_seq, exit_lane_id_set))
          {
            continue;
          }
          auto *lane_seq_ptr =
              &feature->lane.lanegraph.lanesequence.emplace_back();
          *lane_seq_ptr = (lane_seq);
          lane_seq_ptr->set__lanesequenceid(seq_id++);
          lane_seq_ptr->set__lanes(lane.lanes);
          lane_seq_ptr->set__lanel(lane.lanel);
          lane_seq_ptr->set__vehicleonlane(true);
          lane_seq_ptr->set__lanetype(lane.lanetype);
          SetLaneSequenceStopSign(lane_seq_ptr);
          ADEBUG << "Obstacle [" << id_ << "] set a lane sequence ["
                 << lane_seq << "].";
        }
        if (curr_lane_count >= FLAGS_max_num_current_lane)
        {
          break;
        }
      }

      // BuildLaneGraph for neighbor lanes.
      int nearby_lane_count = 0;
      (void)nearby_lane_count;
      for (auto &lane : feature->lane.nearbylanefeature)
      {
        std::shared_ptr<const LaneInfo> lane_info =
            PredictionMap::LaneById(lane.laneid);
        LaneGraph lane_graph = clusters_ptr_->GetLaneGraph(
            lane.lanes, road_graph_search_distance, false, lane_info);
        if (lane_graph.lanesequence.size() > 0)
        {
          ++nearby_lane_count;
        }
        for (const auto &lane_seq : lane_graph.lanesequence)
        {
          if (is_in_junction && !HasJunctionExitLane(lane_seq, exit_lane_id_set))
          {
            continue;
          }
          auto *lane_seq_ptr =
              &feature->lane.lanegraph.lanesequence.emplace_back();
          *lane_seq_ptr = (lane_seq);
          lane_seq_ptr->set__lanesequenceid(seq_id++);
          lane_seq_ptr->set__lanes(lane.lanes);
          lane_seq_ptr->set__lanel(lane.lanel);
          lane_seq_ptr->set__vehicleonlane(false);
          lane_seq_ptr->set__lanetype(lane.lanetype);
          SetLaneSequenceStopSign(lane_seq_ptr);
          ADEBUG << "Obstacle [" << id_ << "] set a lane sequence ["
                 << lane_seq << "].";
        }
        if (nearby_lane_count >= FLAGS_max_num_nearby_lane)
        {
          break;
        }
      }

      if (feature->lane != Lane() && feature->lane.lanegraph != LaneGraph())
      {
        SetLanePoints(feature);
        SetLaneSequencePath(&feature->lane.lanegraph);
      }

      ADEBUG
          << "Obstacle [" << id_ << "] set lane graph features.";
    }

    void Obstacle::SetLaneSequenceStopSign(apollo_msgs::msg::ApollopredictionLaneSequence *lane_sequence_ptr)
    {
      // Set the nearest stop sign along the lane sequence
      if (lane_sequence_ptr->lanesegment.empty())
      {
        return;
      }
      double accumulate_s = 0.0;
      for (const LaneSegment &lane_segment : lane_sequence_ptr->lanesegment)
      {
        const StopSign &stop_sign =
            clusters_ptr_->QueryStopSignByLaneId(lane_segment.laneid);
        if (stop_sign.stopsignid != std::string() &&
            stop_sign.lanes + accumulate_s > lane_sequence_ptr->lanes)
        {
          lane_sequence_ptr->stopsign = (stop_sign);
          lane_sequence_ptr->stopsign.set__lanesequences(
              stop_sign.lanes + accumulate_s);
          ADEBUG << "Set StopSign for LaneSequence ["
                 << lane_sequence_ptr->lanesequenceid << "].";
          break;
        }
        accumulate_s += lane_segment.totallength;
      }
    }

    void Obstacle::GetNeighborLaneSegments(
        std::shared_ptr<const LaneInfo> center_lane_info, bool is_left,
        int recursion_depth, std::list<std::string> *const lane_ids_ordered,
        std::unordered_set<std::string> *const existing_lane_ids)
    {
      // Exit recursion if reached max num of allowed search depth.
      if (recursion_depth <= 0)
      {
        return;
      }
      if (is_left)
      {
        std::vector<std::string> curr_left_lane_ids;
        for (const auto &left_lane_id :
             center_lane_info->lane().leftneighborreverselaneid)
        {
          const std::string &lane_id = left_lane_id.id;
          // If haven't seen this lane id before.
          if (existing_lane_ids->count(lane_id) == 0)
          {
            existing_lane_ids->insert(lane_id);
            lane_ids_ordered->push_front(lane_id);
            curr_left_lane_ids.push_back(lane_id);
          }
        }

        for (const std::string &lane_id : curr_left_lane_ids)
        {
          GetNeighborLaneSegments(PredictionMap::LaneById(lane_id), true,
                                  recursion_depth - 1, lane_ids_ordered,
                                  existing_lane_ids);
        }
      }
      else
      {
        std::vector<std::string> curr_right_lane_ids;
        for (const auto &right_lane_id :
             center_lane_info->lane().rightneighborforwardlaneid)
        {
          const std::string &lane_id = right_lane_id.id;
          // If haven't seen this lane id before.
          if (existing_lane_ids->count(lane_id) == 0)
          {
            existing_lane_ids->insert(lane_id);
            lane_ids_ordered->push_back(lane_id);
            curr_right_lane_ids.push_back(lane_id);
          }
        }

        for (const std::string &lane_id : curr_right_lane_ids)
        {
          GetNeighborLaneSegments(PredictionMap::LaneById(lane_id), false,
                                  recursion_depth - 1, lane_ids_ordered,
                                  existing_lane_ids);
        }
      }
    }

    void Obstacle::BuildLaneGraphFromLeftToRight()
    {
      // Sanity checks.
      if (history_size() == 0)
      {
        AERROR << "No feature found.";
        return;
      }

      // No need to BuildLaneGraph for those non-moving obstacles.
      Feature *feature = mutable_latest_feature();
      if (feature->isstill)
      {
        ADEBUG << "Don't build lane graph for non-moving obstacle.";
        return;
      }
      if (feature->lane.lanegraphordered.lanesequence.size() > 0)
      {
        ADEBUG << "Don't build lane graph for an old obstacle.";
        return;
      }
      double speed = feature->speed;
      (void)speed;
      double road_graph_search_distance = 50.0 * 0.95; // (45mph for 3sec)
      (void)road_graph_search_distance;
      // std::fmax(speed * FLAGS_prediction_trajectory_time_length +
      //               0.5 * FLAGS_vehicle_max_linear_acc *
      //               FLAGS_prediction_trajectory_time_length *
      //               FLAGS_prediction_trajectory_time_length,
      //           FLAGS_min_prediction_trajectory_spatial_length);

      // Treat the most probable lane_segment as the center, put its left
      // and right neighbors into a vector following the left-to-right order.
      if (feature->lane == Lane() || feature->lane.lanefeature == LaneFeature())
      {
        return;
      }

      bool is_in_junction = HasJunctionFeatureWithExits();
      std::unordered_set<std::string> exit_lane_id_set;
      if (is_in_junction)
      {
        for (const auto &exit : feature->junctionfeature.junctionexit)
        {
          exit_lane_id_set.insert(exit.exitlaneid);
        }
      }

      std::shared_ptr<const LaneInfo> center_lane_info = nullptr;
      PredictionMap::LaneById(feature->lane.lanefeature.laneid);

      std::list<std::string> lane_ids_ordered_list;
      std::unordered_set<std::string> existing_lane_ids;
      GetNeighborLaneSegments(center_lane_info, true, 2, &lane_ids_ordered_list,
                              &existing_lane_ids);
      lane_ids_ordered_list.push_back(feature->lane.lanefeature.laneid);
      existing_lane_ids.insert(feature->lane.lanefeature.laneid);
      GetNeighborLaneSegments(center_lane_info, false, 2, &lane_ids_ordered_list,
                              &existing_lane_ids);

      const std::vector<std::string> lane_ids_ordered(lane_ids_ordered_list.begin(),
                                                      lane_ids_ordered_list.end());
      // TODO(all): sort the lane_segments from left to right (again)
      //            to double-check and make sure it's well sorted.
      // Build lane_graph for every lane_segment and update it into proto.
      int seq_id = 0;
      (void)seq_id;
      for (const std::string &lane_id : lane_ids_ordered)
      {
        // Construct the local lane_graph based on the current lane_segment.
        bool vehicle_is_on_lane = (lane_id == center_lane_info->lane().id.id);
        (void)vehicle_is_on_lane;
        std::shared_ptr<const LaneInfo>
            curr_lane_info =
                PredictionMap::LaneById(lane_id);
        LaneGraph local_lane_graph = clusters_ptr_->GetLaneGraphWithoutMemorizing(
            feature->lane.lanefeature.lanes, road_graph_search_distance,
            true, curr_lane_info);
        // Update it into the Feature proto
        for (const auto &lane_seq : local_lane_graph.lanesequence)
        {
          if (is_in_junction && !HasJunctionExitLane(lane_seq, exit_lane_id_set))
          {
            continue;
          }
          auto *lane_seq_ptr = &feature->lane.lanegraphordered.lanesequence.emplace_back();
          *lane_seq_ptr=(lane_seq);
          lane_seq_ptr->set__lanesequenceid(seq_id++);
          lane_seq_ptr->set__lanes(feature->lane.lanefeature.lanes);
          lane_seq_ptr->set__lanel(feature->lane.lanefeature.lanel);
          lane_seq_ptr->set__vehicleonlane(vehicle_is_on_lane);
          ADEBUG << "Obstacle [" << id_ << "] set a lane sequence ["
                 << lane_seq << "].";
        }
      }

      // Build lane_points.
      if (feature->lane.lanegraphordered != LaneGraph())
      {
        SetLanePoints(feature, 0.5, 100, true,
                      &feature->lane.lanegraphordered);
        SetLaneSequencePath(&feature->lane.lanegraphordered);
      }
      ADEBUG << "Obstacle [" << id_ << "] set lane graph features.";
    }

    // The default SetLanePoints applies to lane_graph with
    // FLAGS_target_lane_gap.
    void Obstacle::SetLanePoints(Feature *feature)
    {
      (void)feature;
      LaneGraph *lane_graph = &feature->lane.lanegraph;
      SetLanePoints(feature, FLAGS_target_lane_gap, FLAGS_max_num_lane_point, false,
                    lane_graph);
    }

    // The generic SetLanePoints
    void Obstacle::SetLanePoints(const Feature *feature,
                                 const double lane_point_spacing,
                                 const uint64_t max_num_lane_point,
                                 const bool is_bidirection,
                                 LaneGraph *const lane_graph)
    {
      ADEBUG << "Spacing = " << lane_point_spacing;
      // Sanity checks.
      if (feature == nullptr)
      {
        AERROR << "Null feature or no velocity heading.";
        return;
      }
      double heading = feature->velocityheading;
      double x = feature->position.x;
      double y = feature->position.y;
      Eigen::Vector2d position(x, y);

      // Go through every lane_sequence.
      for (size_t i = 0; i < lane_graph->lanesequence.size(); ++i)
      {
        auto &lane_sequence = lane_graph->lanesequence.at(i);
        if (lane_sequence.lanesegment.empty())
        {
          continue;
        }
        // TODO(jiacheng): can refactor the following two parts into one to
        //                 make it more elegant.

        // If building bidirectionally, then build backward lane-points as well.
        if (is_bidirection)
        {
          size_t lane_index = 0;
          double lane_seg_s = lane_sequence.lanesegment.at(lane_index).starts;
          while (lane_index < lane_sequence.lanesegment.size())
          {
            // Go through lane_segment one by one sequentially.
            LaneSegment &lane_segment =
                lane_sequence.lanesegment.at(lane_index);

            // End-condition: reached the current ADC's location.
            if (lane_index == (size_t)lane_sequence.adclanesegmentidx &&
                lane_seg_s > lane_segment.adcs)
            {
              lane_segment.set__adclanepointidx(lane_segment.lanepoint.size());
              break;
            }

            if (lane_seg_s > lane_segment.ends)
            {
              // If already exceeds the current lane_segment, then go to the
              // next following one.
              ADEBUG << "Move on to the next lane-segment.";
              lane_seg_s = lane_seg_s - lane_segment.ends;
              ++lane_index;
            }
            else
            {
              // Otherwise, update lane_graph:
              // 1. Sanity checks.
              std::string lane_id = lane_segment.laneid;
              lane_segment.set__laneturntype(
                  PredictionMap::LaneTurnType(lane_id));
              ADEBUG << "Currently on " << lane_id;
              auto lane_info = PredictionMap::LaneById(lane_id);
              if (lane_info == nullptr)
              {
                break;
              }
              // 2. Get the closeset lane_point
              ADEBUG << "Lane-segment s = " << lane_seg_s;
              Eigen::Vector2d lane_point_pos =
                  PredictionMap::PositionOnLane(lane_info, lane_seg_s);
              double lane_point_heading =
                  PredictionMap::HeadingOnLane(lane_info, lane_seg_s);
              double lane_point_width =
                  PredictionMap::LaneTotalWidth(lane_info, lane_seg_s);
              double lane_point_angle_diff =
                  common::math::AngleDiff(lane_point_heading, heading);
              // 3. Update it into the lane_graph
              ADEBUG << lane_point_pos[0] << "    " << lane_point_pos[1];
              apollo_msgs::msg::ApollopredictionLanePoint lane_point;
              lane_point.position.set__x(lane_point_pos[0]);
              lane_point.position.set__y(lane_point_pos[1]);
              lane_point.set__heading(lane_point_heading);
              lane_point.set__width(lane_point_width);
              lane_point.set__anglediff(lane_point_angle_diff);
              // Update into lane_segment.
              lane_segment.lanepoint.push_back(lane_point);
              lane_seg_s += lane_point_spacing;
            }
          }
        }

        // Build lane-point in the forward direction.
        size_t lane_index = lane_sequence.adclanesegmentidx;
        double total_s = 0.0;
        double lane_seg_s = lane_sequence.lanesegment.at(lane_index).adcs;
        if (!is_bidirection)
        {
          lane_index = 0;
          lane_seg_s = lane_sequence.lanesegment.at(0).starts;
        }
        std::size_t count_point = 0;
        while (lane_index < lane_sequence.lanesegment.size() &&
               count_point < max_num_lane_point)
        {
          // Go through lane_segment one by one sequentially.
          LaneSegment &lane_segment =
              lane_sequence.lanesegment.at(lane_index);

          if (lane_seg_s > lane_segment.ends)
          {
            // If already exceeds the current lane_segment, then go to the
            // next following one.
            ADEBUG << "Move on to the next lane-segment.";
            lane_seg_s = lane_seg_s - lane_segment.ends;
            ++lane_index;
          }
          else
          {
            // Otherwise, update lane_graph:
            // 1. Sanity checks.
            std::string lane_id = lane_segment.laneid;
            lane_segment.set__laneturntype(PredictionMap::LaneTurnType(lane_id));
            ADEBUG << "Currently on " << lane_id;
            auto lane_info = PredictionMap::LaneById(lane_id);
            if (lane_info == nullptr)
            {
              break;
            }
            // 2. Get the closeset lane_point
            ADEBUG << "Lane-segment s = " << lane_seg_s;
            Eigen::Vector2d lane_point_pos =
                PredictionMap::PositionOnLane(lane_info, lane_seg_s);
            double lane_point_heading =
                PredictionMap::HeadingOnLane(lane_info, lane_seg_s);
            double lane_point_width =
                PredictionMap::LaneTotalWidth(lane_info, lane_seg_s);
            double lane_point_angle_diff =
                common::math::AngleDiff(lane_point_heading, heading);
            // 3. Update it into the lane_graph
            ADEBUG << lane_point_pos[0] << "    " << lane_point_pos[1];
            apollo_msgs::msg::ApollopredictionLanePoint lane_point;
            // Update direct information.
            lane_point.position.set__x(lane_point_pos[0]);
            lane_point.position.set__y(lane_point_pos[1]);
            lane_point.set__heading(lane_point_heading);
            lane_point.set__width(lane_point_width);
            lane_point.set__anglediff(lane_point_angle_diff);
            // Update deducted information.
            double lane_l = feature->lane.lanefeature.lanel;
            lane_point.set__relatives(total_s);
            lane_point.set__relativel(0.0 - lane_l);
            // Update into lane_segment.
            lane_segment.lanepoint.push_back(lane_point);
            ++count_point;
            total_s += lane_point_spacing;
            lane_seg_s += lane_point_spacing;
          }
        }
      }
      ADEBUG << "Obstacle [" << id_ << "] has lane segments and points.";
    }

    void Obstacle::SetLaneSequencePath(LaneGraph *const lane_graph)
    {
      // Go through every lane_sequence.
      for (size_t i = 0; i < lane_graph->lanesequence.size(); ++i)
      {
        auto &lane_sequence = lane_graph->lanesequence.at(i);
        double lane_segment_s = 0.0;
        // Go through every lane_segment.
        for (const LaneSegment &lane_segment : lane_sequence.lanesegment)
        {
          // Go through every lane_point and set the corresponding path_point.
          for (const auto &lane_point : lane_segment.lanepoint)
          {
            PathPoint &path_point = lane_sequence.pathpoint.emplace_back();
            path_point.set__s(lane_point.relatives);
            path_point.set__theta(lane_point.heading);
          }
          lane_segment_s += lane_segment.totallength;
        }
        // Sanity checks.
        int num_path_point = lane_sequence.pathpoint.size();
        if (num_path_point <= 0)
        {
          continue;
        }
        // Go through every path_point, calculate kappa, and update it.
        size_t segment_index = 0;
        size_t point_index = 0;
        for (int j = 0; j + 1 < num_path_point; ++j)
        {
          while (segment_index < lane_sequence.lanesegment.size() &&
                 point_index >=
                     lane_sequence.lanesegment.at(segment_index).lanepoint.size())
          {
            ++segment_index;
            point_index = 0;
          }
          PathPoint &first_point = lane_sequence.pathpoint.at(j);
          PathPoint &second_point = lane_sequence.pathpoint.at(j + 1);
          double delta_theta = apollo::common::math::AngleDiff(
              second_point.theta, first_point.theta);
          double delta_s = second_point.s - first_point.s;
          double kappa = std::abs(delta_theta / (delta_s + FLAGS_double_precision));
          lane_sequence.pathpoint.at(j).set__kappa(kappa);
          if (segment_index < lane_sequence.lanesegment.size() &&
              point_index <
                  lane_sequence.lanesegment.at(segment_index).lanepoint.size())
          {
            lane_sequence.lanesegment.at(segment_index)
                .lanepoint.at(point_index)
                .set__kappa(kappa);
            ++point_index;
          }
        }
        lane_sequence.pathpoint.at(num_path_point - 1).set__kappa(0.0);
      }
    }

    void Obstacle::SetNearbyObstacles()
    {
      // This function runs after all basic features have been set up
      Feature *feature_ptr = mutable_latest_feature();
      (void)feature_ptr;
      LaneGraph *lane_graph = &feature_ptr->lane.lanegraph;
      for (size_t i = 0; i < lane_graph->lanesequence.size(); ++i)
      {
        auto *lane_sequence = &lane_graph->lanesequence.at(i);
        if (lane_sequence->lanesegment.size() == 0)
        {
          AERROR << "Empty lane sequence found.";
          continue;
        }
        double obstacle_s = lane_sequence->lanes;
        double obstacle_l = lane_sequence->lanel;
        NearbyObstacle forward_obstacle;
        if (clusters_ptr_->ForwardNearbyObstacle(*lane_sequence, id_, obstacle_s,
                                                 obstacle_l, &forward_obstacle))
        {
          lane_sequence->nearbyobstacle.push_back(forward_obstacle);
        }
        NearbyObstacle backward_obstacle;
        if (clusters_ptr_->BackwardNearbyObstacle(*lane_sequence, id_, obstacle_s,
                                                  obstacle_l, &backward_obstacle))
        {
          lane_sequence->nearbyobstacle.push_back(backward_obstacle);
        }
      }
    }

    void Obstacle::SetMotionStatus()
    {
      int history_size = static_cast<int>(feature_history_.size());
      if (history_size == 0)
      {
        AERROR << "Zero history found";
        return;
      }
      double pos_std = FLAGS_still_obstacle_position_std;
      double speed_threshold = FLAGS_still_obstacle_speed_threshold;
      if (type_ == perception::PerceptionObstacle::PEDESTRIAN ||
          type_ == perception::PerceptionObstacle::BICYCLE)
      {
        speed_threshold = FLAGS_still_pedestrian_speed_threshold;
        pos_std = FLAGS_still_pedestrian_position_std;
      }
      else if (type_ == perception::PerceptionObstacle::UNKNOWN ||
               type_ == perception::PerceptionObstacle::UNKNOWN_MOVABLE)
      {
        speed_threshold = FLAGS_still_unknown_speed_threshold;
        pos_std = FLAGS_still_unknown_position_std;
      }
      double speed = feature_history_.front().speed;

      if (history_size == 1)
      {
        if (speed < speed_threshold)
        {
          ADEBUG << "Obstacle [" << id_ << "] has a small speed [" << speed
                 << "] and is considered stationary in the first frame.";
          feature_history_.front().set__isstill(true);
        }
        else
        {
          feature_history_.front().set__isstill(false);
        }
        return;
      }

      double start_x = 0.0;
      double start_y = 0.0;
      double avg_drift_x = 0.0;
      double avg_drift_y = 0.0;
      int len = std::min(history_size, FLAGS_max_still_obstacle_history_length);
      len = std::max(len, FLAGS_min_still_obstacle_history_length);
      CHECK_GT(len, 1);

      auto feature_riter = feature_history_.rbegin();
      start_x = feature_riter->position.x;
      start_y = feature_riter->position.y;
      ++feature_riter;
      while (feature_riter != feature_history_.rend())
      {
        avg_drift_x += (feature_riter->position.x - start_x) / (len - 1);
        avg_drift_y += (feature_riter->position.y - start_y) / (len - 1);
        ++feature_riter;
      }

      double delta_ts = feature_history_.front().timestamp -
                        feature_history_.back().timestamp;
      double speed_sensibility = std::sqrt(2 * history_size) * 4 * pos_std /
                                 ((history_size + 1) * delta_ts);
      if (speed < speed_threshold)
      {
        ADEBUG << "Obstacle [" << id_ << "] has a small speed [" << speed
               << "] and is considered stationary.";
        feature_history_.front().set__isstill(true);
      }
      else if (speed_sensibility < speed_threshold)
      {
        ADEBUG << "Obstacle [" << id_ << "]"
               << "] considered moving [sensibility = " << speed_sensibility << "]";
        feature_history_.front().set__isstill(false);
      }
      else
      {
        double distance = std::hypot(avg_drift_x, avg_drift_y);
        double distance_std = std::sqrt(2.0 / len) * pos_std;
        if (distance > 2.0 * distance_std)
        {
          ADEBUG << "Obstacle [" << id_ << "] is moving.";
          feature_history_.front().set__isstill(false);
        }
        else
        {
          ADEBUG << "Obstacle [" << id_ << "] is stationary.";
          feature_history_.front().set__isstill(true);
        }
      }
    }

    void Obstacle::SetMotionStatusBySpeed()
    {
      auto history_size = feature_history_.size();
      if (history_size < 2)
      {
        ADEBUG << "Obstacle [" << id_ << "] has no history and "
               << "is considered moving.";
        if (history_size > 0)
        {
          feature_history_.front().set__isstill(false);
        }
        return;
      }

      double speed_threshold = FLAGS_still_obstacle_speed_threshold;
      double speed = feature_history_.front().speed;

      if (FLAGS_use_navigation_mode)
      {
        if (speed < speed_threshold)
        {
          feature_history_.front().set__isstill(true);
        }
        else
        {
          feature_history_.front().set__isstill(false);
        }
      }
    }

    void Obstacle::InsertFeatureToHistory(const Feature &feature)
    {
      feature_history_.emplace_front(feature);
      ADEBUG << "Obstacle [" << id_ << "] inserted a frame into the history.";
    }

    std::unique_ptr<Obstacle> Obstacle::Create(
        const apollo_msgs::msg::ApolloperceptionPerceptionObstacle &perception_obstacle, const double timestamp,
        const int prediction_id, ObstacleClusters *clusters_ptr)
    {
      std::unique_ptr<Obstacle> ptr_obstacle(new Obstacle());
      ptr_obstacle->SetClusters(clusters_ptr);
      if (!ptr_obstacle->Insert(perception_obstacle, timestamp, prediction_id))
      {
        return nullptr;
      }
      return ptr_obstacle;
    }

    std::unique_ptr<Obstacle> Obstacle::Create(const Feature &feature,
                                               ObstacleClusters *clusters_ptr)
    {
      std::unique_ptr<Obstacle> ptr_obstacle(new Obstacle());
      ptr_obstacle->SetClusters(clusters_ptr);
      ptr_obstacle->InsertFeatureToHistory(feature);
      return ptr_obstacle;
    }

    bool Obstacle::ReceivedOlderMessage(const double timestamp) const
    {
      if (feature_history_.empty())
      {
        return false;
      }
      auto last_timestamp_received = feature_history_.front().timestamp;
      return timestamp <= last_timestamp_received;
    }

    void Obstacle::DiscardOutdatedHistory()
    {
      auto num_of_frames = feature_history_.size();
      const double latest_ts = feature_history_.front().timestamp;
      while (latest_ts - feature_history_.back().timestamp >=
             FLAGS_max_history_time)
      {
        feature_history_.pop_back();
      }
      auto num_of_discarded_frames = num_of_frames - feature_history_.size();
      if (num_of_discarded_frames > 0)
      {
        ADEBUG << "Obstacle [" << id_ << "] discards " << num_of_discarded_frames
               << " historical features";
      }
    }

    void Obstacle::SetCaution()
    {
      CHECK_GT(feature_history_.size(), 0U);
      Feature *feature = mutable_latest_feature();
      feature->priority.set__priority(ObstaclePriority::CAUTION);
    }

    bool Obstacle::IsCaution() const
    {
      if (feature_history_.empty())
      {
        return false;
      }
      const Feature &feature = latest_feature();
      return feature.priority.priority == ObstaclePriority::CAUTION;
    }

    void Obstacle::SetEvaluatorType(
        const ObstacleConf::EvaluatorType &evaluator_type)
    {
      obstacle_conf_.set__evaluatortype(evaluator_type);
    }

    void Obstacle::SetPredictorType(
        const ObstacleConf::PredictorType &predictor_type)
    {
      obstacle_conf_.set__predictortype(predictor_type);
    }

    PredictionObstacle Obstacle::GeneratePredictionObstacle()
    {
      PredictionObstacle prediction_obstacle;
      // TODO(kechxu) implement
      return prediction_obstacle;
    }

    void Obstacle::SetClusters(ObstacleClusters *clusters_ptr)
    {
      clusters_ptr_ = clusters_ptr;
    }

  } // namespace prediction
} // namespace apollo
