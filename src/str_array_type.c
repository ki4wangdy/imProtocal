
#include <type.h>

void _check_the_capacity(str_array_type_t t){
	assert(t);
	int size = atoi(t->size);
	if(size + 1 == t->currentAllocSize){
		t->currentAllocSize = t->currentAllocSize * 2;
		t->str_array_pointer = realloc(t->str_array_pointer,sizeof(str_array_type_t) * t->currentAllocSize);
	}
}

str_array_type_t str_array_type_new(int capacity){
	if(capacity <= 0){
		assert(0);
	}
	str_array_type_t t = calloc(1,sizeof(struct str_array_type_st));
	t->currentAllocSize = capacity;
	t->str_array_pointer = calloc(1,sizeof(str_array_type_t)*capacity);
	return t;
}

void str_array_type_free(str_array_type_t t){
	assert(t != NULL);
	int size = atoi(t->size);
	int i = 0;
	for (; i < size; i++){
		str_type_free(t->str_array_pointer[i]);
	}
	free(t->str_array_pointer);
	free(t);
}

// 0 is ok , and -1 is error
int str_array_type_add_string(str_array_type_t t, char* str){
	assert(t);
	assert(str);
	int size = strlen(str);
	str_array_type_add_str(t,str,size);
	return 0;
}

str_array_type_t str_array_type_deserialization(char* str){
	str_array_type_t t = calloc(1,sizeof(struct str_array_type_st));
	t->n = *str;
	str++;
	
	int size = (int)t->n - 48;
	memcpy(t->size,str,size);
	str += size;

	int pSize = atoi(t->size);
	t->currentAllocSize = pSize + 1;

	t->str_array_pointer = calloc(1,sizeof(str_array_type_t) * pSize);
	int i=0;
	for (; i<pSize; i++){
		t->str_array_pointer[i] = str_type_deserialization(str);
		int s = str_type_memory_len(t->str_array_pointer[i]);
		str += s;
	}
	return t;
}

void str_array_type_print_strings(str_array_type_t t){
	assert(t);
	int size = atoi(t->size);
	int i=0;
	for(;i<size;i++){
		char* str = str_type_str_value(t->str_array_pointer[i]);
		int len = str_type_str_len(t->str_array_pointer[i]);
		char buf[100] = "";
		memcpy(buf, str, len);
		free(str);
		fprintf(stderr, "%s\n", buf);
	}
	fprintf(stderr,"\n");
}

int str_array_type_add_str(str_array_type_t t, char* str, int len){
	assert(str != NULL && len > 0);
	
	// judge the capacity
	_check_the_capacity(t);

	// 1.add the string to pointer
	str_type_t str_t = str_type_init(str,len);

	int size = atoi(t->size);
	t->str_array_pointer[size] = str_t;

	// 2. update the size
	size += 1;
	snprintf(t->size,10,"%d",size);
		
	// 3. update the n
	int s = strlen(t->size);
	t->n = (char)(s+48);
	return 0;
}

char* str_array_type_memory_pointer(str_array_type_t t){
	assert(t);
	int memorySize = str_array_type_memory_length(t);
	if(memorySize < 0){
		assert(0);
		return NULL;
	}
	char* pointer = calloc(1,sizeof(char)*memorySize);
	char* p = pointer;	

	// 1.n
	*p = t->n;
	p++;

	// 2.size
	int size = atoi(t->size);
	memcpy(p,t->size,size);
	int ss = (int)t->n - 48;
	p += ss;

	// 3. copy the string array
	str_type_t ts;
	int s = size;
	int i = 0;
	for(i=0; i<s ; i++){
		ts = t->str_array_pointer[i];
		char* memPointer = str_type_memory_pointer(ts);
		int len = str_type_memory_len(ts);
		memcpy(p,memPointer,len);
		free(memPointer);
		p += len;
	}
	return pointer;
}

int str_array_type_memory_length(str_array_type_t t){
	// 1.the string's array's size
	int arraySize = 0;
	int size = atoi(t->size);

	int i = 0;
	for(i=0; i<size; i++){
		str_type_t ts = t->str_array_pointer[i];
		arraySize += str_type_memory_len(ts);
	}
	return 1 + size + arraySize;
}

int str_array_type_array_size(str_array_type_t t){
	assert(t);
	int size = atoi(t->size);
	return size;
}