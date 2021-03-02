NAME = hashmap

CC = clang
OPT = -O2
VERSION = -std=c89
OUTPUT = $(NAME).so

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS = -Wno-unused-function -Wno-long-long
HEADERS =
LIBS = -fPIC -shared

INPUT = ./*.c

all: default

default:
	$(CC) $(LIB_OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(LIBS) -o $(OUTPUT) $(INPUT)

clean:
	rm -rf ./*.so
