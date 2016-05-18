
#include <type.h>

login_request_t login_request_new(){
	login_request_t ts = calloc(1,sizeof(struct login_request_st));
	ts->header = header_type_new();
	header_type_add_key(ts->header, KEY_MESSAGE_TYPE, Message_Login_Type);
	ts->msg = msg_body_init_string("");
	return ts;
}

login_request_t login_request_init(char* uid, char* body){
	login_request_t ts = calloc(1,sizeof(struct login_request_st));
	ts->header = header_type_new();
	header_type_add_key(ts->header, KEY_MESSAGE_TYPE, Message_Login_Type);
	login_request_set_fromUid(ts,uid);
	ts->msg = msg_body_init_string(body);
	return ts;
}

void login_request_add_body(login_request_t t, char* body){
	assert(t);
	msg_body_free(t->msg);
	t->msg = msg_body_init_string(body);
}

char* login_request_get_body(login_request_t t){
	assert(t);
	return msg_body_value(t->msg);
}

void login_request_set_id(login_request_t t, char* id){
	assert(t);
	header_type_add_id(t->header,id);
}

void login_request_set_fromUid(login_request_t t, char* fromUid){
	assert(t);
	header_type_add_from_id(t->header,fromUid);
}

void login_request_set_toUid(login_request_t t, char* toUid){
	assert(t);
	header_type_add_to_uid(t->header,toUid);
}

void login_request_free(login_request_t t){
	assert(t);
	header_type_free(t->header);
	msg_body_free(t->msg);
	free(t);
}

char* login_request_get_uid(login_request_t t){
	assert(t);
	return header_type_get_from(t->header);
}

char* login_request_get_token(login_request_t t){
	assert(t);
	return msg_body_value(t->msg);
}

login_request_t login_request_deserialization(char* str){
	login_request_t ts = calloc(1,sizeof(struct login_request_st));
	ts->header = header_type_deserialization(str);
	int len = header_type_memory_len(ts->header);
	str += len;
	ts->msg = msg_body_deserialization(str);
	return ts;
}

void login_request_serialize(login_request_t t, char** str, int* len){
	assert(t);

	char* strs;
	int lens;
	header_type_serialize(t->header,&strs,&lens);

	char* bodyStr;
	int bodyLen;
	msg_body_serialize(t->msg,&bodyStr,&bodyLen);

	int total = bodyLen + lens;
	*len = total;

	char* strss = calloc(1,total);
	*str = strss;

	memcpy(strss,strs,lens);
	strss += lens;
	
	memcpy(strss,bodyStr,bodyLen);
	strss += bodyLen;

	free(strs);
	free(bodyStr);
}

char* login_request_get_key(login_request_t t, int key){
	assert(t);
	return header_type_get_key(t->header, key);
}

void login_request_test(){

	login_request_t ts = login_request_init("23423","s9df9sd9fs9df9sdf");

	login_request_set_id(ts,"324k23j4k_and_id");
	login_request_set_fromUid(ts,"23423");
	login_request_set_toUid(ts,"100043");

	char* uid = login_request_get_uid(ts);
	fprintf(stderr,"the uid is %s\n",uid);
	free(uid);

	char* token = login_request_get_token(ts);
	fprintf(stderr,"the token is %s\n",token);
	free(token);

	login_request_add_body(ts,"{{a:b},{4:4}}");

	char* str;
	int len;
	login_request_serialize(ts,&str,&len);

	login_request_t tst = login_request_deserialization(str);

	uid = login_request_get_uid(tst);
	fprintf(stderr,"the uid is %s\n",uid);
	free(uid);

	token = login_request_get_token(tst);
	fprintf(stderr,"the token is %s\n",token);
	free(token);
	
	char* body = login_request_get_body(tst);
	fprintf(stderr,"the body is %s\n",body);
	free(body);

	char* type = login_request_get_key(tst, KEY_MESSAGE_TYPE);
	if (type){
		fprintf(stderr, "the type is %s\n", type);
	}
	free(type);

	free(str);

	login_request_free(tst);
	login_request_free(ts);
}
