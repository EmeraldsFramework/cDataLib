#ifndef __VECTOR_H_
#define __VECTOR_H_

#include "../_data_structures.h"

/* Initial capacity of a vector */
static const size_t vector_init_capacity = 32;

/**
 * @struct: vector
 * @desc: Defines a vector data structure
 * @param items -> A void pointer array that contains the heterogenous elements of the vector
 * @param alloced -> The total capacity of the vector
 * @param length -> The total number of values
 * @param gc -> The garbage collector to save objects to
 **/
typedef struct vector {
    void **items;
    size_t alloced;
    size_t length;
    garbage_collector *gc;
} vector;

/**
 * @func: vector_ensure_space
 * @desc: Ensure there is enough space for our values in the vector
 * @param obj -> The typed object containing the vector
 * @param capacity -> The new capacity to set
 **/
static void vector_ensure_space(typed_object *obj, size_t capacity);

/**
 * @func: new_vector
 * @desc: Initializes a vector data structure
 * @return: The newly created vector
 **/
typed_object *new_vector(void);

/**
 * @func: vector_add
 * @desc: Adds a new element in the vector
 * @param obj -> The typed object containing the vector
 * @param item -> The item to add
 **/
void vector_add(typed_object *obj, void *item);

/**
 * @func: vector_set
 * @desc: Set the value of a specific vector index to a new one
 * @param v-> The vector
 * @param index -> The index to set the value of
 * @param item -> The item to set the value as
 **/
void vector_set(typed_object *obj, size_t index, void *item);

/**
 * @func: vector_get
 * @desc: Get the value of a specific vector index
 * @param obj -> The typed object containing the vector
 * @param index -> The index to get the value of
 * @return The value
 **/
void *vector_get(typed_object *obj, size_t index);

/**
 * @func: vector_delete
 * @desc: Delete a specific vector value by index
 * @param obj -> The typed object containing the vector
 * @param index -> The index to delete
 **/
void vector_delete(typed_object *obj, size_t index);

/**
 * @func: vector_length
 * @desc: Get the total number of values inserted in the vector
 * @param obj -> The typed object containing the vector
 * @return: The number of items in the vector
 **/
size_t vector_length(typed_object *obj);

/**
 * @func: vector_dup
 * @desc: Get a memory duplicate of the passed vector
 * @param obj -> The typed object containing the vector
 * @return The duplicate vector
 **/
typed_object *vector_dup(typed_object *obj);

/**
 * @func: vector_free
 * @desc: Free the allocated memory from the vector
 * @param obj -> The typed object containing the vector
 **/
void vector_free(typed_object *obj);

#endif