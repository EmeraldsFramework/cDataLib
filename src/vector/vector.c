#include "../../headers/_data_structures.h"

static void vector_ensure_space(vectorT *obj, size_t capacity) {
    vector *v = (vector*)obj->value;
    if(v == NULL || capacity == 0) return;

    /* Attempt to reallocate new memory in the items list */
    void **items = realloc(v->items, sizeof(void*) * capacity);

    if(items) {
        /* Reset the items in the new memory space */
        v->items = items;
        v->alloced = capacity;
    }
}

vector *vector_create(void) {
    vector *v = malloc(sizeof(vector));

    v->alloced = vector_init_capacity;
    v->length = 0;

    /* Allocate space for the items array */
    v->items = malloc(sizeof(void*) * v->alloced);

    /* Return the created vector */
    return v;
}

void vector_add(vectorT *obj, void *item) {
    vector *v = (vector*)obj->value;
    if(v == NULL) return;
    /* TODO We allow NULL elements (NOT TESTED) */

    if(v->alloced == v->length) {
        /* Double the memory space if size is appropriate */
        vector_ensure_space(obj, v->alloced * 2);
    }

    v->items[v->length++] = item;
}

void vector_set(vectorT *obj, size_t index, void *item) {
    vector *v = (vector*)obj->value;
    if(v == NULL) return;

    /* As long as the index is valid */
    if(index >= 0 && index < v->length) {
        v->items[index] = item;
    }
}

void *vector_get(vectorT *obj, size_t index) {
    vector *v = (vector*)obj->value;
    if(v == NULL) return NULL;

    /* As long as the index is valid */
    if(index >= 0
    && index < v->length) return v->items[index];
    return NULL;
}

void vector_delete(vectorT *obj, size_t index) {
    vector *v = (vector*)obj->value;
    if(v == NULL) return;
    if(index < 0 || index >= v->length) return;
    
    v->items[index] = NULL;

    /* Reset the rest of the elements forwards */
    for(int i = index; i < v->length - 1; i++) {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = NULL;
    }

    /* Reset the total */
    v->length--;

    if(v->length > 0 && v->length == v->alloced / 4) {
        vector_ensure_space(obj, v->alloced / 2);
    }
}

size_t vector_length(vectorT *obj) {
    vector *v = (vector*)obj->value;
    if(v == NULL) return 0;
    return v->length;
};

void vector_free(vectorT *obj) {
    vector *v = (vector*)obj->value;
    if(v == NULL) return;

    free(v->items);
    free(v);
}
