#ifndef METHODS_H
#define METHODS_H
#include "commands.h"
#include "inputs.h"

typedef struct smethod *method;

method method_new_method();

char *method_get_name(method m);

void method_set_name(method m, char * name);

input method_get_input_by_id(method m, int id);

int method_get_input_id_by_name(method m, char * name);

int method_get_input_size(method m);

void method_add_input(method m, input i);

void method_set_return_type(method m, char * t);

char * method_get_return_type(method m);

commands method_get_commands(method m);

void method_set_commands(method m, commands c);

method method_copy_method(method m);

void method_end_method(method m);

int method_compare_methods(method m1, method m2);
#endif
