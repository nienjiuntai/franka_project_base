cmake_minimum_required(VERSION 3.5)

project(pads_prject_name
    VERSION 0.0.1
    LANGUAGES CXX
)

list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_LIST_DIR}/../cmake)
cmake_policy(SET CMP0078 NEW)
cmake_policy(SET CMP0086 NEW)
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

## SWIG support
find_package(SWIG 4.0 COMPONENTS python3 REQUIRED)
include(UseSWIG)
FIND_PACKAGE(PythonLibs)
INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})
# INCLUDE_DIRECTORIES("include")

set(CMAKE_SWIG_FLAGS"")
set_property(SOURCE franka_util.i PROPERTY CPLUSPLUS ON)
set_property(SOURCE franka_util.i PROPERTY SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE)

## Library
add_library(examples_common SHARED
  examples_common.cpp
)
target_link_libraries(examples_common PUBLIC Franka::Franka Eigen3::Eigen3)
# SWIG_ADD_MODULE(franka_util python franka_util.i franka_util.cpp)
swig_add_library(franka_util TYPE SHARED LANGUAGE python SOURCES franka_util.i franka_util.cpp)
SWIG_LINK_LIBRARIES(franka_util ${PYTHON_LIBRARIES} examples_common)

