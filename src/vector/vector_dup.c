#include "../../headers/_data_structures.h"

vectorT *vector_dup(vectorT *obj) {
    /* Typecast the value to a string so that it can be manipulated */
    vector *v = (vector*)obj->value;

    /* In case of empty vector */
    if(v == NULL) {
        return NULL;
    }

    /* Allocate new space for the vector */
    vectorT *dup = new_vectorT();

    /* Iteratively copy the vector items from one memory location to another */
    for(size_t i = 0; i < vector_length(obj); i++) {
        vector_add(dup, vector_get(obj, i));
    }

    /* Return the new vector duplicate */
    return dup;
}
