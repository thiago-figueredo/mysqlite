#ifndef AST_H
#define AST_H

#include "ast_node.h"
#include "../include/vector.h"

typedef struct
{
    Vector* nodes;
} Ast;

Ast* new_ast();
void ast_add_node(Ast* ast, AstNode node);
void print_ast(Ast ast);

#endif