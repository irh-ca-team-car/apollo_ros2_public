cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(apollo_msgs REQUIRED)

add_executable(
demo_multiargs_component
../../../src/main/multiargs.cpp
../../../src/component/multiargs.cpp
)
target_link_libraries(
  demo_multiargs_component
  common)
ament_target_dependencies(demo_multiargs_component rclcpp std_msgs)

target_include_directories(demo_multiargs_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include)
install(TARGETS
  demo_multiargs_component
  DESTINATION lib/${PROJECT_NAME})