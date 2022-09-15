#ifndef AST_NODE_H
#define AST_NODE_H

typedef enum {
    FUNCTION_CALL,
    BINARY_OPERATOR,
} AstNodeType;

typedef struct
{
    char* function_name;
    char* args;
    size_t args_size;
} FunctionCall;

typedef struct
{
    char* operator_name;
    char* left_hand_side;
    char* right_hand_side;
} BinaryOperator;

typedef union
{
    AstNodeType type;
    FunctionCall function_call;
    BinaryOperator binary_operator;
} AstNode;

AstNode* new_ast_node(AstNodeType node_type);
FunctionCall init_function_call(char* function_name, char* args, size_t args_size);
void print_ast_node(AstNode node);

#endif