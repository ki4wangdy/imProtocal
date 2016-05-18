
#include <type.h>

key_value_array_type_t key_value_array_type_init(){
	key_value_array_type_t ts = calloc(1,sizeof(struct key_value_array_type_st));
	ts->n = '0';
	ts->types = NULL;
	return ts;
}

void key_value_array_type_free(key_value_array_type_t t){
	assert(t);
	int size = (int)t->n - 48;
	int i=0;
	if (size > 0){
		for (; i < size; i++){
			key_value_type_free(t->types[i]);
		}
		free(t->types);
	}
	free(t);
}

void key_value_array_type_print_values(key_value_array_type_t t){
	assert(t);
	int size = (int)t->n - 48;
	int i=0;
	for(;i<size;i++){
		int key = key_value_type_get_key(t->types[i]);
		char* value = key_value_type_get_value(t->types[i]);
		fprintf(stderr,"the key is %d,",key);
		fprintf(stderr,"the value is %s\n",value);
		free(value);
	}
}

void key_value_array_type_add_value(key_value_array_type_t t, int key, char* value){
	assert(t);
	int size = (int)t->n - 48;
	assert(size < 9);

	key_value_type_t ts = key_value_type_init(key,value);
	t->types = realloc(t->types,(size+1)*sizeof(struct key_value_type_st));
	t->types[size] = ts;
	t->n = (char)((size + 1) + 48 );
}

char* key_value_array_type_get_value(key_value_array_type_t t, int key){
	assert(t);
	int size = (int)t->n - 48;
	int i=0;
	for(;i<size;i++){
		int keys = key_value_type_get_key(t->types[i]);
		if(key == keys){
			return key_value_type_get_value(t->types[i]);
		}
	}
	return NULL;
}

key_value_array_type_t key_value_array_type_deserialization(char* str){
	key_value_array_type_t ts = calloc(1,sizeof(struct key_value_array_type_st));
	ts->n = *str;
	str += sizeof(char);
	
	int size = (int)ts->n - 48;
	if (size <= 0){
		return ts;
	}

	ts->types = calloc(1, size*sizeof(struct key_value_type_st));

	int i=0;
	int lens = 0;
	for(;i<size;i++){
		ts->types[i] = key_value_type_deserialization(str);
		key_value_type_memory_length(ts->types[i],&lens);
		str += lens;
	}
	return ts;
}

char* key_value_array_type_memory_pointer(key_value_array_type_t t){
	char* str;
	int len;
	key_value_array_type_serialize(t,&str,&len);
	return str;
}

int key_value_array_type_memory_len(key_value_array_type_t t){
	char* str;
	int len;
	key_value_array_type_serialize(t,&str,&len);
	free(str);
	return len;
}

int key_value_array_type_serialize(key_value_array_type_t t, char** str, int* len){
	assert(t);
	int total = sizeof(char);
	int size = (int)t->n - 48;
	int i=0;
	int memoryLen = 0;
	for(;i<size;i++){
		key_value_type_memory_length(t->types[i],&memoryLen);
		total += memoryLen;
	}
	*len = total;

	char* strs = calloc(1,total+sizeof(char));
	*str = strs;

	*strs = t->n;
	strs += sizeof(char);

	char* memory = NULL;
	memoryLen = 0;
	for(i=0;i<size;i++){
		key_value_type_serialize(t->types[i],&memory,&memoryLen);
		memcpy(strs,memory,memoryLen);
		strs += memoryLen;
		free(memory);
	}
	return 0;
}

