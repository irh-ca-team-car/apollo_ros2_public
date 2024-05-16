cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread)
find_package(CUDA REQUIRED)

add_executable(
fusion_component
../../../src/main/fusion.cpp
../../../src/component/fusion.cpp
../../../src/modules/perception/onboard/common_flags/common_flags.cpp
../../../src/modules/perception/common/perception_gflags.cpp
../../../src/modules/perception/fusion/app/obstacle_multi_sensor_fusion.cpp
../../../src/modules/perception/onboard/msg_serializer/msg_serializer.cpp
../../../src/modules/perception/lib/registerer/registerer.cpp
../../../src/modules/perception/lib/config_manager/config_manager.cpp
../../../src/modules/perception/fusion/lib/data_fusion/existence_fusion/dst_existence_fusion/dst_existence_fusion.cpp
../../../src/modules/perception/fusion/lib/data_fusion/type_fusion/dst_type_fusion/dst_type_fusion.cpp
../../../src/modules/perception/fusion/lib/data_association/hm_data_association/hm_tracks_objects_match.cpp
../../../src/modules/perception/fusion/lib/data_fusion/motion_fusion/kalman_motion_fusion/kalman_motion_fusion.cpp
../../../src/modules/perception/fusion/lib/gatekeeper/pbf_gatekeeper/pbf_gatekeeper.cpp
../../../src/modules/perception/fusion/lib/data_fusion/shape_fusion/pbf_shape_fusion/pbf_shape_fusion.cpp
../../../src/modules/perception/fusion/lib/data_fusion/tracker/pbf_tracker/pbf_tracker.cpp
../../../src/modules/perception/fusion/lib/fusion_system/probabilistic_fusion/probabilistic_fusion.cpp
../../../src/modules/perception/fusion/lib/data_association/hm_data_association/probabilities.cpp
../../../src/modules/perception/fusion/lib/data_association/hm_data_association/track_object_distance.cpp
../../../src/modules/perception/fusion/lib/data_association/hm_data_association/track_object_similarity.cpp
../../../src/modules/perception/fusion/common/camera_util.cpp
../../../src/modules/perception/fusion/common/dst_evidence.cpp
../../../src/modules/perception/fusion/base/base_init_options.cpp
../../../src/modules/perception/fusion/base/sensor_data_manager.cpp
../../../src/modules/perception/fusion/base/sensor.cpp
../../../src/modules/perception/fusion/base/track_pool_types.cpp
../../../src/modules/perception/common/geometry/camera_homography.cpp
../../../src/modules/perception/fusion/base/sensor_object.cpp
../../../src/modules/perception/common/sensor_manager/sensor_manager.cpp
../../../src/modules/perception/fusion/base/track.cpp
../../../src/modules/perception/fusion/common/kalman_filter.cpp
../../../src/modules/perception/fusion/base/sensor_frame.cpp
../../../src/modules/perception/fusion/base/scene.cpp
../../../src/modules/perception/common/graph/connected_component_analysis.cpp
../../../src/modules/perception/common/io/io_util.cpp
)

target_include_directories(fusion_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include)
target_compile_definitions(fusion_component PRIVATE USE_GPU)
ament_target_dependencies(
  fusion_component
  rclcpp
  apollo_msgs)
list(REMOVE_ITEM TORCH_LIBRARIES kineto_LIBRARY-NOTFOUND)
list(REMOVE_ITEM CUDA_npp_LIBRARY nppicom_LIBRARY-NOTFOUND)

target_link_libraries(fusion_component common hdmap perception_base perception_internal  ${TORCH_LIBRARIES} ${CUDA_LIBRARIES} ${CUDA_npp_LIBRARY})
install(TARGETS
  fusion_component
  DESTINATION lib/${PROJECT_NAME})
