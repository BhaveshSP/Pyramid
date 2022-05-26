#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/util.h"

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
	if( strcmp(argv[1],"--compile") == 0 ){
		// Get the file path to read the file 
		char* source = read_file_ascii(argv[2]);
		
		free(source);
	}else{
		command_error();
	}
	return 0 ;
}