#include "../include/util.h"

// Read the Program File 
char* read_file_ascii(const char* file_path){
	FILE* file = fopen(file_path,"r");
	// Check if the file exists 
	if(!file){
		printf("%s Could not be Found\n",file_path);
		return NULL;
	}
	// Set the pointer to the end of the file 
	fseek(file,0,SEEK_END);
	// Get the size of the file 
	int size = ftell(file);
	// Set the pointer back to the start of the file 
	fseek(file,0,SEEK_SET);
	// Create a buffer of size + 1 (1 to add the end line character ) 
	char* buf = malloc(sizeof(char) * (size+1));
	if (!buf){
		printf("Could not allocate memory for file buffer\n");
		return NULL;
	}
	// Read the file to buff (1 for 1 byte which is universal )
	fread(buf,1,size,file);
	// Add the endline character to show the end of line 
	buf[size] = '\0';
	return buf;
}


// Write to the ByteCode File 
void write_ascii_to_file(const char* file_path,ByteBuffer* byte_buffer){
	// Open File to Write Binary 
	FILE* file = fopen(file_path,"wb");
	// Check if the file can be created  
	if(!file){
		printf("Could not write to file %s\n",file_path);
		return;
	}
	// Write the Buffer to the file of size ptr
	fwrite(byte_buffer->buffer,1,byte_buffer->ptr,file);
	fclose(file);
}