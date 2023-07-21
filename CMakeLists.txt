cmake_minimum_required(VERSION 3.14)


project(Nerl_backend
    VERSION 1.0.0
    DESCRIPTION "Nerl backend in early stages of development. Have fun :)"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}"
    is_top_level)

#Main library
add_library(Nerl_backend SHARED)

#Make clang and gcc not include other symbols for lib
if(NOT DEFINED (CMAKE_CXX_VISIBILITY_PRESET))
     set(CMAKE_CXX_VISIBILITY_PRESET hidden)
endif()
if(NOT DEFINED (CMAKE_VISIBILITY_INLINES_HIDDEN))
     set(CMAKE_VISIBILITY_INLINES_HIDDEN  on)
endif()

#For export macro
include(GenerateExportHeader)

#setting headers and sources

    set(public_headers
    include/harpy_system/hash/MD5.h
    include/harpy_system/cxx_save_sys.h
    include/csharp_part/save_sys.h)
set(sources
    ${public_headers}
    ${CMAKE_SOURCE_DIR}/source/harpy_system/cxx_save_sys.cpp
    ${CMAKE_SOURCE_DIR}/source/harpy_system/hash/MD5.cpp
    ${CMAKE_SOURCE_DIR}/source/csharp_part/save_sys.cpp)

#Make same structure in IDE as here
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

include(CMakePackageConfigHelpers)

#Here adding sources to Nerl
target_sources(Nerl_backend PRIVATE ${sources})

target_include_directories(Nerl_backend
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src")

set_target_properties(Nerl_backend PROPERTIES
    PUBLIC_HEADER "${public_headers}"
    SOVERSION ${PROJECT_VERSION_MAJOR}
    VERSION ${PROJECT_VERSION}
    COMPILE_FLAGS "/clr"
    DEBUG_POSTFIX "d")
