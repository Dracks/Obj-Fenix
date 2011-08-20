

add_executable(ofx-vm main.cpp tools.cpp)

target_link_libraries(ofx-vm Builtin runable)

add_subdirectory(Builtin)
add_subdirectory(classes)