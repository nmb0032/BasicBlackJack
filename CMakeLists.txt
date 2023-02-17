cmake_minimum_required(VERSION 3.0.0)
project(black_jack VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCES main.cpp deck.cpp player.cpp card.cpp)

add_executable(black_jack ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
