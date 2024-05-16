cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(PROJ4 REQUIRED)

add_library(
hdmap
STATIC 
#../../src/modules/perception/map/hdmap/hdmap_input.cpp
../../src/modules/map/proto/map_lane_name.cpp
../../src/modules/map/hdmap/hdmap.cpp
../../src/modules/map/hdmap/hdmap_util.cpp
../../src/modules/map/hdmap/hdmap_impl.cpp
../../src/modules/map/hdmap/adapter/opendrive_adapter.cpp
../../src/modules/map/hdmap/adapter/serialization/junctioninfo.cpp
../../src/modules/map/hdmap/adapter/serialization/laneinfo.cpp
../../src/modules/map/hdmap/hdmap_common.cpp
../../src/modules/map/hdmap/adapter/tinyxml2.cpp
../../src/modules/map/hdmap/adapter/xml_parser/roads_xml_parser.cpp
../../src/modules/map/hdmap/adapter/xml_parser/header_xml_parser.cpp
../../src/modules/map/hdmap/adapter/xml_parser/junctions_xml_parser.cpp
../../src/modules/map/hdmap/adapter/xml_parser/lanes_xml_parser.cpp
../../src/modules/map/hdmap/adapter/xml_parser/objects_xml_parser.cpp
../../src/modules/map/hdmap/adapter/xml_parser/signals_xml_parser.cpp
../../src/modules/map/hdmap/adapter/xml_parser/util_xml_parser.cpp
../../src/modules/map/hdmap/adapter/proto_organizer.cpp
../../src/modules/map/hdmap/adapter/coordinate_convert_tool.cpp
../../src/modules/map/pnc_map/path.cpp
../../src/modules/map/pnc_map/pnc_map.cpp
../../src/modules/map/pnc_map/route_segments.cpp
)

ament_target_dependencies(hdmap rclcpp 
  apollo_msgs)
target_compile_definitions(hdmap PRIVATE USE_GPU)
  target_link_libraries(
  hdmap
  common /usr/local/lib/libproj.so.12.0.0 )
target_include_directories(hdmap
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include)
