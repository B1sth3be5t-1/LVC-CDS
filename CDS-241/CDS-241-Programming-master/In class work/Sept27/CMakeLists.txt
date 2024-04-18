cmake_minimum_required(VERSION 3.0.0)
project(Sept27 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Sept27 main.cpp)

set(CMAKE_CXX_VERSION 17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
