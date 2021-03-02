NAME = linked_list

CC = clang
OPT = -O2
#VERSION = -std=c89
VERSION = -std=c11
OUTPUT = $(NAME).a

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS = -Wno-unused-function
HEADERS =
LIBS = -c

INPUT = ./*.c

all: compiler

compiler:
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(LIBS) $(INPUT)
	ar -rcs $(OUTPUT) *.o

clean:
	$(RM) -r ./*.o
	$(RM) $(OUTPUT)
