cmake_minimum_required(VERSION 3.15)
project(example)

set(CMAKE_CXX_STANDARD 20)

add_library(example SHARED Some.cpp Some.h wrap.cpp)

find_package(PythonInterp 3.6 REQUIRED)
find_package(PythonLibs 3.6 REQUIRED)
set(Boost_NO_BOOST_CMAKE ON)
find_package(Boost COMPONENTS python38 REQUIRED)
if (Boost_FOUND)
    message(" Boost include directory found at ${Boost_INCLUDE_DIRS}")
    message(" Boost libraries found at ${Boost_LIBRARY_DIRS}")
else()
    message(" Boost not found")
endif()

#set(Boost_DEBUG                 ON)
set(CMAKE_SHARED_MODULE_PREFIX "")
set(Boost_USE_STATIC_LIBS OFF)
set(BUILD_SHARED_LIBS ON)
#set(Boost_USE_MULTITHREADED     ON)
#set(Boost_USE_STATIC_RUNTIME    ON)

#target_link_directories(_Boost_CPython G:/MinGW_msys/mingw64/lib)

target_link_libraries(example ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

include_directories(example ${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})


message(STATUS "PYTHON_LIBRARIES = ${PYTHON_LIBRARIES}")
message(STATUS "PYTHON_EXECUTABLE = ${PYTHON_EXECUTABLE}")
message(STATUS "PYTHON_INCLUDE_DIRS = ${PYTHON_INCLUDE_DIRS}")


#add_executable(_Boost_CPython main.cpp Some.cpp Some.h wrap.cpp)

