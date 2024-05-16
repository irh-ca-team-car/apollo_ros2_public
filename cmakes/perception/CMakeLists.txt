cmake_minimum_required(VERSION 3.5)
project(apollo)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

set(CMAKE_PREFIX_PATH /opt/libtorch;${CMAKE_PREFIX_PATH})

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  #add_compile_options(-Wall -Wextra -Wpedantic)
  add_compile_options(-Wall -Wextra)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(OpenCV REQUIRED)
find_package(CUDA REQUIRED)
find_package(apollo_msgs REQUIRED)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

file(GLOB_RECURSE PERCEPTION_BASE "../../src/modules/perception/base/*.cpp")

add_library(
perception_base
STATIC 
${PERCEPTION_BASE}
../../src/modules/perception/factories.cpp
)
target_compile_definitions(perception_base PRIVATE USE_GPU)

ament_target_dependencies(perception_base rclcpp apollo_msgs )
#target_link_libraries(
#  perception_base
#  Eigen3::Eigen absl::base absl::synchronization absl::strings nlohmann_json::nlohmann_json yaml-cpp ${OpenCV_LIBRARIES} ${CUDA_LIBRARIES}  ${CUDA_CUBLAS_LIBRARIES})
target_link_libraries(
  perception_base
  Eigen3::Eigen absl::base ${OpenCV_LIBRARIES} 
  )
target_include_directories(perception_base
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include
)

file(GLOB_RECURSE INTERN_MESS "../../src/modules/perception/onboard/internal_messages/*.cpp")

add_library(
perception_internal
STATIC 
../../src/modules/perception/base/base64.cpp
${INTERN_MESS}
)

target_compile_definitions(perception_internal PRIVATE USE_GPU)

ament_target_dependencies(perception_internal rclcpp apollo_msgs )
#target_link_libraries(
#  perception_internal
#  Eigen3::Eigen absl::base absl::synchronization absl::strings nlohmann_json::nlohmann_json yaml-cpp perception_base)
target_link_libraries(
  perception_internal
  perception_base)
target_include_directories(perception_internal
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include
)

add_subdirectory(inference)
#add_subdirectory(cutil)
#add_subdirectory(detection)
#add_subdirectory(fusion)
#add_subdirectory(fusion_camera_detection)
#add_subdirectory(lane_detection)
#add_subdirectory(lidar_output)
add_subdirectory(motion_service)
add_subdirectory(radar_detection)
#add_subdirectory(recognition)
#add_subdirectory(segmentation)
#add_subdirectory(trafficlights_perception)
