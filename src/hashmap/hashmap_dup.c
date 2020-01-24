#include "../../headers/_data_structures.h"

hashmapT *hashmap_dup(hashmapT *obj) {
    /* Typecast the value to a hashmap so that it can be manipulated */
    hashmap *map = (hashmap*)obj->value;
    
    /* In case of empty map */
    if(map == NULL) {
        return NULL;
    }

    /* Allocate space for a new hashmap */
    hashmapT *dup = new_hashmapT();

    /* Iteratively copy all hashmap elements from one pointer to another */
    for(size_t i = 0; i < map->alloced; i++) {
        if(map->data[i].in_use != 0) {
            hashmap_add(dup, map->data[i].key, map->data[i].data);
        }
    }

    /* Return the duplicate */
    return dup;
}
