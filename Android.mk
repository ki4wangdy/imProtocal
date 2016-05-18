
LOCAL_PATH := $(call my-dir)

LOCAL_MODULE := libimProtocal
LOCAL_MODULE_FILENAME := libimProtocal

LOCAL_SRC_FILES := \
	src/header_type.c	\
	src/key_value_array_type.c	\
	src/int_type.c	\
	src/msg_body.c	\
	src/str_type.c	\
	src/header_version.c	\
	src/key_value_type.c	\
	src/str_array_type.c	\
	src/protocal/login.c	\
	src/protocal/message.c

LOCAL_C_INCLUDES :=	$(LOCAL_PATH)/include
LOCAL_EXPORT_C_INCLUDES :=	$(LOCAL_PATH)/include \

#LOCAL_CFLAGS := 
#LOCAL_EXPORT_CFLAGS := 

include $(BUILD_STATIC_LIBRARY)