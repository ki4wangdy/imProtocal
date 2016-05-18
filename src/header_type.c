
#include <type.h>

header_type_t header_type_init(char* id, char* from, char* to){
	header_type_t t = calloc(1,sizeof(struct header_type_st));
	t->id = str_type_init_string(id);
	t->from = str_type_init_string(from);
	t->to = str_type_init_string(to);
	t->key_value = key_value_array_type_init();
	return t;
}

header_type_t header_type_new(){
	header_type_t t = calloc(1,sizeof(struct header_type_st));
	t->key_value = key_value_array_type_init();
	return t;
}

header_type_t header_type_deserialization(char* str){

	header_type_t t = calloc(1,sizeof(struct header_type_st));
	t->id = str_type_deserialization(str);
	if (t->id == NULL){
		free(t);
		return NULL;
	}
	int len = str_type_memory_len(t->id);
	str += len;

	t->from = str_type_deserialization(str);
	len = str_type_memory_len(t->from);
	str += len;

	t->to = str_type_deserialization(str);
	len = str_type_memory_len(t->to);
	str += len;

 	t->key_value = key_value_array_type_deserialization(str);
	len = key_value_array_type_memory_len(t->key_value);
	str += len;

	return t;
}

void header_type_free(header_type_t t){
	assert(t);
	str_type_free(t->id);
	str_type_free(t->from);
	str_type_free(t->to);
	key_value_array_type_free(t->key_value);
	free(t);
}

char* header_type_get_key(header_type_t t, int key){
	assert(t);
	return key_value_array_type_get_value(t->key_value, key);
}

void header_type_add_key(header_type_t t, int key, char* value){
	assert(t);
	key_value_array_type_add_value(t->key_value, key, value);
}

void header_type_add_id(header_type_t t, char* id){
	header_type_set_id(t, id);
}

void header_type_add_from_id(header_type_t t, char* fromUid){
	header_type_set_from(t, fromUid);
}

void header_type_add_to_uid(header_type_t t, char* uid){
	header_type_set_to(t, uid);
}

char* header_type_get_from(header_type_t t){
	assert(t);
	return str_type_str_value(t->from);
}

char* header_type_get_to(header_type_t t){
	assert(t);
	return str_type_str_value(t->to);
}

char* header_type_get_id(header_type_t t){
	assert(t);
	return str_type_str_value(t->id);
}

char* header_type_memory_pointer(header_type_t t){
	assert(t);
	char* str;
	int len;
	header_type_serialize(t,&str,&len);
	return str;
}

int header_type_memory_len(header_type_t t){
	assert(t);
	char* str;
	int len;
	header_type_serialize(t,&str,&len);
	free(str);
	return len;
}

void header_type_set_id(header_type_t t, char* id){
	assert(t);
	if(t->id){
		str_type_free(t->id);
	}
	t->id = str_type_init_string(id);
}

void header_type_set_from(header_type_t t, char* from){
	assert(t);
	if(t->from){
		str_type_free(t->from);
	}
	t->from = str_type_init_string(from);
}

void header_type_set_to(header_type_t t, char* to){
	assert(t);
	if(t->to){
		str_type_free(t->to);
	}
	t->to = str_type_init_string(to);
}


int header_type_serialize(header_type_t t, char** str, int* len){
	assert(t);
	char* idStr;
	int idLen;
	str_type_serialize(t->id,&idStr,&idLen);

	char* fromStr;
	int fromLen;
	str_type_serialize(t->from,&fromStr,&fromLen);

	char* toStr;
	int toLen;
	str_type_serialize(t->to,&toStr,&toLen);

	char* arrayStr;
	int arrayLen;
	key_value_array_type_serialize(t->key_value, &arrayStr, &arrayLen);

	int total = idLen+fromLen+toLen+arrayLen;
	char* s = calloc(1,total);
	*str = s;
	*len = total;
	
	memcpy(s,idStr,idLen);
	s += idLen;
	free(idStr);

	memcpy(s,fromStr,fromLen);
	s += fromLen;
	free(fromStr);

	memcpy(s,toStr,toLen);
	s += toLen;
	free(toStr);

	memcpy(s, arrayStr, arrayLen);
	s += arrayLen;
	free(arrayStr);

	return 0;
}
