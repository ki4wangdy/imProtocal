
#include <type.h>

void ack_type_test(){
	ack_type_t ack = ack_type_init("","","","",Message_Ack_Type);

	header_type_t header = ack_type_get_header(ack);
	msg_body_t body = ack_type_get_body(ack);

	header_type_set_to(header,"400004");
	header_type_set_from(header,"20002");
	header_type_set_id(header,"sdfx");

	msg_body_set_string(body,"ki");

	char* str;
	int len;
	ack_type_serialize(ack,&str,&len);

	fprintf(stderr,"the len is %d\n",len);

	ack_type_t ts = ack_type_deserialization(str);

	char* id = header_type_get_id(ts->header);
	fprintf(stderr,"the id is %s\n",id);
	free(id);

	char* from = header_type_get_from(ts->header);
	fprintf(stderr,"the from is %s\n",from);
	free(from);

	char* to = header_type_get_to(ts->header);
	fprintf(stderr,"the to is %s\n",to);
	free(to);

	char* bodys = msg_body_value(ts->msg);
	fprintf(stderr,"the body is %s\n",bodys);
	free(bodys);

	free(str);

	ack_type_free(ts);
	ack_type_free(ack);

}