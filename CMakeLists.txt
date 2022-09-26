cmake_minimum_required(VERSION 3.20)
project(cppgame)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppgame src/main.cpp src/Diamond.cpp src/Diamond.h src/Potter.cpp src/Potter.h src/Malfoy.cpp src/Malfoy.h src/Engine.cpp src/Engine.h src/Object.cpp src/Object.h src/Player.cpp src/Player.h)
