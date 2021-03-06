PARENT_NAME = cDataLib
NAME = stack

CC = clang
OPT = -O2
VERSION = -std=c89
OUTPUT = $(NAME)

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS =
HEADERS =
NIX_LIBS = -shared -fPIC
OSX_LIBS = -c

INPUT = ./*.c

all: default

nix: build_nix

linux: build_nix

osx: build_osx

mac: build_osx

copy_headers:
	cp -r ./headers/* ../../../export/$(PARENT_NAME)/$(NAME)/headers/

default:
	@echo "Run \`make nix\` or \`make osx\`"

build_nix: copy_headers
	$(CC) $(OPT) $(VERSION) $(FLAGS) $(WARNINGS) $(HEADERS) $(NIX_LIBS) -o $(OUTPUT).so $(INPUT)
	mv $(OUTPUT).so ../../../export/

build_osx: copy_headers
	$(CC) $(OPT) $(VERSION) $(FLAGS) $(WARNINGS) $(HEADERS) $(OSX_LIBS) $(INPUT)
	llvm-ar -rcs $(OUTPUT).a *.o
	$(RM) -r *.o
	mv $(OUTPUT).a ../../../export/$(OUTPUT).so

clean:
	$(RM) -r *.o
	$(RM) -r $(OUTPUT).so
