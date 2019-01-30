
project(TourCpp2)

cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_VERBOSE_MAKEFILE TRUE)

set(COMTASKS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/CommunicatingTasks)
add_executable(com_tasks-exe ${COMTASKS_SRC}/com_tasks.cpp)
