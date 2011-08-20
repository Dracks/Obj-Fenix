Project(ofx-c)

cmake_minimum_required(VERSION 2.8)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

SET(BUILD_PATH ${PROJECT_SOURCE_DIR}/build)

SET(CMAKE_BUILD_TYPE debug)

add_executable(ofx-c src/main.cpp)

target_link_libraries(ofx-c base treeCode classes parsers fl generator)

add_subdirectory(src)
add_subdirectory(build)