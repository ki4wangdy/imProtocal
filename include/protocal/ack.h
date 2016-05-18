
#ifndef _PROTOCAL_ACK_H_
#define _PROTOCAL_ACK_H_

typedef message_type_t ack_type_t;

#define ack_type_init message_type_init
#define ack_type_free message_type_free

//#define ack_type_get_header message_type_get_header
#define ack_type_get_body	message_type_get_body

#define ack_type_deserialization message_type_deserialization
#define ack_type_serialize message_type_serialize

void ack_type_test();

#endif