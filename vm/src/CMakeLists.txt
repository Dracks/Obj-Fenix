

add_executable(ofx-vm main.cpp tools.cpp )

target_link_libraries(ofx-vm BuiltIn SDK tools runable)

add_subdirectory(classes)
add_subdirectory(SDK)
add_subdirectory(tools)
add_subdirectory(BuiltIn)
