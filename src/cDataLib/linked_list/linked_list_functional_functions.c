#include "headers/linked_list_functional_functions.h"

linked_list *linked_list_map(linked_list *list, linked_list_lambda modifier) {
    linked_list *dup = NULL;
    struct llnode **probe = NULL;

    if(list == NULL || modifier == NULL) return NULL;

    dup = linked_list_new();

    /* Typecast and use the address to take advantage of a pointer to pointer approach */
    probe = &(list->head);

    /* Dereference once */
    while(*probe) {
        void *item = (*probe)->item;
        linked_list_add(dup, modifier(item));

        /* Point probe to the next node */
        probe = (struct llnode**)&(*probe)->next;
    }

    return dup;
}

linked_list *linked_list_filter(linked_list *list, linked_list_lambda filter) {
    linked_list *dup = NULL;
    struct llnode **probe = NULL;

    if(list == NULL || filter == NULL) return NULL;

    dup = linked_list_new();

    /* Typecast and use the address to take advantage of a pointer to pointer approach */
    probe = &(list->head);

    /* Dereference once */
    while(*probe) {
        void *item = (*probe)->item;
        if(filter(item))
            linked_list_add(dup, item);

        /* Point probe to the next node */
        probe = (struct llnode**)&(*probe)->next;
    }

    return dup;
}

void *linked_list_reduce(linked_list *list, linked_list_lambda fold) {
    struct llnode **probe = NULL;
    void *accumulator = NULL;

    if(list == NULL || fold == NULL) return NULL;

    probe = (&list->head);

    /* Get the initial value */
    /* Create the value that gets returned with the accumulation of the vector elements */
    accumulator = (*probe)->item;

    /* Start counting from the next */
    probe = (struct llnode**)&(*probe)->next;

    while(*probe) {
        void *current = (*probe)->item;
        accumulator = fold(accumulator, current);
        probe = (struct llnode**)&(*probe)->next;
    }
    
    return accumulator;
}
