#ifndef PYRAMID_UTIL_H
#define PYRAMID_UTIL_H
#include <stdio.h>
#include <stdlib.h>
#include "bytebuffer.h"
// Read the Program File 
char* read_file_ascii(const char* file_path);
// Write the ByteCode File 
void write_ascii_to_file(const char* file_path,ByteBuffer* byte_buffer);
#endif 