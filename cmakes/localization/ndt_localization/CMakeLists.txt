cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(apollo_msgs REQUIRED)

find_package(PCL REQUIRED)
find_package(FastRTPS REQUIRED)
find_package(tf2_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(
ndt_localization_component
../../../src/component/ndt_localization.cpp
../../../src/main/ndt_localization.cpp
../../../src/modules/transform/transform_broadcaster.cpp
../../../src/modules/localization/common/localization_gflags.cpp
../../../src/modules/localization/ndt/ndt_localization.cpp
../../../src/modules/localization/ndt/ndt_locator/lidar_locator_ndt.cpp
../../../src/modules/localization/ndt/localization_pose_buffer.cpp
../../../src/modules/localization/msf/common/util/compression.cpp
../../../src/modules/localization/msf/common/util/file_utility.cpp
../../../src/modules/localization/msf/local_pyramid_map/base_map/base_map.cpp
../../../src/modules/localization/msf/local_pyramid_map/base_map/base_map_config.cpp
../../../src/modules/localization/msf/local_pyramid_map/base_map/base_map_matrix.cpp
../../../src/modules/localization/msf/local_pyramid_map/base_map/base_map_node.cpp
../../../src/modules/localization/msf/local_pyramid_map/base_map/base_map_node_config.cpp
../../../src/modules/localization/msf/local_pyramid_map/base_map/base_map_node_index.cpp
../../../src/modules/localization/msf/local_pyramid_map/base_map/base_map_pool.cpp
../../../src/modules/localization/msf/local_pyramid_map/ndt_map/ndt_map.cpp
../../../src/modules/localization/msf/local_pyramid_map/ndt_map/ndt_map_config.cpp
../../../src/modules/localization/msf/local_pyramid_map/ndt_map/ndt_map_matrix.cpp
../../../src/modules/localization/msf/local_pyramid_map/ndt_map/ndt_map_matrix_handler.cpp
../../../src/modules/localization/msf/local_pyramid_map/ndt_map/ndt_map_node.cpp
../../../src/modules/localization/msf/local_pyramid_map/ndt_map/ndt_map_node_config.cpp
../../../src/modules/localization/msf/local_pyramid_map/ndt_map/ndt_map_pool.cpp
../../../src/modules/transform/buffer.cpp
)

target_include_directories(ndt_localization_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include)

ament_target_dependencies(
  ndt_localization_component
  rclcpp
  apollo_msgs  tf2_msgs tf2_ros geometry_msgs)
#target_link_libraries(ndt_localization_component common Eigen3::Eigen "${TORCH_LIBRARIES}" fftw3 yaml-cpp absl::base absl::synchronization absl::strings ${OpenCV_LIBRARIES} ${PCL_LIBRARIES} ${FastRTPS_LIBRARIES})
target_link_libraries(ndt_localization_component common  ${OpenCV_LIBRARIES} ${PCL_LIBRARIES} ${FastRTPS_LIBRARIES})
target_compile_definitions(ndt_localization_component PRIVATE USE_GPU)
install(TARGETS
  ndt_localization_component
  DESTINATION lib/${PROJECT_NAME})
