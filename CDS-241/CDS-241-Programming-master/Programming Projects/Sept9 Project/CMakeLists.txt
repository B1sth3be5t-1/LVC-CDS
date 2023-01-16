cmake_minimum_required(VERSION 3.0.0)
project(totally-radical VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(totally-radical main.cpp)

set(CMAKE_CXX_VERSION 17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
