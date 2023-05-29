cmake_minimum_required(VERSION 3.0.0)
project(s2p12 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(s2p12 main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)