#ifndef PYRAMID_RUNTIME_H
#define PYRAMID_RUNTIME_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "bytecode.h"
#include "util.h"
#define STACK_SIZE 1024 

enum _RuntimeStatus{
	RUNTIME_SUCCESS,
	RUNTIME_ERROR
};

typedef enum _RuntimeStatus RuntimeStatus;

struct _Runtime{
	uint8_t* code;
	RuntimeStatus status;
	uint8_t stack[STACK_SIZE];
	uint32_t sp;
	uint32_t ip;
	uint8_t result;
	bool is_running;

};

typedef struct _Runtime Runtime;

void runtime_start(Runtime* runtime);

void push8(Runtime* runtime,uint8_t data);
void push16(Runtime* runtime,uint16_t data);
void push32(Runtime* runtime,uint32_t data);
uint8_t pop8(Runtime* runtime);
uint16_t pop16(Runtime* runtime);
uint32_t pop32(Runtime* runtime);


#endif 