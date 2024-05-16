cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(CUDA REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(Torch REQUIRED)

set(CUDA_INCLUDE_DIRS ../../../include)

# cuda_add_library(fusion_camera_detection_component_cuda_smoke
# ../../../src/modules/perception/camera/lib/obstacle/detector/smoke/region_output.cu
# )

cuda_add_library(fusion_camera_detection_component_cuda_yolo
../../../src/modules/perception/camera/lib/obstacle/detector/yolo/region_output.cu
)
target_compile_definitions(fusion_camera_detection_component_cuda_yolo PRIVATE NVVC)
target_compile_definitions(fusion_camera_detection_component_cuda_yolo PRIVATE USE_CUDA)

# cuda_add_library(fusion_camera_detection_component_cuda_yolov4
# ../../../src/modules/perception/camera/lib/obstacle/detector/yolov4/region_output.cu
# )

add_executable(
fusion_camera_detection_component
../../../src/main/fusion_camera_detection.cpp
../../../src/component/fusion_camera_detection.cpp
../../../src/modules/perception/camera/app/cipv_camera.cpp
../../../src/modules/perception/camera/common/util.cpp
../../../src/modules/perception/common/perception_gflags.cpp
#../../../src/modules/perception/camera/tools/offline/visualizer.cpp
../../../src/modules/perception/camera/app/obstacle_camera_perception.cpp
../../../src/modules/perception/common/sensor_manager/sensor_manager.cpp
../../../src/modules/perception/onboard/transform_wrapper/transform_wrapper.cpp
../../../src/modules/transform/buffer.cpp
../../../src/modules/perception/camera/common/data_provider.cpp
../../../src/modules/perception/onboard/common_flags/common_flags.cpp
../../../src/modules/perception/onboard/component/camera_perception_viz_message.cpp
../../../src/modules/perception/camera/tools/offline/transform_server.cpp
../../../src/modules/perception/camera/common/object_template_manager.cpp
../../../src/modules/perception/camera/app/debug_info.cpp
../../../src/modules/perception/lib/registerer/registerer.cpp
../../../src/modules/perception/common/io/io_util.cpp
../../../src/modules/perception/camera/common/undistortion_handler.cpp
../../../src/modules/perception/camera/lib/calibration_service/online_calibration_service/online_calibration_service.cpp
../../../src/modules/perception/camera/lib/calibrator/common/histogram_estimator.cpp
../../../src/modules/perception/camera/lib/calibrator/laneline/lane_based_calibrator.cpp
../../../src/modules/perception/camera/lib/calibrator/laneline/laneline_calibrator.cpp
../../../src/modules/perception/camera/lib/lane/common/common_functions.cpp
../../../src/modules/perception/camera/lib/lane/detector/darkSCNN/darkSCNN_lane_detector.cpp
../../../src/modules/perception/camera/lib/lane/postprocessor/darkSCNN/darkSCNN_lane_postprocessor.cpp
../../../src/modules/perception/camera/lib/feature_extractor/tfe/external_feature_extractor.cpp
../../../src/modules/perception/camera/lib/feature_extractor/tfe/project_feature.cpp
../../../src/modules/perception/camera/lib/feature_extractor/tfe/tracking_feat_extractor.cpp
../../../src/modules/perception/camera/lib/obstacle/tracker/common/half_circle_angle.cpp
../../../src/modules/perception/camera/lib/obstacle/tracker/common/kalman_filter.cpp
../../../src/modules/perception/camera/lib/obstacle/postprocessor/location_refiner/location_refiner_obstacle_postprocessor.cpp
../../../src/modules/perception/camera/lib/obstacle/transformer/multicue/multicue_obstacle_transformer.cpp
../../../src/modules/perception/camera/lib/obstacle/transformer/multicue/obj_mapper.cpp
../../../src/modules/perception/camera/lib/obstacle/postprocessor/location_refiner/obj_postprocessor.cpp
../../../src/modules/perception/camera/lib/obstacle/tracker/omt/obstacle_reference.cpp
../../../src/modules/perception/camera/lib/obstacle/tracker/omt/omt_obstacle_tracker.cpp
../../../src/modules/perception/camera/lib/obstacle/tracker/common/similar.cpp
../../../src/modules/perception/camera/lib/obstacle/tracker/omt/target.cpp
../../../src/modules/perception/camera/lib/obstacle/tracker/omt/track_object.cpp
../../../src/modules/perception/camera/common/camera_ground_plane.cpp
../../..//src/modules/perception/camera/lib/obstacle/transformer/singlestage/singlestage_obstacle_transformer.cpp
../../../src/modules/perception/camera/lib/obstacle/detector/yolo/region_output.cpp
../../../src/modules/perception/camera/lib/obstacle/detector/yolo/object_maintainer.cpp
../../../src/modules/perception/camera/lib/obstacle/detector/yolo/yolo_obstacle_detector.cpp
../../../src/modules/perception/camera/app/obstacle_detection_camera.cpp
)

target_compile_definitions(fusion_camera_detection_component PRIVATE USE_GPU)

target_include_directories(fusion_camera_detection_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include
    /opt/ros/foxy/include/
    /opt/ros/dashing/include/
    )

  target_include_directories(fusion_camera_detection_component_cuda_yolo
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include
    /opt/ros/foxy/include/
    /opt/ros/dashing/include/
    )

ament_target_dependencies(
  fusion_camera_detection_component
  rclcpp
  apollo_msgs tf2_ros)
# target_link_libraries(fusion_camera_detection_component_cuda_smoke absl::base absl::synchronization absl::strings Eigen3::Eigen)
target_link_libraries(fusion_camera_detection_component_cuda_yolo absl::base absl::synchronization absl::strings Eigen3::Eigen)
# target_link_libraries(fusion_camera_detection_component_cuda_yolov4 absl::base absl::synchronization absl::strings Eigen3::Eigen)
list(REMOVE_ITEM CUDA_npp_LIBRARY CUDA_nppicom_LIBRARY-NOTFOUND)
list(REMOVE_ITEM TORCH_LIBRARIES kineto_LIBRARY-NOTFOUND)
target_link_libraries(fusion_camera_detection_component perception_base cutil common perception_internal  ${TORCH_LIBRARIES} ${CUDA_LIBRARIES} ${CUDA_npp_LIBRARY}  ${CUDA_CUBLAS_LIBRARIES}  ${TORCH_LIBRARIES} perception_inference perception_inference_cuda
# fusion_camera_detection_component_cuda_smoke
 fusion_camera_detection_component_cuda_yolo
# fusion_camera_detection_component_cuda_yolov4
)

install(TARGETS
  fusion_camera_detection_component
  DESTINATION lib/${PROJECT_NAME})
