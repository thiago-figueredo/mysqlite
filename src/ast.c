#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "../include/vector.h"

Ast* new_ast()
{
    Ast* ast = malloc(sizeof(Ast));

    if (!ast) {
        fprintf(stderr, "Could not malloc ast\n");
        return NULL;
    }

    ast->nodes = new_vector(AST_NODE);
    
    return ast;
}

void ast_add_node(Ast* ast, AstNode node)
{
    if (!ast) {
        fprintf(stderr, "Could nod add node to null ast\n");
        return;
    }

    vector_push(ast->nodes, &node);
}

void print_ast(Ast ast)
{
    for (size_t i = 0; i < ast.nodes->size; i++) {
        AstNode* ast_node = vector_at(ast.nodes, i);
        print_ast_node(*ast_node);
        printf("\n");
    }
}