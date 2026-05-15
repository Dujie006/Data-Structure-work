cmake_minimum_required(VERSION 4.0)
project(essential_C__)

# 1. 设置C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. 解决终端中文乱码（Windows/MSVC）
if(MSVC)
    add_compile_options(/utf-8)
    add_compile_definitions(UNICODE _UNICODE)
endif()

# 3. 只添加List系列的可执行文件
add_executable(List_1 List_1.cpp)
add_executable(List_2 List_2.cpp)
add_executable(List_2-1 List_2-1.cpp)
add_executable(List_2-2 List_2-2.cpp)
add_executable(List_2_3 List_2_3.cpp)
add_executable(List_3 List_3.cpp)
add_executable(ListListListListListList ListListListListListList.cpp)