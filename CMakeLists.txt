# CMakeList.txt : CMake project for Chaufa, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.8)

project(chaufa C)

find_package(Vulkan REQUIRED)

include_directories(include)

add_library(chaufa SHARED "${CMAKE_SOURCE_DIR}/include/Chaufa.h" src/Chaufa.c)

target_link_directories(chaufa PUBLIC "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>" "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
target_link_directories(chaufa PRIVATE "src" "${CMAKE_BINARY_DIR}/src")
target_link_libraries(chaufa PRIVATE Vulkan::Vulkan User32)