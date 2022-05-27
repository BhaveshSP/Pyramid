#include "../include/runtime.h"



void runtime_start(Runtime* runtime){
	runtime->sp = -1 ;
	runtime->ip = 0;
	runtime->result = 123 ;
	runtime->is_running = true ;

	while (runtime->is_running){
		switch(runtime->code[runtime->ip++]){
			case PUSH_STACK:{
				push32(runtime,read32(runtime->code,runtime->ip));
				runtime->ip+=4;
				break;
			}
			case ADD_STACK:	{
				uint32_t a = pop32(runtime);
				uint32_t b = pop32(runtime);
				push32(runtime,a+b);
				break;
			}
			case HLT_OP:{
				runtime->result = (uint8_t) pop32(runtime);
				runtime->is_running = false;
				runtime->status = RUNTIME_SUCCESS;
				return;
			}
		}
	}

}
void push8(Runtime* runtime,uint8_t data){
	runtime->stack[++runtime->sp] = data;
}
void push16(Runtime* runtime,uint16_t data){
	push8(runtime,(data & 0xFF00)>>8);
	push8(runtime,(data & 0x00FF));
}
void push32(Runtime* runtime,uint32_t data){
	push8(runtime,(data & 0xFF000000)>>24);
	push8(runtime,(data & 0x00FF0000)>>16);
	push8(runtime,(data & 0x0000FF00)>>8);
	push8(runtime,(data & 0x000000FF));
}


uint8_t pop8(Runtime* runtime){
	return runtime->stack[runtime->sp--];

}
uint16_t pop16(Runtime* runtime){
	uint16_t b = pop8(runtime);
	uint16_t a = pop8(runtime);
	return (a << 8) | b ;

}
uint32_t pop32(Runtime* runtime){
	uint8_t d = pop8(runtime);
	uint8_t c = pop8(runtime);
	uint8_t b = pop8(runtime);
	uint8_t a = pop8(runtime);
	return (a << 24) | (b << 16) | (c << 8) | (d); 
}
