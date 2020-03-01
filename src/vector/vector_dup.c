#include "../../headers/_data_structures.h"

vectorT *vector_dup(vectorT *obj) {
    vector *v = (vector*)obj->value;
    if(v == NULL) return NULL;

    vectorT *dup = new_vectorT();
    for(size_t i = 0; i < vector_length(obj); i++) {
        /* Iteratively copy the vector items from one memory location to another */
        vector_add(dup, vector_get(obj, i));
    }

    return dup;
}
