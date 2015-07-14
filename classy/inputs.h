#ifndef INPUTS_H
#define INPUTS_H

typedef struct sinput *input;

input input_new_input();

char *input_get_name(input i);

char *input_get_type(input i);

void input_set_name(input i,char *name);

void input_set_type(input i,char *type);

void input_end_input(input i);


#endif
