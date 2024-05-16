cmake_minimum_required(VERSION 3.5)
project(apollo)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()
message("CUDA STRING:[${CUDA_NVCC_FLAGS}]")
set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  #add_compile_options(-Wall -Wextra -Wpedantic)
  #add_compile_options(-Wall -Wextra -Wfatal-errors)
  add_compile_options(-Wall -Wextra)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

set(BUILD_TESTING=OFF)



##dependancies
add_subdirectory(abseil-cpp)
##base
add_subdirectory(cmakes/common)
add_subdirectory(cmakes/hdmap)
##drivers
add_subdirectory(cmakes/drivers)
##demo
add_subdirectory(cmakes/demos)
##modules
#add_subdirectory(cmakes/audio)
add_subdirectory(cmakes/canbus)
add_subdirectory(cmakes/control)
add_subdirectory(cmakes/drivekit)
#add_subdirectory(cmakes/guardian)
add_subdirectory(cmakes/localization)
add_subdirectory(cmakes/map)
#add_subdirectory(cmakes/perception)
add_subdirectory(cmakes/planning)
#add_subdirectory(cmakes/prediction)
#add_subdirectory(cmakes/routing)
#add_subdirectory(cmakes/taskmanager)
#add_subdirectory(cmakes/third_party_perception)
add_subdirectory(cmakes/transform)
#add_subdirectory(cmakes/v2x)
#add_subdirectory(cmakes/storytelling)

install(DIRECTORY
  conf
  DESTINATION share/${PROJECT_NAME}/
)
install(DIRECTORY
  data
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
