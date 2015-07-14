%{
#include <stdio.h>
#include "y.tab.h"
%}
%%
\=\>			{
				return ARROW;			
			}
;			{
				return CONT;
			}
set			{
				return SET;
			}
get			{
				return GET;
			}
num			{
				return NUM;
			}
string			{
				return STR;
			}
use			{
				return USE;
			}
inherit			{
				return INHERIT;
			}
private			{
				return PRIV;
			}
fun			{
				return FUN;
			}
\{			{
				return OBR;
			}
\}			{
				return CBR;
			}
\(			{
				return OB;
			}
\)			{
				return CB;
			}
,			{
				return COMMA;
			}
[a-zA-Z\-\_]+		{
				yylval.str = yytext;
				return NAME;				
			}
[0-9]+   		{
				
				yylval.str = yytext; 
				return NUMBER;
			}
\n                      /* ignore end of line */;
[ \t]+                  /* ignore whitespace */;
%%

