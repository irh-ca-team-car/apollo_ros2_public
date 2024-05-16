cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(apollo_msgs REQUIRED)

file(GLOB_RECURSE SRC_task_manager "../../src/modules/task_manager/*.cpp")
file(GLOB_RECURSE SRC_COMMON "../../src/modules/common/*.cpp")

add_executable(
task_manager_component
../../src/main/task_manager.cpp
../../src/component/task_manager.cpp
${SRC_task_manager}
../../src/modules/dreamview/map/map_service.cpp
)

target_include_directories(task_manager_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>)

ament_target_dependencies(
  task_manager_component
  rclcpp
  std_msgs
  apollo_msgs)
target_link_libraries(task_manager_component common hdmap )

install(TARGETS
  task_manager_component
  DESTINATION lib/${PROJECT_NAME})

