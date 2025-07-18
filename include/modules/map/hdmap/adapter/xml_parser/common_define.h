/* Copyright 2017 The Apollo Authors. All Rights Reserved.
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
=========================================================================*/
#pragma once

#include <string>
#include <unordered_set>
#include <vector>

#include "cyber/cyber.h"
#include "modules/map/proto/map.pb.h"

namespace apollo {
namespace hdmap {
namespace adapter {

using PbHeader = apollo::hdmap::Header;
using PbRoad = apollo_msgs::msg::ApollohdmapRoad;
using PbRoadSection = apollo::hdmap::RoadSection;
using PbLane = apollo_msgs::msg::ApollohdmapLane;
using PbJunction = apollo::hdmap::Junction;
using PbSignal = apollo_msgs::msg::ApollohdmapSignal;
using PbSubSignal = apollo_msgs::msg::ApollohdmapSubsignal;
using PbRSU = apollo::hdmap::RSU;
using PbCrosswalk = apollo::hdmap::Crosswalk;
using PbParkingSpace = apollo::hdmap::ParkingSpace;
using PbSpeedBump = apollo::hdmap::SpeedBump;
using PbStopSign = apollo_msgs::msg::ApollohdmapStopSign;
using PbYieldSign = apollo::hdmap::YieldSign;
using PbObjectOverlapInfo = apollo_msgs::msg::ApollohdmapObjectOverlapInfo;
using PbOverlap = apollo::hdmap::Overlap;
using PbClearArea = apollo::hdmap::ClearArea;
using PbLineSegment = apollo::hdmap::LineSegment;
using PbCurveSegment = apollo_msgs::msg::ApollohdmapCurveSegment;
using PbCurve = apollo::hdmap::Curve;
using PbPoint3D = apollo::common::PointENU;
using PbLaneType = apollo::hdmap::Lane::LaneType;
using PbTurnType = apollo::hdmap::Lane::LaneTurn;
using PbID = apollo::hdmap::Id;
using PbLaneBoundary = apollo::hdmap::LaneBoundary;
using PbLaneBoundaryTypeType = apollo::hdmap::LaneBoundaryType::Type;
using PbPolygon = apollo::hdmap::Polygon;
using PbBoundaryPolygon = apollo::hdmap::BoundaryPolygon;
using PbBoundaryEdge = apollo_msgs::msg::ApollohdmapBoundaryEdge;
using PbRegionOverlap = apollo::hdmap::RegionOverlapInfo;
using PbPNCJunction = apollo::hdmap::PNCJunction;

using PbLaneDirection = apollo::hdmap::Lane::LaneDirection;
using PbSignalType = apollo::hdmap::Signal::Type;
using PbSubSignalType = apollo::hdmap::Subsignal::Type;
using PbStopSignType = apollo::hdmap::StopSign::StopType;
using PbBoundaryEdgeType = apollo::hdmap::BoundaryEdge::Type;
using PbRoadType = apollo::hdmap::Road::Type;
using PbSignInfoType = apollo::hdmap::SignInfo::Type;
using PbPassageType = apollo::hdmap::Passage::Type;
using PbPassageGroup = apollo::hdmap::PassageGroup;

struct StopLineInternal {
  std::string id;
  PbCurve curve;
};

struct StopSignInternal {
  std::string id;
  PbStopSign stop_sign;
  std::unordered_set<std::string> stop_line_ids;
};

struct YieldSignInternal {
  std::string id;
  PbYieldSign yield_sign;
  std::unordered_set<std::string> stop_line_ids;
};

struct TrafficLightInternal {
  std::string id;
  PbSignal traffic_light;
  std::unordered_set<std::string> stop_line_ids;
};

struct OverlapWithLane {
  std::string object_id;
  double start_s;
  double end_s;
  bool is_merge;

  std::string region_overlap_id;
  std::vector<PbRegionOverlap> region_overlaps;
};

struct OverlapWithJunction {
  std::string object_id;
};

struct LaneInternal {
  PbLane lane;
  std::vector<OverlapWithLane> overlap_signals;
  std::vector<OverlapWithLane> overlap_objects;
  std::vector<OverlapWithLane> overlap_junctions;
  std::vector<OverlapWithLane> overlap_lanes;
};

struct JunctionInternal {
  PbJunction junction;
  std::unordered_set<std::string> road_ids;
  std::vector<OverlapWithJunction> overlap_with_junctions;
};

struct RoadSectionInternal {
  std::string id;
  PbRoadSection section;
  std::vector<LaneInternal> lanes;
};

struct RoadInternal {
  std::string id;
  PbRoad road;

  bool in_junction;
  std::string junction_id;

  std::string type;

  std::vector<RoadSectionInternal> sections;

  std::vector<TrafficLightInternal> traffic_lights;
  // std::vector<RSUInternal> rsus;
  std::vector<StopSignInternal> stop_signs;
  std::vector<YieldSignInternal> yield_signs;
  std::vector<PbCrosswalk> crosswalks;
  std::vector<PbClearArea> clear_areas;
  std::vector<PbSpeedBump> speed_bumps;
  std::vector<StopLineInternal> stop_lines;
  std::vector<PbParkingSpace> parking_spaces;
  std::vector<PbPNCJunction> pnc_junctions;

  RoadInternal() : in_junction(false) { junction_id = ""; }
};

struct RSUInternal {
  std::string id;
  PbRSU rsu;
};

struct ObjectInternal {
  std::vector<RSUInternal> rsus;
};

}  // namespace adapter
}  // namespace hdmap
}  // namespace apollo
