#ifndef __TYPED_OBJECT_H_
#define __TYPED_OBJECT_H_

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
    HASHMAP
} object_type;

/**
 * @struct: typed_object
 * @desc: A wrapper around void* values containing a type
 * @param type -> The type of the object
 * @param value -> The value that the object contains
 **/
typedef struct typed_object {
    object_type type;
    void *value;
} typed_object;

/* Some typenames for calling the types easier */
typedef typed_object charT;
typedef typed_object shortT;
typedef typed_object intT;
typedef typed_object longT;
typedef typed_object longlongT;
typedef typed_object unsignedcharT;
typedef typed_object unsignedshortT;
typedef typed_object unsignedintT;
typedef typed_object unsignedlongT;
typedef typed_object unsignedlonglongT;
typedef typed_object floatT;
typedef typed_object doubleT;
typedef typed_object longdoubleT;
typedef typed_object stringT;
typedef typed_object vectorT;
typedef typed_object hashmapT;

/**
 * @func: typed_object_get_value
 * @desc: Get the value of the object
 * @return -> The value
 **/
void *typed_object_get_value(typed_object *object);

/**
 * @func: typed_object_get_type
 * @desc: Get the type of the object
 * @return -> The type of the object
 **/
object_type typed_object_get_type(typed_object *object);

/**
 * @func: typed_object_set_value
 * @desc: Set the value of the object
 * @param value -> The value to set
 **/
void typed_object_set_value(typed_object *object, void *value);

/**
 * @func: typed_object_set_type
 * @desc: Set the value of the object
 * @param type -> The type to set
 **/
void typed_object_set_type(typed_object *object, object_type type);

/**
 * @funcs: new_*
 * @desc: Creates a typed variable value
 * @param value -> The value to insert
 * @return The typed variable
 **/
intT *new_int(int value);
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

/**
 * @func: typed_object_free
 * @desc: Frees a typed object
 * @param obj -> The object to free
 **/
void typed_object_free(typed_object *obj);

// /**
//  * @func: typed_object_typecast
//  * @desc: Typecast the object passed according to its type field
//  * @param obj -> The object to typecast
//  **/
// void *typed_object_typecast(void *obj);

#endif