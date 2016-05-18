
#include <type.h>

str_type_t str_type_init_string(char* str){
	str_type_t st = calloc(1,sizeof(struct str_type_st));
	
	int size = strlen(str);
	snprintf(st->size,10,"%d",size);

	int l = strlen(st->size);
	st->n = (char)(l+ 48);

	char* s = calloc(1,size);
	memcpy(s,(const void*)str,size);
	st->str =s;

	return st;
}

void str_type_set_string(str_type_t t, char* str){
	assert(t);
	if(t->str){
		free(t->str);
		memset(t->size,0,10);
	}

	int size = strlen(str);
	snprintf(t->size,10,"%d",size);

	int l = strlen(t->size);
	t->n = (char)(l+ 48);

	char* s = calloc(1,size);
	memcpy(s,(const void*)str,size);
	t->str = s;
}

str_type_t str_type_init(char* str, int len){
	str_type_t st = calloc(1,sizeof(struct str_type_st));

	int size = len;
	char* s = calloc(1,size);
	memcpy(s,(const void*)str,size);
	st->str =s;

	snprintf(st->size,10,"%d",size);

	int n = strlen(st->size);
	st->n = (char)(n + 48);
	return st;
}

void str_type_free(str_type_t str){
	free(str->str);
	free(str);
}

char* str_type_str_value(str_type_t t){
	int size = atoi(t->size);
	char* str = calloc(1,size+1);
	memcpy(str,(const void*)t->str,size);
	return str;
}

int str_type_str_len(str_type_t t){
	return atoi(t->size);
}

char* str_type_memory_pointer(str_type_t t){
	char* str;
	int len;
	str_type_serialize(t,&str,&len);
	return str;
}

int str_type_memory_len(str_type_t t){
	char* str;
	int len;
	str_type_serialize(t,&str,&len);
	free(str);
	return len;
}

str_type_t str_type_deserialization(char* str){
	str_type_t s = calloc(1,sizeof(struct str_type_st));
	s->n = *str++;

	int size = (int)s->n - 48;
	if (size <= 0 || size >= 10){
		free(s);
		return NULL;
	}

	memcpy(s->size,str,size);
	str += size;

	size = atoi(s->size);
	s->str = calloc(1,size);
	memcpy(s->str,(const void*)str,size);
	str += size;

	return s;
}

int str_type_serialize(str_type_t t, char** str, int* len){
	
	int size = (int)t->n - 48;
	int strLen = atoi(t->size);

	char* s = calloc(1,sizeof(char)+size+strLen);
	*str = s;
	*len = sizeof(char)+size+strLen;

	// 1
	*s = t->n;
	s++;

	// 2
	memcpy(s,(const void*)t->size,size);
	s += size;

	// 3
	memcpy(s,(const void*)t->str,strLen);
	return 0;
}
