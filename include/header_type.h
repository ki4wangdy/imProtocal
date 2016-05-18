
#ifndef _HEADER_TYPE_H_
#define _HEADER_TYPE_H_

typedef struct header_type_st{
	str_type_t id;
	str_type_t from;
	str_type_t to;
	key_value_array_type_t key_value;
}*header_type_t;

#define KEY_MESSAGE_VERSION		0x01
#define KEY_MESSAGE_TYPE		0x02
#define KEY_MESSAGE_TIME		0x04
#define KEY_MESSAGE_ASK			0x08

#define KEY_USER_SENDER_NAME	0x010
#define KEY_USER_ICON_URL		0x011

#define KEY_MESSAGE_PING		0x100
#define KEY_MESSAGE_PANG		0x101

#define Message_Login_Type				"1"
#define Message_Ack_Type				"2"
#define Message_Ping_Type				"3"
#define Message_Pang_Type				"4"
#define Message_Friend_Add_Type			"5"
#define Message_Friend_Agree_Type		"6"
#define Message_Friend_Reply_Type		"7"
#define Message_Message_Type			"8"

#define Message_Login_Type_Int			1
#define Message_Ack_Type_Int			2
#define Message_Ping_Type_Int			3
#define Message_Pang_Type_Int			4
#define Message_Friend_Add_Type_Int		5
#define Message_Friend_Agree_Type_Int	6
#define Message_Friend_Reply_Int		7
#define Message_Message_Type_Int		8

header_type_t header_type_init(char* id, char* from, char* to);
header_type_t header_type_new();

void header_type_free(header_type_t t);

header_type_t header_type_deserialization(char*);

char* header_type_get_from(header_type_t t);
char* header_type_get_to(header_type_t t);
char* header_type_get_id(header_type_t t);

void header_type_set_id(header_type_t t, char* id);
void header_type_set_from(header_type_t t, char* from);
void header_type_set_to(header_type_t t, char* to);

void header_type_add_key(header_type_t t, int key, char* value);
char* header_type_get_key(header_type_t t, int key);

char* header_type_memory_pointer(header_type_t t);
int header_type_memory_len(header_type_t t);

int header_type_serialize(header_type_t t, char** str, int* len);

void header_type_test();

#endif