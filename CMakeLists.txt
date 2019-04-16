cmake_minimum_required (VERSION 3.6)

set (TRAVIS_BUILD_NUMBER "$ENV{TRAVIS_BUILD_NUMBER}")

if ("${TRAVIS_BUILD_NUMBER}" STREQUAL "")
	set (TRAVIS_BUILD_NUMBER "1")
endif ("${TRAVIS_BUILD_NUMBER}" STREQUAL "")

project ("timus"
	VERSION "0.0.${TRAVIS_BUILD_NUMBER}"
	DESCRIPTION "Solutions for Timus tasks"
	HOMEPAGE_URL "https://github.com"
	LANGUAGES CXX)

option (BUILD_TYPE_RELEASE "Is build type Release")

if (BUILD_TYPE_RELEASE)
	set (CMAKE_BUILD_TYPE "Release")
	set (INSTALL_SUBDIR ".")
else (BUILD_TYPE_RELEASE)
	set (CMAKE_BUILD_TYPE "Debug")
	set (INSTALL_SUBDIR "Debug")
endif (BUILD_TYPE_RELEASE)

find_package (GTest REQUIRED)
find_package (Threads REQUIRED)

configure_file (version.hpp.in version.hpp)

set (CMAKE_VERBOSE_MAKEFILE OFF)

add_library (testlib INTERFACE)

target_include_directories (testlib INTERFACE
	"${CMAKE_SOURCE_DIR}"
)

foreach (target 1000 1001 1073 1197 1264 1293 1306 1409 1639 1785 1787 1820 1864 1877 1880 2001 2012 2066)
	add_executable ("timus-${target}" "${target}/impl.cpp")
	add_executable ("test-${target}" "${target}/test.cpp")

	set_target_properties ("timus-${target}" PROPERTIES
		CXX_STANDARD 14
		CXX_EXTENSIONS OFF
		CXX_STANDARD_REQUIRED ON
		COMPILE_OPTIONS "-pedantic;-Wall;-Wextra"
		LINK_LIBRARIES "${CMAKE_THREAD_LIBS_INIT}"
	)

	set_target_properties ("test-${target}" PROPERTIES
		CXX_STANDARD 14
		CXX_EXTENSIONS OFF
		CXX_STANDARD_REQUIRED ON
		COMPILE_OPTIONS "-pedantic;-Wall;-Wextra"
		INCLUDE_DIRECTORIES "${CMAKE_BINARY_DIR}"
		LINK_LIBRARIES "${GTEST_LIBRARY};${GTEST_MAIN_LIBRARY};${CMAKE_THREAD_LIBS_INIT};testlib"
	)

	install (TARGETS "timus-${target}" RUNTIME DESTINATION bin COMPONENT "${target}")

	add_test (NAME "Test-${target}"
		COMMAND "test-${target}" "./timus-${target}" "in-${target}" "out-${target}"
		WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
	)

	string (TOUPPER "${target}" target_upper)

	set (CPACK_COMPONENT_${target_upper}_DESCRIPTION
"Timus task ${target} implementation
 This package contains the Timus task ${target} implementation
 that is to be checked on by the OTUS C++ course instructor.")
endforeach(target)

include (CTest)

set (CPACK_GENERATOR DEB)

set (CPACK_DEB_PACKAGE_DEBUG ON)

set (CPACK_DEB_COMPONENT_INSTALL ON)
set (CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

set (CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set (CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set (CPACK_PACKAGE_ARCHITECTURE "amd64")
set (CPACK_PACKAGE_CONTACT myname@company.com)
set (CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)

include (CPack)
