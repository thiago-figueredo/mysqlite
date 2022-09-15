#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tokenizer.h"
#include "../include/string_utils.h"
#include "../include/vector.h"

static const char* tokens_type[] = {
    [KEYWORD] = "KEYWORD",
    [VALUE] = "VALUE",
};

Token init_token(TokenType type, char* content) 
{
    Token token = {
        .type = type,
        .content = content,
    };

    return token;
}

Vector* tokenize(char* string) 
{
    if (!string) {
        fprintf(stderr, "Could not tokenize %s", string);
        return NULL;
    }

    size_t string_length = strlen(string);

    if (string[string_length-1] == ';') {
        string[string_length-1] = '\0';
    } 

    char* token_string = strtok(string, " ");
    Vector* token_vector = new_vector(TOKEN);

    while (token_string) {
        if (
            str_equals(str_to_upper(token_string), "CREATE") || 
            str_equals(str_to_upper(token_string), "INSERT") || 
            str_equals(str_to_upper(token_string), "SELECT") || 
            str_equals(str_to_upper(token_string), "TABLE") ||
            str_equals(str_to_upper(token_string), "DATABASE") 
        ) {
            Token token = init_token(KEYWORD, token_string);
            vector_push(token_vector, &token);
        } else if (str_equals(token_string, "<")) {
            Token token = init_token(LESS, token_string);
            vector_push(token_vector, &token);
        } else if (str_equals(token_string, ">")) {
            Token token = init_token(GREATER, token_string);
            vector_push(token_vector, &token);
        } else if (str_equals(token_string, "<=")) {
            Token token = init_token(LESS_OR_EQUAL, token_string);
            vector_push(token_vector, &token);
        } else if (str_equals(token_string, ">=")) {
            Token token = init_token(GREATER_OR_EQUAL, token_string);
            vector_push(token_vector, &token);
        } else if (str_equals(token_string, "=")) {
            Token token = init_token(EQUAL, token_string);
            vector_push(token_vector, &token);
        } else if (str_equals(token_string, "!=")) {
            Token token = init_token(NOT_EQUAL, token_string);
            vector_push(token_vector, &token);
        } else if (str_equals(token_string, "(")) {
            Token token = init_token(LEFT_PARENTHESIS, token_string);
            vector_push(token_vector, &token);
        } else if (str_equals(token_string, ")")) {
            Token token = init_token(RIGHT_PARENTHESIS, token_string);
            vector_push(token_vector, &token);
        } else {
            Token token = init_token(VALUE, token_string);
            vector_push(token_vector, &token);
        }

        token_string = strtok(NULL, " ");
    }

    return token_vector;
}

void free_token(Token* token)
{
    free(token);
}

void print_token(Token token)
{
    if (token.type < KEYWORD || token->type > VALUE) {
        fprintf(stderr, "Cannot print unknown token");
        return;
    }

    printf("{ TOKEN_TYPE = %s, TOKEN_CONTENT = %s }", tokens_type[token.type], token.content);
}