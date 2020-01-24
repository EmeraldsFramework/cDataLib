#include "../../headers/_data_structures.h"

static void vector_ensure_space(vectorT *obj, size_t capacity) {
    /* Typecast the value to a string so that it can be manipulated */
    vector *v = (vector*)obj->value;

    /* In case of invalid input */
    if(v == NULL || capacity == 0) {
        return;
    }

    /* Attempt to reallocate new memory in the items list */
    void **items = realloc(v->items, sizeof(void*) * capacity);

    /* If items exist reset the items in the new memory space */
    if(items) {
        v->items = items;
        v->alloced = capacity;
    }
}

vector *vector_create(void) {
    /* Allocate space for the vector */
    vector *v = malloc(sizeof(vector));

    /* Set base values */
    v->alloced = vector_init_capacity;
    v->length = 0;

    /* Allocate memory according to the data type we insert */
    v->items = malloc(sizeof(void*) * v->alloced);

    /* Return the vector */
    return v;
}

void vector_add(vectorT *obj, void *item) {
    /* Typecast the value to a string so that it can be manipulated */
    vector *v = (vector*)obj->value;

    /* In case of empty vector */
    if(v == NULL) {
        return;
    }

    /* We allow NULL elements (NOT TESTED) */

    /* Check if the size is appropriate */
    if(v->alloced == v->length) {
        /* Double the memory space */
        vector_ensure_space(obj, v->alloced * 2);
    }

    /* Add the item and increase the total */
    v->items[v->length++] = item;
}

void vector_set(vectorT *obj, size_t index, void *item) {
    /* Typecast the value to a string so that it can be manipulated */
    vector *v = (vector*)obj->value;

    /* In case of invalid inputs */
    if(v == NULL) {
        return;
    }

    /* As long as the index is valid */
    if(index >= 0 && index < v->length) {
        v->items[index] = item;
    }
}

void *vector_get(vectorT *obj, size_t index) {
    /* Typecast the value to a string so that it can be manipulated */
    vector *v = (vector*)obj->value;

    /* In case of invalid inputs */
    if(v == NULL) {
        return NULL;
    }

    /* As long as the index is valid */
    if(index >= 0 && index < v->length) {
        return v->items[index];
    }
    
    /* Else simply return NULL */
    return NULL;
}

void vector_delete(vectorT *obj, size_t index) {
    /* Typecast the value to a string so that it can be manipulated */
    vector *v = (vector*)obj->value;

    /* In case of empty vector */
    if(v == NULL) {
        return;
    }

    /* If the index is invalid */
    if(index < 0 || index >= v->length) {
        return;
    }

    /* NULL out the value in the spesific index */
    v->items[index] = NULL;

    /* Reset the rest of the elements forwards */
    for(int i = index; i < v->length - 1; i++) {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = NULL;
    }

    /* Reset the total */
    v->length--;

    /* Check if we need to reduce the size of the array */
    if(v->length > 0 && v->length == v->alloced / 4) {
        vector_ensure_space(obj, v->alloced / 2);
    }
}

size_t vector_length(vectorT *obj) {
    /* Typecast the value to a string so that it can be manipulated */
    vector *v = (vector*)obj->value;

    /* In case of empty vector */
    if(v == NULL) {
        return 0;
    }

    return v->length;
};

void vector_free(vectorT *obj) {
    /* Typecast the value to a string so that it can be manipulated */
    vector *v = (vector*)obj->value;

    /* In case of NULL value */
    if(v == NULL) {
        return;
    }

    /* Free the items */
    free(v->items);

    /* Free the pointer itself */
    free(v);
}
