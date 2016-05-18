
#ifndef _KEY_VALUE_TYPE_H_
#define _KEY_VALUE_TYPE_H_

typedef struct key_value_type_st{
	int_type_t key;
	str_type_t value;
}*key_value_type_t;

#define KEY_VERSION				0x01
#define KEY_MESSAGE_TYPE		0x02
#define KEY_MESSAGE_TIME		0x04

#define KEY_USER_SENDER_NAME	0x010

key_value_type_t key_value_type_init(int key, char* value);
void key_value_type_free(key_value_type_t t);

int key_value_type_get_key(key_value_type_t t);
char* key_value_type_get_value(key_value_type_t t);

key_value_type_t key_value_type_deserialization(char*);
int key_value_type_serialize(key_value_type_t t,char** str, int* len);

void key_value_type_memory_pointer(key_value_type_t t, char** str);
void key_value_type_memory_length(key_value_type_t t, int* len);

void key_value_type_test();

#endif