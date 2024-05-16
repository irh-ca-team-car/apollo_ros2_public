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
find_package(apollo_msgs REQUIRED)
find_package(CUDA REQUIRED)
find_package(Torch REQUIRED)
find_package(Python3 COMPONENTS Interpreter Development)
find_package(OpenMP REQUIRED)

add_executable(
recognition_component
../../../src/main/recognition.cpp
../../../src/component/recognition.cpp
../../../src/modules/perception/lidar/app/lidar_obstacle_tracking.cpp
../../../src/modules/perception/lib/config_manager/config_manager.cpp
../../../src/modules/perception/lib/registerer/registerer.cpp
../../../src/modules/perception/common/io/io_util.cpp
../../../src/modules/perception/common/perception_gflags.cpp
../../../src/modules/perception/lidar/lib/classifier/fused_classifier/ccrf_type_fusion.cpp
../../../src/modules/perception/lidar/lib/classifier/fused_classifier/fused_classifier.cpp
../../../src/modules/perception/lidar/lib/classifier/fused_classifier/util.cpp
../../../src/modules/perception/lidar/common/object_sequence.cpp
../../../src/modules/perception/lidar/lib/tracker/association/distance_collection.cpp
../../../src/modules/perception/lidar/lib/tracker/semantic_map/evaluator_manager.cpp
../../../src/modules/perception/lidar/lib/tracker/association/gnn_bipartite_graph_matcher.cpp
../../../src/modules/perception/lidar/lib/tracker/measurement/measurement_collection.cpp
../../../src/modules/perception/lidar/lib/tracker/multi_lidar_fusion/mlf_engine.cpp
../../../src/modules/perception/lidar/lib/tracker/multi_lidar_fusion/mlf_motion_filter.cpp
../../../src/modules/perception/lidar/lib/tracker/multi_lidar_fusion/mlf_motion_measurement.cpp
../../../src/modules/perception/lidar/lib/tracker/multi_lidar_fusion/mlf_motion_refiner.cpp
../../../src/modules/perception/lidar/lib/tracker/multi_lidar_fusion/mlf_shape_filter.cpp
../../../src/modules/perception/lidar/lib/tracker/common/mlf_track_data.cpp
../../../src/modules/perception/lidar/lib/tracker/multi_lidar_fusion/mlf_tracker.cpp
../../../src/modules/perception/lidar/lib/tracker/multi_lidar_fusion/mlf_track_object_distance.cpp
../../../src/modules/perception/lidar/lib/tracker/multi_lidar_fusion/mlf_track_object_matcher.cpp
../../../src/modules/perception/lidar/lib/tracker/association/multi_hm_bipartite_graph_matcher.cpp
../../../src/modules/perception/lidar/lib/tracker/common/track_data.cpp
../../../src/modules/perception/lidar/lib/tracker/common/tracked_object.cpp
../../../src/modules/perception/lidar/lib/tracker/common/track_pool_types.cpp
../../../src/modules/perception/lidar/common/lidar_object_util.cpp
../../../src/modules/perception/common/graph/connected_component_analysis.cpp
../../../src/modules/prediction/common/feature_output.cpp
../../../src/modules/prediction/common/junction_analyzer.cpp
../../../src/modules/prediction/common/prediction_gflags.cpp
../../../src/modules/prediction/common/prediction_map.cpp
../../../src/modules/prediction/common/prediction_system_gflags.cpp
../../../src/modules/prediction/common/prediction_util.cpp
../../../src/modules/prediction/common/road_graph.cpp
../../../src/modules/prediction/common/semantic_map.cpp
../../../src/modules/prediction/container/adc_trajectory/adc_trajectory_container.cpp
../../../src/modules/prediction/container/container_manager.cpp
../../../src/modules/prediction/container/obstacles/obstacle.cpp
../../../src/modules/prediction/container/obstacles/obstacle_cluster.cpp
../../../src/modules/prediction/container/obstacles/obstacles_container.cpp
../../../src/modules/prediction/container/pose/pose_container.cpp
../../../src/modules/prediction/container/storytelling/storytelling.cpp
../../../src/modules/prediction/evaluator/vehicle/semantic_lstm_evaluator.cpp
../../../src/modules/prediction/network/net_layer.cpp
../../../src/modules/prediction/network/net_model.cpp
../../../src/modules/prediction/network/net_util.cpp
../../../src/modules/prediction/network/rnn_model/rnn_model.cpp
../../../src/modules/prediction/submodules/submodule_output.cpp 
../../../src/modules/perception/lidar/common/cloud_mask.cpp 
../../..//src/modules/perception/common/image_processing/hough_transfer.cpp
)

target_include_directories(recognition_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include)
target_compile_definitions(recognition_component PRIVATE USE_GPU)
ament_target_dependencies(
  recognition_component
  rclcpp
  apollo_msgs)
list(REMOVE_ITEM CUDA_npp_LIBRARY CUDA_nppicom_LIBRARY-NOTFOUND)
target_link_libraries(recognition_component perception_base common perception_base perception_internal hdmap ${CUDA_LIBRARIES} ${CUDA_CUBLAS_LIBRARIES} ${CUDA_npp_LIBRARY} ${TORCH_LIBRARIES} Python3::Python OpenMP::OpenMP_CXX)

install(TARGETS
  recognition_component
  DESTINATION lib/${PROJECT_NAME})
