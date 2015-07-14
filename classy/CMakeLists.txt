cmake_minimum_required(VERSION 3.1)
set(PROJECT_NAME classy)
project(${PROJECT_NAME} C)

find_package(BISON)
find_package(FLEX)


set(CMAKE_C_FLAGS  "-Wall -lm -lpthread -lrt -lcheck")
set(SOURCE_FILES
    attributes.c
    commands.c
    inputs.c
    methods.c
    syntactic_structure.c
)

set(TEST_SOURCES_FILES
    run_tests.c
    attributes_tests.c
    inputs_tests.c
    methods_tests.c
    syntactic_structure_test.c
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${TEST_SOURCES_FILES})
target_link_libraries(${PROJECT_NAME}  check pthread m rt )

add_custom_target(classy_parser echo "Creating the parser")

set(PROJECT_PATH /home/perez/ClionProjects/classy/)
#add_custom_command(
#    COMMAND ${FLEX_EXECUTABLE}
#    ARGS ${PROJECT_PATH}classy.lex
#    ARGS classy.lex
#    TARGET classy_parser
#    OUTPUTS lex.yy.c
#)

#add_custom_command(
#    COMMAND ${BISON_EXECUTABLE}
    #ARGS -d ${PROJECT_PATH}classy.yacc
#    ARGS -d classy.yacc
#    TARGET classy_parser
#    DEPENDS lex.yy.c
#    OUTPUTS y.tab.c
#)


bison_target(parser classy.yacc y.tab.c)

SET(CLASSY_COMPILER_SRCS ${Foo_SRCS} ${Foo_BINARY_DIR}/src/parser.c)
