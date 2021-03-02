#include "headers/vector_dup.h"

vector *vector_dup(vector *v) {
    if(v == NULL) return NULL;

    vector *dup = new_vector();
    
    /* Iteratively copy the vector items from one memory location to another */
    size_t i;
    for(i = 0; i < vector_length(v); i++)
        vector_add(dup, vector_get(v, i));

    return dup;
}
