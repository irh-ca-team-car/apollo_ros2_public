cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

add_executable(
odometry_adapter_component
../../../src/main/odometry-adapter.cpp
../../../src/component/odometry-adapter.cpp
)

ament_target_dependencies(odometry_adapter_component apollo_msgs rclcpp nav_msgs)
target_link_libraries(
  odometry_adapter_component
  common
  )
target_include_directories(odometry_adapter_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
)
install(TARGETS
  odometry_adapter_component
  DESTINATION lib/${PROJECT_NAME})