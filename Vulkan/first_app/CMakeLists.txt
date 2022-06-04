cmake_minimum_required(VERSION 3.22)
project(first_app)

set(CMAKE_CXX_STANDARD 23)
find_package(glfw3 REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

add_executable(first_app main.cpp ve_window.cpp ve_window.hpp first_app.hpp first_app.cpp ve_pipeline.hpp ve_pipeline.cpp)

target_link_libraries(first_app ${OPENGL_INCLUDE_DIR} glfw)