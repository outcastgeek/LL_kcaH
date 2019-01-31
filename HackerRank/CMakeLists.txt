
project(TourCpp2)

cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(CMAKE_VERBOSE_MAKEFILE TRUE)

set(HR_HELLO_SRC ${CMAKE_CURRENT_SOURCE_DIR}/HR_Hello)
add_executable(hr_hello_world-exe ${HR_HELLO_SRC}/hr_hello_world.cpp)

set(HR_INOUT_SRC ${CMAKE_CURRENT_SOURCE_DIR}/HR_InputOutput)
add_executable(hr_input_output-exe ${HR_INOUT_SRC}/hr_input_output.cpp)

set(HR_BASICDATATYPES_SRC ${CMAKE_CURRENT_SOURCE_DIR}/HR_BasicDataTypes)
add_executable(hr_basic_data_types-exe ${HR_BASICDATATYPES_SRC}/hr_basic_data_types.cpp)

set(HR_INHERITEDCODE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/HR_InheritedCode)
add_executable(hr_inherited_code-exe ${HR_INHERITEDCODE_SRC}/hr_inherited_code.cpp)

set(HR_EXCEPTIONALSERVER_SRC ${CMAKE_CURRENT_SOURCE_DIR}/HR_ExceptionalServer)
add_executable(hr_exceptional_server-exe ${HR_EXCEPTIONALSERVER_SRC}/hr_exceptional_server.cpp)

#set(HR_VIRTUALFUNCTIONS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/HR_VirtualFunctions)
#add_executable(hr_virtual_functions-exe ${HR_VIRTUALFUNCTIONS_SRC}/hr_virtual_functions.cpp)
