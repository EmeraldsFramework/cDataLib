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
	cd src/$(VECTOR) && cp headers -r ../../export/$(VECTOR) && make && cp $(VECTOR).so ../../export/lib/lib$(VECTOR).so && cd ../../
	cd src/$(STRING) && cp headers -r ../../export/$(STRING) && make && cp $(STRING).so ../../export/lib/lib$(STRING).so && cd ../../
	cd src/$(HASHMAP) && cp headers -r ../../export/$(HASHMAP) && make && cp $(HASHMAP).so ../../export/lib/lib$(HASHMAP).so && cd ../../
	cd src/$(STACK) && cp headers -r ../../export/$(STACK) && make && cp $(STACK).so ../../export/lib/lib$(STACK).so && cd ../../
	cd src/$(LINKED_LIST) && cp headers -r ../../export/$(LINKED_LIST) && make && cp $(LINKED_LIST).so ../../export/lib/lib$(LINKED_LIST).so && cd ../../
	cp export/lib/* /usr/lib/

clean:
	rm -rf export
	rm -rf /usr/lib/lib/$(VECTOR).so
	rm -rf /usr/lib/lib/$(STRING).so
	rm -rf /usr/lib/lib/$(HASHMAP).so
	rm -rf /usr/lib/lib/$(STACK).so
	rm -rf /usr/lib/lib/$(LINKED_LIST).so
	cd src/$(STRING) && make clean && cd ../../
	cd src/$(VECTOR) && make clean && cd ../../
	cd src/$(HASHMAP) && make clean && cd ../../
	cd src/$(STACK) && make clean && cd ../../
	cd src/$(LINKED_LIST) && make clean && cd ../../
