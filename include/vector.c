#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "../src/tokenizer.h"
#include "../src/ast_node.h"
#include "../src/ast.h"

Vector* new_vector(VectorElementType element_type) 
{
    Vector* vector = malloc(sizeof(Vector));

    if (!vector) {
        fprintf(stderr, "Could not malloc vector\n");
        return NULL;
    }

    vector->array = malloc(sizeof(void));
    vector->size = 0;
    vector->capacity = 1;
    vector->element_type = element_type;

    return vector;
}

void vector_push(Vector* vector, void* element)
{
    size_t old_capacity = vector->capacity;
    size_t new_capacity = old_capacity * 2;
    vector->capacity = new_capacity;
    void* old_vector_array = vector->array;

    switch (vector->element_type) {
        case TOKEN:
            if (vector->size == vector->capacity) {
                vector->array = calloc(new_capacity, sizeof(Token));

                for (size_t i = 0; i < old_capacity; i++) {
                    ((Token*)vector->array)[i] = ((Token*)old_vector_array)[i];
                }
            } 

            ((Token*)vector->array)[vector->size++] = *((Token*)element);
            break;
        case AST_NODE:
            vector->array = calloc(new_capacity, sizeof(AstNode));

            for (size_t i = 0; i < old_capacity; i++) {
                ((AstNode*)vector->array)[i] = ((AstNode*)old_vector_array)[i];
            }

            ((AstNode*)vector->array)[vector->size++] = *((AstNode*)element);
            break;
        default:
            fprintf(stderr, "Could not push a new element to vector\n");
            break;
    }
}

void print_vector(Vector* vector) 
{
    if (!vector || !vector->array) {
        fprintf(stderr, "Could not print null vector\n");
        return;
    }

    if (vector->element_type < TOKEN || vector->element_type > TOKEN) {
        fprintf(stderr, "Could not print vector of unknown elements\n");
        return;
    }

    for (size_t i = 0; i < vector->size; i++) {
        switch (vector->element_type) {
            case TOKEN: 
                print_token(((Token*)vector->array)[i]);
                printf(",\n");
            case AST_NODE:
                print_ast_node(((AstNode*)vector->array)[i]);
                printf(",\n");
        }
    }
}

void free_vector(Vector* vector) 
{
    free(vector->array);
    free(vector);
}