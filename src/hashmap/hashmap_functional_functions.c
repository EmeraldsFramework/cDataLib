#include "../../headers/_data_structures.h"

hashmapT *hashmap_map(hashmapT *obj, lambda modifier, hashmap_element_type element_type) {
    /* Typecast the value to a hashmap so that it can be manipulated */
    hashmap *map = (hashmap*)obj->value;

    /* In case of invalid inputs */
    if(map == NULL || modifier == NULL || element_type == NULL) {
        return NULL;
    }

    /* Create a duplicate */
    /* In the case of hashmaps, deleting or setting elements is faster than inserting */
    hashmapT *dup = object_dup(obj);

    /* Typecast the dup */
    hashmap *dup_map = (hashmap*)dup->value;

    /* Iterate with linear probing */
    for(size_t i = 0; i < map->alloced; i++) {
        if(map->data[i].in_use != 0) {
            switch(element_type) {
                case KEYS:
                    /* Modify the keys in some shape or form */
                    /* TODO CREATE ACCESSOR METHODS */
                    dup_map->data[i].key = modifier(map->data[i].key);
                    break;
                case VALUES:
                    /* Modify the values in some shape or form */
                    hashmap_set(dup, map->data[i].key, modifier(map->data[i].data));
                    break;
                default:
                    return NULL;
            }
        }
    }

    /* Return the duplicate typed hashmap */
    return dup;
}

hashmapT *hashmap_filter(hashmapT *obj, lambda filter, hashmap_element_type element_type) {
    /* Typecast the value to a hashmap so that it can be manipulated */
    hashmap *map = (hashmap*)obj->value;

    /* In case of invalid inputs */
    if(map == NULL || filter == NULL || element_type == NULL) {
        return NULL;
    }

    /* Create a duplicate */
    hashmapT *dup = object_dup(obj);

    /* Iterate with linear probing */
    for(size_t i = 0; i < map->alloced; i++) {
        if(map->data[i].in_use != 0) {
            switch(element_type) {
                case KEYS:
                    if(filter(map->data[i].key)) {
                        /* If the key passes the filter we continue to the next */
                        continue;
                    }
                    /* Delete the element with the specific key from the hashmap */
                    hashmap_delete(dup, map->data[i].key);
                    break;
                case VALUES:
                    if(filter(map->data[i].data)) {
                        /* If the value passes the filter we continue to the next */
                        continue;
                    }
                    /* Delete the element with the specific key from the hashmap */
                    hashmap_delete(dup, map->data[i].key);
                    break;
                default:
                    return NULL;
            }
        }
    }

    /* Return the filtered hashmap */
    return dup;
}

void *hashmap_reduce(hashmapT *obj, lambda2 fold, hashmap_element_type element_type) {
    /* Typecast the value to a hashmap so that it can be manipulated */
    hashmap *map = (hashmap*)obj->value;

    /* In case of invalid inputs */
    if(map == NULL || fold == NULL || element_type == NULL) {
        return NULL;
    }

    /* Get the initial value */
    /* Create the value that gets returned with the accumulation of the vector elements */
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

    /* Return the accumulated value */
    return object_get_value(accumulator);
}
