NAME = test

CC = clang
OPT = -O2
# TODO -> MOVE TO C89
VERSION = -std=c99
OUTPUT = a.out

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS = -Wno-unused-function
HEADERS =
LIBS = ../export/*.so

INPUT = $(NAME).c

all: compiler

make_library:
	cd .. && em build lib && cd examples

compiler: make_library
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(PRINT_WARNINGS) $(C99_WARNINGS) $(LIBS) -o $(OUTPUT) $(INPUT)
	./$(OUTPUT)

clean:
	cd .. && em clean && cd examples
	rm -rf $(OUTPUT)
