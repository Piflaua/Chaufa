# CMakeList.txt : CMake project for Chaufa, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.8)

project(Chaufa C)

find_package(Vulkan REQUIRED)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_library(Chaufa STATIC ${SOURCES})

target_link_libraries(Chaufa Vulkan::Vulkan User32)	

target_link_directories(Chaufa PUBLIC include)