cmake_minimum_required(VERSION 3.10)


# set the project name
project(mere-utils
        VERSION 0.0.1.1
        DESCRIPTION "A simple helper library"
        HOMEPAGE_URL "https://utils.merelabs.io"
        LANGUAGES C CXX)


#
cmake_host_system_information(RESULT HOSTNAME QUERY FQDN)
message(STATUS "Preparing build on ${HOSTNAME}")
message(STATUS "    System    : ${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_VERSION}")
message(STATUS "    Processor : ${CMAKE_HOST_SYSTEM_PROCESSOR}")

configure_file(Configure.h.in Configure.h)

# specify the mode
set(CMAKE_BUILD_TYPE Release)

#target_include_directories(mere-utils PUBLIC "${PROJECT_BINARY_DIR}")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core REQUIRED)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS src/*.h)

# Create shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Install library
install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION lib)

## Install headers
install(FILES ${HEADERS} DESTINATION include/mere/utils)

target_link_libraries(${PROJECT_NAME} Qt5::Core)
