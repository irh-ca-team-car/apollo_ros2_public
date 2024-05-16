cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(can_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(apollo_msgs REQUIRED)

file(GLOB_RECURSE SRC_V2X "../../src/modules/v2x/*.cpp")
file(GLOB_RECURSE SRC_COMMON "../../src/modules/common/*.cpp")

add_executable(
v2x_fusion_component
../../src/main/v2x.cpp
../../src/component/v2x_fusion.cpp
${SRC_V2X}
)

target_include_directories(v2x_fusion_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>)

ament_target_dependencies(
  v2x_fusion_component
  rclcpp
  std_msgs
  sensor_msgs 
  apollo_msgs)
target_link_libraries(v2x_fusion_component common )

install(TARGETS
  v2x_fusion_component
  DESTINATION lib/${PROJECT_NAME})
