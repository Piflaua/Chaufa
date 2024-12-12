# CMakeList.txt : CMake project for Chaufa, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.10)

project(chaufa 
	VERSION 1.0
	DESCRIPTION "Eat chaufa with sillao"
	LANGUAGES C
)

set(CMAKE_C_STANDARD 99)

find_package(Vulkan REQUIRED)

add_library(${PROJECT_NAME} 
	"include/Chaufa.h"
	"src/Chaufa.c"
)

target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan User32)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
