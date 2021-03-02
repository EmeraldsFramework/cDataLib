NAME = stack

CC = clang
OPT = -O2
#VERSION = -std=c89
VERSION = -std=c11
OUTPUT = $(NAME).so

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS = -Wno-unused-function
HEADERS =
LIBS = -fPIC -shared

INPUT = ./*.c ../vector/*.c

all: compiler

compiler:
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(LIBS) -o $(OUTPUT) $(INPUT)

clean:
	rm -rf ./*.so
