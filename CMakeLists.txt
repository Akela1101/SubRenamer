cmake_minimum_required(VERSION 2.8)

# compile
add_definitions("-std=c++11")
set(CMAKE_VERBOSE_MAKEFILE "1")

if(WIN32)
	set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static -static-libgcc")
	include_directories($ENV{BOOST_ROOT})
	link_directories($ENV{BOOST_ROOT}/stage/lib)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

add_executable(subrenamer main.cpp)
target_link_libraries(subrenamer boost_system boost_filesystem)

# install
if(UNIX)
	set(CMAKE_INSTALL_PREFIX "/usr/local/")
	install(TARGETS subrenamer DESTINATION bin)
endif()
