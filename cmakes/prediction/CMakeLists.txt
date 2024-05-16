cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(Torch REQUIRED)
find_package(OpenMP REQUIRED)
find_package(OpenCV REQUIRED)

if(OPENMP_FOUND)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

file(GLOB_RECURSE SRC_PRED1 "../../src/modules/prediction/*.cpp")

add_executable(
prediction_component
../../src/main/prediction.cpp
../../src/component/prediction.cpp
${SRC_PRED1}
)
add_executable(
prediction_component_evaluator
../../src/main/prediction_evaluator.cpp
${SRC_PRED1}
)
add_executable(
prediction_component_predictor
../../src/main/prediction_predictor.cpp
${SRC_PRED1}
)




ament_target_dependencies(prediction_component apollo_msgs rclcpp OpenCV )

target_include_directories(prediction_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
    /usr/include/python3.4
    /usr/include/python3.6
    /usr/include/python3.8)
target_link_libraries(
  prediction_component
  "${TORCH_LIBRARIES}"
  common hdmap pthread )

install(TARGETS
  prediction_component
  DESTINATION lib/${PROJECT_NAME})

ament_target_dependencies(prediction_component_predictor apollo_msgs rclcpp OpenCV )

target_include_directories(prediction_component_predictor
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
    /usr/include/python3.4
    /usr/include/python3.6
    /usr/include/python3.8)
target_link_libraries(
  prediction_component_predictor
  "${TORCH_LIBRARIES}"
  common hdmap pthread )

install(TARGETS
  prediction_component_predictor
  DESTINATION lib/${PROJECT_NAME})

  ament_target_dependencies(prediction_component_evaluator apollo_msgs rclcpp OpenCV )

target_include_directories(prediction_component_evaluator
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
    /usr/include/python3.4
    /usr/include/python3.6
    /usr/include/python3.8)
target_link_libraries(
  prediction_component_evaluator
  "${TORCH_LIBRARIES}"
  common hdmap pthread )

install(TARGETS
  prediction_component_evaluator
  DESTINATION lib/${PROJECT_NAME})