cmake_minimum_required(VERSION 3.9)

project("PID-Tuning" CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake.modules/")

# Debug mode
set(CMAKE_BUILD_TYPE Debug)
# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# conan_basic_setup()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# You can try and uncomment this if clang is complaining about not finding the standard
# library headers or symbols on OSX
#if (APPLE)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -I/usr/include/libcxxabi")
#    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
#endif()

add_subdirectory(src)
add_subdirectory(apps)
# add_subdirectory(tests)

enable_testing()
