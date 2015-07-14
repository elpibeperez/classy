#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "methods.h"
#include "commands.h"


struct smethod{
	char *name;
	input *inputs;
	int input_sz;
	char *return_type;
	commands definition;
};

method method_new_method()
{
	method m = NULL;
	m = (struct smethod *)malloc(sizeof(struct smethod));
	m->name = NULL;
	m->inputs = NULL;
	m->input_sz = 0;
	m->return_type = NULL;
	m->definition = NULL;
	return m;
}

char *method_get_name(method m)
{
	if(m != NULL){
		return m->name;
	}
	return NULL;

}

void method_set_name(method m, char * name)
{
	if(m != NULL){
		if(m->name != NULL){
			free(m->name);
		}
        if(name != NULL){
            m->name = (char *)calloc(sizeof(char),strlen(name)+1);
            strcpy(m->name ,name);
        }else{
            m->name = NULL;
        }
	}
}

input method_get_input_by_id(method m, int id)
{

	if(	(m != NULL) && (m->inputs != NULL) &&
		(id >= 0) && (id < m-> input_sz)){

		return m->inputs[id];
	}
	return  NULL;
}

int method_get_input_id_by_name(method m, char *name)
{
	int i = 0;
	if( m != NULL && name != NULL ){
		for(; i < m-> input_sz ; i++){
			if (0 == strcmp(input_get_name(m->inputs[i]),name)){
				return i;
			}
		}
	}
	return -1;
}

int method_get_input_size(method m)
{
	if(m!=NULL){
		return(m->input_sz);
	}
	return -1;
}


void method_add_input(method m, input i)
{
	if(m != NULL){
		if(m->inputs == NULL){
			m->inputs = (input *)malloc(sizeof(input));
			m->input_sz = 0;
		}else{
			m->inputs = (input *)realloc(m->inputs, sizeof(input) *(m->input_sz+1));
		}
		m->inputs[m->input_sz] = input_new_input();
		input_set_name(m->inputs[m->input_sz], input_get_name(i));
		input_set_type(m->inputs[m->input_sz], input_get_type(i));
		m->input_sz = m->input_sz+1;
	}
}

void method_set_return_type(method m, char * t){
	if(m!=NULL){
		if(m->return_type != NULL){
			free(m->return_type);
		}
		if(t != NULL){
            m->return_type = (char *)malloc(sizeof(char) * (strlen(t)+1));
            strcpy(m->return_type, t);
        }else{
            m->return_type = NULL;
        }
	}
}

char * method_get_return_type(method m){
	if(m!=NULL){
		return (m->return_type);
	}
	return NULL;
}

commands method_get_commands(method m){
	if(m!=NULL){
		return (m->definition);
	}
	return NULL;
}

void method_set_commands(method m, commands c){
	if(m!=NULL){
		m->definition = commands_copy_commands(c);
	}
}

void method_end_method(method m){
	int i = 0;
	if(m != NULL){
		if(m->name != NULL){
			free(m->name);
		}
		for(; i < m->input_sz; i++){
			input_end_input(m->inputs[i]);
		}
		if(m->return_type != NULL){
			free(m->return_type);
		}
		if(m->definition!= NULL){
			commands_end_commands(m->definition);
		}
	}
}

method method_copy_method(method m){
	method ret = NULL;
	int i = 0;
	if(m != NULL){
		ret = method_new_method();
		if(m->name != NULL){
			ret->name = (char *)malloc(sizeof(char) * (strlen(m->name) +1));
			strcpy(ret->name, m->name);
		}
		for(; i < m->input_sz; i++){
			method_add_input(ret,m->inputs[i]);
		}
		if(m->return_type != NULL){
			ret->return_type =
				(char *)malloc(sizeof(char) * (strlen(m->return_type) +1));
			strcpy(ret->return_type, m->return_type);
		}
		if(m->definition!= NULL){
			ret->definition=commands_copy_commands(m->definition);
		}
	}
	return ret;
}

int method_compare_methods(method m1, method m2)
{
	int i  = 0;
	int ret = 1;
	if(m1 != NULL && m2 != NULL){
		ret = ret && ( (m1->name == NULL && m2->name == NULL)||
			((m1->name == NULL && m2->name == NULL) ||
			(0 == strcmp(m1->name, m2->name))));
		ret = ret && ((m1->return_type == NULL && m2->return_type == NULL)||
			((m1->return_type == NULL && m2->return_type == NULL) ||
			(0 == strcmp(m1->return_type, m2->return_type))));

		ret = ret && (m1->input_sz ==  m2->input_sz);
		if (ret){
			for (; i < m1->input_sz; i++ ){
				ret = ret &&(0 == strcmp(input_get_type(m1->inputs[i]),
						input_get_type(m2->inputs[i])));
				if(! ret){
					break;
				}
			}
		}
		return ret;
	}else if(m1 == NULL && m2 == NULL){
		return ret;
	}else{
		return 0;
	}
}


