#ifndef __HASHMAP_FUNCTIONAL_FUNCTIONS_H_
#define __HASHMAP_FUNCTIONAL_FUNCTIONS_H_

#include "../_data_structures.h"

/**
 * @func: lambda
 * @desc: A generic function type used upon iterable data structures
 * @param -> An element belonging to an iterable
 * @return -> A value that satisfies the callee's purpose (map, filter, reduce)
 **/
/* The param void* can have more than 1 argument stored as a list of some sort */
/* Since this is completely generic we can't check for validity of arguments */
/* The validity of the function is dependent on the callee */
typedef void* (*lambda)(void*);
typedef void* (*lambda2)(void*, void*);
typedef void* (*lambda3)(void*, void*, void*);
typedef void* (*lambda4)(void*, void*, void*, void*);

/* TODO Obviously find some generic abstraction for the above */

/**
 * @func: hashmap_map
 * @desc: Maps all hashmap elements in iteration using a modifier function pointer
 * @param obj -> The typed object containing the hashmap
 * @param modifier -> The modifier function
 * @return The mapped hashmap duplicate
 **/
hashmapT *hashmap_map(hashmapT *obj, lambda modifier);

/**
 * @func: hashmap_filter
 * @desc: Filters all hashmap elements in iteration using a filter function
 * @param obj -> The typed object containing the hashmap
 * @param filter -> The filter function
 * @return The filtered hashmap duplicate
 **/
hashmapT *hashmap_filter(hashmapT *obj, lambda filter);

/**
 * @func: hashmap_reduce
 * @desc: Recudes all hashmap elements into a void* result using a foldl function
 * @param obj -> The typed object containing the hashmap
 * @param fold -> The folding function to use
 * @return The folder void* result
 **/
void *hashmap_reduce(hashmapT *obj, lambda2 fold, hashmap_element_type element_type);

#endif