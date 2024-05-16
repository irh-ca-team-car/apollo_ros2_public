cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(can_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(apollo_msgs REQUIRED)

add_executable(
demo_timer_component
../../../src/main/demo_timer.cpp
../../../src/component/demo_timer.cpp
)
target_link_libraries(
  demo_timer_component
  common)
ament_target_dependencies(demo_timer_component rclcpp std_msgs can_msgs sensor_msgs cv_bridge  OpenCV)

target_include_directories(demo_timer_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include)
install(TARGETS
  demo_timer_component
  DESTINATION lib/${PROJECT_NAME})