
#ifndef _STR_TYPE_H
#define _STR_TYPE_H

typedef struct str_type_st{
	char n;
	char size[10];
	char* str;
}*str_type_t;

str_type_t str_type_init(char* str, int len);
str_type_t str_type_init_string(char* str);
void str_type_free(str_type_t str);

void str_type_set_string(str_type_t t, char* str);

// need to be free
char* str_type_str_value(str_type_t t);

// the string's size
int str_type_str_len(str_type_t t);

char* str_type_memory_pointer(str_type_t t);
int str_type_memory_len(str_type_t t);

str_type_t str_type_deserialization(char* str);
int str_type_serialize(str_type_t t, char** str, int* len);

void str_type_test();

#endif