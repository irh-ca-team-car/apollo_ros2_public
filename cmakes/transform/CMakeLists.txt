cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(tf2_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

file(GLOB_RECURSE SRC_static_transform "../../src/modules/static_transform/*.cpp")
file(GLOB_RECURSE SRC_COMMON "../../src/modules/common/*.cpp")

add_executable(
static_transform_component
../../src/main/static_transform.cpp
../../src/component/static_transform.cpp
${SRC_static_transform}
)

target_include_directories(static_transform_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>)

ament_target_dependencies(
  static_transform_component
  rclcpp
  std_msgs
  sensor_msgs 
  apollo_msgs
  tf2_msgs
  geometry_msgs)
target_link_libraries(static_transform_component common )

install(TARGETS
  static_transform_component
  DESTINATION lib/${PROJECT_NAME})
