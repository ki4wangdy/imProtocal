
#include <type.h>

static void _test1(){
	str_array_type_t t = str_array_type_new(DEFAUL_FIVE_CAPACITY);
	assert(str_array_type_array_size(t) == 0);

	str_array_type_add_str(t,"abc",sizeof("abc"));
	str_array_type_add_string(t,"feg32");
	assert(str_array_type_array_size(t) == 2);

	str_array_type_print_strings(t);
	str_array_type_free(t);
}

static void _test2(){
	str_array_type_t t = str_array_type_new(DEFAUL_FIVE_CAPACITY);
	assert(str_array_type_array_size(t) == 0);

	int i=0;
	for(; i<18; i++){
		char buf[10] = "";
		snprintf(buf,10,"%d,",i);
		str_array_type_add_str(t,buf,strlen(buf));
	}

	str_array_type_add_str(t,"abc",sizeof("abc"));
	str_array_type_add_str(t,"d",sizeof("d"));

	str_array_type_print_strings(t);

	assert(str_array_type_array_size(t) == 20);
	str_array_type_free(t);
}

static void _test3(){
	str_array_type_t t = str_array_type_new(DEFAUL_FIVE_CAPACITY);
	assert(str_array_type_array_size(t) == 0);

	str_array_type_add_str(t,"<>,ds,f.sd,f.",strlen("<>,ds,f.sd,f."));
	str_array_type_add_str(t, "d", strlen("d"));
	str_array_type_add_str(t, "abcd", strlen("abcd"));
	str_array_type_add_str(t, "<>fsd,f.s,f", strlen("<>fsd,f.s,f"));

	char* str = str_array_type_memory_pointer(t);
	int len = str_array_type_memory_length(t);

	fprintf(stderr,"the size is:%d\n",len);

	str_array_type_t ts = str_array_type_deserialization(str);
	
	assert(str_array_type_array_size(ts) == 4);
	str_array_type_print_strings(ts);

	free(str);
	str_array_type_free(ts);
	str_array_type_free(t);
}

void str_array_type_test(){
	_test1();
	//_test2();
	//_test3();
}