cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)


add_executable(
demo_component
../../../src/main/demo.cpp
../../../src/component/demo.cpp
)

target_link_libraries(
  demo_component
  common)
ament_target_dependencies(demo_component apollo_msgs rclcpp)

target_include_directories(demo_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include)

install(TARGETS
  demo_component
  DESTINATION lib/${PROJECT_NAME})