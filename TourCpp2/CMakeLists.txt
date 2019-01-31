
project(TourCpp2)

cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(CMAKE_VERBOSE_MAKEFILE TRUE)

set(STRUCTS_STUDY_SRC ${CMAKE_CURRENT_SOURCE_DIR}/Structures)
add_executable(structs_study-exe ${STRUCTS_STUDY_SRC}/structs_study.cpp)

set(COMTASKS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/CommunicatingTasks)
add_executable(com_tasks-exe ${COMTASKS_SRC}/com_tasks.cpp)
