cmake_minimum_required(VERSION 3.5)

project(pads_prject_name
    VERSION 0.0.1
    LANGUAGES CXX
)
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

## set default c standar
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

## Build options
option(STRICT "Treat warnings as errors" OFF)
if(STRICT)
  if(MSVC)
    add_compile_options(/WX)
  else()
    add_compile_options(-Werror)
  endif()
endif()

if(MSVC)
  add_compile_options(/W0)
else()
  add_compile_options(-Wall -Wextra)
endif()

## Use Thread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

## Dependencies
find_package(Eigen3 REQUIRED)

find_package(SWIG 3.0 COMPONENTS python)
if(SWIG_FOUND)
  message("SWIG found: ${SWIG_EXECUTABLE}")
endif()
INCLUDE_DIRECTORIES("include")
# ## Tools
file(GLOB_RECURSE SOURCES
  src/*.cpp
)
file(GLOB_RECURSE HEADERS
  include/*.h
  include/*.hpp
  src/*.h
  src/*.hpp
)

option(BUILD_EXAMPLES "Build example code" ON)
if(BUILD_EXAMPLES)
  add_subdirectory(src)
endif()