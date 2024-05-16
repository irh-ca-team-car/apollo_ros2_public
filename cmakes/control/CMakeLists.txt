cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(can_msgs REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(osqp REQUIRED)

set(CONTROL_GENERAL_FILE 
../../src/modules/control/common/control_gflags.cpp
../../src/modules/control/common/interpolation_1d.cpp
../../src/modules/control/common/interpolation_2d.cpp
../../src/modules/control/common/leadlag_controller.cpp
../../src/modules/control/common/mrac_controller.cpp
../../src/modules/control/common/pid_BC_controller.cpp
../../src/modules/control/common/pid_controller.cpp
../../src/modules/control/common/pid_IC_controller.cpp
../../src/modules/control/common/trajectory_analyzer.cpp
../../src/modules/control/controller/controller_agent.cpp
../../src/modules/control/controller/lat_controller.cpp
../../src/modules/control/controller/lon_controller.cpp
../../src/modules/control/controller/mpc_controller.cpp
../../src/modules/control/proto/control_conf.cpp
)

add_executable(
control_component
../../src/main/control.cpp
../../src/component/control.cpp
${CONTROL_GENERAL_FILE}
)
add_executable(
control_PreprocessorSubmodule
../../src/main/control_PreprocessorSubmodule.cpp
../../src/modules/control/submodules/preprocessor_submodule.cpp
${CONTROL_GENERAL_FILE}
)
add_executable(
control_MPCSubmodule
../../src/main/control_MPCSubmodule.cpp
../../src/modules/control/submodules/mpc_controller_submodule.cpp
${CONTROL_GENERAL_FILE}
)
add_executable(
control_LATLONSubmodule
../../src/main/control_LATLONSubmodule.cpp
../../src/modules/control/submodules/lat_lon_controller_submodule.cpp
${CONTROL_GENERAL_FILE}
)
add_executable(
control_PostprocessorSubmodule
../../src/main/control_PostprocessorSubmodule.cpp
../../src/modules/control/submodules/postprocessor_submodule.cpp
${CONTROL_GENERAL_FILE}
)
ament_target_dependencies(control_component apollo_msgs rclcpp  can_msgs  )
target_link_libraries(
  control_component
  common
  osqp::osqp)
target_link_libraries(
  control_PreprocessorSubmodule
  common
  osqp::osqp)
target_link_libraries(
  control_MPCSubmodule
  common
  osqp::osqp)
target_link_libraries(
  control_LATLONSubmodule
  common
  osqp::osqp)
target_link_libraries(
  control_PostprocessorSubmodule
  common
  osqp::osqp)
target_include_directories(control_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
)
install(TARGETS
  control_component
  DESTINATION lib/${PROJECT_NAME})
target_include_directories(control_MPCSubmodule
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
)
install(TARGETS
  control_MPCSubmodule
  DESTINATION lib/${PROJECT_NAME})
target_include_directories(control_PreprocessorSubmodule
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
)
install(TARGETS
  control_PreprocessorSubmodule
  DESTINATION lib/${PROJECT_NAME})
target_include_directories(control_LATLONSubmodule
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
)
install(TARGETS
  control_LATLONSubmodule
  DESTINATION lib/${PROJECT_NAME})
target_include_directories(control_PostprocessorSubmodule
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
)
install(TARGETS
  control_PostprocessorSubmodule
  DESTINATION lib/${PROJECT_NAME})