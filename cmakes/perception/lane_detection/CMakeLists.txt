cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(CUDA REQUIRED)
find_package(Torch REQUIRED)
find_package(tf2_ros REQUIRED)
list(REMOVE_ITEM TORCH_LIBRARIES kineto_LIBRARY-NOTFOUND)

add_executable(
lane_detection_component
../../../src/main/lane_detection.cpp
../../../src/component/lane_detection.cpp
../../../src/modules/perception/camera/app/cipv_camera.cpp
../../../src/modules/perception/common/perception_gflags.cpp
#../../../src/modules/perception/camera/tools/offline/visualizer.cpp
../../../src/modules/perception/camera/app/lane_camera_perception.cpp
../../../src/modules/perception/common/sensor_manager/sensor_manager.cpp
../../../src/modules/perception/onboard/transform_wrapper/transform_wrapper.cpp
../../../src/modules/transform/buffer.cpp
../../../src/modules/perception/camera/common/data_provider.cpp
../../../src/modules/perception/onboard/common_flags/common_flags.cpp
../../../src/modules/perception/base/blob.cpp
../../../src/modules/perception/camera/tools/offline/transform_server.cpp
../../../src/modules/perception/camera/common/util.cpp
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
../../../src/modules/perception/camera/lib/lane/detector/denseline/denseline_lane_detector.cpp
../../../src/modules/perception/camera/lib/lane/postprocessor/denseline/denseline_lane_postprocessor.cpp
../../../src/modules/perception/inference/inference_factory.cpp
../../../src/modules/perception/inference/inference.cpp
../../../src/modules/perception/inference/libtorch/torch_det.cpp
../../../src/modules/perception/inference/libtorch/torch_net.cpp
../../../src/modules/perception/inference/onnx/libtorch_obstacle_detector.cpp
../../../src/modules/perception/inference/onnx/onnx_obstacle_detector.cpp
../../../src/modules/perception/inference/utils/binary_data.cpp
#../../../src/modules/perception/camera/tools/lane_detection/lane_common.cpp

)

target_compile_definitions(lane_detection_component PRIVATE USE_GPU)

target_include_directories(lane_detection_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include)

ament_target_dependencies(
  lane_detection_component
  rclcpp
  apollo_msgs tf2_ros)
list(REMOVE_ITEM CUDA_npp_LIBRARY CUDA_nppicom_LIBRARY-NOTFOUND)
target_link_libraries(lane_detection_component perception_inference common cutil perception_base libnvinfer.so nvonnxparser ${CUDA_LIBRARIES} ${CUDA_npp_LIBRARY}  ${CUDA_CUBLAS_LIBRARIES} ${TORCH_LIBRARIES} )

install(TARGETS
  lane_detection_component
  DESTINATION lib/${PROJECT_NAME})
