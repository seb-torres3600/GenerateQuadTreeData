cmake_minimum_required(VERSION 3.23)
project(GenerateQuadTreeData VERSION 1.0)

# Set C++ compiler
set(CMAKE_CXX_COMPILER g++)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add CMAKE_CXX_FLAGS_DEBUG with debugging symbols and no optimizations
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")

# Add include directories
include_directories(include /usr/local/include/)

# Add all source files in the src/ directory
file(GLOB SOURCES "src/*.cpp")

# Create executable from sources
add_executable(main ${SOURCES})

