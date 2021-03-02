NAME = hashmap

CC = clang
OPT = -O2
VERSION = -std=c89
OUTPUT = $(NAME).a

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS = -Wno-unused-function -Wno-long-long
HEADERS =
LIBS = -c

INPUT = ./*.c

all: default

default:
	$(CC) $(LIB_OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(LIBS) $(INPUT)
	ar -rcs $(OUTPUT) *.o

clean:
	$(RM) -rf ./*.o
	$(RM) $(OUTPUT)
