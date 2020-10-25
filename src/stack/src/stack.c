#include "../headers/stack.h"

stack *stack_create(void) {
    stack *st = (stack*)malloc(sizeof(stack));

    /* Initial values */
    st->length = 0;
    st->top = -1;
    st->items = new_vector();

    return st;
}

size_t stack_length(stack *st) {
    if(st == NULL) return 0;

    return st->length;
}

bool stack_is_empty(stack *st) {
    if(st == NULL) return 0;

    return stack_length(st) == 0;
}

void stack_push(stack *st, void *item) {
    if(st == NULL) return;

    /* Keep track of the top element and the length */
    st->top++;
    st->length++;

    vector_add(st->items, item);
}

void *stack_pop(stack *st) {
    if(st == NULL) return NULL;

    if(!stack_is_empty(st)) {
        st->length--;
        return vector_get(st->items, st->top--);
    }
    return NULL;
}

void *stack_peek(stack *st) {
    if(st == NULL) return NULL;

    if(!stack_is_empty(st)) return vector_get(st->items, st->top);
    return NULL;
}

