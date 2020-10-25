STRING = src/string
VECTOR = src/vector
HASHMAP = src/hashmap
STACK = src/stack
LINKED_LIST = src/linked_list

all: compiler

compiler:
	cd $(STRING) && make && cd ../../
	cd $(VECTOR) && make && cd ../../
	cd $(HASHMAP) && make && cd ../../
	cd $(STACK) && make && cd ../../
	cd $(LINKED_LIST) && make && cd ../../

clean:
	cd $(STRING) && make clean && cd ../../
	cd $(VECTOR) && make clean && cd ../../
	cd $(HASHMAP) && make clean && cd ../../
	cd $(STACK) && make clean && cd ../../
	cd $(LINKED_LIST) && make clean && cd ../../
