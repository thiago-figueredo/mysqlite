#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tokenizer.h"
#include "../include/vector.h"
#include "../include/string_utils.h"
#include "../include/input_buffer.h"

#define MYSQLITE_VERSION "0.0.1"

typedef enum  {
    TABLES,
    QUIT,
    EXIT,
} Commands;

static const char *commands[] = {
    [TABLES] = "tables (show tables)",
    [QUIT] = "quit",
    [EXIT] = "exit",
};

void print_initial_info()
{
    printf("mysqlite version %s\n", MYSQLITE_VERSION);
    printf("Enter \"commands\" to see available commands\n");
    printf("Enter \"quit\" or \"exit\" to exit\n");
}

void show_tables()
{
    printf("\n");
}

void help_commands()
{
    size_t keywords_size = sizeof(commands) / sizeof(const char*);

    for (int i = 0 ; i < keywords_size; i++) {
        printf("%s\n", commands[i]);
    }
}

void print_prompt() 
{
    printf("mysqlite> "); 
}

void read_input(InputBuffer* input_buffer)
{
    ssize_t bytes_read = getline(&input_buffer->buffer, &input_buffer->buffer_length, stdin); 

    if (bytes_read <= 0) {
        fprintf(stderr, "Error reading input!\n");
        exit(EXIT_FAILURE);
    }

    // ignore trailing white space
    input_buffer->input_length = bytes_read - 1;
    input_buffer->buffer[bytes_read - 1] = '\0';
}

int main()
{
    InputBuffer* input_buffer = new_input_buffer();
    print_initial_info();

    do {
        print_prompt();
        read_input(input_buffer);

        if (str_equals(input_buffer->buffer, "commands")) {
            help_commands();
        } else if (
            str_equals(input_buffer->buffer, "quit") || 
            str_equals(input_buffer->buffer, "exit")
        ) {
            exit(EXIT_SUCCESS);
        } else if (str_equals(input_buffer->buffer, "tables")) {
            show_tables();
        } else {
            fprintf(stderr, "Unkown command %s!\n", input_buffer->buffer);
        }
    } while (true);

    return 0;
}