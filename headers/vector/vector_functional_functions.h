#ifndef __VECTOR_FUNCTIONAL_FUNCTIONS_H_
#define __VECTOR_FUNCTIONAL_FUNCTIONS_H_

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

/**
 * @func: vector_map
 * @desc: Maps all vector elements in iteration using a modifier function pointer
 * @param obj -> The typed object containing the hashmap to map
 * @param modifier -> The modifier function
 * @return The mapped vector duplicate
 **/
vector *vector_map(typed_object *obj, lambda modifier);

/**
 * @func: vector_filter
 * @desc: Filters all vector elements in iteration using a filter function
 * @param obj -> The typed object containing the hashmap to filter
 * @param filter -> The filter function
 * @return The filtered vector duplicate
 **/
vector *vector_filter(typed_object *obj, lambda filter);

/**
 * @func: vector_reduce
 * @desc: Recudes all vector elements into a void* result using a foldl function
 * @param obj -> The typed object containing the hashmap to reduce
 * @param fold -> The folding function to use
 * @return The folder void* result
 **/
void *vector_reduce(typed_object *obj, lambda fold);

#endif