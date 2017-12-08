
project(LearnC)

cmake_minimum_required(VERSION 3.3)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(EX1_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex1)
add_executable(ex1-exe ${EX1_SRC}/ex1.c)

#set(EX2_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex2)
#add_executable(ex2-exe ${EX2_SRC}/ex2.c)

set(EX3_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex3)
add_executable(ex3-exe ${EX3_SRC}/ex3.c)

set(EX4_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex4)
add_executable(ex4-exe ${EX4_SRC}/ex4.c)

set(EX5_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex5)
add_executable(ex5-exe ${EX5_SRC}/ex5.c)

set(EX6_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex6)
add_executable(ex6-exe ${EX6_SRC}/ex6.c)

set(EX7_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex7)
add_executable(ex7-exe ${EX7_SRC}/ex7.c)

set(EX8_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex8)
add_executable(ex8-exe ${EX8_SRC}/ex8.c)

set(EX9_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex9)
add_executable(ex9-exe ${EX9_SRC}/ex9.c)

set(EX10_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex10)
add_executable(ex10-exe ${EX10_SRC}/ex10.c)

set(EX11_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex11)
add_executable(ex11-exe ${EX11_SRC}/ex11.c)

set(EX12_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex12)
add_executable(ex12-exe ${EX12_SRC}/ex12.c)

set(EX13_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex13)
add_executable(ex13-exe ${EX13_SRC}/ex13.c)

set(EX14_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex14)
add_executable(ex14-exe ${EX14_SRC}/ex14.c)

set(EX15_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex15)
add_executable(ex15-exe ${EX15_SRC}/ex15.c)

set(EX16_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex16)
add_executable(ex16-exe ${EX16_SRC}/ex16.c)

set(EX17_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex17)
add_executable(ex17-exe ${EX17_SRC}/ex17.c)

set(EX18_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex18)
add_executable(ex18-exe ${EX18_SRC}/ex18.c)

set(EX19_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex19)
add_executable(ex19-exe ${EX19_SRC}/ex19.c)

#set(EX20_SRC ${CMAKE_CURRENT_SOURCE_DIR}/ex20)
#add_executable(ex20-exe ${EX20_SRC}/ex20.c)
