%{
#include <stdio.h>
#include <string.h>
#include "syntactic_structure.h"
#include "attributes.h" 
void yyerror(const char *str)
{
        fprintf(stderr,"error: %s\n",str);
}
 
int yywrap()
{
        return 1;
} 
syntactic_structure ss;
attribute attr;
int id;
  
main()
{
	int attrib_size = 0;
	int i = 0;
	ss = syntactic_structure_new_syntactic_structure();
	attr = NULL;
        yyparse();
	printf("every attrib:\n");
	for(; i < syntactic_structure_get_attrib_size(ss); i++){
		printf("Attribs id: %d\n", i);
		attribute_show_attribute(syntactic_structure_get_attrib(ss, i));
	}

	printf("every Name:\n");
	for(; i < syntactic_structure_get_name_size(ss); i++){
		printf("Names id: %d\n", i);
		printf("Name: %s\n", syntactic_structure_get_name(ss, i));
	}
	
} 

%}

%union{
	char *str;
}

%token <str> NAME 
%token <str> NUMBER

//HEADERS 
%token INHERIT 
%token USE
//DECLARATIONS
%token PRIV
%token FUN
%token ARROW
%token NUM
%token STR
%token SET
%token GET
%token OB
%token CB
%token OBR
%token CBR
%token COMMA
%token CONT

%left CONT
%nonassoc COMMA
//start
%start class
%%

//class	:  empty 
//      | uses  declarations main tests 
//      ;

class	:uses declars
	|inherit uses declars
	;

uses:
	| uses use
	;

use:	USE used CONT
	{
		printf("USE CLAUSE \n");
	}
	;
used	: NAME
	{
		syntactic_structure_add_use(ss, $1);
		id = syntactic_structure_get_use_id(ss, $1);
		if(id != -1){
			printf("using id: %d \n", id);
			printf("using: %s \n", syntactic_structure_get_use(ss,id));
		}else{
			printf("Not able to add using clause: %d \n", id);
		}
	}
	;

inherit	:INHERIT father CONT
	{
		printf("INHERIT clause\n");
	}
	;
father : NAME
	{
		syntactic_structure_set_inherit(ss, $1);
		printf("INHERIT FROM: %s \n", syntactic_structure_get_inherit(ss));
	}
	;	

declars	: 
	| declars attrib 
	| declars method
	;

attrib : access NUM varname CONT
	{
		if(NULL != attr){
			attribute_set_type(attr,"num");
			attribute_show_attribute(attr);
			syntactic_structure_add_attrib(ss, attr);
		}

		attribute_end_attribute(attr);
		attr = NULL;
	}
	| access STR varname CONT
	{
		if(NULL != attr){
			attribute_set_type(attr,"string");
			attribute_show_attribute(attr);
			syntactic_structure_add_attrib(ss, attr);
		}
		attribute_end_attribute(attr);
		attr = NULL;
	}
	| access classname varname CONT
	{
		if(NULL != attr)
		{
			printf("Class\n");
			attribute_show_attribute(attr);
			syntactic_structure_add_attrib(ss, attr);
		}
		attribute_end_attribute(attr);
		attr = NULL;
	}
	;

varname	: NAME
	{	
		syntactic_structure_add_name(ss, $1);
		attribute_set_name(attr,$1);
	}
	;

access	: set
	| GET set 
	{
		printf("3- attrib GET: %d\n", id);
		if(NULL == attr){
			attr = attribute_new_attribute();
		}
		if(A_SET ==attribute_get_access(attr)){
			attribute_set_access(attr,A_SET_GET);
		}else{
			attribute_set_access(attr,A_GET);	
		}
	}
	| SET GET
	{
		printf("3- attrib SET GET: %d\n", id);
		if(NULL == attr){
			attr = attribute_new_attribute();
		}
		attribute_set_access(attr,A_SET_GET);
	}
	;

set	: 
	| SET
	{
		if(NULL == attr){
			attr = attribute_new_attribute();
		}
		attribute_set_access(attr,A_SET);
	}
	;

classname:NAME
	{	
		
		if(NULL == attr){
			attr = attribute_new_attribute();
		}
		attribute_set_type(attr,$1);		
	}
	;

method	: PRIV FUN funname OB inputs CB ARROW return definit
	| FUN funname OB inputs CB ARROW return definit
	| PRIV FUN funname OB inputs CB definit
	| FUN funname OB inputs CB definit
	;

funname	: NAME 
	{
		syntactic_structure_add_name(ss, $1);
	}
	;

inputs	: 
	| input
	| inputs COMMA input
	;

input : NUM NAME 
	{
		printf("input: Num %s \n", $2);	
	}
	| STR NAME 
	{
		printf("input: String %s \n", $2);	
	}
	| NAME NAME 
	{
		printf("input: Classname %s: %s \n", $1, $2);
	}
	;

return	: STR
	| NUM
	| NAME
	;


definit	: OBR CBR
	;



