#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "syntactic_structure.h"


struct ssyntactic_structure{
	char *inherit;
	char **use;
	int use_sz;
	attribute *attrib;
	int attrib_sz;
	method *methods;
	int method_sz;
	char **variables;
	int variables_sz;
	char **name;
	int name_sz;
};

//typedef struct ssyntactic_structure *syntactic_structure;
syntactic_structure syntactic_structure_new_syntactic_structure()
{
	syntactic_structure ss = (struct ssyntactic_structure *)malloc(sizeof(struct ssyntactic_structure));
	ss->inherit = NULL;
	ss->use = NULL;
	ss->use_sz = 0;
	ss->attrib = NULL;
	ss->attrib_sz = 0;
	ss->methods = NULL;
	ss->method_sz = 0;
	ss->variables = NULL;
	ss->variables_sz = 0;
	ss->name = NULL;
	ss->name_sz = 0;
	return ss;
}

char *syntactic_structure_get_inherit(syntactic_structure s){
	return s->inherit;
}

void syntactic_structure_set_inherit(syntactic_structure s, char *inherit){
	if(s != NULL) {
		if (s->inherit != NULL) {
			free(s->inherit);
		}
		if(inherit != NULL) {
			s->inherit = (char *) calloc(sizeof(char), strlen(inherit) + 1);
			strcpy(s->inherit, inherit);
		}else{
			s->inherit = NULL;
		}
	}
}

char *syntactic_structure_get_use(syntactic_structure s, int i){
	char * ret = NULL;
	if(s != NULL) {
		if (0 <= i && i < s->use_sz) {
			ret = s->use[i];
		}
	}
	return ret;
}

void syntactic_structure_add_use(syntactic_structure s, char *use){
	if(s != NULL) {
		if (s->use == NULL) {
			s->use = calloc(sizeof(char *), 1);
		} else {
			s->use = realloc(s->use, sizeof(char *) * (s->use_sz + 1));
		}
		if(use != NULL) {
			s->use[s->use_sz] = (char *) calloc(sizeof(char), strlen(use) + 1);
			strcpy((s->use)[(s->use_sz)], use);
			s->use_sz = s->use_sz + 1;
		}
	}
}

int syntactic_structure_get_use_id(syntactic_structure s, char *use){
	int i = 0;
	for(; i < s->use_sz; i++){
		if ( 0 == strcmp(s->use[i], use)){
			break;
		}
	}
	if( i == s->use_sz){
		i = -1;
	}
	return i;
}

int syntactic_structure_get_use_size(syntactic_structure s){
	int ret = -1;
	if(s != NULL) {
		ret = s->use_sz;
	}
	return ret;
}

attribute syntactic_structure_get_attrib(syntactic_structure s, int i){
	if(0<= i && s != NULL && i < s->attrib_sz  ){
		return s->attrib[i];
	}else{
		return NULL;
	}
}
void syntactic_structure_add_attrib(syntactic_structure s, attribute attrib ){
	if(s != NULL && attrib != NULL) {
		if (s->attrib == NULL) {
			s->attrib = (attribute *) calloc(sizeof(attribute), 1);
		} else {
			s->attrib = realloc(s->attrib, sizeof(attribute) * (s->attrib_sz + 1));
		}
		s->attrib[s->attrib_sz] = attribute_new_attribute();
		attribute_set_access(s->attrib[s->attrib_sz], attribute_get_access(attrib));
		attribute_set_type(s->attrib[s->attrib_sz], attribute_get_type(attrib));
		attribute_set_name(s->attrib[s->attrib_sz], attribute_get_name(attrib));
		attribute_set_value(s->attrib[s->attrib_sz], attribute_get_value(attrib));
		s->attrib_sz = s->attrib_sz + 1;
	}
}
int syntactic_structure_get_attrib_id(syntactic_structure s, attribute attrib) {
	int i = 0;
	if (s != NULL){
		for (; i < s->attrib_sz; i++) {
			if (are_attributes_equal(s->attrib[i], attrib)) {
				break;
			}
		}
		if (i == s->attrib_sz) {
			i = -1;
		}
	}else{
		i = -1;
	}
	return i;
}
int syntactic_structure_get_attrib_id_by_name(syntactic_structure s, char *name) {
	int i = 0;
	if (s != NULL && name != NULL) {
		for (; i < s->attrib_sz; i++) {
			if (0 == strcmp(attribute_get_name(s->attrib[i]), name)) {
				break;
			}
		}
		if (i == s->attrib_sz) {
			i = -1;
		}
	}else{
		i = -1;
	}
	return i;
}


