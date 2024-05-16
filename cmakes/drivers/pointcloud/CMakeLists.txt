cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)

add_executable(
pointcloud_adapter_component
../../../src/main/pointcloud_adapter.cpp
../../../src/component/pointcloud_adapter.cpp
)

ament_target_dependencies(pointcloud_adapter_component apollo_msgs rclcpp)
target_link_libraries(
  pointcloud_adapter_component
  common
  )
target_include_directories(pointcloud_adapter_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
)
install(TARGETS
  pointcloud_adapter_component
  DESTINATION lib/${PROJECT_NAME})