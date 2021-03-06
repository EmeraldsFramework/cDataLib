NAME = cDataLib
STRING = string
VECTOR = vector
HASHMAP = hashmap
STACK = stack
LINKED_LIST = linked_list

CC = clang
OPT = -O2
VERSION = -std=c11

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS =
UNUSED_WARNINGS = -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-extra-semi
REMOVE_WARNINGS = -Wno-macro-redefined
LIBS =

INPUT = src/$(NAME).c
OUTPUT = $(NAME)

#TESTFILES = ../src/$(NAME)/*.c
TESTINPUT = $(NAME).spec.c
TESTOUTPUT = spec_results

all: default

nix: build_nix

linux: build_nix

osx: build_osx

mac: build_osx

# TODO -> ADD A UNAME TYPE OF BUILD

default:
	@echo "Run \`make nix\` or \`make osx\`"

build_export:
	$(RM) -r export
	mkdir export
	mkdir export/$(NAME)
	mkdir export/$(NAME)/$(VECTOR) && mkdir export/$(NAME)/$(VECTOR)/headers
	mkdir export/$(NAME)/$(STRING) && mkdir export/$(NAME)/$(STRING)/headers
	mkdir export/$(NAME)/$(HASHMAP) && mkdir export/$(NAME)/$(HASHMAP)/headers
	mkdir export/$(NAME)/$(STACK) && mkdir export/$(NAME)/$(STACK)/headers
	mkdir export/$(NAME)/$(LINKED_LIST) && mkdir export/$(NAME)/$(LINKED_LIST)/headers
	cp src/$(NAME).h export/

build_nix: build_export
	cd src/$(NAME)/$(VECTOR) && make nix && cd ../../../
	cd src/$(NAME)/$(STRING) && make nix && cd ../../../
	cd src/$(NAME)/$(HASHMAP) && make nix && cd ../../../
	cd src/$(NAME)/$(STACK) && make nix && cd ../../../
	cd src/$(NAME)/$(LINKED_LIST) && make nix && cd ../../../

build_osx: build_export
	cd src/$(NAME)/$(VECTOR) && make osx && cd ../../../
	cd src/$(NAME)/$(STRING) && make osx && cd ../../../
	cd src/$(NAME)/$(HASHMAP) && make osx && cd ../../../
	cd src/$(NAME)/$(STACK) && make osx && cd ../../../
	cd src/$(NAME)/$(LINKED_LIST) && make osx && cd ../../../

test:
	cd spec && $(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(REMOVE_WARNINGS) $(UNUSED_WARNINGS) $(LIBS) -o $(TESTOUTPUT) $(TESTFILES) $(TESTINPUT)
	@echo
	./spec/$(TESTOUTPUT)

spec: test

clean:
	$(RM) spec/$(TESTOUTPUT)
	$(RM) -r export
	cd src/$(NAME)/$(STRING) && make clean && cd ../../
	cd src/$(NAME)/$(VECTOR) && make clean && cd ../../
	cd src/$(NAME)/$(HASHMAP) && make clean && cd ../../
	cd src/$(NAME)/$(STACK) && make clean && cd ../../
	cd src/$(NAME)/$(LINKED_LIST) && make clean && cd ../../
