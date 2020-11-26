cmake_minimum_required(VERSION 3.16)
project(proyecto)

set(CMAKE_CXX_STANDARD 14)

add_executable(proyecto
        keyboarEvent.cpp
        observer.cpp
        test.cpp)
