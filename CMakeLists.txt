cmake_minimum_required(VERSION 3.29)
project(minitalk C)

set(CMAKE_C_STANDARD 99)

add_library(minitalk STATIC server.c
        client.c)
