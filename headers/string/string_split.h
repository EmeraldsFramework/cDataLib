#ifndef __STRING_SPLIT_H_
#define __STRING_SPLIT_H_

#include "../_data_structures.h"

/**
 * @func: string_split
 * @desc: Splits a string to a spesific delimeter
 * @param str -> The typed string to split
 * @param delimeter -> The string delimeter
 * @return A vector with the string tokens
 **/
vectorT *string_split(stringT *str, stringT *delimeter);

#endif