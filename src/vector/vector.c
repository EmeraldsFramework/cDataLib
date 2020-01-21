#include "../../headers/_data_structures.h"

extern garbage_collector *gc;

static void vector_ensure_space(typed_object *obj, size_t capacity) {
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

typed_object *new_vector(void) {
    /* Allocate space for the vector */
    vector *v = malloc(sizeof(vector));

    /* Set base values */
    v->alloced = vector_init_capacity;
    v->length = 0;
    v->gc = gc;

    /* Allocate memory according to the data type we insert */
    v->items = malloc(sizeof(void*) * v->alloced);

    /* Created a typed wrapper */
    typed_object *obj = malloc(sizeof(typed_object));

    /* Set the type */
    obj->type = VECTOR;

    /* Set the value */
    obj->value = v;
    
    /* Push the value to the garbage collector and return it */
    garbage_collector_push_value(v->gc, obj);
    return obj;
}

void vector_add(typed_object *obj, void *item) {
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

void vector_set(typed_object *obj, size_t index, void *item) {
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

void *vector_get(typed_object *obj, size_t index) {
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

void vector_delete(typed_object *obj, size_t index) {
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

size_t vector_length(typed_object *obj) {
    /* Typecast the value to a string so that it can be manipulated */
    vector *v = (vector*)obj->value;

    /* In case of empty vector */
    if(v == NULL) {
        return 0;
    }

    return v->length;
};

typed_object *vector_dup(typed_object *obj) {
    /* Typecast the value to a string so that it can be manipulated */
    vector *v = (vector*)obj->value;

    /* In case of empty vector */
    if(v == NULL) {
        return NULL;
    }

    /* Allocate new space for the vector */
    typed_object *dup = new_vector();

    /* Iteratively copy the vector items from one memory location to another */
    for(size_t i = 0; i < vector_length(obj); i++) {
        vector_add(dup, vector_get(obj, i));
    }

    /* Return the new vector duplicate */
    return dup;
}

void vector_free(typed_object *obj) {
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
