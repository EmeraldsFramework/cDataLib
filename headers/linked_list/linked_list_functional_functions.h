#ifndef __LINKED_LIST_FUNCTIONAL_FUNCTIONS_H_
#define __LINKED_LIST_FUNCTIONAL_FUNCTIONS_H_

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
 * @func: linked_list_map
 * @desc: Maps all linked list elements in iteration using a modifier function pointer
 * @param obj -> The typed object containing the linked list to map
 * @param modifier -> The modifier function
 * @return The mapped linked list duplicate
 **/
linked_listT *linked_list_map(linked_listT *obj, lambda modifier);

#endif