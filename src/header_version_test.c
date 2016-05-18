
#include <type.h>

void header_version_test(){
	header_version_t t = header_version_init(534234);
	int s = header_version_value(t);
	assert(s == 534234);
	header_version_free(t);

	t = header_version_init(534234);

	char* str;
	int len;
	header_version_serialize(t,&str,&len);

	header_version_t ts = header_version_deserialization(str);

	int ss = header_version_value(ts);
	assert(ss == 534234);

	header_version_free(ts);
	header_version_free(t);

}