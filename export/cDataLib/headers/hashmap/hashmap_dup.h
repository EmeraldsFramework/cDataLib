#ifndef __HASHMAP_DUP_H_
#define __HASHMAP_DUP_H_

#include "../_data_structures.h"

/**
 * @func: hashmap_dup
 * @desc: Create a memory duplicate of the hashmap
 * @param obj -> The typed object containing the hashmap to copy
 * @return The duplicate hashmap
 **/
hashmapT *hashmap_dup(hashmapT *obj);

#endif