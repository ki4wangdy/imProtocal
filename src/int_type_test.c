
#include <type.h>

void init_type_test(){
	int_type_t t = int_type_init(-429496729);

	char* str = NULL;
	int len = 0;
	int_type_serialize(t,&str,&len);

	int_type_t sf = int_type_init_deserialization(str);
	int value = int_type_int_value(sf);
	fprintf(stderr,"%d\n",value);

	free(str);
	int_type_free(sf);
	int_type_free(t);
}

