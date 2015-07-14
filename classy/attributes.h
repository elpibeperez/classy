#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

typedef enum {A_PRIVATE, A_SET, A_GET, A_SET_GET, A_ERROR} access;

typedef struct sattribute *attribute;

attribute attribute_new_attribute();
access attribute_get_access(attribute attr);
void attribute_set_access(attribute attr,access accesval);
char * attribute_get_type(attribute attr);
void attribute_set_type(attribute attr, char *type);
char * attribute_get_name(attribute attr);
void attribute_set_name(attribute attr, char *name);
char * attribute_get_value(attribute attr);
void attribute_set_value(attribute attr, char *value);
void attribute_end_attribute(attribute attr);
void attribute_show_attribute(attribute attr);
int are_attributes_equal(attribute attr1, attribute attr2);

#endif
