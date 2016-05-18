
#ifndef _PROTOCAL_MESSAGE_H_
#define _PROTOCAL_MESSAGE_H_

typedef struct message_type_st{
	header_type_t header;
	msg_body_t msg;
}*message_type_t;

message_type_t message_type_init(char* id, char* from, char* to, char* body, char* type);

char* message_type_get_id(message_type_t t);
char* message_type_get_from(message_type_t t);
char* message_type_get_to(message_type_t t);
char* message_type_get_body(message_type_t t);
char* message_type_get_type(message_type_t t);

message_type_t* multi_message_type_deserialization(char* str, int len, int* temp_count);

message_type_t message_type_deserialization(char* str);
void message_type_serialize(message_type_t t, char** str, int* len);

void message_type_free(message_type_t t);

void message_type_test();

#endif