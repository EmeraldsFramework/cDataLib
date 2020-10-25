CC = clang
OPT = -march=native -O2
#VERSION = -std=c89
OUTPUT = a.out

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS = -Wno-unused-function
HEADERS =
LIBS =

COMPILE = test.c

all: compiler

compiler:
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(LIBS) -o $(OUTPUT) $(COMPILE)
	./$(OUTPUT)

clean:
	rm -rf $(OUTPUT)
