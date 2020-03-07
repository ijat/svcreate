cmake_minimum_required(VERSION 3.15)
project(svcreate)

set(CMAKE_CXX_STANDARD 20)

add_executable(svcreate svcreate.cpp lib/inipp.h)
target_link_libraries(svcreate -static)