#ifndef __STRING_FUNCTIONAL_FUNCTIONS_H_
#define __STRING_FUNCTIONAL_FUNCTIONS_H_

#include "string.h"

/**
 * @func: lambda
 * @desc: A generic function type used upon iterable data structures
 * @param -> An element belonging to an iterable
 * @return -> A value that satisfies the callee's purpose (map, filter, reduce)
 **/
/* The param void* can have more than 1 argument stored as a list of some sort */
/* Since this is completely generic we can't check for validity of arguments */
/* The validity of the function is dependent on the callee */
typedef void* (*lambda)();

/**
 * @func: string_iterate
 * @desc: Iterates through the characters of the string
 * @param sb -> The string builder we want to iterate
 * @param apply -> The function we apply to each character
 * @return The mapped string duplicate
 **/
string *string_iterate(string *sb, lambda apply);

#endif