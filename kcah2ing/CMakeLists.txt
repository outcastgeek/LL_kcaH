
project(kcah2ing)

cmake_minimum_required(VERSION 3.3)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(FIRSTPROG_SRC ${CMAKE_CURRENT_SOURCE_DIR}/firstprog)
add_executable(firstprog-exe ${FIRSTPROG_SRC}/firstprog.c)

set(STRINGS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/strings)
add_executable(char_array-exe ${STRINGS_SRC}/char_array.c)

set(STRINGS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/strings)
add_executable(char_array2-exe ${STRINGS_SRC}/char_array2.c)

set(SIGNEDUNSIGNEDLONGSHORT_SRC ${CMAKE_CURRENT_SOURCE_DIR}/signedunsignedlongshort)
add_executable(datatype_sizes-exe ${SIGNEDUNSIGNEDLONGSHORT_SRC}/datatype_sizes.c)