int syntactic_structure_get_attrib_size(syntactic_structure s){
	if(s != NULL) {
		return s->attrib_sz;
	}
	return -1;
}


method syntactic_structure_get_method(syntactic_structure s, int i){
	if(s != NULL){
		if(0<= i && i < s->method_sz ){
			return s->methods[i];
		}
	}
	return NULL;
}
void syntactic_structure_add_method(syntactic_structure s, method m){
	if(s != NULL && m != NULL) {
		if (s->methods == NULL) {
			s->methods = (method *) malloc(sizeof(method));
		} else {
			s->methods = (method *) realloc(s->methods, sizeof(method) * (s->method_sz + 1));
		}
		s->methods[s->method_sz] = method_copy_method(m);
		s->method_sz = s->method_sz + 1;
	}
}
int syntactic_structure_get_method_id(syntactic_structure s, method m){
	int i = 0;
	if(s!=NULL&&m != NULL){
        for(; i < s->method_sz; i++){

            if ((s->methods[i] != NULL) && (method_compare_methods((s->methods)[i], m))){
                break;
            }
        }
        if( i == s->method_sz){
            i = -1;
        }
    }else{
		i = -1;
	}
	return i;
}
int syntactic_structure_get_method_size(syntactic_structure s) {
	if (s != NULL){
		return s->method_sz;
	}
	return -1;
}

char *syntactic_structure_get_name(syntactic_structure s, int i){
	if(0<= i && i < s->name_sz ){
		return s->name[i];
	}else{
		return NULL;
	}

}
void syntactic_structure_add_name(syntactic_structure s, char *name){
	if(s->name == NULL){
		s->name = calloc(sizeof(char *),1);
	}else{
		s->name=realloc(s->name,sizeof(char **) * (s->name_sz +1));
	}
	s->name[s->name_sz] = (char *)calloc(sizeof(char), strlen(name)+1);
	strcpy(s->name[s->attrib_sz],name);
	s->name_sz = s->name_sz +1;
}
int syntactic_structure_get_name_id(syntactic_structure s, char *name){
	int i = 0;
	for(; i < s->name_sz; i++){
		if ( 0 == strcmp(method_get_name(s->methods[i]), name)){
			break;
		}
	}
	if( i == s->name_sz){
		i = -1;
	}
	return i;
}
int syntactic_structure_get_name_size(syntactic_structure s){
	return s->name_sz;
}

void syntactic_structure_end_syntactic_structure(syntactic_structure s){
	int i;
	if(s != NULL){
		if(s->inherit != NULL){
			free(s->inherit);
		}
		if(s->use!= NULL && s->use_sz > 0){
			for(i = 0; i < s->use_sz; i++){
				if(NULL != s->use[i]){
					free(s->use[i]);
				}
			}
			free(s->use);
		}
		if(s->attrib!= NULL && s->attrib_sz> 0){
			for(i = 0; i < s->attrib_sz; i++){
				if(NULL != s->attrib[i]){
					attribute_end_attribute(s->attrib[i]);
				}
			}
			free(s->use);
		}
		if(s->methods!= NULL && s->method_sz>0){
			for(i = 0; i < s->method_sz; i++){
				if(NULL != s->methods[i]){
					method_end_method(s->methods[i]);
				}
			}
		}
	}
}

