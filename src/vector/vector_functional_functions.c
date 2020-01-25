#include "../../headers/_data_structures.h"

vectorT *vector_map(vectorT *obj, lambda modifier) {
    /* Typecast the value to a vector so that it can be manipulated */
    vector *v = (vector*)obj->value;
    
    /* In case of invalid inputs */
    if(v == NULL || modifier == NULL) {
        return NULL;
    }

    /* Create a new vector */
    vectorT *dup = new_vectorT();

    /* Iterate over the elements */
    for(size_t i = 0; i < vector_length(obj); i++) {
        /* Modify the element and add it to the new vector */
        vector_add(dup, modifier(vector_get(obj, i)));
    }

    /* Return the new vector */
    return dup;
}

vectorT *vector_filter(vectorT *obj, lambda filter) {
    /* Typecast the value to a vector so that it can be manipulated */
    vector *v = (vector*)obj->value;

    /* In case of invalid inputs */
    if(v == NULL || filter == NULL) {
        return NULL;
    }

    /* Create a new vector */
    vectorT *dup = new_vectorT();

    /* Iterate over the elements */
    for(size_t i = 0; i < vector_length(obj); i++) {
        /* Get the item */
        void *item = vector_get(obj, i);

        /* If the item passes the filter */
        if(filter(item)) {
            /* Gets added to the dup vector */
            vector_add(dup, item);
        }
    }
    
    /* Return the new vector */
    return dup;
}

void *vector_reduce(vectorT *obj, lambda2 fold) {
    /* Typecast the value to a vector so that it can be manipulated */
    vector *v = (vector*)obj->value;

    /* In case of invalid inputs */
    if(v == NULL || fold == NULL) {
        return NULL;
    }

    /* Get the initial value */
    /* Create the value that gets returned with the accumulation of the vector elements */
    void *accumulator = vector_get(obj, 0);

    /* Iterate over the elements */
    for(size_t i = 1; i < vector_length(obj); i++) {
        /* Get the current item */
        void *current = vector_get(obj, i);
        accumulator = fold(accumulator, current);
    }

    /* Return the accumulated value */
    return object_get_value(accumulator);
}