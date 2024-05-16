cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV 4 REQUIRED)

add_executable(
adc_trajectory_adapter_component
../../../src/main/adc-trajectory-adapter.cpp
../../../src/component/adc-trajectory-adapter.cpp
)

ament_target_dependencies(adc_trajectory_adapter_component apollo_msgs rclcpp nav_msgs cv_bridge OpenCV)
target_link_libraries(
  adc_trajectory_adapter_component
  common
  )
target_include_directories(adc_trajectory_adapter_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
)
install(TARGETS
  adc_trajectory_adapter_component
  DESTINATION lib/${PROJECT_NAME})