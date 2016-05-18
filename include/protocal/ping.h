
#ifndef _PROTOCAL_PING_H_
#define _PROTOCAL_PING_H_

typedef msg_body_t ping_type_t;

#define ping_type_init message_type_init
#define ping_type_free message_type_free

//#define ping_type_get_header message_type_get_header
#define ping_type_get_body	message_type_get_body

#define ping_type_deserialization message_type_deserialization
#define ping_type_serialize message_type_serialize

#endif