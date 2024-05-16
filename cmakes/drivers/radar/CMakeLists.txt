cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(radar_conti_ars408_msgs REQUIRED)

add_executable(
radar_adapter_component
../../../src/main/radar-adapter.cpp
../../../src/component/radar-adapter.cpp
)

ament_target_dependencies(radar_adapter_component apollo_msgs rclcpp radar_conti_ars408_msgs)
target_link_libraries(
  radar_adapter_component
  common
  )
target_include_directories(radar_adapter_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
)
install(TARGETS
  radar_adapter_component
  DESTINATION lib/${PROJECT_NAME})