cmake_minimum_required(VERSION 3.10.0)
project(s2p8 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(s2p8 main.cpp OBJECT.cpp BOOK.cpp PRINT.cpp LIST.cpp EVENT.h DIALOG.h DIALOG.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)