cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(CUDA REQUIRED)

add_executable(
lidar_output_component
../../../src/main/lidar_output.cpp
../../../src/component/lidar_output.cpp
../../../src/modules/perception/onboard/msg_serializer/msg_serializer.cpp
../../../src/modules/perception/onboard/common_flags/common_flags.cpp
)

target_include_directories(lidar_output_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include)
target_compile_definitions(lidar_output_component PRIVATE USE_GPU)
ament_target_dependencies(
  lidar_output_component
  rclcpp
  apollo_msgs)
target_link_libraries(lidar_output_component common perception_internal perception_base ${CUDA_LIBRARIES}  ${CUDA_CUBLAS_LIBRARIES})

install(TARGETS
  lidar_output_component
  DESTINATION lib/${PROJECT_NAME}
  )
