#ifndef PYRAMID_BYTECODE_H
#define PYRAMID_BYTECODE_H
// OP Code for Bytecode Conversion 
enum _Opcode{
	NO_OP=0x00,
	ADD_STACK=0x01,
	PUSH_STACK=0x02,
	HLT_OP=0xFF
};
typedef enum _Opcode Opcode;

#endif 