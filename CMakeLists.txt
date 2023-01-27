cmake_minimum_required(VERSION 3.23)

project("px"
    VERSION 0.1.0
    DESCRIPTION "A project to review Xerces-C"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(px main.cpp main.hpp dom.hpp)

find_library(XERCES_LIB xerces-c)

target_link_libraries(px PRIVATE "${XERCES_LIB}")

include_directories(px PRIVATE "/usr/local/include/xercesc")
