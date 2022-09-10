#include <stdio.h>
#include <stdlib.h>
#include "input_buffer.h"

InputBuffer* new_input_buffer()
{
    InputBuffer* input_buffer = malloc(sizeof(InputBuffer));

    if (!input_buffer) {
        fprintf(stderr, "Could not malloc input buffer!\n");
        exit(EXIT_FAILURE);
    }

    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;

    return input_buffer;
}

void free_input_buffer(InputBuffer* input_buffer)
{
    free(input_buffer);
    free(input_buffer->buffer);
}
