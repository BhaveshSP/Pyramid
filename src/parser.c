#include "../include/parser.h"

ParserStatus parser_start(TokenList* list,const char* source ){
	char lex[256];
	int lexi = 0 ;
	int line = 1 ;
	int i = 0;
	while(1){
		while(source[i]!='\n' && source[i]!=' ' && source[i]!='\0'){
			lex[lexi++] = source[i++];
		}
		if (lex[0] == '\0'){
			break;
		}
		lex[lexi] = '\0';
		
		if(strlen(lex)==0){
			continue;
		}

		if(lex[0]== '#'){
			int number = parser_get_number(lex);
			add_token_to_list(list,create_token(NUMBER,number,line));
		}else{
			int inst = parser_get_instr(lex);
			if(inst >=0){
				add_token_to_list(list,create_token(INST,inst,line));
			}else{
				printf("Syntax Error: No such Instruction %s\n",lex);
				return PARSER_SYNTAX_ERROR;
			}
		}
		if(source[i] == '\n'){
			line++;
		}
		if(source[i] == '\0'){
			break;
		}
		i++;
		lexi = 0 ;


	}
}

uint32_t parser_get_number(const char* buf){
	uint32_t number = atoi(&buf[1]);
	return (number<= UINT32_MAX) ? number : 0;
}
TokenInstruction parser_get_instr(const char* buf ){
	if(strcmp(buf,"push")==0){
		return PUSH;
	}
	if(strcmp(buf,"add")==0){
		return ADD;
	}
	
	if(strcmp(buf,"hlt")==0){
		return HLT;
	}
	return (TokenInstruction)-1;
}


