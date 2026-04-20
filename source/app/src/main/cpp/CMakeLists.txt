cmake_minimum_required(VERSION 4.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} 
    -std=c++20"

)
add_compile_options(-std=c++20)
add_definitions(-std=c++20)

project(blenderAndroid)

add_library(blenderAndroid SHARED
    jni/blender_bridge.cpp
    creator/creator.cc
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_NINJA_RESTAT ON)

add_compile_options(-std=c++20)

target_include_directories(blenderAndroid PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp # This allows the ../ jumps to work
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp/jni
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp/creator
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp/creatorinclude
)

# You MUST include the Blender source directories here
target_include_directories(blenderAndroid PRIVATE 
    jni/
    creator/
    creatorinclude/
)

