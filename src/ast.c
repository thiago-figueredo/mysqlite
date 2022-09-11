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
    ast->nodes_size = 0;
    
    return ast;
}

void ast_add_node(Ast* ast, AstNode node)
{
    if (!ast) {
        fprintf(stderr, "Could nod add node to null ast\n");
        return;
    }

    vector_push(ast->nodes, &node);
    ast->nodes_size++;
}

void print_ast(Ast ast)
{
    for (size_t i = 0; i < ast.nodes_size; i++) {
        print_ast_node(ast->nodes[i]);
        printf("\n");
    }
}