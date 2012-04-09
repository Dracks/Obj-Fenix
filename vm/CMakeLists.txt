project (ofx-vm)

cmake_minimum_required(VERSION 2.8)


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/lib)

#SET(CMAKE_BUILD_TYPE debug)
SET(CMAKE_BUILD_TYPE "Release")
set(CMAKE_SHARED_LINKER_FLAGS "-flat_namespace")


add_subdirectory(src)
