
#ifndef _PROTOCAL_PANG_H_
#define _PROTOCAL_PANG_H_

typedef msg_body_t pang_type_t;

#define pang_type_init message_type_init
#define pang_type_free message_type_free

//#define pang_type_get_header message_type_get_header
#define pang_type_get_body	message_type_get_body

#define pang_type_deserialization message_type_deserialization
#define pang_type_serialize message_type_serialize

#endif