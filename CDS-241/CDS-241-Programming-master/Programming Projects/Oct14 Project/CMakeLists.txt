cmake_minimum_required(VERSION 3.0.0)
project(Oct14Project VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Oct14Project main.cpp org_event_fns.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
