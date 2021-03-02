NAME = test

CC = clang
OPT = -O2
VERSION = -std=c11
OUTPUT = a.out

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
PRINT_WARNINGS = -Wno-int-conversion -Wno-format -Wno-incompatible-pointer-types
WARNINGS = $(PRINT_WARNINGS) -Wno-unused-function -Wno-macro-redefined
HEADERS =
LIBS = -L/usr/local/lib -lstring -lvector -lhashmap -lstack -llinked_list

INPUT = $(NAME).c

all: compiler

make_library:
	cd ../ && make && cd examples

compiler: make_library
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(LIBS) -o $(OUTPUT) $(INPUT)
	./$(OUTPUT)

clean:
	cd .. && make clean && cd examples
	rm -rf $(OUTPUT)
