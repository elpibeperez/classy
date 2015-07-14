#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

commands commands_copy_commands(commands c){
	commands ret = NULL;
	if(c != NULL){
		ret = (commands)calloc(sizeof(char), strlen((char *)c)+1);
		strcpy((char *) ret,(char *) c);
	}
	return ret;	
}

void commands_end_commands(commands c)
{
	free(c);
}
