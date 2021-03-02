NAME = cDataLib

CC = clang
OPT = -O2
VERSION = -std=c11

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS =
UNUSED_WARNINGS = -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-extra-semi
REMOVE_WARNINGS = -Wno-macro-redefined
LIBS =

INPUT = src/$(NAME).c src/$(NAME)/*.c
OUTPUT = $(NAME)

#TESTFILES = ../src/$(NAME)/*.c
TESTINPUT = $(NAME).spec.c
TESTOUTPUT = spec_results

STRING = string
VECTOR = vector
HASHMAP = hashmap
STACK = stack
LINKED_LIST = linked_list

all: default

build_export:
	$(RM) -r export
	mkdir export
	mkdir export/$(NAME)
	mkdir export/$(NAME)/$(VECTOR) && mkdir export/$(NAME)/$(VECTOR)/headers
	mkdir export/$(NAME)/$(STRING) && mkdir export/$(NAME)/$(STRING)/headers
	mkdir export/$(NAME)/$(HASHMAP) && mkdir export/$(NAME)/$(HASHMAP)/headers
	mkdir export/$(NAME)/$(STACK) && mkdir export/$(NAME)/$(STACK)/headers
	mkdir export/$(NAME)/$(LINKED_LIST) && mkdir export/$(NAME)/$(LINKED_LIST)/headers

default: build_export
	cp src/cDataLib.h export/
	cd src/$(NAME)/$(VECTOR) && cp -r headers/* ../../../export/$(NAME)/$(VECTOR)/headers && make && cp $(VECTOR).a ../../../export/lib$(VECTOR).a && cd ../../../
	cd src/$(NAME)/$(STRING) && cp -r headers/* ../../../export/$(NAME)/$(STRING)/headers && make && cp $(STRING).a ../../../export/lib$(STRING).a && cd ../../../
	cd src/$(NAME)/$(HASHMAP) && cp -r headers/* ../../../export/$(NAME)/$(HASHMAP)/headers && make && cp $(HASHMAP).a ../../../export/lib$(HASHMAP).a && cd ../../../
	cd src/$(NAME)/$(STACK) && cp -r headers/* ../../../export/$(NAME)/$(STACK)/headers && make && cp $(STACK).a ../../../export/lib$(STACK).a && cd ../../../
	cd src/$(NAME)/$(LINKED_LIST) && cp -r headers/* ../../../export/$(NAME)/$(LINKED_LIST)/headers && make && cp $(LINKED_LIST).a ../../../export/lib$(LINKED_LIST).a && cd ../../../
	cp export/*.a /usr/local/lib/

lib: default

test:
	cd spec && $(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(REMOVE_WARNINGS) $(UNUSED_WARNINGS) $(LIBS) -o $(TESTOUTPUT) $(TESTFILES) $(TESTINPUT)
	@echo
	./spec/$(TESTOUTPUT)

spec: test

clean:
	$(RM) spec/$(TESTOUTPUT)
	$(RM) -r export
	$(RM) -r /usr/local/lib$(VECTOR).a
	$(RM) -r /usr/local/lib$(STRING).a
	$(RM) -r /usr/local/lib$(HASHMAP).a
	$(RM) -r /usr/local/lib$(STACK).a
	$(RM) -r /usr/local/lib$(LINKED_LIST).a
	cd src/$(NAME)/$(STRING) && make clean && cd ../../
	cd src/$(NAME)/$(VECTOR) && make clean && cd ../../
	cd src/$(NAME)/$(HASHMAP) && make clean && cd ../../
	cd src/$(NAME)/$(STACK) && make clean && cd ../../
	cd src/$(NAME)/$(LINKED_LIST) && make clean && cd ../../
