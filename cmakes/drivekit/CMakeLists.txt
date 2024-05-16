cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)

add_executable(
drivekit_component
../../src/main/drivekit.cpp
../../src/component/drivekit.cpp
../../src/modules/drivekit/pid_control.cpp
)

target_link_libraries(
  drivekit_component
  common)
ament_target_dependencies(drivekit_component apollo_msgs rclcpp )

target_include_directories(drivekit_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include)

install(TARGETS
  drivekit_component
  DESTINATION lib/${PROJECT_NAME})