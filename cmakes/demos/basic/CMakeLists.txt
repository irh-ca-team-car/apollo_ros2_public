cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)

add_executable(
demo_basic_component
../../../src/main/basic.cpp
../../../src/component/basic.cpp
)
ament_target_dependencies(demo_basic_component rclcpp )
target_link_libraries(
  demo_basic_component
  common )
target_include_directories(demo_basic_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
)
install(TARGETS
  demo_basic_component
  DESTINATION lib/${PROJECT_NAME})
