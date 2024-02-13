# minimal setup for cmake, which is a popular build tool
cmake_minimum_required(VERSION 3.5)
project(c-examples VERSION 1.0.0)
# get all .c files in a directory as ${SOURCES}
# may cause problems as compile order is unknown,
# but is convenient for small projects like this
file(GLOB SOURCES "src/examples/*.c")
# compile main.c and other found sources to an executable
add_executable(c-examples src/main.c ${SOURCES})