

#ifndef _INT_TYPE_H
#define _INT_TYPE_H

typedef struct int_type_st{
	char n;
	char b[10];
}*int_type_t;

int_type_t int_type_init(int v);
int_type_t int_type_init_deserialization (char* str);

void int_type_free(int_type_t t);
int int_type_int_value(int_type_t t);

int int_type_memory_len(int_type_t t);
char* int_type_memory_pointer(int_type_t t);

/* return value , 0 is ok , -1 is error **/
int int_type_serialize(int_type_t t, char** str, int* len);

void init_type_test();

#endif