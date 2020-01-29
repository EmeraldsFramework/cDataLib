#ifndef __OBJECT_H_
#define __OBJECT_H_

#include "../_data_structures.h"

/**
 * @enum: object_type
 * @desc: An enum of object names literals
 **/
typedef enum {
    CHAR,
    SHORT,
    INT,
    LONG,
    LONG_LONG,
    UNSIGNED_CHAR,
    UNSIGNED_SHORT,
    UNSIGNED_INT,
    UNSIGNED_LONG,
    UNSIGNED_LONG_LONG,
    FLOAT,
    DOUBLE,
    LONG_DOUBLE,

    /* Custom data types */
    STRING,
    VECTOR,
    HASHMAP,
    LINKED_LIST,
    BINARY_TREE
} object_type;

/**
 * @struct: object
 * @desc: A wrapper around void* values containing a type
 * @param type -> The type of the object
 * @param value -> The value that the object contains
 **/
typedef struct object {
    object_type type;
    void *value;
} object;

/* Some typenames for calling the types easier */
typedef object charT;
typedef object shortT;
typedef object intT;
typedef object longT;
typedef object longlongT;
typedef object unsignedcharT;
typedef object unsignedshortT;
typedef object unsignedintT;
typedef object unsignedlongT;
typedef object unsignedlonglongT;
typedef object floatT;
typedef object doubleT;
typedef object longdoubleT;
typedef object stringT;
typedef object vectorT;
typedef object hashmapT;
typedef object linked_listT;
typedef object binary_treeT;

/**
 * @func: object_get_value
 * @desc: Get the value of the object
 * @return -> The value
 **/
void *object_get_value(object *object);

/**
 * @func: object_get_type
 * @desc: Get the type of the object
 * @return -> The type of the object
 **/
object_type object_get_type(object *object);

/**
 * @func: object_set_value
 * @desc: Set the value of the object
 * @param value -> The value to set
 **/
void object_set_value(object *object, void *value);

/**
 * @func: object_set_type
 * @desc: Set the value of the object
 * @param type -> The type to set
 **/
void object_set_type(object *object, object_type type);

/**
 * @funcs: new_*
 * @desc: Creates a typed variable value
 * @param value -> The value to insert
 * @return The typed variable
 **/
charT *new_charT(char value);
shortT *new_shortT(short value);
intT *new_intT(int value);
longT *new_longT(long value);
longlongT *new_longlongT(long long value);
unsignedcharT *new_unsignedcharT(unsigned char value);
unsignedshortT *new_unsignedshortT(unsigned short value);
unsignedintT *new_unsignedintT(unsigned int value);
unsignedlongT *new_unsignedlongT(unsigned long value);
unsignedlonglongT *new_unsignedlonglongT(unsigned long value);
floatT *new_floatT(float *value);
doubleT *new_doubleT(double *value);
longdoubleT *new_longdoubleT(long double *value);

/* Custom data types */
stringT *new_stringT(char *value);
vectorT *new_vectorT(void);
hashmapT *new_hashmapT(void);
linked_listT *new_linked_listT(void);
binary_treeT *new_binary_treeT(void);

#endif