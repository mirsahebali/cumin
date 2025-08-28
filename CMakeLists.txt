cmake_minimum_required(VERSION 3.15)
project(cumin VERSION 1.70)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib REQUIRED)
include_directories(include)
include_directories(deps)

add_executable(${PROJECT_NAME}
                  objects.cpp
                  draw.cpp
                  utils.cpp
                  render.cpp
                  main.cpp)
target_link_libraries(${PROJECT_NAME} raylib)
