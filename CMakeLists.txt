cmake_minimum_required(VERSION 3.10)

project(glsl2spv)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/glsl2spv.cpp
)

set(ENABLE_GLSLANG_BINARIES OFF)
set(ENABLE_HLSL OFF)
set(ENABLE_CTEST OFF)
set(ENABLE_SPVREMAPPER OFF)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glslang/)

add_library(glsl2spv STATIC ${SOURCES})
target_link_libraries(glsl2spv SPIRV glslang)
target_include_directories(glsl2spv PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glslang/)