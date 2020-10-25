NAME = linked_list

CC = clang
OPT = -march=native -O2
#VERSION = -std=c89
OUTPUT = $(NAME).o
LIB_OUTPUT = $(NAME).so

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS = -Wno-unused-function -Wno-incompatible-pointer-types
HEADERS =
LIBS = -c -fpic

COMPILE = src/$(NAME).c \
		  src/$(NAME)_dup.c \
		  src/$(NAME)_functional_functions.c

all: compiler

compiler:
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(LIBS) $(COMPILE)
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) -shared -o $(LIB_OUTPUT) ./*.o

clean:
	rm -rf ./*.o ./*.so
