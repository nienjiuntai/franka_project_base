cmake_minimum_required(VERSION 3.4)

project(pads_prject_name
    VERSION 0.0.1
    LANGUAGES CXX
)

list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_LIST_DIR}/../cmake)

## set default c standar
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

## Use Thread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

## Dependencies
find_package(Franka REQUIRED PATHS ${CMAKE_SOURCE_DIR}/cmake)
find_package(Eigen3 REQUIRED)

## Library
add_library(examples_common STATIC
  examples_common.cpp
)

target_link_libraries(examples_common PUBLIC Franka::Franka Eigen3::Eigen3)

## Main Program
set(EXAMPLES
  communication_test
)

foreach(example ${EXAMPLES})
  add_executable(${example} ${example}.cpp)
  target_link_libraries(${example} Franka::Franka examples_common Eigen3::Eigen3)
endforeach()

include(GNUInstallDirs)
install(TARGETS ${EXAMPLES}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)