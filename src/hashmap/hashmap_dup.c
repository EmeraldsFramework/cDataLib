#include "../../headers/_data_structures.h"

hashmapT *hashmap_dup(hashmapT *obj) {
    hashmap *map = (hashmap*)obj->value;
    if(map == NULL) return NULL;

    hashmapT *dup = new_hashmapT();
    for(size_t i = 0; i < map->alloced; i++) {
        /* Iteratively copy all hashmap elements from one pointer to another */
        if(map->data[i].in_use != 0) {
            hashmap_add(dup, map->data[i].key, map->data[i].data);
        }
    }

    return dup;
}
