cmake_minimum_required(VERSION 3.25)
project(Basic_Http_Server)

set(CMAKE_CXX_STANDARD 26)

find_library(wiringPi_LIB wiringPi REQUIRED)
include_directories(/usr/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

message(STATUS "wiringPi_LIB: ${wiringPi_LIB}")

add_executable(Basic_Http_Server src/main.cpp src/UDPServer.cpp)

target_link_libraries(Basic_Http_Server ${wiringPi_LIB})

