
#include <type.h>

void key_value_type_test(){
	key_value_type_t t = key_value_type_init(KEY_USER_SENDER_NAME,"fsfsdfsdf");
	
	int key = key_value_type_get_key(t);
	char* value = key_value_type_get_value(t);

	fprintf(stderr,"the key is %d\n",key);
	fprintf(stderr,"the value is %s\n",value);

	char* str;
	int len;
	key_value_type_serialize(t,&str,&len);

	key_value_type_t ts = key_value_type_deserialization(str);

	int keys = key_value_type_get_key(ts);
	fprintf(stderr, "the key is %d\n", keys);

	char* values = key_value_type_get_value(ts);
	fprintf(stderr, "the values is %s\n", values);
	free(values);

	key_value_type_free(ts);
	free(str);
	free(value);

	key_value_type_free(t);
}
