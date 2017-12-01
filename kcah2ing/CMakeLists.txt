
project(firstprog)

cmake_minimum_required(VERSION 3.3)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(FIRSTPROG_SRC ${CMAKE_SOURCE_DIR}/firstprog)
add_executable(firstprog-exe ${FIRSTPROG_SRC}/firstprog.c)
