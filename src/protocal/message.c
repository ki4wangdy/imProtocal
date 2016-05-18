
#include <type.h>

message_type_t message_type_init(char* id, char* from, char* to, char* body, char* type){
	message_type_t t = calloc(1, sizeof(struct message_type_st));
	t->header = header_type_new();
	header_type_set_id(t->header,id);
	header_type_set_from(t->header, from);
	header_type_set_to(t->header, to);
	header_type_add_key(t->header, KEY_MESSAGE_TYPE, type);
	t->msg = msg_body_init_string(body);
	return t;
}

char* message_type_get_id(message_type_t t){
	assert(t);
	return header_type_get_id(t->header);
}

char* message_type_get_from(message_type_t t){
	assert(t);
	return header_type_get_from(t->header);
}

char* message_type_get_to(message_type_t t){
	assert(t);
	return header_type_get_to(t->header);
}

char* message_type_get_body(message_type_t t){
	assert(t);
	return msg_body_value(t->msg);
}

char* message_type_get_type(message_type_t t){
	assert(t);
	return header_type_get_key(t->header, KEY_MESSAGE_TYPE);
}

void message_type_free(message_type_t t){
	assert(t);
	header_type_free(t->header);
	msg_body_free(t->msg);
	free(t);
}

message_type_t message_type_deserialization(char* str){
	message_type_t ts = calloc(1,sizeof(struct message_type_st));	
	ts->header = header_type_deserialization(str);
	if (ts->header == NULL){
		free(ts);
		return NULL;
	}
	int len = header_type_memory_len(ts->header);
	str += len;
	ts->msg = msg_body_deserialization(str);
	return ts;
}

static message_type_t message_type_deserializations(char* str,char** end_str){
	message_type_t ts = calloc(1,sizeof(struct message_type_st));	
	ts->header = header_type_deserialization(str);
	if (ts->header == NULL){
		free(ts);
		return NULL;
	}
	int len = header_type_memory_len(ts->header);
	str += len;
	ts->msg = msg_body_deserialization(str);

	char* temp_str = NULL;
	int temp_len = 0;
	str_type_serialize(ts->msg, &temp_str, &temp_len);

	free(temp_str);
	str += temp_len;

	*end_str = str;
	return ts;
}


message_type_t* multi_message_type_deserialization(char* str, int len, int* temp_count){
	int count = 10;
	char* end_str = NULL;
	char* start_str = str;
	int index = 0;
	int is_continue = 1;
	message_type_t temp = NULL;
	message_type_t* type_ts = calloc(1, count*sizeof(message_type_t));
	do{
		temp = message_type_deserializations(start_str, &end_str);
		if (index == count){
			count = 2 * count;
			type_ts = realloc(type_ts, count*sizeof(message_type_t));
		}
		type_ts[index] = temp;
		if (end_str - str == len){
			is_continue = 0;
		}
		start_str = end_str;
		index++;
	} while (is_continue);
	*temp_count = index;
	return type_ts;
}

void message_type_serialize(message_type_t t, char** str, int* len){
	assert(t);
	char* st;
	int lens;
	header_type_serialize(t->header,&st,&lens);

	char* msgStr;
	int msgLen;
	msg_body_serialize(t->msg,&msgStr,&msgLen);

	char* s = calloc(1,lens+msgLen);
	*str = s;
	*len = lens + msgLen;

	memcpy(s,st,lens);
	s += lens;
	free(st);

	memcpy(s,msgStr,msgLen);
	s += msgLen;
	free(msgStr);
}

void message_type_test(){
	message_type_t t = message_type_init("ki","343434","434344","body","1");

	header_type_t header = t->header;
	header_type_add_key(header,KEY_MESSAGE_TYPE,Message_Message_Type);

	char* str;
	int len;
	message_type_serialize(t,&str,&len);

	message_type_t ts = message_type_deserialization(str);
	header_type_t tsHeader = ts->header;

	char* ids = header_type_get_id(tsHeader);
	fprintf(stderr,"the ids is %s\n",ids);
	free(ids);

	char* tos = header_type_get_to(tsHeader);
	fprintf(stderr,"the tos is %s\n",tos);
	free(tos);

	char* froms = header_type_get_from(tsHeader);
	fprintf(stderr,"the froms is %s\n",froms);
	free(froms);

	char* bodys = msg_body_value(ts->msg);
	fprintf(stderr,"the body is %s\n",bodys);
	free(bodys);

	free(str);

	message_type_free(ts);
	message_type_free(t);
}
