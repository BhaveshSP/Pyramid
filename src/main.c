#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/util.h"
#include "../include/token.h"
#include "../include/parser.h"

void command_error(){
	printf("Command Error : \n");
	printf("Correct Syntax ./pyramid --compile file_name.pyrd");
}

int main(int argc, char **argv){
	// Command Syntax Check 
	if(argc <3){
		printf("Too Few Arguments Passed !!...\n");
		return 1;
	}
	if(strcmp(argv[1],"--compile") == 0){
		// Get the file path to read the file 
		char* source = read_file_ascii(argv[2]);
		TokenList token_list ;
		create_token_list(&token_list,1);
		ParserStatus par_status = parser_start(&token_list,source);
		if (par_status!=PARSER_SUCCESS)
			return 1 ;
		for(int i = 0;i < token_list.ptr;i++){
			Token* token = get_token_from_list(&token_list,i);
			printf("%d %d %d\n",token->type,token->data,token->line);
		}
		free(source);
	}else{
		command_error();
	}
	return 0 ;
}