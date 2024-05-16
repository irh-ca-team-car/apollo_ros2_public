cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)

add_executable(
storytelling_component
../../src/main/storytelling.cpp
../../src/component/storytelling.cpp
../../src/modules/storytelling/common/storytelling_gflags.cpp
../../src/modules/storytelling/frame_manager.cpp
../../src/modules/storytelling/story_tellers/close_to_junction_teller.cpp
)

target_link_libraries(
  storytelling_component
  common hdmap)
ament_target_dependencies(storytelling_component apollo_msgs rclcpp)

target_include_directories(storytelling_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include)

install(TARGETS
  storytelling_component
  DESTINATION lib/${PROJECT_NAME})