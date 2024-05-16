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
#set(ad_rss_DIR ../../ad-rss-lib/install/ad_rss/lib/cmake/ad_rss/)
#set(ad_physics_DIR ../../ad-rss-lib/install/ad_physics/lib/cmake/ad_physics/)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(can_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(ad_rss REQUIRED)
find_package(Torch REQUIRED)
find_package(OpenMP REQUIRED)
find_package(osqp REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(rosbag2_cpp REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
set(Boost_USE_STATIC_LIBS   ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_ADDITIONAL_VERSIONS "1.44" "1.44.0")
find_package(Boost COMPONENTS thread date_time program_options filesystem system REQUIRED)
find_package(Threads REQUIRED)

if (ADOLC_INCLUDES AND ADOLC_LIBRARIES)
  set(ADOLC_FIND_QUIETLY TRUE)
endif (ADOLC_INCLUDES AND ADOLC_LIBRARIES)

find_path(ADOLC_INCLUDES
  NAMES
  adolc/adouble.h
  PATHS
  $ENV{ADOLCDIR}
  ${INCLUDE_INSTALL_DIR}
)

find_library(ADOLC_LIBRARIES adolc PATHS $ENV{ADOLCDIR} ${LIB_INSTALL_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(ADOLC DEFAULT_MSG
                                  ADOLC_INCLUDES ADOLC_LIBRARIES)

mark_as_advanced(ADOLC_INCLUDES ADOLC_LIBRARIES)

set(IPOPT_LIBRARY_DIRS /usr/local/lib)
set(IPOPT_INCLUDE_DIRS /usr/local/include/coin)

if(OPENMP_FOUND)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

file(GLOB_RECURSE SRC_PLANNING "../../src/modules/planning/*.cpp")

add_executable(
planning_component
../../src/main/planning.cpp
../../src/common/utils.cpp
../../src/modules/common/math/math_utils.cpp
../../src/modules/common/math/vec2d.cpp
../../src/modules/perception/proto/perception_obstacle.cpp
${SRC_PLANNING}
../../src/component/planning.cpp
)

target_include_directories(planning_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>)
ament_target_dependencies(
  planning_component
  rclcpp
  std_msgs
  can_msgs 
  OpenCV
  sensor_msgs 
  apollo_msgs
  rosbag2_cpp
  ad_rss)
target_link_libraries(planning_component ${Boost_LIBRARIES} ipopt /usr/local/lib64/libadolc.so ad_rss common osqp::osqp hdmap Eigen3::Eigen "${TORCH_LIBRARIES}" fftw3 yaml-cpp absl::base absl::synchronization absl::strings)
target_compile_definitions(planning_component PRIVATE HAVE_STDDEF_H HAVE_CSTDDEF)
install(TARGETS
  planning_component
  DESTINATION lib/${PROJECT_NAME})
