#ifndef PYRAMID_UTIL_H
#define PYRAMID_UTIL_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "bytebuffer.h"
// Read the Program File 
char* read_file_ascii(const char* file_path);
// Read the ByteCode from File 
uint8_t* read_binary_from_file(const char* file_path);
uint16_t read16(uint8_t* buffer, uint32_t index);
uint32_t read32(uint8_t* buffer, uint32_t index);
// Write the ByteCode File 
void write_binary_to_file(const char* file_path,ByteBuffer* byte_buffer);
#endif 