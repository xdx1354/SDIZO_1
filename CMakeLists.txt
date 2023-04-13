cmake_minimum_required(VERSION 3.24)
project(Project_1)

set(CMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

add_executable(Project_1
        AutoTests.cpp
        AutoTests.h
        BST.cpp
        BST.h
        DynamicArray.cpp
        DynamicArray.h
        Heap.cpp
        Heap.h
        List.cpp
        List.h
        ListNode.cpp
        ListNode.h
        main.cpp
        Node.cpp
        Node.h
        Tests.cpp
        Tests.h
        Time.cpp
        Time.h)