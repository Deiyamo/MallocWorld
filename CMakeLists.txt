cmake_minimum_required(VERSION 3.17)
project(Malloc_World C)

set(CMAKE_C_STANDARD 99)

#Many c files (these 3 below lines)
set(MALWORLD_SOURCE_PATH ${PROJECT_SOURCE_DIR}/src)
file(GLOB_RECURSE MALWORLD_SOURCE_FILES ${MALWORLD_SOURCE_PATH}/*.c)
add_executable(Malloc_World ${MALWORLD_SOURCE_FILES} src/types.h)

#add_executable(Malloc_World main.c) #Single c file
