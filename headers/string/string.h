#ifndef __STRING_H_
#define __STRING_H_

#include "../_data_structures.h"

/** The initial minimum size of a string **/
static const size_t string_init_capacity = 32;

/**
 * @struct: string
 * @desc: A mutable string of characters used to dynamically build a string.
 * @param str -> The str char* we construct our string into
 * @param alloced -> The total sized allocated for the string
 * @param length -> The total length of the string
 **/
typedef struct string {
    char *str;
    size_t alloced;
    size_t length;
} string;

/**
 * @func: string_ensure_space
 * @desc: Ensure there is enough space for data being added plus a NULL terminator
 * @param obj -> The typed object containing the string builder
 * @param add_len -> he length that needs to be added *not* including a NULL terminator
 **/
static void string_ensure_space(stringT *obj, size_t add_len);

/**
 * @func: new_string
 * @desc: Create an str builder
 * @return The str builder
 **/
string *string_create();

/**
 * @func: string_add_str
 * @desc: Add a string to the builder
 * @param obj -> The typed object containing the string builder
 * @param str -> The string to add
 * @param len -> The length of the string to add.
 *              If 0, strlen will be called internally to determine length
 **/
void string_add_str(stringT *obj, const char *str);

/**
 * @func: string_add_char
 * @desc: Add a character to the builder
 * @param sb -> The typed object containing the string builder
 * @param c -> The character to add 
 **/
void string_add_char(stringT *obj, char c);

/**
 * @func: string_add_int
 * @desc: Add an integer to the builder
 * @param obj -> The typed object containing the string builder
 * @param val -> The integer to add
 **/
void string_add_int(stringT *obj, size_t val);

/**
 * @func: string_get
 * @desc: A pointer to the internal buffer with the builder's stirng data
 * @param obj -> The typed object containing the string builder
 * @return A pointer to the internal string data
 **/
char *string_get(stringT *obj);

/**
 * @func: string_shorten
 * @desc: Remove data from the end of the builder
 * @param obj -> The typed object containing the string builder
 * @param len -> The new length of the string, anything after this length is removed
 **/
void string_shorten(stringT *obj, size_t len);

/**
 * @func: string_delete
 * @desc: Clear the builder
 * @param obj -> The typed object containing the string builder
 **/
void string_delete(stringT *obj);

/**
 * @func: string_skip
 * @desc: Remove data from the beginning of the builder
 * @param obj -> The typed object containing the string builder
 * @param len -> The length to remove
 **/
void string_skip(stringT *obj, size_t len);

/**
 * @func: string_length
 * @desc: The length of the string contained in the builder
 * @param obj -> The typed object containing the string builder
 * @return The current length of the string
 **/
size_t string_length(stringT *obj);

/**
 * @func: string_free
 * @desc: Free the allocated memory for the char*
 * @param obj -> The typed object containing the string builder
 **/
void string_free(stringT *obj);

#endif