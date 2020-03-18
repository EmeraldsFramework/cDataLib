// #ifndef __OBJECT_H_
// #define __OBJECT_H_

// #include "../_data_structures.h"

// /**
//  * @enum: object_type
//  * @desc: An enum of object names literals
//  **/
// typedef enum {
//     STRING,
//     VECTOR,
//     HASHMAP,
//     LINKED_LIST,
//     BINARY_TREE,
//     STACK
// } object_type;

// /**
//  * @struct: object
//  * @desc: A wrapper around void* values containing a type
//  * @param type -> The type of the object
//  * @param value -> The value that the object contains
//  **/
// typedef struct object {
//     object_type type;
//     void *value;
// } object;

// typedef object stringT;
// typedef object vectorT;
// typedef object hashmapT;
// typedef object linked_listT;
// typedef object binary_treeT;
// typedef object stackT;

// /**
//  * @func: object_get_value
//  * @desc: Get the value of the object
//  * @return -> The value
//  **/
// void *object_get_value(object *object);

// /**
//  * @func: object_get_type
//  * @desc: Get the type of the object
//  * @return -> The type of the object
//  **/
// object_type object_get_type(object *object);

// /**
//  * @func: object_set_value
//  * @desc: Set the value of the object
//  * @param value -> The value to set
//  **/
// void object_set_value(object *object, void *value);

// /**
//  * @func: object_set_type
//  * @desc: Set the value of the object
//  * @param type -> The type to set
//  **/
// void object_set_type(object *object, object_type type);

// stringT *new_stringT(char *value);
// vectorT *new_vectorT(void);
// hashmapT *new_hashmapT(void);
// linked_listT *new_linked_listT(void);
// binary_treeT *new_binary_treeT(void);
// stackT *new_stackT(void);

// #endif