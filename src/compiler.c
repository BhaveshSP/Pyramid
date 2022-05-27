#include "../include/compiler.h"

// Start Compling 
void compiler_start(Compiler* compiler){
	// Initialize Compiler Byte Buffer with Byte Buffer of Size 1 
	compiler->byte_buffer = create_byte_buffer(1);
	// Iterate over Token List 
	for(int i =0 ;i<compiler->list->ptr;i++){
		// Get the Token at Position i 
		Token* token = get_token_from_list(compiler->list,i);
		// Check if the Token is of type Instruction
		if(token->type == INST){
			switch(token->data){
				case PUSH:
					// Check if the next Token is a Number 
					// if so then write to the Byte Buffer
					// Otherwise show error 
					// Invalid Use of Push Instruction
					if(get_token_from_list(compiler->list,i+1)->type == NUMBER){
						// Write Op Code to the Byte Buffer 
						write_byte_buffer_8(compiler->byte_buffer,PUSH_STACK);
						// Write the Number to the Byte Buffer 
						write_byte_buffer_32(compiler->byte_buffer,get_token_from_list(compiler->list,i+1)->data);
						// Skip the Number which is on the next position 
						i+=1 ;
					}else{
						// Show Error
						printf("Compiler Error: Invalid Use of Push Instruction ");
						// Set the Compiler Status to Compiler Error 
						// and Exit the Function 
						compiler->status = COMPILER_ERROR;
						return ;
					}
					break;
				case ADD:
					// Write Op Code to the Byte Buffer 
						
					write_byte_buffer_8(compiler->byte_buffer,ADD_STACK);
					break;
				case HLT:
					
					// Write Op Code to the Byte Buffer 
					write_byte_buffer_8(compiler->byte_buffer,HLT_OP);
					break;
				default:
					// Cannot Reach here but if does check when such a case araises
					// and fix the issue
					printf("Error While Compiling");
					compiler->status = COMPILER_ERROR;
					return ;
			}
		}
	}
	// Looped over all Tokens 
	// Set the Compiler Status to Success 
	// and Exit 
	compiler->status = COMPILER_SUCCESS;
	return ;
}