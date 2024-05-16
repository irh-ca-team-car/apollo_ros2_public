cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)

file(GLOB_RECURSE SRC_guardian "../../src/modules/guardian/*.cpp")
file(GLOB_RECURSE SRC_COMMON "../../src/modules/common/*.cpp")

add_executable(
guardian_component
../../src/main/guardian.cpp
../../src/component/guardian.cpp
${SRC_guardian}
)

target_include_directories(guardian_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>)

ament_target_dependencies(
  guardian_component
  rclcpp
  apollo_msgs)
target_link_libraries(guardian_component common )

install(TARGETS
  guardian_component
  DESTINATION lib/${PROJECT_NAME})