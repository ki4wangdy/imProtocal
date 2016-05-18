
#ifndef _LOGIN_REQUEST_H_
#define _LOGIN_REQUEST_H_

typedef struct login_request_st{
	header_type_t header;
	msg_body_t msg;
}*login_request_t;

login_request_t login_request_init(char* uid, char* body);
void login_request_free(login_request_t t);

void login_request_set_id(login_request_t t, char* id);
void login_request_set_fromUid(login_request_t t, char* fromUid);
void login_request_set_toUid(login_request_t t, char* toUid);

char* login_request_get_uid(login_request_t t);
char* login_request_get_token(login_request_t t);

void login_request_add_body(login_request_t t, char* body);
char* login_request_get_body(login_request_t t);

char* login_request_get_key(login_request_t t, int key);

login_request_t login_request_deserialization(char* str);
void login_request_serialize(login_request_t t, char** str, int* len);

void login_request_test();

#endif