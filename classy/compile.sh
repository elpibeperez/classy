
yacc -d $1.yacc
lex $1.lex
#gcc -o $1 attributes.c syntactic_structure.c y.tab.c lex.yy.c -ly -ll
