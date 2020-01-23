#ifndef __HASHMAP_H_
#define __HASHMAP_H_

#include "../_data_structures.h"

/* Initial capacity of the hashmap */
static const size_t hashmap_init_capacity = 32;

/* Max chain hash length */
static const size_t max_chain_length = 8;

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

/* A hashmap has some maximum size and current size,
    as well as the data to hold. */

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
} hashmap;

/**
 * @func: hashmap_create
 * @desc: Create an empty hashmap
 * @return: The hashmap
 **/
hashmap *hashmap_create(void);

/**
 * @func: hashmap_add
 * @desc: Add an element to the hashmap
 * @param obj -> The typed object containing the hashmap
 * @param key -> The key of the new element
 * @param value -> The value of the new element
 **/
void hashmap_add(hashmapT *obj, char *key, void *value);

/**
 * @func: hashmap_set
 * @desc: Set an element from the hashmap to a new one
 * @param obj -> The typed object containing the hashmap
 * @param key -> The key to get the value of
 * @param value -> The item to set to the specific key
 **/
void hashmap_set(hashmapT *obj, char *key, void *value);

/**
 * @func: hashmap_get
 * @desc: Get an element from the hashmap
 * @param obj -> The typed object containing the hashmap
 * @param key -> The key to get the value of
 * @return The value we are searching for
 **/
void *hashmap_get(hashmapT *obj, char *key);

/**
 * @func: hashmap_delete
 * @desc: Remove an element from the hashmap
 * @param obj -> The typed object containing the hashmap
 * @param key -> The key of the element to remove
 **/
void hashmap_delete(hashmapT *obj, char *key);

/**
 * @func: hashmap_length
 * @desc: Get the current size of the hashmap
 * @param obj -> The typed object containing the hashmap
 * @return The size of the provided hashmap
 **/
size_t hashmap_length(hashmapT *obj);

/**
 * @func: hashmap_dup
 * @desc: Create a memory duplicate of the hashmap
 * @param obj -> The typed object containing the hashmap to copy
 * @return The duplicate hashmap
 **/
hashmapT *hashmap_dup(hashmapT *obj);

/**
 * @func: hashmap_free
 * @desc: Free (deallocate) the hashmap memory
 * @param obj -> The typed object containing the hashmap
 **/
void hashmap_free(hashmapT *obj);

#endif