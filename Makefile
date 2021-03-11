NAME = cDataLib

DEPS = $(shell find ./export -name "*.*o") $(shell find ./libs -name "*.*o")

all: default

make_export:
	$(RM) -r export && mkdir export

copy_headers:
	mkdir export/$(NAME) && mkdir export/$(NAME)/headers
	cp src/$(NAME).h export/

default: lib

lib: $(shell uname)
	cp $(shell find ./libs -name "*.*o") export/

Darwin: make_export copy_headers

Linux: make_export copy_headers

test:
	@echo

spec: test

clean:
	$(RM) -r export

