#include "../../headers/_data_structures.h"

vectorT *vector_map(vectorT *obj, lambda modifier) {
    vector *v = (vector*)obj->value;
    if(v == NULL || modifier == NULL) return NULL;

    vectorT *dup = new_vectorT();
    for(size_t i = 0; i < vector_length(obj); i++) {
        /* Pass each element through the modifier and add it to the new vector */
        vector_add(dup, modifier(vector_get(obj, i)));
    }

    return dup;
}

vectorT *vector_filter(vectorT *obj, lambda filter) {
    vector *v = (vector*)obj->value;
    if(v == NULL || filter == NULL) return NULL;

    vectorT *dup = new_vectorT();
    for(size_t i = 0; i < vector_length(obj); i++) {
        void *item = vector_get(obj, i);
        if(filter(item)) {
            /* If the item passes the filter it gets added to the dup vector */
            vector_add(dup, item);
        }
    }

    return dup;
}

void *vector_reduce(vectorT *obj, lambda2 fold) {
    vector *v = (vector*)obj->value;
    if(v == NULL || fold == NULL) return NULL;

    /* Get the initial value */
    /* Create the value that gets returned with the accumulation of the vector elements */
    void *accumulator = vector_get(obj, 0);

    for(size_t i = 1; i < vector_length(obj); i++) {
        /* Accumulate the current item */
        void *current = vector_get(obj, i);
        accumulator = fold(accumulator, current);
    }
    
    return object_get_value(accumulator);
}