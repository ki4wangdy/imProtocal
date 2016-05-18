
#include <type.h>


void key_value_array_type_test(){
	key_value_array_type_t ts = key_value_array_type_init();

	key_value_array_type_add_value(ts,0,"ab");
	key_value_array_type_add_value(ts,1,"abc");

	key_value_array_type_print_values(ts);

	char* str;
	int len;
	key_value_array_type_serialize(ts,&str,&len);
	key_value_array_type_t tss = key_value_array_type_deserialization(str);
	key_value_array_type_print_values(tss);

	int lens = key_value_array_type_memory_len(tss);
	fprintf(stderr, "the len is %d\n", lens);

	char* strs = key_value_array_type_memory_pointer(tss);
	fprintf(stderr, "the strs is %s\n", strs);

	free(strs);
	free(str);
	key_value_array_type_free(tss);
	key_value_array_type_free(ts);
}