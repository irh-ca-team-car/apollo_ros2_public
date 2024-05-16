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

add_executable(
motion_service
../../../src/main/motion_service.cpp
../../../src/component/motion_service.cpp
#../../../src/modules/perception/camera/lib/motion_service/motion_service.cpp
../../../src/modules/perception/camera/lib/motion/plane_motion.cpp

)

target_include_directories(motion_service
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include)
target_compile_definitions(motion_service PRIVATE USE_GPU)
ament_target_dependencies(
  motion_service
  rclcpp
  apollo_msgs)
list(REMOVE_ITEM CUDA_npp_LIBRARY CUDA_nppicom_LIBRARY-NOTFOUND)
list(REMOVE_ITEM TORCH_LIBRARIES kineto_LIBRARY-NOTFOUND)

target_link_libraries(motion_service common perception_internal perception_base ${TORCH_LIBRARIES} ${CUDA_LIBRARIES} ${CUDA_npp_LIBRARY}  ${CUDA_CUBLAS_LIBRARIES})

install(TARGETS
  motion_service
  DESTINATION lib/${PROJECT_NAME})
