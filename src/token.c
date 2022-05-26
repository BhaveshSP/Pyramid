#include "../include/token.h"

// Create a Token with given values 
Token* create_token(int type,int data,int line){
	Token* token = (Token*) malloc(sizeof(Token));
	token->type = type;
	token->data = data;
	token->line = line;
	return token;
}

// Free the resource of the Token from memory
void destroy_token(Token* token){
	free(token);
}

// Initialize the TokenList with Default Values
void create_token_list(TokenList* list, int size){
	list->data = (Token**) malloc(sizeof(Token*) * size);
	list->ptr = 0 ;
	list->size = size ;
}

// Add a Token the Token List 
void add_token_to_list(TokenList* list, Token* token){
	// If the size of the list is smaller than the pointer 
	// double the size of the list and reallocate the list 
	if(list->ptr >= list->size){
		list->size *= 2;
		list->data = (Token**) realloc(list->data, sizeof(Token*)*(list->size)); 
	}
	// Set the Data and Increament the pointer 
	list->data[list->ptr++] = token;
}

// Return the Token at position or index 
Token* get_token_from_list(TokenList* list, int position){
	return list->data[position];
}

// Free the resources of the each Token from memory of list 
void destroy_token_list(TokenList* list){
	for(int i=0;i<=list->ptr;i++){
		free(list->data[i]);
	}
	// Free the resource of the Token List itself 
	free(list->data);
}