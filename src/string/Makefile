NAME = string

CC = clang
OPT = -march=native -O2
#VERSION = -std=c89
OUTPUT = $(NAME).o
LIB_OUTPUT = $(NAME).so

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS = -Wno-unused-function
HEADERS =
LIBS = -c -fpic

COMPILE = src/$(NAME).c \
		  src/$(NAME)_dup.c \
		  src/$(NAME)_functional_functions.c \
		  src/$(NAME)_interpolation.c \
		  src/$(NAME)_split.c \
		  src/$(NAME)_substring.c

all: compiler

compiler:
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(LIBS) $(COMPILE)
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) -shared -o $(LIB_OUTPUT) ./*.o

clean:
	rm -rf ./*.o ./*.so
