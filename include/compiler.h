#ifndef PYRAMID_COMPILER_H
#define PYRAMID_COMPILER_H

#include "token.h"
#include "bytebuffer.h"
#include "bytecode.h"
#include <stdio.h>

// Compiler States 
enum _CompilerStatus{
	COMPILER_SUCCESS,
	COMPILER_ERROR
};

typedef enum _CompilerStatus CompilerStatus;

// Compiler ADT 
struct _Compiler{
	CompilerStatus status;
	TokenList* list;
	ByteBuffer* byte_buffer;
};

typedef struct _Compiler Compiler;
// Operations on Compiler ADT 
void compiler_start(Compiler* compiler);

#endif