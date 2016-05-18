
#include <type.h>


header_version_t header_version_init(int version){
	header_version_t t = calloc(1,sizeof(struct header_version_st));
	t->version = int_type_init(version);
	return t;
}

void header_version_free(header_version_t t){
	assert(t);
	int_type_free(t->version);
	free(t);
}

header_version_t header_version_deserialization(char* str){
	header_version_t t  =calloc(1,sizeof(struct header_version_st));
	t->version = int_type_init_deserialization(str);
	return t;
}

int header_version_serialize(header_version_t t, char** str, int* len){
	assert(t);
	int lens = int_type_memory_len(t->version);
	char* pointer = int_type_memory_pointer(t->version);
	*len = lens;

	char* strs = calloc(1,lens);
	*str = strs;

	memcpy(strs,pointer,lens);
	strs += lens;
	return 0;
}

int header_version_value(header_version_t t){
	assert(t);
	return int_type_int_value(t->version);
}
