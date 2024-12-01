cmake_minimum_required(VERSION 3.10)

# Set the project name
project(TrackingDataReader)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable and source files
add_executable(TrackingDataReader main.cpp Reader.cpp)

# Include the current directory to locate header files
target_include_directories(TrackingDataReader PUBLIC "${CMAKE_SOURCE_DIR}")
