
#ifndef _PROTOCAL_FRIEND_H_
#define _PROTOCAL_FRIEND_H_

typedef message_type_t friend_type_t;

#define friend_type_init message_type_init
#define friend_type_free message_type_free

//#define friend_type_get_header message_type_get_header
#define friend_type_get_body	message_type_get_body

#define friend_type_deserialization message_type_deserialization
#define friend_type_serialize message_type_serialize

void frined_type_test();

#endif