
#include <type.h>

static void _header_type_test1(){
	header_type_t t = header_type_init("w34wsdfs", "10004", "10006");

	char* id = header_type_get_id(t);
	char* from = header_type_get_from(t);
	char* to = header_type_get_to(t);

	char* str = header_type_memory_pointer(t);
	int len = header_type_memory_len(t);
	fprintf(stderr, "the memory's len is %d:\n", len);

	header_type_t ts = header_type_deserialization(str);

	char* idid = header_type_get_id(ts);
	char* fromfrom = header_type_get_from(ts);
	char* toto = header_type_get_to(ts);

	fprintf(stderr, "the idid is %s\n", idid);
	fprintf(stderr, "the fromfrom is %s\n", fromfrom);
	fprintf(stderr, "the toto is %s\n", toto);

	free(idid);
	free(fromfrom);
	free(toto);
 	free(str);
 
 	header_type_free(ts);

	free(id);
	free(from);
	free(to);

	header_type_free(t);
}

static void _header_type_test2(){
	header_type_t t = header_type_init("w34wsdfs", "10004", "10006");

	header_type_add_key(t, KEY_USER_SENDER_NAME, "ki");
	header_type_add_key(t, KEY_MESSAGE_TYPE, "login");
	header_type_add_key(t, KEY_MESSAGE_TIME, "32423423432");
	header_type_add_key(t, KEY_MESSAGE_VERSION, "1.0");

	char* str;
	int len;
	header_type_serialize(t, &str, &len);
	header_type_free(t);

	header_type_t ts = header_type_deserialization(str);

	char* senderName = header_type_get_key(t, KEY_USER_SENDER_NAME);
	char* msgType = header_type_get_key(t, KEY_MESSAGE_TYPE);
	char* msgTime = header_type_get_key(t, KEY_MESSAGE_TIME);
	char* msgVersion = header_type_get_key(t, KEY_MESSAGE_VERSION);

	fprintf(stderr, "the senderName is %s\n", senderName);
	fprintf(stderr, "the msgTye is %s\n", msgType);
	fprintf(stderr, "the msgTime is %s\n", msgTime);
	fprintf(stderr, "the msgVersion is %s\n", msgVersion);

	free(senderName);
	free(msgTime);
	free(msgType);
	free(msgVersion);

	free(str);
	header_type_free(ts);
}

void header_type_test(){
	_header_type_test1();
	_header_type_test2();
}