cmake_minimum_required(VERSION 2.6)
project(MythicFATE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")

add_executable(fate
	sources/main.cpp)
