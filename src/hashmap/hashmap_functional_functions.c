#include "../../headers/_data_structures.h"

hashmapT *hashmap_map(hashmapT *obj, lambda modifier, hashmap_element_type element_type) {
    hashmap *map = (hashmap*)obj->value;
    if(map == NULL || modifier == NULL || element_type == NULL) return NULL;

    hashmapT *dup = object_dup(obj);
    hashmap *dup_map = (hashmap*)dup->value;
    
    /* Iterate with linear probing */
    for(size_t i = 0; i < map->alloced; i++) {
        if(map->data[i].in_use != 0) {
            switch(element_type) {
                case KEYS:
                    /* TODO CREATE ACCESSOR METHODS */
                    dup_map->data[i].key = modifier(map->data[i].key);
                    break;
                case VALUES:
                    hashmap_set(dup, map->data[i].key, modifier(map->data[i].data));
                    break;
                default:
                    return NULL;
            }
        }
    }

    return dup;
}

hashmapT *hashmap_filter(hashmapT *obj, lambda filter, hashmap_element_type element_type) {
    hashmap *map = (hashmap*)obj->value;
    if(map == NULL || filter == NULL || element_type == NULL) return NULL;

    hashmapT *dup = object_dup(obj);

    /* Iterate with linear probing */
    for(size_t i = 0; i < map->alloced; i++) {
        if(map->data[i].in_use != 0) {
            switch(element_type) {
                case KEYS:
                    /* If the key passes the filter we continue to the next */
                    if(filter(map->data[i].key)) continue;

                    /* Delete the element with the specific key from the hashmap */
                    hashmap_delete(dup, map->data[i].key);
                    break;
                case VALUES:
                    /* If the value passes the filter we continue to the next */
                    if(filter(map->data[i].data)) continue;

                    /* Delete the element with the specific key from the hashmap */
                    hashmap_delete(dup, map->data[i].key);
                    break;
                default:
                    return NULL;
            }
        }
    }

    return dup;
}

void *hashmap_reduce(hashmapT *obj, lambda2 fold, hashmap_element_type element_type) {
    hashmap *map = (hashmap*)obj->value;
    if(map == NULL || fold == NULL || element_type == NULL) return NULL;

    void *accumulator;
    void *current;

    /* Iterate through the hashmap */
    for(size_t i = 0; i < map->alloced; i++) {
        if(map->data[i].in_use != 0) {
            switch(element_type) {
                case KEYS:
                    /* Set accumulator to some arbitrary hashmap key */
                    accumulator = map->data[i].key;

                    /* Get the current item */
                    current = map->data[i].key;

                    /* Accumulate the result */
                    accumulator = fold(accumulator, current);
                    break;
                case VALUES:
                    /* Set accumulator to some arbitrary hashmap value  */
                    accumulator = hashmap_get(obj, map->data[i].key);
                    
                    /* Get the current item */
                    current = hashmap_get(obj, map->data[i].key);
                    
                    /* Accumulate the result */
                    accumulator = fold(accumulator, current);
                    break;
                default:
                    return NULL;
            }
        }
    }
    
    return object_get_value(accumulator);
}
