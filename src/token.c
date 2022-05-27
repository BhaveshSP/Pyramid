#include "../include/token.h"

// Create a Token with given values 
void create_token(Token* token,int type,int data,int line){

	token->type = type;
	token->data = data;
	token->line = line;
}

// Free the resource of the Token from memory
void destroy_token(Token* token){
	// free(token);
}

// Initialize the TokenList with Default Values
void create_token_list(TokenList* list, int size){
	list->data = (Token*) malloc(sizeof(Token) * size);
	list->ptr = 0 ;
	list->size = size ;
}

// Add a Token the Token List 
void add_token_to_list(TokenList* list, Token token){
	// If the size of the list is smaller than the pointer 
	// double the size of the list and reallocate the list 
	if(list->ptr >= list->size){
		list->size *= 2;
		list->data = (Token*) realloc(list->data, sizeof(Token)*(list->size)); 
	}
	// Set the Data and Increament the pointer 
	Token* temp_token = &list->data[list->ptr++];
	create_token(temp_token,token.type,token.data,token.line);
}

// Return the Token at position or index 
Token* get_token_from_list(TokenList* list, int position){
	return &list->data[position];
}

// Free the resources of the each Token from memory of list 
void destroy_token_list(TokenList* list){
	for(int i=0;i<=list->ptr;i++){
		destroy_token(&list->data[i]);
	}
	// Free the resource of the Token List itself 
	free(list->data);
}