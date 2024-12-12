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

//Delete
include(CMakePackageConfigHelpers)
//Delete

include(GNUInstallDirs)

//Delete
set(CHAUFA_CONFIG_PATH "${CMAKE_INSTALL_LIBDIR}/cmake/chaufa")

configure_package_config_file(cmake/chaufaConfig.cmake.in
	src/chaufaConfig.cmake
	INSTALL_DESTINATION "{CHAUFA_CONFIG_PATH}"
)

write_basic_package_version_file(
	src/chaufaConfigVersion.cmake
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion
)
//Delete

add_subdirectory(src)

//Delete
install(DIRECTORY include/
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/src/chaufaConfig.cmake
	${CMAKE_CURRENT_BINARY_DIR}/src/chaufaConfigVersion.cmake
	DESTINATION "{CHAUFA_CONFIG_PATH}"
)
//Delete

install(EXPORT chaufaTargets
	FILE chaufaTargets.cmake
	EXPORT_LINK_INTERFACE_LIBRARIES
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)




