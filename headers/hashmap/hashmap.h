#ifndef __HASHMAP_H_
#define __HASHMAP_H_

#include "../../../cSuite.h"

/* Initial capacity of the hashmap */
static const size_t hashmap_init_capacity = 32;
static const size_t max_chain_length = 8;

/**
 * @enum: hashmap_element_type
 * @desc: Defines an enum of KEYS or VALUES
 **/
typedef enum {
	KEYS,
	VALUES
} hashmap_element_type;

/**
 * @struct: hashmap_element
 * @desc: Elements contained in the hashmap both keys and values
 * @param key -> The key of the element
 * @param data -> The value of the element
 * @param map_use -> Boolean used for hashmap operations and linear probing
 **/
typedef struct _hashmap_element {
	char *key;
	void *data;
	size_t in_use;
} hashmap_element;

/**
 * @struct: hashmap
 * @desc: A hashmap struct that has some maximum size and
 *          current size as well as the data to hold
 * @param alloced -> The maximum allocated size
 * @param length -> The current total size
 * @param data -> The data array contained
 **/
typedef struct _hashmap {
	size_t alloced;
	size_t length;
	hashmap_element *data;
	bool persistance;
} hashmap;

/**
 * @func: hashmap_create
 * @desc: Create an empty hashmap
 * @return: The hashmap
 **/
hashmap *hashmap_create(void);
hashmap *hashmap_persistent_create(void);
#define new_hashmap() hashmap_create()
#define new_persistent_hashmap() hashmap_persistent_create()

/**
 * @func: hashmap_add
 * @desc: Add an element to the hashmap
 * @param map -> The hashmap to use
 * @param key -> The key of the new element
 * @param value -> The value of the new element
 **/
void hashmap_add(hashmap *map, char *key, void *value);

/**
 * @func: hashmap_set
 * @desc: Set an element from the hashmap to a new one
 * @param map -> The hashmap to use
 * @param key -> The key to get the value of
 * @param value -> The item to set to the specific key
 **/
void hashmap_set(hashmap *map, char *key, void *value);

/**
 * @func: hashmap_get
 * @desc: Get an element from the hashmap
 * @param map -> The hashmap to use
 * @param key -> The key to get the value of
 * @return The value we are searching for
 **/
void *hashmap_get(hashmap *map, char *key);

/**
 * @func: hashmap_delete
 * @desc: Remove an element from the hashmap
 * @param map -> The hashmap to use
 * @param key -> The key of the element to remove
 **/
void hashmap_delete(hashmap *map, char *key);

/**
 * @func: hashmap_length
 * @desc: Get the current size of the hashmap
 * @param map -> The hashmap to use
 * @return The size of the provided hashmap
 **/
size_t hashmap_length(hashmap *map);

#endif