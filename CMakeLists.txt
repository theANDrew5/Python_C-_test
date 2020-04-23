cmake_minimum_required(VERSION 3.15)
project(_Boost_CPython)

set(CMAKE_CXX_STANDARD 20)

#add_executable(_Boost_CPython main.cpp Some.cpp Some.h wrap.cpp)
add_library(example STATIC Some.cpp Some.h wrap.cpp)

find_package(Boost)
find_package(PythonInterp 3 REQUIRED)
find_package(PythonLibs 3 REQUIRED)

include_directories((${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS}))


message(STATUS "PYTHON_LIBRARIES = ${PYTHON_LIBRARIES}")
message(STATUS "PYTHON_EXECUTABLE = ${PYTHON_EXECUTABLE}")
message(STATUS "PYTHON_INCLUDE_DIRS = ${PYTHON_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")