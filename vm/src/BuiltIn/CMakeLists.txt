add_library(BuiltIn SHARED Boolean.cpp Boolean.h Integer.cpp Integer.h Shell.cpp Shell.h String.cpp String.h List.cpp List.h)

target_link_libraries(BuiltIn tools SDK runable)