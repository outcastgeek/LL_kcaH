
project(kcah2ing)

cmake_minimum_required(VERSION 3.3)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(FIRSTPROG_SRC ${CMAKE_CURRENT_SOURCE_DIR}/firstprog)
add_executable(firstprog-exe ${FIRSTPROG_SRC}/firstprog.c)

set(STRINGS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/strings)
add_executable(char_array-exe ${STRINGS_SRC}/char_array.c)
add_executable(char_array2-exe ${STRINGS_SRC}/char_array2.c)

set(SIGNEDUNSIGNEDLONGSHORT_SRC ${CMAKE_CURRENT_SOURCE_DIR}/signedunsignedlongshort)
add_executable(datatype_sizes-exe ${SIGNEDUNSIGNEDLONGSHORT_SRC}/datatype_sizes.c)

set(MEMORYLOCATIONS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/memorylocations)
add_executable(pointer-exe ${MEMORYLOCATIONS_SRC}/pointer.c)
add_executable(addressof-exe ${MEMORYLOCATIONS_SRC}/addressof.c)
add_executable(addressof2-exe ${MEMORYLOCATIONS_SRC}/addressof2.c)

set(FORMATSTRINGS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/formatstrings)
add_executable(fmt_strings-exe ${FORMATSTRINGS_SRC}/fmt_strings.c)
add_executable(input-exe ${FORMATSTRINGS_SRC}/input.c)

set(TYPECASTING_SRC ${CMAKE_CURRENT_SOURCE_DIR}/typecasting)
add_executable(typecasting-exe ${TYPECASTING_SRC}/typecasting.c)
add_executable(pointer_types-exe ${TYPECASTING_SRC}/pointer_types.c)

