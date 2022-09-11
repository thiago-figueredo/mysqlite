#include <stdio.h>
#include <stdlib.h>
#include "ast_node.h"

FunctionCall init_function_call(char* function_name, char* args, size_t args_size)
{
    FunctionCall function_call = {
        .function_name = function_name,
        .args = args,
        .args_size = args_size,
    };

    return function_call;
}

BinaryOperator init_binary_operator(char* operator_name, char* left_hand_side, char* right_hand_side)
{
    BinaryOperator binary_operator = {
        .operator_name = operator_name,
        .left_hand_side = left_hand_side,
        .right_hand_side = right_hand_side,
    };

    return binary_operator;
}

AstNode* new_ast_node(AstNodeType node_type) 
{
    AstNode* node;

    switch (node_type) {
        case FUNCTION_CALL:
            node = malloc(sizeof(AstNode));
            node->function_call = init_function_call(NULL, NULL, 0);
            break;
        case BINARY_OPERATOR:
            node = malloc(sizeof(AstNode));
            node->binary_operator = init_binary_operator(NULL, NULL, NULL);
            break;
        default:
            fprintf(stderr, "Unknown ast node type\n");
            return NULL;
    }

    node->type = node_type;
    return node;
}

void print_ast_node(AstNode node)
{
    switch (node.type) {
        case FUNCTION_CALL:
            printf(
                "FunctionCall {\n  function_name = %s\n  args = %s\n  args_size = %zu\n}", 
                node.function_call.function_name,
                node.function_call.args,
                node.function_call.args_size
            );
            break;
        case BINARY_OPERATOR:
            printf(
                "BinaryOperator {\n  operator_name = %s\n  left_hand_side = %s\n  right_hand_side = %s}", 
                node.binary_operator.operator_name,
                node.binary_operator.left_hand_side,
                node.binary_operator.right_hand_side
            );
            break;
        default:
            break;
    }
}