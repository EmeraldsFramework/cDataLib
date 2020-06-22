#ifndef __HASHMAP_DUP_H_
#define __HASHMAP_DUP_H_

#include "../../../cSuite.h"

/**
 * @func: hashmap_dup
 * @desc: Create a memory duplicate of the hashmap
 * @param map -> The map to copy
 * @return The duplicate hashmap
 **/
__export hashmap *hashmap_dup(hashmap *map);

#endif