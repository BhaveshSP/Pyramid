#ifndef PYRAMID_PARSER_H
#define PYRAMID_PARSER_H
#include "token.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Parser Status States
enum _ParserStatus{
	PARSER_SUCCESS,
	PARSER_SYNTAX_ERROR
};
	
typedef enum _ParserStatus ParserStatus;

ParserStatus parser_start(TokenList* list,const char* source );
uint32_t parser_get_number(const char* buf);
TokenInstruction parser_get_instr(const char* buf );

#endif 