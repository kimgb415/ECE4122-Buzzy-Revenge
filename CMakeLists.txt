cmake_minimum_required(VERSION 2.8)
project(LAB3)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML COMPONENTS graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
add_executable(LAB3 main.cpp loadFile.hpp loadFile.cpp Buzzy.cpp Buzzy.h)
target_link_libraries(LAB3 sfml-graphics sfml-audio)
