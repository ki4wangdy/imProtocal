
#include <type.h>

key_value_type_t key_value_type_init(int key, char* value){
	key_value_type_t t = calloc(1,sizeof(struct key_value_type_st));
	t->key = int_type_init(key);
	t->value = str_type_init_string(value);
	return t;
}

void key_value_type_free(key_value_type_t t){
	assert(t);
	int_type_free(t->key);
	str_type_free(t->value);
	free(t);
}

int key_value_type_get_key(key_value_type_t t){
	assert(t);
	return int_type_int_value(t->key);
}

char* key_value_type_get_value(key_value_type_t t){
	assert(t);
	return str_type_str_value(t->value);
}

key_value_type_t key_value_type_deserialization(char* t){
	int_type_t key = int_type_init_deserialization(t);
	key_value_type_t ts = calloc(1,sizeof(struct key_value_type_st));
	ts->key = key;

	int len = int_type_memory_len(key);
	t += len;

	str_type_t value = str_type_deserialization(t);
	len = str_type_memory_len(value);
	ts->value = value;
	t += len;

	return ts;
}

int key_value_type_serialize(key_value_type_t t, char** str, int* len){
	assert(t);
	char* key;
	int keyLen;
	int_type_serialize(t->key,&key,&keyLen);	

	char* value;
	int valueLen;
	str_type_serialize(t->value,&value,&valueLen);
	
	int total = keyLen + valueLen;
	char* strs = calloc(1,total);
	*str = strs;
	*len = total;

	memcpy(strs,key,keyLen);
	strs += keyLen;

	memcpy(strs,value,valueLen);
	strs  += valueLen;

	free(key);
	free(value);

	return 0;
}

void key_value_type_memory_pointer(key_value_type_t t, char** str){
	char* strs;
	int lens;
	key_value_type_serialize(t,&strs,&lens);
	*str  = strs;
}

void key_value_type_memory_length(key_value_type_t t, int* len){
	char* strs;
	int lens;
	key_value_type_serialize(t,&strs,&lens);
	*len = lens;
	free(strs);
}

