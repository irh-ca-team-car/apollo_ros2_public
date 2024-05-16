cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)

add_executable(
imu_adapter_component
../../../src/main/imu-adapter.cpp
../../../src/component/imu-adapter.cpp
)

ament_target_dependencies(imu_adapter_component apollo_msgs rclcpp)
target_link_libraries(
  imu_adapter_component
  common
  )
target_include_directories(imu_adapter_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
)
install(TARGETS
  imu_adapter_component
  DESTINATION lib/${PROJECT_NAME})