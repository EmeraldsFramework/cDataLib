#include "../../headers/_data_structures.h"

hashmapT *hashmap_map(hashmapT *obj, lambda modifier) {
    /* Typecast the value to a hashmap so that it can be manipulated */
    /* In case of invalid inputs */
    if((hashmap *)obj->value == NULL || modifier == NULL) {
        return NULL;
    }

    /* Create a duplicate */
    /* In the case of hashmaps, deleting or setting elements is faster than inserting */
    hashmapT *dup = object_dup(obj);

    /* Typecast the dup */
    hashmap *dup_map = (hashmap*)dup->value;

    /* Iterate with linear probing */
    for(size_t i = 0; i < dup_map->alloced; i++) {
        if(dup_map->data[i].in_use != 0) {
            /* Set the element with the specific key to a modified version of its data */
            hashmap_set(dup, dup_map->data[i].key, modifier(&(dup_map->data[i])));
        }
    }

    /* Return the duplicate typed hashmap */
    return dup;
}

hashmapT *hashmap_filter(hashmapT *obj, lambda filter) {
    /* Typecast the value to a hashmap so that it can be manipulated */
    hashmap *map = (hashmap*)obj->value;

    /* In case of invalid inputs */
    if(map == NULL || filter == NULL) {
        return NULL;
    }

    /* Create a duplicate */
    hashmapT *dup = object_dup(obj);

    /* Typecast the dup */
    hashmap *dup_map = (hashmap*)dup->value;

    /* Iterate with linear probing */
    for(size_t i = 0; i < dup_map->alloced; i++) {
        if(map->data[i].in_use != 0) {
            if(filter(&(dup_map->data[i]))) {
                /* If the data element passes the filter we continue to the next */
                continue;
            }
            /* Delete the element with the specific key from the hashmap */
            hashmap_delete(dup, dup_map->data[i].key);
        }
    }

    /* Return the filtered hashmap */
    return dup;
}



/* FIX MAKE REDUCE ALSO WORD FOR KEYS AND VALUES AND PAIRS */





void *hashmap_reduce(hashmapT *obj, lambda2 fold, hashmap_element_type element_type) {
    /* Typecast the value to a hashmap so that it can be manipulated */
    hashmap *map = (hashmap*)obj->value;

    /* In case of invalid inputs */
    if(map == NULL || fold == NULL) {
        return NULL;
    }

    /* Get the initial value */
    /* Create the value that gets returned with the accumulation of the vector elements */
    void *accumulator;

    /* Iterate through the hashmap */
    for(size_t i = 0; i < map->alloced; i++) {
        if(map->data[i].in_use != 0) {
            /* Set accumulator to some arbitrary hashmap value  */
            accumulator = hashmap_get(obj, map->data[i].key);

            /* Get the current item */
            void *current = hashmap_get(obj, map->data[i].key);

            /* Accumulate the result */
            accumulator = fold(accumulator, current);
        }
    }

    /* Return the accumulated value */
    return object_get_value(accumulator);
}