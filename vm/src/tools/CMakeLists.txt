add_library(tools SHARED Adapter.cpp Adapter.h Cache.cpp Cache.h Register.cpp Register.h)

target_link_libraries(tools SDK runable)