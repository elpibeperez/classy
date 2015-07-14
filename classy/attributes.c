#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "attributes.h"

struct sattribute{
	access attrib_access;
	char *type;
	char *name;
	char *value;
};

attribute attribute_new_attribute(){
	attribute attr = (struct sattribute *)malloc(sizeof(struct sattribute));
	attr->attrib_access = A_PRIVATE;
	attr->type = NULL;
	attr->name = NULL;
	attr->value = NULL;
    return attr;
}

access attribute_get_access(attribute attr){
    if (attr != NULL){
        return(attr->attrib_access);
    }else{
        return A_ERROR;
    }
}

void attribute_set_access(attribute attr,access accesval){
	if(attr != NULL){
		attr->attrib_access=accesval;
	}
}

char * attribute_get_type(attribute attr){
	return attr -> type;
}

void attribute_set_type(attribute attr, char *type){
	if(attr -> type != NULL) {
		free(attr -> type);
		attr->type = NULL;
	}if(NULL != type){
		attr -> type = (char *) malloc(sizeof(char) * (strlen(type) + 1));
		strcpy(attr->type, type);
	}
}

char * attribute_get_name(attribute attr){
	return attr -> name;
}

void attribute_set_name(attribute attr, char *name){
	if(attr -> name != NULL) {
		free(attr -> name);
		attr->name = NULL;
	}if(NULL != name){
		attr -> name = (char *) malloc(sizeof(char) * (strlen(name) + 1));
		strcpy(attr->name, name);
	}
}

char * attribute_get_value(attribute attr){
	return attr -> value;
}

void attribute_set_value(attribute attr, char *value){
	if(attr -> value != NULL) {
		free(attr -> value);
		attr->value = NULL;
	}if(NULL != value){
		attr -> value = (char *) malloc(sizeof(char) * (strlen(value) + 1));
		strcpy(attr->value, value);
	}
}

void attribute_end_attribute(attribute attr){
	if(NULL != attr){
		if(NULL != attr->type){
			free(attr->type);
		}
		if(NULL != attr->name){
			free(attr->name);
		}
		if(NULL != attr->value){
			free(attr->value);
		}
		free(attr);
	}
}

void attribute_show_attribute(attribute attr){
	printf("Attribute values:\n");
	switch(attr->attrib_access){
		case A_PRIVATE:
			printf("ACCESS: A_PRIVATE\n");
			break;
		case A_SET:
			printf("ACCESS: A_SET\n");
			break;
		case A_GET:
			printf("ACCESS: A_GET\n");
			break;
		default:
			printf("ACCESS: A_GET_SET\n");
			break;
	}
	if(NULL != attr->type){
		printf("TYPE: %s\n", attr->type);
	}
	if(NULL != attr->name){
		printf("NAME: %s\n", attr->name);
	}
	if(NULL != attr->value){
		printf("VALUE: %s\n", attr->value);
	}
}

int are_attributes_equal(attribute attr1, attribute attr2)
{
	int bl = 1;
	//comparing attrib_access
	if((attr1 != NULL) && (attr2 != NULL)){
        bl = (attr1->attrib_access == attr2->attrib_access);
        //comparing attrib types
        bl = (bl && ((attr1->type == attr2->type)||((attr1->type != NULL)&&(attr2->type != NULL)
            &&(0 == strcmp(attr1->type, attr2->type)))));
        //comparing attrib names
        bl = (bl && ((attr1->name == attr2->name)||((attr1->name != NULL)&&(attr2->name != NULL)
            &&(0 == strcmp(attr1->name, attr2->name)))));
        //comparing attrib values
        bl = (bl && ((attr1->value == attr2->value)||((attr1->value != NULL)&&
            (attr2->value != NULL)&&(0 == strcmp(attr1->value,attr2->value)))));
    }else if( attr1 != attr2){ //One of boths is NULL the other one is pointing somewhere else
        bl = 0;
    }//Else boths are null, but bl is true, so skip;
	return bl;
}
