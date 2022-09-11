#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "../include/vector.h"

typedef enum
{
    KEYWORD,
    GREATER,
    GREATER_OR_EQUAL,
    LESS,
    LESS_OR_EQUAL,
    EQUAL,
    NOT_EQUAL,
    LEFT_PARENTHESIS,
    RIGHT_PARENTHESIS,
    VALUE,
} TokenType;

typedef struct 
{
    TokenType type;
    char* content;
} Token;

Token init_token(TokenType type, char* content);
Vector* tokenize(char* string);
void print_token(Token token);
void free_token(Token* token);

#endif