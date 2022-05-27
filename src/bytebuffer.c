#include "../include/bytebuffer.h"


// Create a Byte Buffer of Given Size 
ByteBuffer* create_byte_buffer(int size){
	ByteBuffer* byte_buffer = (ByteBuffer*) malloc(sizeof(ByteBuffer));
	byte_buffer->buffer = (uint8_t*) malloc(sizeof(uint8_t)*size);
	byte_buffer->ptr = 0;
	byte_buffer->size = size ;
	return byte_buffer;
}

// Write to the Byte Buffer only 8 bits
void write_byte_buffer_8(ByteBuffer* byte_buffer,uint8_t data){
	if(byte_buffer->ptr >= byte_buffer->size){
		byte_buffer->size *=2 ;
		byte_buffer->buffer = (uint8_t*) realloc(byte_buffer->buffer,sizeof(uint8_t) * byte_buffer->size) ;
	}
	byte_buffer->buffer[byte_buffer->ptr++] = data;

}


// Write to the Byte Buffer 16 bits per 8 bits
void write_byte_buffer_16(ByteBuffer* byte_buffer,uint16_t data){
	write_byte_buffer_8(byte_buffer,(0xFF00 & data)>>8);
	write_byte_buffer_8(byte_buffer,(0xFF & data));
}


// Write to the Byte Buffer 32 bits per 8 bits
void write_byte_buffer_32(ByteBuffer* byte_buffer,uint32_t data){
	write_byte_buffer_8(byte_buffer,(0xFF000000 & data)>>24);
	write_byte_buffer_8(byte_buffer,(0x00FF0000 & data)>>16);
	write_byte_buffer_8(byte_buffer,(0x0000FF00 & data)>>8);
	write_byte_buffer_8(byte_buffer,(0x000000FF & data));
}

// Free the Resources allocated by the Byte Buffer and Buffer 
void destroy_byte_buffer(ByteBuffer* byte_buffer){
	free(byte_buffer->buffer);
	free(byte_buffer);
}