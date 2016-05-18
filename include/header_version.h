
#ifndef _HEADER_VERSION_H_
#define _HEADER_VERSION_H_

typedef struct header_version_st{
	int_type_t version;
}*header_version_t;

header_version_t header_version_init(int version);
void header_version_free(header_version_t t);

header_version_t header_version_deserialization(char*);
int header_version_serialize(header_version_t t, char** str, int* len);

int header_version_value(header_version_t t);

void header_version_test();

#endif