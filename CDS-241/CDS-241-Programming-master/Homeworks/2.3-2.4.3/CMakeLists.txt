cmake_minimum_required(VERSION 3.0.0)
project(2.3-2.4.3 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(2.3-2.4.3 main.cpp)

set(CMAKE_CXX_VERSION 17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
