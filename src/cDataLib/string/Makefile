NAME = string

CC = clang
OPT = -O2
#VERSION = -std=c89
VERSION = -std=c11
OUTPUT = $(NAME).so

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS = -Wno-unused-function -Wno-macro-redefined
HEADERS =
LIBS = -fPIC -shared

INPUT = ./*.c ../vector/*.c

all: default

default:
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(LIBS) -o $(OUTPUT) $(INPUT)

clean:
	rm -rf ./*.so
