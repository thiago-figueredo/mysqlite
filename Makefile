CC=gcc
CFLAGS=-g -w -O2 -std=c99
INCLUDE_DIR=include
MAIN_DEPS=$(INCLUDE_DIR)/input_buffer.c \
	$(INCLUDE_DIR)/string_utils.c

main: main.o
	$(CC) $(CFLAGS) src/main.c $(MAIN_DEPS) -o main.o

string_utils: string_utils.o
	$(CC) $(CFLAGS) string_utils.c -o string_utils.o

input_buffer: input_buffer.o
	$(CC) $(CFLAGS) input_buffer.c -o input_buffer.o

clean:
	rm -f *.o