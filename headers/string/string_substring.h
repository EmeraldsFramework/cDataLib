#ifndef __STRING_SUBSTRING_H_
#define __STRING_SUBSTRING_H_

#include "../_data_structures.h"

/**
 * @func: string_substring
 * @desc: Return a substring of our current string without modifying the original
 * @param obj -> The typed object containing the string builder
 * @param from -> The point where we start our substring
 * @param to -> The point where we end our substring
 * @return A substring of a copy of the original string
 **/
typed_object *string_substring(typed_object *obj, size_t from, size_t to);

#endif
