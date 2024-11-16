cmake_minimum_required(VERSION 3.29)
project(TP1v2)

set(CMAKE_CXX_STANDARD 14)

add_executable(TP1v2 main.cpp
        Structs/Graph.cpp
        Structs/Graph.h
        structs/CustomQueue.cpp
        structs/CustomQueue.h
        services/Capital.cpp
        services/Capital.h
        services/Battalion.cpp
        services/Battalion.h)
