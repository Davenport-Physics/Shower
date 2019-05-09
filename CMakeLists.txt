cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(Shower)

file(GLOB_RECURSE sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE headers ${PROJECT_SOURCE_DIR}/src/*.hh)

add_executable(shower ${sources} ${headers})
