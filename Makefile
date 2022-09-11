CC=gcc
CFLAGS=-g -w -O2 -std=c99
INCLUDE_DIR=include
MAIN_DEPS=$(INCLUDE_DIR)/input_buffer.c \
	$(INCLUDE_DIR)/string_utils.c \
	$(INCLUDE_DIR)/vector.c \
	src/tokenizer.c \
	src/ast_node.c \
	src/ast.c \

main: src/main.o 
	$(CC) $(CFLAGS) src/main.c $(MAIN_DEPS) -o main.o

string_utils: string_utils.o
	$(CC) $(CFLAGS) string_utils.c -o string_utils.o

input_buffer: input_buffer.o
	$(CC) $(CFLAGS) input_buffer.c -o input_buffer.o

tokenizer: tokenizer.o
	$(CC) $(CFLAGS) src/tokenizer.c -o tokenizer.o

vector: vector.o
	$(CC) $(CFLAGS) $(INCLUDE_DIR)/vector.c src/tokenizer.c src/ast.c src/ast_node.c -o vector.o

ast_node: ast_node.o
	$(CC) $(CFLAGS) src/ast_node.c -o ast_node.o

ast: ast.o
	$(CC) $(CFLAGS) src/ast.c $(INCLUDE_DIR)/vector.c -o ast.o

clean:
	rm -f **/*.o