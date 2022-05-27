#ifndef PYRAMID_BYTECODE_H
#define PYRAMID_BYTECODE_H
// OP Code for Bytecode Conversion 
enum _Opcode{
	NO_OP=0x00,
	PUSH_STACK=0x01,
	ADD_STACK=0x02,
	SUB_STACK=0x03,
	MUL_STACK=0x04,
	INCR_STACK=0x05,
	HLT_OP=0xFF
};
typedef enum _Opcode Opcode;

#endif 