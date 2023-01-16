cmake_minimum_required(VERSION 3.0.0)
project(botworld VERSION 0.1.0)

include(CTest)
enable_testing()


set(CMAKE_CXX_STANDARD 17)
add_executable(botworld main.cpp follow_bot.cpp drunk_bot.cpp smart_bot.cpp)

# set up to use the BotWorld library
set(BW_BASE ${CMAKE_CURRENT_SOURCE_DIR}/BW_Library)
target_include_directories(botworld PUBLIC ${BW_BASE}/include)
target_sources(botworld PUBLIC 
                    ${BW_BASE}/src/botdisp.cpp 
                    ${BW_BASE}/src/botworld.cpp
                    ${BW_BASE}/src/bot.cpp  
                    ${BW_BASE}/include/bot.h                    
                )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
