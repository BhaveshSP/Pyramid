#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/util.h"
#include "../include/token.h"
#include "../include/parser.h"
#include "../include/compiler.h"
#include "../include/bytebuffer.h"

// Show Command Error if Incorrect Syntax is entered 
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
		// Declare the Token List 
		TokenList token_list ;
		// Initialize the Token List with default size 1 
		create_token_list(&token_list,1);
		// Parse the Source Program into the Token List  
		ParserStatus par_status = parser_start(&token_list,source);
		// If Parser Error return 
		// Error is already shown in the parser.c 
		if (par_status!=PARSER_SUCCESS)
			return 1 ;
		// See the Token List 
		// for(int i = 0;i < token_list.ptr;i++){
		// 	Token* token = get_token_from_list(&token_list,i);
		// 	printf("%d %d %d\n",token->type,token->data,token->line);
		// }
		// Declare Compiler 
		Compiler compiler ;
		// Set the Token List for the Compiler 
		compiler.list = &token_list;
		// Start Compiling 
		compiler_start(&compiler);
		// If Compiler Status is not success return
		// Error is already shown in the compiler.c  
		if(compiler.status!= COMPILER_SUCCESS){
			return 1;
		}
		// Write the Complete ByteCode of the Program to the file 
		// with file name out.pyrdb
		write_ascii_to_file("out.pyrdb",compiler.byte_buffer);
		// Free the resources allocated to the Byte Buffer 
		destroy_byte_buffer(compiler.byte_buffer);
		// Free the resources allocation to the Source Program 
		free(source);
	}else{
		command_error();
	}
	return 0 ;
}