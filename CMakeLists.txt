cmake_minimum_required(VERSION 2.8)

# compile

add_definitions("-std=c++11")

add_executable(subrenamer main.cpp)

target_link_libraries(subrenamer boost_system boost_filesystem)

# install

set(CMAKE_INSTALL_PREFIX "/usr/local/")

install(TARGETS subrenamer DESTINATION bin)