cmake_minimum_required(VERSION 3.15)
project(_Boost_CPython)

set(CMAKE_CXX_STANDARD 20)

add_library(_Boost_CPython SHARED Some.cpp Some.h wrap.cpp)

set(BOOST_ROOT G:/MinGW_msys/mingw64)
#set(Boost_LIBRARIES G:/MinGW_msys/mingw64/lib)
find_package(Boost REQUIRED python)
if (Boost_FOUND)
    message(" Boost include directory found at ${Boost_INCLUDE_DIRS}")
    message(" Boost libraries found at ${Boost_LIBRARY_DIRS}")
else()
    message(" Boost not found")
endif()

set(Boost_DEBUG                 ON)
#set(Boost_USE_STATIC_LIBS       ON)
set(Boost_USE_MULTITHREADED     ON)
#set(Boost_USE_STATIC_RUNTIME    ON)

find_package(PythonInterp 3 REQUIRED)
find_package(PythonLibs 3 REQUIRED)

#target_link_directories(_Boost_CPython G:/MinGW_msys/mingw64/lib)

target_link_libraries(_Boost_CPython ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

include_directories(_Boost_CPython ${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})


message(STATUS "PYTHON_LIBRARIES = ${PYTHON_LIBRARIES}")
message(STATUS "PYTHON_EXECUTABLE = ${PYTHON_EXECUTABLE}")
message(STATUS "PYTHON_INCLUDE_DIRS = ${PYTHON_INCLUDE_DIRS}")


#add_executable(_Boost_CPython main.cpp Some.cpp Some.h wrap.cpp)
