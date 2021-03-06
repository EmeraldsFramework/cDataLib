NAME = stack

CC = clang
OPT = -O2
VERSION = -std=c89
OUTPUT = $(NAME).so

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS =
HEADERS =
LIBS = -shared -fPIC

INPUT = ./*.c

all: default

default:
	$(CC) $(OPT) $(VERSION) $(FLAGS) $(WARNINGS) $(HEADERS) $(LIBS) -o $(OUTPUT) $(INPUT)

clean:
	$(RM) $(OUTPUT)
