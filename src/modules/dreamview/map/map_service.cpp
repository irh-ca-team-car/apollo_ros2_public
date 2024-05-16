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

#include "modules/dreamview/backend/map/map_service.h"

#include <algorithm>
#include <fstream>
#include <utility>

#include "modules/common/util/json_util.h"
#include "modules/common/util/string_util.h"
#include "modules/map/hdmap/hdmap_util.h"

namespace apollo {
namespace dreamview {

using apollo::common::PointENU;
using apollo::hdmap::ClearAreaInfoConstPtr;
using apollo::hdmap::CrosswalkInfoConstPtr;
using apollo::hdmap::HDMapUtil;
using apollo::hdmap::Id;
using apollo::hdmap::JunctionInfoConstPtr;
using apollo::hdmap::LaneInfoConstPtr;
using apollo::hdmap::Map;
using apollo::hdmap::MapPathPoint;
using apollo::hdmap::ParkingSpaceInfoConstPtr;
using apollo::hdmap::Path;
using apollo::hdmap::PNCJunctionInfoConstPtr;
using apollo::hdmap::SignalInfoConstPtr;
using apollo::hdmap::SpeedBumpInfoConstPtr;
using apollo::hdmap::StopSignInfoConstPtr;
using apollo::hdmap::YieldSignInfoConstPtr;
using apollo::routing::RoutingResponse;

namespace {

template <typename MapElementInfoConstPtr>
void ExtractIds(const std::vector<MapElementInfoConstPtr> &items,
                std::vector<std::string> *ids) {
  ids->reserve(static_cast<unsigned int>(items.size()));
  for (const auto &item : items) {
    ids->push_back(item->id.id);
  }
  // The output is sorted so that the calculated hash will be
  // invariant to the order of elements.
  std::sort(ids->begin(), ids->end());
}
}  // namespace

const char MapService::kMetaFileName[] = "/metaInfo.json";

MapService::MapService(bool use_sim_map) : use_sim_map_(use_sim_map) {
  ReloadMap(false);
}

bool MapService::ReloadMap(bool force_reload) {
  std::unique_lock<std::shared_mutex> writer_lock(mutex_);
  bool ret = true;
  if (force_reload) {
    ret = HDMapUtil::ReloadMaps();
  }

  // Update the x,y-offsets if present.
  UpdateOffsets();
  return ret;
}

void MapService::UpdateOffsets() {
  x_offset_ = 0.0;
  y_offset_ = 0.0;
  std::ifstream ifs(FLAGS_map_dir + kMetaFileName);
  if (!ifs.is_open()) {
    AINFO << "Failed to open map meta file: " << kMetaFileName;
  } else {
    nlohmann::json json;
    ifs >> json;
    ifs.close();

    for (auto it = json.begin(); it != json.end(); ++it) {
      auto val = it.value();
      if (val.is_object()) {
        auto x_offset = val.find("xoffset");
        if (x_offset == val.end()) {
          AWARN << "Cannot find x_offset for this map " << it.key();
          continue;
        }

        if (!x_offset->is_number()) {
          AWARN << "Expect x_offset with type 'number', but was "
                << x_offset->type_name();
          continue;
        }
        x_offset_ = x_offset.value();

        auto y_offset = val.find("yoffset");
        if (y_offset == val.end()) {
          AWARN << "Cannot find y_offset for this map " << it.key();
          continue;
        }

        if (!y_offset->is_number()) {
          AWARN << "Expect y_offset with type 'number', but was "
                << y_offset->type_name();
          continue;
        }
        y_offset_ = y_offset.value();
      }
    }
  }
  AINFO << "Updated with map: x_offset " << x_offset_ << ", y_offset "
        << y_offset_;
}

const hdmap::HDMap *MapService::HDMap() const {
  return HDMapUtil::BaseMapPtr();
}

const hdmap::HDMap *MapService::SimMap() const {
  return use_sim_map_ ? HDMapUtil::SimMapPtr() : HDMapUtil::BaseMapPtr();
}

bool MapService::MapReady() const { return HDMap() && SimMap(); }

bool MapService::GetNearestLane(const double x, const double y,
                                LaneInfoConstPtr *nearest_lane,
                                double *nearest_s, double *nearest_l) const {
  std::shared_lock<std::shared_mutex> reader_lock(mutex_);

  PointENU point;
  point.set__x(x);
  point.set__y(y);
  if (!MapReady() ||
      HDMap()->GetNearestLane(point, nearest_lane, nearest_s, nearest_l) < 0) {
    AERROR << "Failed to get nearest lane!";
    return false;
  }
  return true;
}

bool MapService::GetNearestLaneWithHeading(const double x, const double y,
                                           LaneInfoConstPtr *nearest_lane,
                                           double *nearest_s, double *nearest_l,
                                           const double heading) const {
  std::shared_lock<std::shared_mutex> reader_lock(mutex_);

  PointENU point;
  point.set__x(x);
  point.set__y(y);
  static constexpr double kSearchRadius = 1.0;
  static constexpr double kMaxHeadingDiff = 1.0;
  if (!MapReady() || HDMap()->GetNearestLaneWithHeading(
                         point, kSearchRadius, heading, kMaxHeadingDiff,
                         nearest_lane, nearest_s, nearest_l) < 0) {
    AERROR << "Failed to get nearest lane with heading.";
    return false;
  }
  return true;
}

bool MapService::GetPathsFromRouting(const RoutingResponse &routing,
                                     std::vector<Path> *paths) const {
  if (!CreatePathsFromRouting(routing, paths)) {
    AERROR << "Unable to get paths from routing!";
    return false;
  }
  return true;
}

bool MapService::GetPoseWithRegardToLane(const double x, const double y,
                                         double *theta, double *s) const {
  double l;
  LaneInfoConstPtr nearest_lane;
  if (!GetNearestLane(x, y, &nearest_lane, s, &l)) {
    return false;
  }

  *theta = nearest_lane->Heading(*s);
  return true;
}

bool MapService::ConstructLaneWayPoint(
    const double x, const double y, routing::LaneWaypoint *laneWayPoint) const {
  double s, l;
  LaneInfoConstPtr lane;
  if (!GetNearestLane(x, y, &lane, &s, &l)) {
    return false;
  }

  if (!CheckRoutingPointLaneType(lane)) {
    return false;
  }

  laneWayPoint->set__id(lane->id().id);
  laneWayPoint->set__s(s);
  auto *pose = &laneWayPoint->pose;
  pose->set__x(x);
  pose->set__y(y);

  return true;
}

bool MapService::ConstructLaneWayPointWithHeading(
    const double x, const double y, const double heading,
    routing::LaneWaypoint *laneWayPoint) const {
  double s, l;
  LaneInfoConstPtr lane;
  if (!GetNearestLaneWithHeading(x, y, &lane, &s, &l, heading)) {
    return false;
  }

  if (!CheckRoutingPointLaneType(lane)) {
    return false;
  }

  laneWayPoint->set__id(lane->id().id);
  laneWayPoint->set__s(s);
  auto *pose = &laneWayPoint->pose;
  pose->set__x(x);
  pose->set__y(y);

  return true;
}

bool MapService::CheckRoutingPoint(const double x, const double y) const {
  double s, l;
  LaneInfoConstPtr lane;
  if (!GetNearestLane(x, y, &lane, &s, &l)) {
    return false;
  }
  if (!CheckRoutingPointLaneType(lane)) {
    return false;
  }
  return true;
}

bool MapService::CheckRoutingPointLaneType(LaneInfoConstPtr lane) const {
  if (lane->lane().type != apollo::hdmap::Lane::CITY_DRIVING) {
    AERROR
        << "Failed to construct LaneWayPoint for RoutingRequest: Expected lane "
        << lane->id().id << " to be CITY_DRIVING, but was "
        << apollo::hdmap::Lane::LaneType_Name((apollo::hdmap::Lane::LaneType)lane->lane().type);
    return false;
  }
  return true;
}

bool MapService::GetStartPoint(apollo::common::PointENU *start_point) const {
  // Start from origin to find a lane from the map.
  double s, l;
  LaneInfoConstPtr lane;
  if (!GetNearestLane(0.0, 0.0, &lane, &s, &l)) {
    return false;
  }

  *start_point = lane->GetSmoothPoint(0.0);
  return true;
}

bool MapService::CreatePathsFromRouting(const RoutingResponse &routing,
                                        std::vector<Path> *paths) const {
  if (routing.road.empty()) {
    return false;
  }

  for (const auto &road : routing.road) {
    for (const auto &passage_region : road.passage) {
      // Each passage region in a road forms a path
      if (!AddPathFromPassageRegion(passage_region, paths)) {
        return false;
      }
    }
  }
  return true;
}

bool MapService::AddPathFromPassageRegion(
    const routing::Passage &passage_region, std::vector<Path> *paths) const {
  if (!MapReady()) {
    return false;
  }
  std::shared_lock<std::shared_mutex> reader_lock(mutex_);

  std::vector<MapPathPoint> path_points;
  for (const auto &segment : passage_region.segment) {
    auto lane_ptr = HDMap()->GetLaneById(hdmap::MakeMapId(segment.id));
    if (!lane_ptr) {
      AERROR << "Failed to find lane: " << segment.id;
      return false;
    }
    if (segment.starts >= segment.ends) {
      continue;
    }
    auto points = MapPathPoint::GetPointsFromLane(lane_ptr, segment.starts,
                                                  segment.ends);
    path_points.insert(path_points.end(), points.begin(), points.end());
  }

  if (path_points.size() < 2) {
    return false;
  }
  paths->emplace_back(Path(std::move(path_points)));

  return true;
}

}  // namespace dreamview
}  // namespace apollo