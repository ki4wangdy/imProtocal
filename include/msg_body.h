
#ifndef _MSG_BODY_H_
#define _MSG_BODY_H_

typedef struct str_type_st* msg_body_t;

#define msg_body_init str_type_init 
#define msg_body_free str_type_free

#define msg_body_init_string str_type_init_string

#define msg_body_value str_type_str_value
#define msg_body_str_len str_type_str_len

#define msg_body_set_string str_type_set_string

#define msg_body_memory_pointer str_type_memory_pointer
#define msg_body_memory_len	str_type_memory_len

#define msg_body_deserialization str_type_deserialization
#define msg_body_serialize str_type_serialize

void msg_body_test();

#endif