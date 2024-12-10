# CMakeList.txt : CMake project for Chaufa, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.8)

project(chaufa C)

include(GNUInstallDirs)

find_package(Vulkan REQUIRED)

add_library(chaufa STATIC "include/Chaufa.h" "src/Chaufa.c")

target_include_directories(chaufa 
						PUBLIC
							$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
							$<INSTALL_INTERFACE:include>
						PRIVATE
							${CMAKE_SOURCE_DIR}/src
							${CMAKE_BINARY_DIR}/src
)

target_link_libraries(chaufa PRIVATE Vulkan::Vulkan User32)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(TARGETS chaufa
	EXPORT chaufaTargets
	RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
	ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
	LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
)

install(EXPORT chaufaTargets
	FILE chaufaTargets.cmake
	NAMESPACE chaufa::
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/chaufa"
)