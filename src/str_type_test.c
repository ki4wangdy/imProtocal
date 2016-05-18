
#include <type.h>

// str_type_t str_type_init(char* str, int len);

// str_type_t str_type_deserialization(char* str, int len);
// int str_type_serialize(str_type_t t, char** str, int* len);


void str_type_test(){
	str_type_t t= str_type_init_string("<a sfdf=\"sdfsd\"><#?><Msdfsdf,.//.,</a>");

	char* str = str_type_memory_pointer(t);
	int len = str_type_memory_len(t);
	fprintf(stderr,"memory's lenth is :%d\n",len);

	str_type_t sf = str_type_deserialization(str);
	char* value = str_type_str_value(t);
	fprintf(stderr,"the string is :%s\n",value);
	free(value);

	len = str_type_str_len(t);
	fprintf(stderr,"the string's sizes is :%d\n",len);

	free(str);
	str_type_free(sf);
	str_type_free(t);
}