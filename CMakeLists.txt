# CMakeList.txt : CMake project for Chaufa, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.8)

project(chaufa C)

find_package(Vulkan REQUIRED)

add_library(chaufa STATIC "include/Chaufa.h" "src/Chaufa.c")

target_include_directories(chaufa PUBLIC
							$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
							$<INSTALL_INTERFACE:include>)

target_include_directories(chaufa PRIVATE
							{CMAKE_SOURCE_DIR}/src
							{CMAKE_BINARY_DIR}/src)

target_link_libraries(chaufa PRIVATE Vulkan::Vulkan User32)