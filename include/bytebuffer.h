#ifndef PYRAMID_BYTEBUFFER_H
#define PYRAMID_BYTEBUFFER_H
#include <stdlib.h>
#include <stdint.h>

// ByteBuffer ADT for ByteCode Conversion 
struct _ByteBuffer{
	uint8_t* buffer;
	int ptr;
	int size;
};

typedef struct _ByteBuffer ByteBuffer;

// Operations on ByteBuffer ADT 
ByteBuffer* create_byte_buffer(int size);
void write_byte_buffer_8(ByteBuffer* byte_buffer,uint8_t data);
void write_byte_buffer_16(ByteBuffer* byte_buffer,uint16_t data);
void write_byte_buffer_32(ByteBuffer* byte_buffer,uint32_t data);
void destroy_byte_buffer(ByteBuffer* byte_buffer);



#endif 