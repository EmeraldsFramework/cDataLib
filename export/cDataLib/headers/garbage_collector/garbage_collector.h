#ifndef __GARBAGE_COLLECTOR_H_
#define __GARBAGE_COLLECTOR_H_

#include "../_data_structures.h"

/**
 * @struct: gc_item
 * @desc: Items stored in the garbage collector
 * @param marked -> A flag used for collection of memory to free
 * @param next -> The next item in the stack
 * @param value -> The actual value pointer we store
 **/
typedef struct gc_item {
    unsigned char marked;
    struct gc_item *next;
    void *value;
} gc_item;

/**
 * @struct garbage_collector
 * @desc: A linked list implementation of a garbage collector with stack push/pop handlers
 * @param stack -> The stack of elements inside the garbage collector
 * @param stack_size -> The size of elements stored in the collector
 * @param first_object -> The head node of the list of elements
 * @param num_of_objects -> The number of allocated objects
 * @param max_objects -> The number of objects signaling a gc extension
 **/
typedef struct {
    gc_item **stack;
    int stack_size;
    gc_item *first_object;
    int num_of_objects;
    int max_objects;
} garbage_collector;

/**
 * @func: new_garbage_collector
 * @desc: Creates a new instance of a garbage collector
 * @param stack_max -> The maximum size of elements
 * @return The new gc intance
 **/
garbage_collector *new_garbage_collector(const size_t stack_max);

/**
 * @func: garbage_collector_collect
 * @desc: Collect all elements to be freed
 * @param gc -> The gc which items we collect
 **/
void garbage_collector_collect(garbage_collector *gc);

/**
 * @func: garbage_collector_push_value
 * @desc: Create a new object and push it to the gc
 *          (THIS IS CALLED FOR EACH MEMORY ALLOCATION)
 * @param gc -> The gc to add to
 * @param value -> The value to wrap with an object wrapper
 **/
void garbage_collector_push_value(garbage_collector *gc, void *value);

/**
 * @func: garbage_collector_free
 * @desc: Free all memory allocated and saved inside the gc
 * @param gc -> The gc to free
 **/
void garbage_collector_free(garbage_collector *gc);

#endif