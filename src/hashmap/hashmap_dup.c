#include "../../../cSuite.h"

hashmap *hashmap_dup(hashmap *map) {
    if(map == NULL) return NULL;

    hashmap *dup = new_hashmap();
    
    /* Iteratively copy all hashmap elements from one pointer to another */
    for(size_t i = 0; i < map->alloced; i++)
        if(map->data[i].in_use != 0)
            hashmap_add(dup, map->data[i].key, map->data[i].data);

    return dup;
}
