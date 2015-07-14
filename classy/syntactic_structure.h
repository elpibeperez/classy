#ifndef SYNTACTIC_STRUCTRE_H
#define SYNTACTIC_STRUCTRE_H

#include "attributes.h"
#include "methods.h"

typedef struct ssyntactic_structure *syntactic_structure;

syntactic_structure syntactic_structure_new_syntactic_structure();

char *syntactic_structure_get_inherit(syntactic_structure s);
void syntactic_structure_set_inherit(syntactic_structure s, char *inherit);

char *syntactic_structure_get_use(syntactic_structure s, int i);
void syntactic_structure_add_use(syntactic_structure s, char *use);
int syntactic_structure_get_use_id(syntactic_structure s, char *use);
int syntactic_structure_get_use_size(syntactic_structure s);

attribute syntactic_structure_get_attrib(syntactic_structure s, int i);
void syntactic_structure_add_attrib(syntactic_structure s, attribute);
int syntactic_structure_get_attrib_id(syntactic_structure s, attribute);
int syntactic_structure_get_attrib_id_by_name(syntactic_structure s, char *name);
int syntactic_structure_get_attrib_size(syntactic_structure s);

method syntactic_structure_get_method(syntactic_structure s, int i);
void syntactic_structure_add_method(syntactic_structure s, method m);
int syntactic_structure_get_method_id(syntactic_structure s, method m);
int syntactic_structure_get_method_size(syntactic_structure s);


char *syntactic_structure_get_name(syntactic_structure s, int i);
void syntactic_structure_add_name(syntactic_structure s, char *name);
int syntactic_structure_get_name_id(syntactic_structure s, char *name);
int syntactic_structure_get_name_size(syntactic_structure s);

void syntactic_structure_end_syntactic_structure(syntactic_structure s);

#endif
