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

/**
 * @file
 * @brief This file provides the implementation of the class `NavigationLane`.
 */

#include "modules/map/relative_map/navigation_lane.h"

#include <algorithm>
#include <limits>
#include <string>
#include "modules/common/util/map_util.h"
#include "absl/strings/str_cat.h"
#include "cyber/cyber.h"
#include "modules/common/math/math_utils.h"
#include "modules/common/math/vec2d.h"
#include "modules/common/util/util.h"
#include <map> 
#include "modules/map/proto/map_lane.pb.h"
#include "modules/map/relative_map/common/relative_map_gflags.h"

namespace apollo {
namespace relative_map {

using apollo::common::VehicleStateProvider;
using apollo::common::math::Vec2d;
using apollo::common::util::DistanceXY;
using  apollo_msgs::msg::ApollohdmapLane;
using apollo::common::util::operator+;
using apollo::common::util::IsFloatEqual;

namespace {
/**
 * @brief Create a single lane map.
 * @param navi_path_tuple A navigation path tuple.
 * @param map_config Map generation configuration information.
 * @param perception_obstacles The Perceived obstacle information and the lane
 * markings are used here.
 * @param hdmap The output single lane map in high-definition map format in the
 * relative map.
 * @param navigation_path The output navigation path map in the relative map.
 * @return True if the map is created; false otherwise.
 */
bool CreateSingleLaneMap(
    const NaviPathTuple & navi_path_tuple,const apollo_msgs::msg::ApollorelativeMapMapGenerationParam & map_config,
    const apollo_msgs::msg::ApolloperceptionPerceptionObstacles & perception_obstacles,
    hdmap::Map *const hdmap,
    std::vector<apollo_msgs::msg::ApollorelativeMapMapMsgnavigationPath> *const navigation_path) {
  CHECK_NOTNULL(hdmap);
  CHECK_NOTNULL(navigation_path);

  const auto &navi_path = std::get<3>(navi_path_tuple);
  const auto &path = navi_path->path;
  if (path.pathpoint.size() < 2) {
    AERROR << "The path length of line index is invalid";
    return false;
  }
  apollo_msgs::msg::ApollohdmapLane *lane =&hdmap->lane.emplace_back();
  lane->id.id=
      absl::StrCat(navi_path->pathpriority, "_", path.name);
      // (*navigation_path)[lane->id.id] = *navi_path;

  apollo_msgs::msg::ApollorelativeMapMapMsgnavigationPath t;
  t.key = lane->id.id;
  t.data = *navi_path;
  navigation_path->push_back(t);
  //apollo::common::util::InsertOrUpdate(*navigation_path,lane->id.id,*navi_path);
    
  // lane types
  lane->type=apollo::hdmap::Lane::CITY_DRIVING;
  lane->turn=apollo::hdmap::Lane::NO_TURN;

  // speed limit
  lane->speedlimit=map_config.defaultspeedlimit;

  // center line
  
  auto curve_segment = &lane->centralcurve.segment.emplace_back();
  curve_segment->heading=path.pathpoint[0].theta;
  apollo_msgs::msg::ApollohdmapLineSegment *line_segment = &curve_segment->curvetype.linesegment;

  
  // left boundary
  hdmap::LineSegment *left_segment = nullptr;
  if (FLAGS_relative_map_generate_left_boundray) {
    auto *left_boundary = &lane->leftboundary;
    auto *left_boundary_type=&left_boundary->boundarytype.emplace_back();
    left_boundary->virtuall=false;
    left_boundary_type->s=0.0;
    left_boundary_type->types.push_back(
        perception_obstacles.lanemarker.leftlanemarker.lanetype);
    left_segment =
        &left_boundary->curve.segment.emplace_back().curvetype.linesegment;
  }

  // right boundary
  auto *right_boundary = &lane->rightboundary;
    auto *right_boundary_type=&right_boundary->boundarytype.emplace_back();
    right_boundary->virtuall=false;
    right_boundary_type->s=0.0;
    right_boundary_type->types.push_back(
        perception_obstacles.lanemarker.rightlanemarker.lanetype);
    auto *right_segment =
        &right_boundary->curve.segment.emplace_back().curvetype.linesegment;

  const double lane_left_width = std::get<1>(navi_path_tuple);
  const double lane_right_width = std::get<2>(navi_path_tuple);

  for (const auto &pathpoint : path.pathpoint) {
    auto point = &line_segment->point.emplace_back();
    point->x=pathpoint.x;
    point->y=pathpoint.y;
    point->z=pathpoint.z;
    if (FLAGS_relative_map_generate_left_boundray) {
      auto *left_sample = &(lane->leftsample.emplace_back());
      left_sample->s=pathpoint.s;
      left_sample->width=lane_left_width;
      left_segment->point.push_back(
          *point + lane_left_width *
                       Vec2d::CreateUnitVec2d(pathpoint.theta + M_PI_2));
    }
    apollo_msgs::msg::ApollohdmapLaneSampleAssociation rfrightsample;
    auto *right_sample = &(lane->rightsample.emplace_back());
    right_sample->s=pathpoint.s;
    right_sample->width=lane_right_width;
    right_segment->point.push_back(
        *point +
        lane_right_width * Vec2d::CreateUnitVec2d(pathpoint.theta - M_PI_2));
    
  }
  return true;
}
}  // namespace

NavigationLane::NavigationLane(const apollo_msgs::msg::ApollorelativeMapNavigationLaneConfig & config)
    : config_(config) {}

void NavigationLane::SetConfig(const apollo_msgs::msg::ApollorelativeMapNavigationLaneConfig & config) {
  config_ = config;
}

void NavigationLane::SetVehicleStateProvider(
    common::VehicleStateProvider *vehicle_state_provider) {
  vehicle_state_provider_ = vehicle_state_provider;
}

void NavigationLane::UpdateNavigationInfo(
  apollo_msgs::msg::ApollorelativeMapNavigationInfo::SharedPtr navigation_path) {
  navigation_info_ = *navigation_path;
  last_project_index_map_.clear();
  navigation_path_list_.clear();
  current_navi_path_tuple_ = std::make_tuple(-1, -1.0, -1.0, nullptr);
  if (FLAGS_enable_cyclic_rerouting) {
    UpdateStitchIndexInfo();
  }
}

bool NavigationLane::GeneratePath() {
  navigation_path_list_.clear();
  current_navi_path_tuple_ = std::make_tuple(-1, -1.0, -1.0, nullptr);

  // original_pose is in world coordination: ENU
  original_pose_ = vehicle_state_provider_->original_pose();

  int navigation_line_num = navigation_info_.navigationpath.size();
  const auto &lane_marker = perception_obstacles_.lanemarker;

  //Make navi_path_tuple (navigation path) from lane_marker (perception).
  auto generate_path_on_perception_func = [this, &lane_marker]() {
    auto current_navi_path = std::make_shared<NavigationPath>();
    apollo_msgs::msg::ApollocommonPath *path = &current_navi_path->path;
    ConvertLaneMarkerToPath(lane_marker, path);
    current_navi_path->pathpriority=0;
    double left_width = perceived_left_width_ > 0.0 ? perceived_left_width_
                                                    : default_left_width_;
    double right_width = perceived_right_width_ > 0.0 ? perceived_right_width_
                                                      : default_right_width_;
    current_navi_path_tuple_ =
        std::make_tuple(0, left_width, right_width, current_navi_path);
  };

  ADEBUG << "Beginning of NavigationLane::GeneratePath().";
  ADEBUG << "navigation_line_num: " << navigation_line_num;

  // priority: merge > navigation line > perception lane marker
  if (config_.lanesource == NavigationLaneConfig::OFFLINE_GENERATED &&
      navigation_line_num > 0) {
    // Generate multiple navigation paths based on navigation lines.
    // Don't worry about efficiency because the total number of navigation lines
    // will not exceed 10 at most.
    for (int i = 0; i < navigation_line_num; ++i) {
      auto current_navi_path = std::make_shared<NavigationPath>();
      apollo_msgs::msg::ApollocommonPath *path = &current_navi_path->path;
      if (ConvertNavigationLineToPath(i, path)) {
        current_navi_path->pathpriority=
            navigation_info_.navigationpath[i].pathpriority;
        navigation_path_list_.emplace_back(
            i, default_left_width_, default_right_width_, current_navi_path);
      }
    }

    // If no navigation path is generated based on navigation lines, we generate
    // one where the vehicle is located based on perceived lane markers.
    if (navigation_path_list_.empty()) {
      generate_path_on_perception_func();
      return true;
    }

    // Sort navigation paths from left to right according to the vehicle's
    // direction.
    // In the FLU vehicle coordinate system, the y-coordinate on the left side
    // of the vehicle is positive, and the right value is negative. Therefore,
    // the navigation paths can be sorted from left to right according to its
    // y-coordinate.
    navigation_path_list_.sort(
        [](const NaviPathTuple &left, const NaviPathTuple &right) {
          double left_y = std::get<3>(left)->path.pathpoint[0].y;
          double right_y = std::get<3>(right)->path.pathpoint[0].y;
          return left_y > right_y;
        });

    // Get which navigation path the vehicle is currently on.
    double min_d = std::numeric_limits<double>::max();
    for (const auto &navi_path_tuple : navigation_path_list_) {
      int current_line_index = std::get<0>(navi_path_tuple);
      ADEBUG << "Current navigation path index is: " << current_line_index;
      double current_d = std::numeric_limits<double>::max();
      auto item_iter = last_project_index_map_.find(current_line_index);
      if (item_iter != last_project_index_map_.end()) {
        current_d = item_iter->second.second;
      }
      if (current_d < min_d) {
        min_d = current_d;
        current_navi_path_tuple_ = navi_path_tuple;
      }
    }

    // Merge current navigation path where the vehicle is located with perceived
    // lane markers.
    apollo_msgs::msg::ApollocommonPath *path = &(std::get<3>(current_navi_path_tuple_)->path);
    int line_index = std::get<0>(current_navi_path_tuple_);
    MergeNavigationLineAndLaneMarker(line_index, path);

    // Set the width for the navigation path which the vehicle is currently on.
    double left_width = perceived_left_width_ > 0.0 ? perceived_left_width_
                                                    : default_left_width_;
    double right_width = perceived_right_width_ > 0.0 ? perceived_right_width_
                                                      : default_right_width_;
    if (!IsFloatEqual(left_width, default_left_width_) &&
        !IsFloatEqual(right_width, default_right_width_)) {
      left_width = left_width > default_left_width_ ? left_width - min_d
                                                    : left_width + min_d;
      right_width = right_width > default_right_width_ ? right_width - min_d
                                                       : right_width + min_d;
    }

    ADEBUG << "The left width of current lane is: " << left_width
           << " and the right width of current lane is: " << right_width;

    std::get<1>(current_navi_path_tuple_) = left_width;
    std::get<2>(current_navi_path_tuple_) = right_width;
    auto curr_navi_path_iter = std::find_if(
        std::begin(navigation_path_list_), std::end(navigation_path_list_),
        [this](const NaviPathTuple &item) {
          return std::get<0>(item) == std::get<0>(current_navi_path_tuple_);
        });
    if (curr_navi_path_iter != std::end(navigation_path_list_)) {
      std::get<1>(*curr_navi_path_iter) = left_width;
      std::get<2>(*curr_navi_path_iter) = right_width;
    }

    // Set the width between each navigation path and its adjacent path.
    // The reason for using average of multiple points is to prevent too much
    // interference from a singularity.
    // If current navigation path is the path which the vehicle is currently
    // on, the current lane width uses the perceived width.
    int average_point_size = 5;
    for (auto iter = navigation_path_list_.begin();
         iter != navigation_path_list_.end(); ++iter) {
      const auto &curr_path = std::get<3>(*iter)->path;

      // Left neighbor
      auto prev_iter = std::prev(iter);
      if (prev_iter != navigation_path_list_.end()) {
        const auto &prev_path = std::get<3>(*prev_iter)->path;
        int min=std::min(curr_path.pathpoint.size(), prev_path.pathpoint.size());
        average_point_size = std::min(
            average_point_size,min);
        double lateral_distance_sum = 0.0;
        for (int i = 0; i < average_point_size; ++i) {
          lateral_distance_sum +=
              fabs(curr_path.pathpoint[i].y - prev_path.pathpoint[i].y);
        }
        double width = lateral_distance_sum /
                       static_cast<double>(average_point_size) / 2.0;
        width = common::math::Clamp(width, config_.minlanehalfwidth,
                                    config_.maxlanehalfwidth);

        auto &curr_left_width = std::get<1>(*iter);
        auto &prev_right_width = std::get<2>(*prev_iter);
        if (std::get<0>(*iter) == std::get<0>(current_navi_path_tuple_)) {
          prev_right_width = 2.0 * width - curr_left_width;
        } else {
          curr_left_width = width;
          prev_right_width = width;
        }
      }
      // Right neighbor
      auto next_iter = std::next(iter);
      if (next_iter != navigation_path_list_.end()) {
        const auto &next_path = std::get<3>(*next_iter)->path;
        int min=std::min(curr_path.pathpoint.size(), next_path.pathpoint.size());
        average_point_size = std::min(
            average_point_size,
            min);
        double lateral_distance_sum = 0.0;
        for (int i = 0; i < average_point_size; ++i) {
          lateral_distance_sum +=
              fabs(curr_path.pathpoint[i].y - next_path.pathpoint[i].y);
        }
        double width = lateral_distance_sum /
                       static_cast<double>(average_point_size) / 2.0;
        width = common::math::Clamp(width, config_.minlanehalfwidth,
                                    config_.maxlanehalfwidth);

        auto &curr_right_width = std::get<2>(*iter);
        auto &next_left_width = std::get<1>(*next_iter);
        if (std::get<0>(*iter) == std::get<0>(current_navi_path_tuple_)) {
          next_left_width = 2.0 * width - curr_right_width;
        } else {
          next_left_width = width;
          curr_right_width = width;
        }
      }
    }

    return true;
  }

  // Generate a navigation path where the vehicle is located based on perceived
  // lane markers.
  generate_path_on_perception_func();
  return true;
}

double NavigationLane::EvaluateCubicPolynomial(const double c0, const double c1,
                                               const double c2, const double c3,
                                               const double x) const {
  return ((c3 * x + c2) * x + c1) * x + c0;
}

void NavigationLane::MergeNavigationLineAndLaneMarker(
    const int line_index, common::Path *const path) {
  CHECK_NOTNULL(path);

  // If the size of "path" points is smaller than 2, it indicates that a
  // navigation path needs to be generated firstly.
  if (path->pathpoint.size() < 2) {
    path->name.clear();
    path->pathpoint.clear();
    ConvertNavigationLineToPath(line_index, path);
  }

  // If the size of "path" points is still smaller than 2, just generate a
  // navigation path based on perceived lane markers.
  if (path->pathpoint.size() < 2) {
    path->name.clear();
    path->pathpoint.clear();
    ConvertLaneMarkerToPath(perception_obstacles_.lanemarker, path);
    return;
  }

  common::Path lane_marker_path;
  ConvertLaneMarkerToPath(perception_obstacles_.lanemarker,
                          &lane_marker_path);

  // If the size of lane marker path points is smaller than 2, merging is not
  // required.
  if (lane_marker_path.pathpoint.size() < 2) {
    return;
  }

  int lane_marker_index = 0;
  double navigation_line_weight = 1.0 - config_.lanemarkerweight;
  int size=path->pathpoint.size();
  for (int i = 0; i < size; ++i) {
    apollo_msgs::msg::ApollocommonPathPoint *point = &(path->pathpoint[i]);
    double s = point->s;
    auto lane_maker_point = GetPathPointByS(lane_marker_path, lane_marker_index,
                                            s, &lane_marker_index);
    // For the beginning and ending portions of a navigation path beyond the
    // perceived path, only the y-coordinates in the FLU coordinate system are
    // used for merging.
    const int marker_size = lane_marker_path.pathpoint.size();
    if (lane_marker_index < 0 || lane_marker_index > (marker_size - 1)) {
      point->y=(navigation_line_weight * point->y +
                   (1 - navigation_line_weight) * lane_maker_point.y);
      lane_marker_index = 0;
      continue;
    }
    *point = common::util::GetWeightedAverageOfTwoPathPoints(
        *point, lane_maker_point, navigation_line_weight,
        1 - navigation_line_weight);
  }
}

common::PathPoint NavigationLane::GetPathPointByS(const common::Path &path,
                                                  const int start_index,
                                                  const double s,
                                                  int *const matched_index) {
  CHECK_NOTNULL(matched_index);
  const int size = path.pathpoint.size();

  if (start_index < 0 || s < path.pathpoint[start_index].s) {
    *matched_index = -1;
    return path.pathpoint[0];
  }

  if (s > path.pathpoint[size - 1].s || start_index > (size - 1)) {
    *matched_index = size;
    return path.pathpoint[size - 1];
  }

  static constexpr double kEpsilon = 1e-9;
  if (std::fabs(path.pathpoint[start_index].s - s) < kEpsilon) {
    *matched_index = start_index;
    return path.pathpoint[start_index];
  }
  int i = start_index;
  while (i + 1 < size && path.pathpoint[i+1].s < s) {
    ++i;
  }
  *matched_index = i;

  // x, y, z, theta, kappa, s, dkappa, ddkappa
  const double r = (s - path.pathpoint[i].s) /
                   (path.pathpoint[i].s - path.pathpoint[i-1].s);
  auto p = common::util::GetWeightedAverageOfTwoPathPoints(
      path.pathpoint[i], path.pathpoint[i+1], 1 - r, r);
  return p;
}

bool NavigationLane::ConvertNavigationLineToPath(const int line_index,
                                                 common::Path *const path) {
  CHECK_NOTNULL(path);
  if (navigation_info_.navigationpath[line_index].path.pathpoint.size() == 0) {
    // path is empty
    return false;
  }
  path->set__name(absl::StrCat("Path from navigation line index ", line_index));
  const auto &navigation_path =
      navigation_info_.navigationpath[line_index].path;
  //Get the index of the closest waypoint in the navigation_info path and its respective distance to the car.
  auto proj_index_pair = UpdateProjectionIndex(navigation_path, line_index);
  // Can't find a proper projection index in the "line_index" lane according to
  // current vehicle position.
  int current_project_index = proj_index_pair.first;
  int size = navigation_path.pathpoint.size();
  if (current_project_index < 0 ||
      current_project_index >= size) {
    AERROR << "Invalid projection index " << current_project_index
           << " in line " << line_index;
    last_project_index_map_.erase(line_index);
    return false;
  } else {
    last_project_index_map_[line_index] = proj_index_pair;
  }

  // offset between the current vehicle state and navigation line
  //Conert point from ENU to FLU (first pose if point x,y=0,0 , heading=0)
  const double dx = -original_pose_.position.x;
  const double dy = -original_pose_.position.y;
  auto enu_to_flu_func = [this, dx, dy](const double enu_x, const double enu_y,
                                        const double enu_theta, double *flu_x,
                                        double *flu_y, double *flu_theta) {
    if (flu_x != nullptr && flu_y != nullptr) {
      Eigen::Vector2d flu_coordinate = common::math::RotateVector2d(
          {enu_x + dx, enu_y + dy}, -original_pose_.heading);

      *flu_x = flu_coordinate.x();
      *flu_y = flu_coordinate.y();
    }

    if (flu_theta != nullptr) {
      *flu_theta = common::math::NormalizeAngle(
          common::math::NormalizeAngle(enu_theta) - original_pose_.heading);
    }
  };
  //convert navigation_info to path FLU coordinates.
  auto gen_navi_path_loop_func =
      [this, &navigation_path, &enu_to_flu_func](
          const int start, const int end, const double ref_s_base,
          const double max_length, common::Path *path) {
        CHECK_NOTNULL(path);
        const double ref_s = navigation_path.pathpoint[start].s;
        for (int i = start; i < end; ++i) {
          auto * point = &path->pathpoint.emplace_back();

          *point=navigation_path.pathpoint[i];

          double flu_x = 0.0;
          double flu_y = 0.0;
          double flu_theta = 0.0;
          enu_to_flu_func(point->x, point->y, point->theta, &flu_x,
                          &flu_y, &flu_theta);

          point->x=flu_x;
          point->y=flu_y;
          point->theta=flu_theta;
          const double accumulated_s =
              navigation_path.pathpoint[i].s - ref_s + ref_s_base;
          point->s=accumulated_s;

          if (accumulated_s > max_length) {
            break;
          }
        }
      };

  double dist = navigation_path.pathpoint.rbegin()->s -
                navigation_path.pathpoint[current_project_index].s;
  // Stitch current position to the beginning for a cyclic/circular route.
  if (FLAGS_enable_cyclic_rerouting &&
      dist < config_.maxlenfromnavigationline) {
    auto item_iter = stitch_index_map_.find(line_index);
    if (item_iter != stitch_index_map_.end()) {
      int stitch_start_index =
          std::max(item_iter->second.first, item_iter->second.second);
      stitch_start_index = std::max(current_project_index, stitch_start_index);
      int min=navigation_path.pathpoint.size() - 1;
      stitch_start_index =
          std::min( min, stitch_start_index);

      int stitch_end_index =
          std::min(item_iter->second.first, item_iter->second.second);
      stitch_end_index = std::max(0, stitch_end_index);
      stitch_end_index = std::min(current_project_index, stitch_end_index);

      ADEBUG << "The stitch_start_index is: " << stitch_start_index << "; "
             << "the stitch_end_index is: " << stitch_end_index << "; "
             << "the current_project_index is: " << current_project_index
             << " for the navigation line: " << line_index;

      double length = navigation_path.pathpoint[stitch_start_index].s -
                      navigation_path.pathpoint[current_project_index].s;
      gen_navi_path_loop_func(std::max(0, current_project_index - 3),
                              stitch_start_index + 1, 0.0, length, path);
      if (length > config_.maxlenfromnavigationline) {
        return true;
      }
      gen_navi_path_loop_func(stitch_end_index,
                              navigation_path.pathpoint.size(), length,
                              config_.maxlenfromnavigationline, path);
      return true;
    }
  }

  if (dist < 20) {
    return false;
  }
  gen_navi_path_loop_func(std::max(0, current_project_index - 3),
                          navigation_path.pathpoint.size(), 0.0,
                          config_.maxlenfromnavigationline, path);
  return true;
}

// project adc_state_ onto path: find closest waypoint in path to the vehicle and its distance.
ProjIndexPair NavigationLane::UpdateProjectionIndex(const common::Path &path,
                                                    const int line_index) {
  if (path.pathpoint.size() < 2) {
    return std::make_pair(-1, std::numeric_limits<double>::max());
  }

  double min_d = std::numeric_limits<double>::max();
  const int path_size = path.pathpoint.size();
  int current_project_index = 0;
  auto item_iter = last_project_index_map_.find(line_index);
  if (item_iter != last_project_index_map_.end()) {
    current_project_index = std::max(0, item_iter->second.first);
  }

  // A lambda expression for checking the distance between the vehicle's initial
  // position and the starting point of  the current navigation line.
  auto check_distance_func = [this, &path, &path_size](
                                 const int project_index,
                                 double *project_distance) {
    // Convert the starting point of the current navigation line from the
    // ENU coordinates to the FLU coordinates. For the multi-lane situation,
    // the distance in the Y-axis direction can be appropriately enlarged,
    // but the distance in the X-axis direction should be small.

    // flu_x = (enu_x - x_shift) * cos(angle) + (enu_y - y_shift) *
    //  sin(angle)
    // flu_y = (enu_y - y_shift) * cos(angle) - (enu_x - x_shift) *
    //  sin(angle)
    if (project_index < 0 || project_index > path_size - 1) {
      return false;
    }
    double enu_x = path.pathpoint[project_index].x;
    double enu_y = path.pathpoint[project_index].y;
    double x_shift = original_pose_.position.x;
    double y_shift = original_pose_.position.y;
    double cos_angle = std::cos(original_pose_.heading);
    double sin_angle = std::sin(original_pose_.heading);
    double flu_x =
        (enu_x - x_shift) * cos_angle + (enu_y - y_shift) * sin_angle;
    double flu_y =
        (enu_y - y_shift) * cos_angle - (enu_x - x_shift) * sin_angle;

    if (project_distance != nullptr) {
      *project_distance = std::fabs(flu_y);
    }

    if (std::fabs(flu_x) < config_.maxdistancetonavigationline / 2.0 &&
        std::fabs(flu_y) < config_.maxdistancetonavigationline * 2.0) {
      return true;
    }
    return false;
  };

  int index = 0;
  //util.h DistanceXY modifier x,y () -> x,y
  //Get the index of the closest waypoint in the path.
  for (int i = current_project_index; i + 1 < path_size; ++i) {
    const double d =DistanceXY(original_pose_.position, path.pathpoint[i]);
    if (d < min_d) {
      min_d = d;
      index = i;
    }
    const double kMaxDistance = 50.0;
    if (current_project_index != 0 && d > kMaxDistance) {
      break;
    }
  }
  
  if (check_distance_func(index, &min_d)) {
    if (FLAGS_enable_cyclic_rerouting) {
      // We create a condition here that sets the "current_project_index" to
      // 0, should the vehicle reach the end point of a cyclic/circular
      // route. For cyclic/circular navigation lines where the distance
      // between their start and end points is very small, it is tedious
      // and unnecessary to re-send navigation lines every time.
      auto item_iter = stitch_index_map_.find(line_index);
      if (item_iter != stitch_index_map_.end()) {
        int start_index =
            std::max(item_iter->second.first, item_iter->second.second);
        int end_index =
            std::min(item_iter->second.first, item_iter->second.second);
        int index_diff = index - start_index;
        if (index_diff >= 0) {
          index = std::min(end_index + index_diff, start_index);
          min_d = DistanceXY(original_pose_.position, path.pathpoint[index]);
        }
      }
    }
    return std::make_pair(index, min_d);
  }

  return std::make_pair(-1, std::numeric_limits<double>::max());
}

double NavigationLane::GetKappa(const double c1, const double c2,
                                const double c3, const double x) {
  const double dy = 3 * c3 * x * x + 2 * c2 * x + c1;
  const double d2y = 6 * c3 * x + 2 * c2;
  return d2y / std::pow((1 + dy * dy), 1.5);
}

void NavigationLane::ConvertLaneMarkerToPath(
     const apollo_msgs::msg::ApolloperceptionLaneMarkers &lane_marker, common::Path *const path) {
  CHECK_NOTNULL(path);

  path->name="Path from lane markers.";
  const auto &left_lane = lane_marker.leftlanemarker;
  const auto &right_lane = lane_marker.rightlanemarker;

  double path_c0 = (left_lane.c0position + right_lane.c0position) / 2.0;

  double left_quality = left_lane.quality + 0.001;
  double right_quality = right_lane.quality + 0.001;

  double quality_divider = left_quality + right_quality;

  double path_c1 = (left_lane.c1headingangle * left_quality +
                    right_lane.c1headingangle * right_quality) /
                   quality_divider;

  double path_c2 = (left_lane.c2curvature * left_quality +
                    right_lane.c2curvature * right_quality) /
                   quality_divider;

  double path_c3 = (left_lane.c3curvaturederivative * left_quality +
                    right_lane.c3curvaturederivative * right_quality) /
                   quality_divider;

  const double current_speed =
      vehicle_state_provider_->vehicle_state().linearvelocity;
  double path_range =
      current_speed * config_.rationavigationlanelentospeed;
  if (path_range <= config_.minlenfornavigationlane) {
    path_range = config_.minlenfornavigationlane;
  } else {
    path_range = config_.maxlenfornavigationlane;
  }

  const double unit_z = 1.0;
  const double start_s = -2.0;
  double accumulated_s = start_s;
  for (double z = start_s; z <= path_range; z += unit_z) {
    double x1 = z;
    double y1 = 0;
    if (left_lane.viewrange > config_.minviewrangetouselanemarker ||
        right_lane.viewrange > config_.minviewrangetouselanemarker) {
      y1 = EvaluateCubicPolynomial(path_c0, path_c1, path_c2, path_c3, z);
    }
          auto * point = &path->pathpoint.emplace_back();

    point->x=x1;
    point->y=y1;

    if (path->pathpoint.size() > 1) {
      auto &pre_point = path->pathpoint[path->pathpoint.size() - 2];
      accumulated_s += std::hypot(x1 - pre_point.x, y1 - pre_point.y);
    }
    point->s=accumulated_s;
    point->theta=
        std::atan2(3 * path_c3 * x1 * x1 + 2 * path_c2 * x1 + path_c1, 1);
    point->kappa=GetKappa(path_c1, path_c2, path_c3, x1);

    const double k1 = GetKappa(path_c1, path_c2, path_c3, x1 - 0.0001);
    const double k2 = GetKappa(path_c1, path_c2, path_c3, x1 + 0.0001);
    point->dkappa=(k2 - k1) / 0.0002;
  }

  perceived_left_width_ = std::fabs(left_lane.c0position);
  perceived_right_width_ = std::fabs(right_lane.c0position);
  // If the perceived lane width is incorrect, use the default lane width
  // directly.
  double perceived_lane_width = perceived_left_width_ + perceived_right_width_;
  if (perceived_lane_width < 2.0 * config_.minlanehalfwidth ||
      perceived_lane_width > 2.0 * config_.maxlanehalfwidth) {
    perceived_left_width_ = default_left_width_;
    perceived_right_width_ = default_right_width_;
  }
}

//Put all paths generated from perception and NavigationInfo in a single road map. 
//Set the boundary of the road and the lanes
bool NavigationLane::CreateMap( const apollo_msgs::msg::ApollorelativeMapMapGenerationParam & map_config,
                               apollo_msgs::msg::ApollorelativeMapMapMsg *const map_msg) const {
  auto *navigation_path =& map_msg->navigationpath;
  auto *hdmap = &map_msg->hdmap;
  auto *lane_marker = &map_msg->lanemarker;

  *lane_marker=perception_obstacles_.lanemarker;

  // If no navigation path is generated based on navigation lines, we try to
  // create map with "current_navi_path_tuple_" which is generated based on
  // perceived lane markers.
  if (navigation_path_list_.size()<1) {
    if (std::get<3>(current_navi_path_tuple_) != nullptr) {
      FLAGS_relative_map_generate_left_boundray = true;
      return CreateSingleLaneMap(current_navi_path_tuple_, map_config,
                                 perception_obstacles_, hdmap, navigation_path);
    } else {
      return false;
    }
  }

  int fail_num = 0;
  FLAGS_relative_map_generate_left_boundray = true;
  for (auto iter = navigation_path_list_.cbegin();
       iter != navigation_path_list_.cend(); ++iter) {
    std::size_t index = std::distance(navigation_path_list_.cbegin(), iter);
    if (!CreateSingleLaneMap(*iter, map_config, perception_obstacles_, hdmap,
                             navigation_path)) {
      AWARN << "Failed to generate lane: " << index;
      ++fail_num;
      FLAGS_relative_map_generate_left_boundray = true;
      continue;
    }
    FLAGS_relative_map_generate_left_boundray = false;

    // The left border of the middle lane uses the right border of the left
    // lane.
    int lane_index = static_cast<int>(index) - fail_num;
    if (lane_index > 0) {
      auto *left_boundary =
          &(hdmap->lane[lane_index].leftboundary);
      *left_boundary=hdmap->lane[lane_index - 1].rightboundary;
      auto *left_sample =
          &hdmap->lane[lane_index].leftsample;
      *left_sample=hdmap->lane[lane_index - 1].rightsample;
    }
  }

  int lane_num = hdmap->lane.size();
  ADEBUG << "The Lane number is: " << lane_num;
  
  // Set road boundary according to the lanes on the endside of the road
  auto *road=&hdmap->road.emplace_back();
   //add
  road->id.id="road_" + hdmap->lane[0].id.id;
  auto*section=&road->section.emplace_back();
   //add
  for (int i = 0; i < lane_num; ++i) {
    section->laneid.push_back(hdmap->lane[i].id);
  }
  auto *outer_polygon = &section->boundary.outerpolygon;
  auto*left_edge=& outer_polygon->edge.emplace_back();
  //add
  left_edge->type=apollo::hdmap::BoundaryEdge::LEFT_BOUNDARY;
  left_edge->curve=hdmap->lane[0].leftboundary.curve;
  auto*right_edge=& outer_polygon->edge.emplace_back();
  //add
  right_edge->type=apollo::hdmap::BoundaryEdge::RIGHT_BOUNDARY;
  right_edge->curve=
      hdmap->lane[lane_num - 1].rightboundary.curve;
  // Set neighbor information for each lane
  if (lane_num < 2) {
    return true;
  }
  for (int i = 0; i < lane_num; ++i) {
    auto *lane = &hdmap->lane[i];
    if (i > 0) {
           lane->leftneighborforwardlaneid.push_back(hdmap->lane[i - 1].id) ;  //add
          
      ADEBUG << "Left neighbor is: " << hdmap->lane[i - 1].id.id;
    }
    if (i < lane_num - 1) {
      lane->rightneighborforwardlaneid.push_back(hdmap->lane[i - 1].id); //add
      ADEBUG << "Right neighbor is: " << hdmap->lane[i - 1].id.id;
    }
  }
  return true;
}

void NavigationLane::UpdateStitchIndexInfo() {
  stitch_index_map_.clear();

  int navigation_line_num = navigation_info_.navigationpath.size();
  if (navigation_line_num <= 0) {
    return;
  }

  static constexpr int kMinPathPointSize = 10;
  for (int i = 0; i < navigation_line_num; ++i) {
    const auto &navigation_path = navigation_info_.navigationpath[i].path;
    if (
      navigation_info_.navigationpath[i]!=apollo_msgs::msg::ApollorelativeMapNavigationPath() ||
        navigation_path.pathpoint.size() < kMinPathPointSize) {
      continue;
    }

    double min_distance = std::numeric_limits<double>::max();
    StitchIndexPair min_index_pair = std::make_pair(-1, -1);

    int path_size = navigation_path.pathpoint.size();
    const double start_s = navigation_path.pathpoint[0].s;
    const double end_s = navigation_path.pathpoint[path_size - 1].s;
    for (int m = 0; m < path_size; ++m) {
      double forward_s = navigation_path.pathpoint[m].s - start_s;
      if (forward_s > config_.maxlenfromnavigationline) {
        break;
      }

      for (int n = path_size - 1; n >= 0; --n) {
        double reverse_s = end_s - navigation_path.pathpoint[n].s;
        if (reverse_s > config_.maxlenfromnavigationline) {
          break;
        }
        if (m == n) {
          break;
        }

        double current_distance = DistanceXY(navigation_path.pathpoint[m],
                                             navigation_path.pathpoint[n]);
        if (current_distance < min_distance) {
          min_distance = current_distance;
          min_index_pair = std::make_pair(m, n);
        }
      }
    }

    if (min_distance < config_.minlanehalfwidth) {
      AINFO << "The stitching pair is: (" << min_index_pair.first << ", "
            << min_index_pair.second << ") for the navigation line: " << i;
      stitch_index_map_[i] = min_index_pair;
    }
  }
}

}  // namespace relative_map
}  // namespace apollo