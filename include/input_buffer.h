#ifndef INPUT_BUFFER
#define INPUT_BUFFER

#include <sys/types.h>

typedef struct 
{
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer();
void free_input_buffer();

#endif