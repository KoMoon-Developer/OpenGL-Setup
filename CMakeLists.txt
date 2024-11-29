# CMake Config 
cmake_minimum_required(VERSION 3.11)
include_directories(${CMAKE_SOURCE_DIR}/include)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Project Name
project(Template)

# Executable Sources 
set(GLAD_SRC ${CMAKE_SOURCE_DIR}/src/glad.c)
set(SRC ${GLAD_SRC})

# Find Dependencies
find_package(OpenGL REQUIRED)

# Create Executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(OpenGLTemp Main.cpp ${SRC})
target_link_libraries(OpenGLTemp OpenGL::GL ${CMAKE_SOURCE_DIR}/lib/glfw3.lib)

