cmake_minimum_required(VERSION 3.22)


add_executable(telephone2 main.cpp telephone2.cpp ${MY_INCLUDE_DIR}/telephone2.h)
target_include_directories(telephone2 PUBLIC ${MY_INCLUDE_DIR})