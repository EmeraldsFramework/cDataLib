NAME = test

CC = clang
OPT = -O2
# TODO -> MOVE TO C89
VERSION = -std=c99
OUTPUT = a.out

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS = -Wno-unused-function
HEADERS =
NIX_LIBS = ../export/*.so
OSX_LIBS = ../export/*.a

INPUT = $(NAME).c

all: default

default:
	@echo "Run \`make nix\` or \`make osx\`"

nix: build_nix

linux: build_nix

osx: build_osx

mac: build_osx

make_nix_library:
	cd .. && make nix && cd examples

make_osx_library:
	cd .. && make osx && cd examples

build_nix: make_nix_library
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(PRINT_WARNINGS) $(C99_WARNINGS) $(NIX_LIBS) -o $(OUTPUT) $(INPUT)
	./$(OUTPUT)

build_osx: make_osx_library
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(PRINT_WARNINGS) $(C99_WARNINGS) $(OSX_LIBS) -o $(OUTPUT)      $(INPUT)
	./$(OUTPUT)

clean:
	cd .. && em clean && cd examples
	rm -rf $(OUTPUT)
