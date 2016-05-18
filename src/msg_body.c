
#include <type.h>

void msg_body_test(){
	msg_body_t t = msg_body_init_string("adfsdfsdf");

	char* str = msg_body_value(t);
	fprintf(stderr, "the body is %s\n", str);
	free(str);

	char* strs;
	int len;
	msg_body_serialize(t, &strs, &len);

	fprintf(stderr, "the len is %d\n", len);

	msg_body_t ts = msg_body_deserialization(strs);

	char* value = msg_body_value(ts);
	fprintf(stderr, "the value is %s\n", value);
	free(value);

	msg_body_free(ts);
	msg_body_free(t);
}
