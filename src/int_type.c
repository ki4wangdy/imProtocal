
#include <type.h>

int_type_t int_type_init(int v){
	int_type_t t = calloc(1,sizeof(struct int_type_st));
	snprintf(t->b,10,"%d",v);
	int size = strlen(t->b);
	char b[2] = "";
	snprintf(b,2,"%d",size);
	t->n = b[0];
	return t;
}

int_type_t int_type_init_deserialization(char* str){
	int_type_t s = calloc(1,sizeof(struct int_type_st));
	s->n = *str;
	str ++ ;
	int size = (int)s->n - 48;
	memcpy(s->b,(const void*)str,size);
	return s;
}

int int_type_int_value(int_type_t t){
	return atoi(t->b);
}

void int_type_free(int_type_t t){
	free(t);
}

/* return value , 0 is ok , -1 is error **/
int int_type_serialize(int_type_t t, char** str, int* len){
	int size = (int)t->n - 48;
	char* r = calloc(1,size+sizeof(char));
	*str = r;
	*len = size + sizeof(char);
	
	*r = t->n;
	r++;

	memcpy(r,(const void*)t->b,size);
	return 0;
}

int int_type_memory_len(int_type_t t){
	char s = t->n;
	int size = (int)s - 48;
	return sizeof(char) + size;
}

char* int_type_memory_pointer(int_type_t t){
	int size = (int)t->n - 48;
	char* r = calloc(1,size+sizeof(char));
	char* str = r;
	*r = t->n;
	r++;
	memcpy(r,(const void*)t->b,size);
	return str;
}



