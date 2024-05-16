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

#include "modules/map/hdmap/adapter/proto_organizer.h"

#include <unordered_set>

#include "absl/strings/str_cat.h"

#include "cyber/cyber.h"
#include "modules/common/math/polygon2d.h"
#include "modules/common/math/vec2d.h"

namespace {

std::string CreateOverlapId() {
  static int count = 0;
  ++count;
  return absl::StrCat("overlap_", count);
}

}  // namespace

namespace apollo {
namespace hdmap {
namespace adapter {

using apollo::common::util::PairHash;

void ProtoOrganizer::GetRoadElements(std::vector<RoadInternal>* roads) {
  for (auto& road_internal : *roads) {
    // lanes
    for (auto& section_internal : road_internal.sections) {
      for (auto& lane_internal : section_internal.lanes) {
        std::string lane_id = lane_internal.lane.id.id;
        proto_data_.pb_lanes[lane_id] = lane_internal.lane;
        Id interid;
        interid.id = lane_id;
        section_internal.section.laneid.push_back(interid);
      }
      road_internal.road.section.push_back(section_internal.section);
      proto_data_.pb_roads[road_internal.id] = road_internal.road;
    }
    // crosswalks
    for (auto& crosswalk : road_internal.crosswalks) {
      proto_data_.pb_crosswalks[crosswalk.id.id] = crosswalk;
    }
    // parking_spaces
    for (auto& parking_space : road_internal.parking_spaces) {
      proto_data_.pb_parking_spaces[parking_space.id.id] = parking_space;
    }
    // clear areas
    for (auto& clear_area : road_internal.clear_areas) {
      proto_data_.pb_clear_areas[clear_area.id.id] = clear_area;
    }
    // speed_bump
    for (auto& speed_bump : road_internal.speed_bumps) {
      proto_data_.pb_speed_bumps[speed_bump.id.id] = speed_bump;
    }
    // stop lines
    for (auto& stop_line_internal : road_internal.stop_lines) {
      proto_data_.pb_stop_lines[stop_line_internal.id] = stop_line_internal;
    }
    // traffic_lights
    for (auto& traffic_light_internal : road_internal.traffic_lights) {
      auto& traffic_light = traffic_light_internal.traffic_light;
      for (auto stop_line_id : traffic_light_internal.stop_line_ids) {
        CHECK_GT(proto_data_.pb_stop_lines.count(stop_line_id), 0U);
        auto& stop_line_curve = proto_data_.pb_stop_lines[stop_line_id].curve;
        traffic_light.stopline.push_back(stop_line_curve);
      }
      proto_data_.pb_signals[traffic_light.id.id] = traffic_light;
    }
    // stop signs
    for (auto& stop_sign_internal : road_internal.stop_signs) {
      auto& stop_sign = stop_sign_internal.stop_sign;
      for (auto stop_line_id : stop_sign_internal.stop_line_ids) {
        CHECK_GT(proto_data_.pb_stop_lines.count(stop_line_id), 0U);
        auto& stop_line_curve = proto_data_.pb_stop_lines[stop_line_id].curve;
        stop_sign.stopline.push_back(stop_line_curve);
      }
      proto_data_.pb_stop_signs[stop_sign.id.id] = stop_sign;
    }
    // yield signs
    for (auto& yield_sign_internal : road_internal.yield_signs) {
      auto& yield_sign = yield_sign_internal.yield_sign;
      for (auto stop_line_id : yield_sign_internal.stop_line_ids) {
        CHECK_GT(proto_data_.pb_stop_lines.count(stop_line_id), 0U);
        auto& stop_line_curve = proto_data_.pb_stop_lines[stop_line_id].curve;
        yield_sign.stopline.push_back(stop_line_curve);
      }
      proto_data_.pb_yield_signs[yield_sign.id.id] = yield_sign;
    }
    // pnc junctions
    for (auto& pnc_junction : road_internal.pnc_junctions) {
      proto_data_.pb_pnc_junctions[pnc_junction.id.id] = pnc_junction;
    }
  }
}

void ProtoOrganizer::GetJunctionElements(
    const std::vector<JunctionInternal>& junctions) {
  for (auto& junction_internal : junctions) {
    std::string junction_id = junction_internal.junction.id.id;
    proto_data_.pb_junctions[junction_id] = junction_internal.junction;
  }
}

void ProtoOrganizer::GetLaneObjectOverlapElements(
    const std::string& lane_id,
    const std::vector<OverlapWithLane>& overlap_with_lanes) {
  for (auto& overlap_object : overlap_with_lanes) {
    std::string object_id = overlap_object.object_id;
    if (proto_data_.pb_crosswalks.count(object_id) <= 0 &&
        proto_data_.pb_clear_areas.count(object_id) <= 0 &&
        proto_data_.pb_speed_bumps.count(object_id) <= 0 &&
        proto_data_.pb_parking_spaces.count(object_id) <= 0 &&
        proto_data_.pb_pnc_junctions.count(object_id) <= 0) {
      continue;
    }
    PbOverlap overlap;
    std::string overlap_id = CreateOverlapId();
    overlap.id.id=overlap_id;
    for (auto& region_overlap : overlap_object.region_overlaps) {
      overlap.regionoverlap.push_back(region_overlap);
    }

    PbObjectOverlapInfo object_overlap; //= overlap.add_object();
    object_overlap.id.id=lane_id;
    object_overlap.overlapinfo.laneoverlapinfo.starts=overlap_object.start_s;
    object_overlap.overlapinfo.laneoverlapinfo.ends=overlap_object.end_s;
    object_overlap.overlapinfo.laneoverlapinfo.ismerge=overlap_object.is_merge;
    if (!overlap_object.region_overlap_id.empty()) {
      object_overlap.overlapinfo.laneoverlapinfo
          .regionoverlapid
          .id=overlap_object.region_overlap_id;
    }
    
    overlap.object.push_back(object_overlap);
    
    PbObjectOverlapInfo object_overlap1;
    
    //object_overlap = overlap.add_object();
    object_overlap1.id.id=object_id;
    if (proto_data_.pb_crosswalks.count(object_id) > 0) {
      Id interoverid;
      interoverid.id = overlap_id;
      proto_data_.pb_crosswalks[object_id].overlapid.push_back(interoverid);
      if (!overlap_object.region_overlap_id.empty()) {
        object_overlap1.overlapinfo.crosswalkoverlapinfo
            .regionoverlapid
            .id=overlap_object.region_overlap_id;
      }
      //object_overlap1.overlapinfo.crosswalkoverlapinfo;
    } else if (proto_data_.pb_clear_areas.count(object_id) > 0) {
      //object_overlap1.overlapinfo.clearareaoverlapinfo;
      Id interoverid;
      interoverid.id = overlap_id;
      proto_data_.pb_clear_areas[object_id].overlapid.push_back(interoverid);
    } else if (proto_data_.pb_speed_bumps.count(object_id)) {
      //object_overlap1.overlapinfo.speedbumpoverlapinfo;
      Id interoverid;
      interoverid.id = overlap_id;
      proto_data_.pb_speed_bumps[object_id].overlapid.push_back(interoverid);
    } else if (proto_data_.pb_parking_spaces.count(object_id)) {
      //object_overlap1.overlapinfo.parkingspaceoverlapinfo;
      Id interoverid;
      interoverid.id = overlap_id;
      proto_data_.pb_parking_spaces[object_id].overlapid.push_back(interoverid);
    } else if (proto_data_.pb_pnc_junctions.count(object_id)) {
      //object_overlap1.overlapinfo.pncjunctionoverlapinfo;
      Id interoverid;
      interoverid.id = overlap_id;
      proto_data_.pb_pnc_junctions[object_id].overlapid.push_back(interoverid);
    } else {
      AERROR << "unknown object, object id:" << object_id;
    }
    
    overlap.object.push_back(object_overlap1);
    
    Id interoverid;
    interoverid.id = overlap_id;
    proto_data_.pb_lanes[lane_id].overlapid.push_back(interoverid);
    proto_data_.pb_overlaps[overlap_id] = overlap;
  }
}

void ProtoOrganizer::GetObjectElements(const ObjectInternal& objects) {
  for (const auto& rsu_internal : objects.rsus) {
    const std::string& rsu_id = rsu_internal.rsu.id.id;
    proto_data_.pb_rsus[rsu_id] = rsu_internal.rsu;
  }
}

void ProtoOrganizer::GetLaneSignalOverlapElements(
    const std::string& lane_id,
    const std::vector<OverlapWithLane>& overlap_with_lanes) {
  for (auto& overlap_signal : overlap_with_lanes) {
    std::string object_id = overlap_signal.object_id;
    if (proto_data_.pb_signals.count(object_id) <= 0 &&
        proto_data_.pb_stop_signs.count(object_id) <= 0 &&
        proto_data_.pb_yield_signs.count(object_id) <= 0) {
      AINFO << "cannot find signal object_id:" << object_id;
      continue;
    }
    PbOverlap overlap;
    std::string overlap_id = CreateOverlapId();
    overlap.id.id=overlap_id;
    PbObjectOverlapInfo object_overlap; //= overlap.add_object();
    object_overlap.id.id=lane_id;
    object_overlap.overlapinfo.laneoverlapinfo.starts=
        overlap_signal.start_s;
    object_overlap.overlapinfo.laneoverlapinfo.ends=
        overlap_signal.end_s;
    object_overlap.overlapinfo.laneoverlapinfo.ismerge=
        overlap_signal.is_merge;
    
    overlap.object.push_back(object_overlap);
    
    //object_overlap = overlap.add_object();
    PbObjectOverlapInfo object_overlap1;
    
    Id interoverid;
    interoverid.id = overlap_id;
    
    object_overlap1.id.id=object_id;
    if (proto_data_.pb_signals.count(object_id) > 0) {
      //object_overlap1.overlapinfo.signaloverlapinfo;
      proto_data_.pb_signals[object_id].overlapid.push_back(interoverid);
    } else if (proto_data_.pb_stop_signs.count(object_id) > 0) {
      //object_overlap1.overlapinfo.stopsignoverlapinfo;
      proto_data_.pb_stop_signs[object_id].overlapid.push_back(interoverid);
    } else if (proto_data_.pb_yield_signs.count(object_id) > 0) {
      //object_overlap1.overlapinfo.yieldsignoverlapinfo;
      proto_data_.pb_yield_signs[object_id].overlapid.push_back(interoverid);
    } else if (proto_data_.pb_rsus.count(object_id) > 0) {
      //object_overlap1.overlapinfo.rsuoverlapinfo;
      proto_data_.pb_rsus[object_id].overlapid.push_back(interoverid);
    } else {
      AERROR << "unknown signal, signal id:" << object_id;
    }
    
    overlap.object.push_back(object_overlap1);

    proto_data_.pb_lanes[lane_id].overlapid.push_back(interoverid);
    proto_data_.pb_overlaps[overlap_id] = overlap;
  }
}

void ProtoOrganizer::GetLaneJunctionOverlapElements(
    const std::string& lane_id,
    const std::vector<OverlapWithLane>& overlap_with_lanes) {
  for (auto& overlap_junction : overlap_with_lanes) {
    std::string object_id = overlap_junction.object_id;
    if (proto_data_.pb_junctions.count(object_id) <= 0) {
      AINFO << "cannot find junction object " << object_id;
      continue;
    }
    PbOverlap overlap;
    std::string overlap_id = CreateOverlapId();
    overlap.id.id=overlap_id;
    
    Id interoverid;
    interoverid.id = overlap_id;
    
    PbObjectOverlapInfo object_overlap; //= overlap.add_object();
    object_overlap.id.id=lane_id;
    object_overlap.overlapinfo.laneoverlapinfo.starts=
        overlap_junction.start_s;
    object_overlap.overlapinfo.laneoverlapinfo.ends=
        overlap_junction.end_s;
    object_overlap.overlapinfo.laneoverlapinfo.ismerge=
        overlap_junction.is_merge;
        
    overlap.object.push_back(object_overlap);
    
    PbObjectOverlapInfo object_overlap1;
    //object_overlap = overlap.add_object();
    
    object_overlap1.id.id=object_id;
    if (proto_data_.pb_junctions.count(object_id) > 0) {
      //object_overlap1.overlapinfo.junctionoverlapinfo;
      proto_data_.pb_junctions[object_id].overlapid.push_back(interoverid);
    } else {
      AERROR << "unknown junction overlap, id:" << object_id;
    }
    
    overlap.object.push_back(object_overlap1);
    
    proto_data_.pb_lanes[lane_id].overlapid.push_back(interoverid);
    proto_data_.pb_overlaps[overlap_id] = overlap;
  }
}

void ProtoOrganizer::GetLaneLaneOverlapElements(
    const std::unordered_map<std::pair<std::string, std::string>,
                             OverlapWithLane, PairHash>& lane_lane_overlaps) {
  std::unordered_set<std::string> close_set;
  for (auto& overlap_lane_pair : lane_lane_overlaps) {
    auto& lane_id = overlap_lane_pair.first.first;
    auto& overlap_lane = overlap_lane_pair.second;
    std::string object_id = overlap_lane.object_id;
    std::string unique_object_id = lane_id + "_" + object_id;
    if (close_set.count(unique_object_id) > 0) {
      continue;
    }
    unique_object_id = object_id + "_" + lane_id;
    if (close_set.count(unique_object_id) > 0) {
      continue;
    }
    close_set.insert(unique_object_id);
    PbOverlap overlap;
    std::string overlap_id = CreateOverlapId();
    overlap.id.id=overlap_id;
    PbObjectOverlapInfo object_overlap; //= overlap.add_object();
    object_overlap.id.id=lane_id;
    object_overlap.overlapinfo.laneoverlapinfo.starts=
        overlap_lane.start_s;
    object_overlap.overlapinfo.laneoverlapinfo.ends=overlap_lane.end_s;
    object_overlap.overlapinfo.laneoverlapinfo.ismerge=
        overlap_lane.is_merge;
    
    overlap.object.push_back(object_overlap);
    
    Id interoverid;
    interoverid.id = overlap_id;
        
    PbObjectOverlapInfo object_overlap1;
    //object_overlap = overlap.add_object();
    
    object_overlap1.id.id=object_id;
    if (proto_data_.pb_lanes.count(object_id) <= 0) {
      AERROR << "unknown overlap lane, id:" << object_id;
      continue;
    }

    if (lane_lane_overlaps.count(make_pair(object_id, lane_id)) <= 0) {
      AERROR << "lane overlap is not symmetrical " << overlap_id;
      continue;
    }
    proto_data_.pb_lanes[lane_id].overlapid.push_back(interoverid);
    auto& lane_lane_overlap =
        lane_lane_overlaps.at(make_pair(object_id, lane_id));
    object_overlap1.overlapinfo.laneoverlapinfo.starts=
        lane_lane_overlap.start_s;
    object_overlap1.overlapinfo.laneoverlapinfo.ends=
        lane_lane_overlap.end_s;
    object_overlap1.overlapinfo.laneoverlapinfo.ismerge=
        lane_lane_overlap.is_merge;
    
    overlap.object.push_back(object_overlap1);
    
    proto_data_.pb_lanes[object_id].overlapid.push_back(interoverid);
    proto_data_.pb_overlaps[overlap_id] = overlap;
  }
}

void ProtoOrganizer::GetJunctionObjectOverlapElements(
    const std::vector<JunctionInternal>& junctions) {
  for (auto& junction_internal : junctions) {
    const auto& junction_id = junction_internal.junction.id.id;
    for (auto& overlap_junction : junction_internal.overlap_with_junctions) {
      PbOverlap overlap;
      std::string overlap_id = CreateOverlapId();
      overlap.id.id=overlap_id;
      PbObjectOverlapInfo object_overlap; //= overlap.add_object();
      object_overlap.id.id=junction_id;
      //object_overlap.overlapinfo.junctionoverlapinfo;
      std::string object_id = overlap_junction.object_id;
      
      overlap.object.push_back(object_overlap);
      
      Id interoverid;
      interoverid.id = overlap_id;
      
      PbObjectOverlapInfo object_overlap1;
      //object_overlap = overlap.add_object();
      
      object_overlap1.id.id=object_id;
      if (proto_data_.pb_crosswalks.count(object_id) > 0) {
        //object_overlap1.overlapinfo.crosswalkoverlapinfo;
        proto_data_.pb_crosswalks[object_id].overlapid.push_back(interoverid);
      } else if (proto_data_.pb_clear_areas.count(object_id) > 0) {
        //object_overlap1.overlapinfo.clearareaoverlapinfo;
        proto_data_.pb_clear_areas[object_id].overlapid.push_back(interoverid);
      } else if (proto_data_.pb_stop_signs.count(object_id) > 0) {
        //object_overlap1.overlapinfo.stopsignoverlapinfo;
        proto_data_.pb_stop_signs[object_id].overlapid.push_back(interoverid);
      } else if (proto_data_.pb_signals.count(object_id) > 0) {
        //object_overlap1.overlapinfo.signaloverlapinfo;
        proto_data_.pb_signals[object_id].overlapid.push_back(interoverid);
      } else if (proto_data_.pb_rsus.count(object_id) > 0) {
        //object_overlap1.overlapinfo.rsuoverlapinfo;
        proto_data_.pb_rsus[object_id].overlapid.push_back(interoverid);
      } else {
        continue;
      }
      
      overlap.object.push_back(object_overlap1);

      proto_data_.pb_junctions[junction_id].overlapid.push_back(interoverid);
      proto_data_.pb_overlaps[overlap_id] = overlap;
    }
  }
}

void ProtoOrganizer::GetOverlapElements(
    const std::vector<RoadInternal>& roads,
    const std::vector<JunctionInternal>& junctions) {
  std::unordered_map<std::pair<std::string, std::string>, OverlapWithLane,
                     PairHash>
      lane_lane_overlaps;
  // overlap
  for (auto& road_internal : roads) {
    for (auto& road_section : road_internal.sections) {
      for (auto& lane_internal : road_section.lanes) {
        std::string lane_id = lane_internal.lane.id.id;
        GetLaneObjectOverlapElements(lane_id, lane_internal.overlap_objects);
        GetLaneSignalOverlapElements(lane_id, lane_internal.overlap_signals);
        GetLaneJunctionOverlapElements(lane_id,
                                       lane_internal.overlap_junctions);
        for (auto& overlap_lane : lane_internal.overlap_lanes) {
          lane_lane_overlaps[make_pair(lane_id, overlap_lane.object_id)] =
              overlap_lane;
        }
      }
    }
  }

  GetLaneLaneOverlapElements(lane_lane_overlaps);
  GetJunctionObjectOverlapElements(junctions);
}

void ProtoOrganizer::OutputData(apollo::hdmap::Map* pb_map) {
  for (auto& road_pair : proto_data_.pb_roads) {
    pb_map->road.push_back(road_pair.second);
  }
  for (auto& lane_pair : proto_data_.pb_lanes) {
    pb_map->lane.push_back(lane_pair.second);
  }
  for (auto& crosswalk_pair : proto_data_.pb_crosswalks) {
    pb_map->crosswalk.push_back(crosswalk_pair.second);
  }
  for (auto& parking_space_pair : proto_data_.pb_parking_spaces) {
    pb_map->parkingspace.push_back(parking_space_pair.second);
  }
  for (auto& clear_area_pair : proto_data_.pb_clear_areas) {
    pb_map->cleararea.push_back(clear_area_pair.second);
  }
  for (auto& speed_bump_pair : proto_data_.pb_speed_bumps) {
    pb_map->speedbump.push_back(speed_bump_pair.second);
  }
  for (auto& signal_pair : proto_data_.pb_signals) {
    pb_map->signal.push_back(signal_pair.second);
  }
  for (auto& stop_sign_pair : proto_data_.pb_stop_signs) {
    pb_map->stopsign.push_back(stop_sign_pair.second);
  }
  for (auto& yield_sign_pair : proto_data_.pb_yield_signs) {
    pb_map->yieldd.push_back(yield_sign_pair.second);
  }
  for (auto& pnc_junction_pair : proto_data_.pb_pnc_junctions) {
    pb_map->pncjunction.push_back(pnc_junction_pair.second);
  }
  for (auto& junction_pair : proto_data_.pb_junctions) {
    pb_map->junction.push_back(junction_pair.second);
  }
  for (auto& rsu_pair : proto_data_.pb_rsus) {
    pb_map->rsu.push_back(rsu_pair.second);
  }
  for (auto& overlap_pair : proto_data_.pb_overlaps) {
    pb_map->overlap.push_back(overlap_pair.second);
  }

  AINFO << "hdmap statistics: roads-" << proto_data_.pb_roads.size()
        << ",lanes-" << proto_data_.pb_lanes.size() << ",crosswalks-"
        << proto_data_.pb_crosswalks.size() << ",parking spaces-"
        << proto_data_.pb_parking_spaces.size() << ",clear areas-"
        << proto_data_.pb_clear_areas.size() << ",speed bumps-"
        << proto_data_.pb_speed_bumps.size() << ",signals-"
        << proto_data_.pb_signals.size() << ",stop signs-"
        << proto_data_.pb_stop_signs.size() << ",yield signs-"
        << proto_data_.pb_yield_signs.size() << ",pnc-junctions-"
        << proto_data_.pb_pnc_junctions.size() << ",junctions-"
        << proto_data_.pb_junctions.size() << ",overlaps-"
        << proto_data_.pb_rsus.size() << ",rsus-"
        << proto_data_.pb_overlaps.size();
}

}  // namespace adapter
}  // namespace hdmap
}  // namespace apollo

