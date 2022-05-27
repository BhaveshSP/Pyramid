#include "../include/parser.h"
// Parse the Instructions and Numbers from the the TokenList 
ParserStatus parser_start(TokenList* list,const char* source ){
	// Define Lexer for storing Words or Numbers
	char lex[256];
	// Lexer Index 
	int lexi = 0 ;
	// Line Number Index to Show Error on Line 
	int line = 1 ;
	// Pointer for the TokenList 
	int i = 0;
	while(1){
		// Get the Whole Word without spaces newline or \0 endline character 
		while(source[i]!='\n' && source[i]!=' ' && source[i]!='\0'){
			lex[lexi++] = source[i++];
		}
		// If end of sentence or program break
		if (lex[0] == '\0'){
			break;
		}
		// Add end of sentence to the word or number 
		lex[lexi] = '\0';
		// If spaces after each line 
		// this handles the empty chars in the program 
		if(strlen(lex)==0){
			continue;
		}
		// number starts with # symbol 
		if(lex[0]== '#'){
			// Parse the number from the lex string 
			int number = parser_get_number(lex);
			// Create Token for the Number 
			add_token_to_list(list,create_token(NUMBER,number,line));
		}else{
			// Parse the Instruction from the lex string 
			int inst = parser_get_instr(lex);
			// If the Instruction is predefined positive value is 
			// returned otherwise negative -1 
			if(inst >=0){
				// Create Token for the Instruction
				add_token_to_list(list,create_token(INST,inst,line));
			}else{
				// Instruction is Not defined in the Grammer 
				printf("Syntax Error: No such Instruction %s\n",lex);
				return PARSER_SYNTAX_ERROR;
			}
		}
		// If new line char increment line pointer  
		if(source[i] == '\n'){
			line++;
		}
		// If end of sentence or tokenlist break the loop 
		if(source[i] == '\0'){
			break;
		}
		// Increment the pointer 
		i++;
		// Reset the lexer Index 
		lexi = 0 ;
	}
}


// Parse the Number from the Lexer String 
uint32_t parser_get_number(const char* buf){
	// Char to number from address plus one 
	uint32_t number = atoi(&buf[1]);
	// If the Number is greater than INT_MAX_32 return 0 
	return (number<= UINT32_MAX) ? number : 0;
}


// Parse the Instructions from lexer String 
TokenInstruction parser_get_instr(const char* buf ){
	// Return the Instructions Defined in the Grammer 
	if(strcmp(buf,"push")==0){
		return PUSH;
	}
	if(strcmp(buf,"add")==0){
		return ADD;
	}
	
	if(strcmp(buf,"hlt")==0){
		return HLT;
	}
	// Otherwise Return -1 
	return (TokenInstruction)-1;
}


