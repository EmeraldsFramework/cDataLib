#include "../../headers/_data_structures.h"

stack *stack_create(void) {
    stack *st = (stack*)malloc(sizeof(stack));

    /* Initial values */
    st->length = 0;
    st->top = -1;
    st->items = new_vectorT();

    return st;
}

size_t stack_length(stackT *obj) {
    stack *st = (stack*)obj->value;
    if(st == NULL) return 0;

    return st->length;
}

int stack_is_empty(stackT *obj) {
    stack *st = (stack*)obj->value;
    if(st == NULL) return 0;

    return stack_length(obj) == 0;
}

void stack_push(stackT *obj, void *item) {
    stack *st = (stack*)obj->value;
    if(st == NULL) return;

    /* Keep track of the top element and the length */
    st->top++;
    st->length++;

    vector_add(st->items, item);
}

void *stack_pop(stackT *obj) {
    stack *st = (stack*)obj->value;
    if(st == NULL) return NULL;

    if(!stack_is_empty(obj)) return vector_get(st->items, st->top--);
    return NULL;
}

void *stack_peek(stackT *obj) {
    stack *st = (stack*)obj->value;
    if(st == NULL) return NULL;

    if(!stack_is_empty(obj)) return vector_get(st->items, st->top);
    return NULL;
}

void stack_free(stackT *obj) {
    stack *st = (stack*)obj->value;
    if(st == NULL) return 0;

    /* 'items' is free'd using vector_free */
    free(st);
}