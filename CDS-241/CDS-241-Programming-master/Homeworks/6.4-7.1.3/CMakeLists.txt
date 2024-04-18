cmake_minimum_required(VERSION 3.0.0)
project(6.4-7.1.3 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(6.4-7.1.3 main.cpp combo.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
