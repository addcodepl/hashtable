cmake_minimum_required(VERSION 3.20)
project(hashtable C)

set(CMAKE_C_STANDARD 99)

add_executable(hashtable main.c hashtable.h hashtable.c hash.c hash.h)
