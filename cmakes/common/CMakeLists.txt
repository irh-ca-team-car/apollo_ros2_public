cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

file(GLOB_RECURSE SRC_COMMON "../../src/modules/common/*.cpp")
file(GLOB_RECURSE SRC_COMMON2 "../../src/cyber/*.cpp")
file(GLOB_RECURSE SRC_COMMON3 "../../src/common/*.cpp")
file(GLOB_RECURSE SRC_COMMON4 "../../src/adapter/*.cpp")


add_library(
common
STATIC 
${SRC_COMMON}
${SRC_COMMON2}
${SRC_COMMON3}
${SRC_COMMON4}
)

ament_target_dependencies(common rclcpp apollo_msgs )
#target_link_libraries(
#  common
#  Eigen3::Eigen absl::base absl::synchronization absl::strings osqp::osqp nlohmann_json::nlohmann_json yaml-cpp)
target_link_libraries(
  common
  absl::base absl::synchronization absl::strings Eigen3::Eigen yaml-cpp nlohmann_json::nlohmann_json 
  )
target_include_directories(common
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
)
