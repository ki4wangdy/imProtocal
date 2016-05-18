
#include <type.h>

void frined_type_test(){
	friend_type_t t = friend_type_init("","","","",Message_Friend_Add_Type);

	header_type_t header = friend_type_get_header(t);
	msg_body_t body = friend_type_get_body(t);

	header_type_add_key(header, KEY_USER_SENDER_NAME, "ki");
	header_type_add_key(header, KEY_MESSAGE_TYPE, Message_Friend_Add_Type);
	header_type_set_id(header, "34dfsd");
	header_type_set_to(header, "3444");
	header_type_set_from(header, "10004");

	msg_body_set_string(body, "body");

	char* str;
	int len;
	friend_type_serialize(t, &str, &len);

	friend_type_t ts = friend_type_deserialization(str);

	char* id = header_type_get_id(ts->header);
	char* to = header_type_get_to(ts->header);
	char* fr = header_type_get_from(ts->header);

	fprintf(stderr, "the id is %s\n", id);
	free(id);

	fprintf(stderr, "the to is %s\n", to);
	free(to);

	fprintf(stderr, "the from is %s\n", fr);
	free(fr);

	char* bodys = msg_body_value(ts->msg);
	fprintf(stderr, "the body is %s\n", bodys);
	free(bodys);

	free(str);

	friend_type_free(ts);
	friend_type_free(t);
}

