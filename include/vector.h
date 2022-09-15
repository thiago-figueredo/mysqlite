#ifndef VECTOR_H
#define VECTOR_H

typedef enum { TOKEN, AST_NODE } VectorElementType;

typedef struct 
{
    void* array;
    size_t size;
    size_t capacity;
    VectorElementType element_type;
} Vector;

Vector* new_vector(VectorElementType element_type);
void vector_push(Vector* vector, void* element);
void* vector_at(Vector* vector, size_t index);
void print_vector(Vector* vector);
void free_vector(Vector* vector);

#endif
