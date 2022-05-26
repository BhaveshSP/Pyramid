#ifndef PYRAMID_TOKEN_H
#define PYRAMID_TOKEN_H

#include <stdlib.h>

// Token Types 
enum _TokenType{
	INST,
	NUMBER
};

typedef enum _TokenType TokenType;

// Token Instructions 
enum _TokenInstruction{
	ADD,
	PUSH,
	HLT
};

typedef enum _TokenInstruction TokenInstruction;

// Structure to Store Token's or Word's 
struct _Token{
	int type;
	int data;
	int line;
};

typedef struct _Token Token;

// Operations on Token ADT 
Token* create_token(int type,int data,int line);
void destroy_token(Token* token);


// Structure to Store TokenList or Sentence or List of Words
struct _TokenList{
	Token** data;
	int ptr;
	int size;
};

typedef struct _TokenList TokenList;
// Operations on TokenList ADT
void create_token_list(TokenList* list, int size);
void add_token_to_list(TokenList* list, Token* token);
Token* get_token_from_list(TokenList* list, int position);
void destroy_token_list(TokenList* list); 

#endif 