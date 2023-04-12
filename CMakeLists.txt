cmake_minimum_required(VERSION 3.20)

project(game)

add_compile_options(-g -Wall -Wextra -std=c++17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(engine)
add_subdirectory(content)

add_executable(game main.cpp)
target_link_libraries(game PUBLIC engine actions actors events)
