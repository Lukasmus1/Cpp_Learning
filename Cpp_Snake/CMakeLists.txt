cmake_minimum_required(VERSION 4.4)
project(Cpp_Snake)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Cpp_Snake main.cpp
        Game.cpp
        Game.h
        Food.cpp
        Food.h
        Snake.cpp
        Snake.h
        Direction.h
        StateMachine.cpp
        StateMachine.h
        States.h
)

find_package(raylib CONFIG REQUIRED)

target_link_libraries(Cpp_Snake PRIVATE raylib)