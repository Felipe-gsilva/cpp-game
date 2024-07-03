cmake_minimum_required(VERSION 3.5)
project(cpp-game)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
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
include_directories(${SDL2_INCLUDE_DIRS})

# FetchContent module to add SDL_image from its repository
include(FetchContent)

FetchContent_Declare(SDL2_image
                     GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
                     GIT_TAG release-2.8.2
)

FetchContent_MakeAvailable(SDL2_image)

# Include SDL2_image directories
include_directories(${sdl2_image_SOURCE_DIR})
# Print out the paths to help with debugging
message(STATUS "OpenGL include dirs: ${OPENGL_INCLUDE_DIRS}")
message(STATUS "OpenGL libraries: ${OPENGL_LIBRARIES}")
message(STATUS "OpenAL include dirs: ${OPENAL_INCLUDE_DIRS}")
message(STATUS "OpenAL libraries: ${OPENAL_LIBRARIES}")
message(STATUS "SDL2 include dirs: ${SDL2_INCLUDE_DIRS}")
message(STATUS "SDL2 libraries: ${SDL2_LIBRARIES}")
message(STATUS "SDL2_image libraries: ${SDL2_IMAGE_LIBRARIES}")

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${OPENAL_LIBRARIES} ${SDL2_LIBRARIES} SDL2_image::SDL2_image)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

