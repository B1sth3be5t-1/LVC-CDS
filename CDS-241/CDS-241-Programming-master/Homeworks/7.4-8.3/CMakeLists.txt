cmake_minimum_required(VERSION 3.0.0)
project(7.4-8.3 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(7.4-8.3 main.cpp log.cpp loglist.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
