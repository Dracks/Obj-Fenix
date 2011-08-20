

ADD_CUSTOM_COMMAND(
   OUTPUT ${BUILD_PATH}/syntactic_parser.cpp
   COMMAND bison -d -v  -o ${BUILD_PATH}/syntactic_parser.cpp ${PROJECT_SOURCE_DIR}/src/syntactic_parser.y
   DEPENDS ${PROJECT_SOURCE_DIR}/src/syntactic_parser.y
)

ADD_CUSTOM_COMMAND(
   OUTPUT ${BUILD_PATH}/flex.yy.cpp
   COMMAND flex -o ${BUILD_PATH}/flex.yy.cpp $(LFLAGS) --header-file=${BUILD_PATH}/flex.yy.h  ${PROJECT_SOURCE_DIR}/src/lexical_analyzer.l
   DEPENDS ${PROJECT_SOURCE_DIR}/src/lexical_analyzer.l
)

add_library(base symtab.cpp symtab.h debug.cpp debug.h
		SemanticAnalisis.cpp SemanticAnalisis.h
		tools.cpp tools.h)

add_library(parsers ${BUILD_PATH}/syntactic_parser.cpp ${BUILD_PATH}/flex.yy.cpp ${BUILD_PATH}/syntactic_parser.h ${BUILD_PATH}/flex.yy.h)

add_subdirectory(treeCode)
add_subdirectory(classes)
add_subdirectory(generator)

