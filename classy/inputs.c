#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"



struct sinput
{
	char *name;
	char *type;
};

input input_new_input()
{
	input i = NULL;
	i = (struct sinput *)malloc(sizeof(struct sinput));
	i->name =NULL;
	i->type =NULL;
	return i;
}

char *input_get_name(input i)
{
	return(i->name);
}
char *input_get_type(input i)
{
	return(i->type);
}

void input_set_name(input i,char * name)
{
	if(i != NULL && name != NULL ){
		if(i->name !=NULL){
			free (i->name);
		}
        i->name = (char *)calloc(sizeof(char), strlen(name)+1);
		strcpy(i->name, name);
	}

}

void input_set_type(input i,char *type)
{
	if(i != NULL && type != NULL ){
		if(i->type !=NULL){
			free(i->type);
		}
        i->type = (char *)calloc(sizeof(char), strlen(type)+1);
		strcpy(i->type, type);
	}
}

void input_end_input(input i){
	if(i->name != NULL){
		free(i->name);
	}
	if(i->type != NULL){
		free(i->type);
	}
	free(i);
}



