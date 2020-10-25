STRING = string
VECTOR = vector
HASHMAP = hashmap
STACK = stack
LINKED_LIST = linked_list

all: compiler

compiler:
	mkdir export
	mkdir export/lib
	cp src/cDataLib.h export/
	cd src/$(VECTOR) && cp headers -r ../../export/$(VECTOR) && make && cp $(VECTOR).so ../../export/lib/ && cd ../../
	cd src/$(STRING) && cp headers -r ../../export/$(STRING) && make && cp $(STRING).so ../../export/lib/ && cd ../../
	cd src/$(HASHMAP) && cp headers -r ../../export/$(HASHMAP) && make && cp $(HASHMAP).so ../../export/lib/ && cd ../../
	cd src/$(STACK) && cp headers -r ../../export/$(STACK) && make && cp $(STACK).so ../../export/lib/ && cd ../../
	cd src/$(LINKED_LIST) && cp headers -r ../../export/$(LINKED_LIST) && make && cp $(LINKED_LIST).so ../../export/lib/ && cd ../../

clean:
	rm -rf export
	cd src/$(STRING) && make clean && cd ../../
	cd src/$(VECTOR) && make clean && cd ../../
	cd src/$(HASHMAP) && make clean && cd ../../
	cd src/$(STACK) && make clean && cd ../../
	cd src/$(LINKED_LIST) && make clean && cd ../../
