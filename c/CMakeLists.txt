# minimal setup for cmake, which is a popular build tool
cmake_minimum_required(VERSION 3.5)
project(c-examples VERSION 1.0.0)
# get all .c files as ${SOURCES}
# may cause problems as compile order is unknown,
# but is convenient for small projects like this
file(GLOB SOURCES "src/*.c")
add_executable(c-examples ${SOURCES})