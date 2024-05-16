cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(can_msgs REQUIRED)
find_package(tf2_msgs REQUIRED)
find_package(apollo_msgs REQUIRED)

add_executable(
canbus_component
../../src/main/canbus.cpp
../../src/component/canbus.cpp
../../src/modules/canbus/kia/translator.cpp
../../src/modules/canbus/common/canbus_gflags.cpp)

ament_target_dependencies(canbus_component apollo_msgs rclcpp  can_msgs tf2_msgs )
target_link_libraries(
  canbus_component
  common)
target_include_directories(canbus_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
)
install(TARGETS
  canbus_component
  DESTINATION lib/${PROJECT_NAME})