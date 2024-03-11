cmake_minimum_required(VERSION 3.5)
project(tluv)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Include directories
include_directories(inc)
include_directories(inc/glfw)

# GLFW
add_subdirectory(inc/glfw)
set(GLFW_LIBRARIES glfw)

# Set OpenGL vendor-neutral dispatch (GLVND) as preferred
set(OpenGL_GL_PREFERENCE GLVND)

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# OpenAL
find_package(OpenAL REQUIRED)
include_directories(${OPENAL_INCLUDE_DIRS})

# FreeGlut
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${OPENAL_LIBRARIES} ${GLFW_LIBRARIES})

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

