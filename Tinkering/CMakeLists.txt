
project(Tinkering)

cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(CMAKE_VERBOSE_MAKEFILE TRUE)

find_package(fmt CONFIG REQUIRED)
set(TKFMT_SRC ${CMAKE_CURRENT_SOURCE_DIR}/TkFmt)
add_executable(tk_fmt-exe ${TKFMT_SRC}/main.cpp)
target_link_libraries(tk_fmt-exe PRIVATE fmt::fmt)

find_package(unofficial-abseil CONFIG REQUIRED)
set(TKABSEIL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/TkAbseil)
add_executable(tk_abseil-exe ${TKABSEIL_SRC}/main.cpp)
target_link_libraries(tk_abseil-exe PRIVATE unofficial::abseil::base unofficial::abseil::strings)
