cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(can_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(apollo_msgs REQUIRED)

find_package(Torch REQUIRED)
find_package(OpenMP REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

if(OPENMP_FOUND)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

file(GLOB_RECURSE SRC_AUDIO "../../src/modules/audio/*.cpp")
file(GLOB_RECURSE SRC_COMMON "../../src/modules/common/*.cpp")

add_executable(
audio_component
../../src/main/audio.cpp
../../src/component/audio.cpp
${SRC_AUDIO}
)

target_include_directories(audio_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include)

ament_target_dependencies(
  audio_component
  rclcpp
  apollo_msgs)
target_link_libraries(audio_component common Eigen3::Eigen "${TORCH_LIBRARIES}" fftw3 yaml-cpp absl::base absl::synchronization absl::strings)
#target_link_libraries(audio_component common "${TORCH_LIBRARIES}" fftw3  )
target_compile_definitions(audio_component PRIVATE USE_GPU )
install(TARGETS
  audio_component
  DESTINATION lib/${PROJECT_NAME})
