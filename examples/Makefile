CC = clang
OPT = -march=native -O2
VERSION = -std=c89
OUTPUT = a.out

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
PRINT_WARNINGS = -Wno-int-conversion -Wno-format -Wno-incompatible-pointer-types
WARNINGS = $(PRINT_WARNINGS) -Wno-unused-function
HEADERS =
LIBS = -lstring -lvector -lhashmap -lstack -llinked_list

COMPILE = test.c

all: compiler

make_library:
	cd ../ && make && cd examples

compiler: make_library
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(LIBS) -o $(OUTPUT) $(COMPILE)
	./$(OUTPUT)

clean:
	cd .. && make clean && cd examples
	rm -rf $(OUTPUT)
