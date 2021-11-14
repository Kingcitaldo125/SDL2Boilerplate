cmake_minimum_required(VERSION 3.16)

project(SDL_TEST_PROJECT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

find_library(SDL2 NAME SDL2 REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main ${SDL2})

