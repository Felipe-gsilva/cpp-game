cmake_minimum_required(VERSION 3.5)
project(cpp-game)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Include directories
include_directories(inc)

# Set OpenGL vendor-neutral dispatch (GLVND) as preferred
set(OpenGL_GL_PREFERENCE GLVND)

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# OpenAL
find_package(OpenAL REQUIRED)
include_directories(${OPENAL_INCLUDE_DIRS})

# SDL
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRES})

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${OPENAL_LIBRARIES} ${SDL2_LIBRARIES})

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

