cmake_minimum_required(VERSION 3.15)

# give a name to the project
project(conic LANGUAGES C CXX)

# include Eigen
find_package(Eigen3 REQUIRED)
if(${EIGEN3_FOUND})
    message(STATUS "lib EIGEN3 found")
    message(STATUS "  version " ${EIGEN3_VERSION_STRING})
    message(STATUS "  include " ${EIGEN3_INCLUDE_DIR})
else()
    #message(FATAL_ERROR "lib EIGEN3 not found")
    set(EIGEN3_INCLUDE_DIR "C:/eigen/eigen-3.4.0")    # windows users: put the path to eigen lib
    message(STATUS "  include " ${EIGEN3_INCLUDE_DIR})
endif()

# call the CMakeLists.txt to make the documentation (Doxygen)
find_package(Doxygen OPTIONAL_COMPONENTS QUIET)
if(DOXYGEN_FOUND)
	add_subdirectory(doc)
else()
	message(WARNING "Doxygen not found, skip dococumentation")
endif()

# add a "output" directory in the project binary directory
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/output)
# TODO : set the output path

# put the binary files in this directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# files to compile

add_executable(conic src/main.cpp 
    src/Geogebra_conics.cpp include/Geogebra_conics.hpp 
    src/Entry.cpp include/Entry.hpp 
    src/Directory.cpp include/Directory.hpp
    src/Conic.cpp include/Conic.hpp 
    src/Point.cpp include/Point.hpp
    src/Viewer.cpp include/Viewer.hpp
    include/Geogebra_object.hpp
)

# compilation options
target_compile_features(conic PRIVATE cxx_std_20) # use at least c++ 11
if (MSVC)
    target_compile_options(conic PRIVATE /W3)
else()
    target_compile_options(conic PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

# lib include path
target_include_directories(conic PRIVATE "${EIGEN3_INCLUDE_DIR}")

# include directory
target_include_directories(conic PRIVATE "include")