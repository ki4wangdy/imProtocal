

#ifndef _STR_ARRAY_TYPE_H
#define _STR_ARRAY_TYPE_H

typedef struct str_array_type_st{
	char n;
	char size[10];
	str_type_t* str_array_pointer;
	int currentAllocSize;
}*str_array_type_t;

#define DEFAUL_FIVE_CAPACITY 5

// default capacity is 5
str_array_type_t str_array_type_deserialization(char* str);
str_array_type_t str_array_type_new(int capacity);
void str_array_type_free(str_array_type_t t);

// 0 is ok , and -1 is error
int str_array_type_add_string(str_array_type_t t, char* str);
int str_array_type_add_str(str_array_type_t t, char* str, int len);

void str_array_type_print_strings(str_array_type_t t);

char* str_array_type_memory_pointer(str_array_type_t t);
int str_array_type_memory_length(str_array_type_t t);

int str_array_type_array_size(str_array_type_t t);

void str_array_type_test();

#endif