
#ifndef _KEY_VALUE_ARRAY_TYPE_H_
#define _KEY_VALUE_ARRAY_TYPE_H_

typedef struct key_value_array_type_st{
	char n;
	key_value_type_t* types;
}*key_value_array_type_t;

key_value_array_type_t key_value_array_type_init();
void key_value_array_type_free(key_value_array_type_t t);

void key_value_array_type_print_values(key_value_array_type_t t);

void key_value_array_type_add_value(key_value_array_type_t t, int key, char* value);
char* key_value_array_type_get_value(key_value_array_type_t t, int key);

key_value_array_type_t key_value_array_type_deserialization(char* str);

char* key_value_array_type_memory_pointer(key_value_array_type_t t);
int key_value_array_type_memory_len(key_value_array_type_t t);

int key_value_array_type_serialize(key_value_array_type_t t, char** str, int* len);

void key_value_array_type_test();

#endif