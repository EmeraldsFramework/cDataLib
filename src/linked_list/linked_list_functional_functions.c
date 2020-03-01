#include "../../headers/_data_structures.h"

linked_listT *linked_list_map(linked_listT *obj, lambda modifier) {
    linked_list *list = (linked_list*)object_get_value(obj);
    if(list == NULL || modifier == NULL) return NULL;

    linked_listT *dup = new_linked_listT();

    /* Typecast and use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(list->head);

    /* Dereference once */
    while(*probe) {
        object *item = (*probe)->item;
        linked_list_add(dup, modifier(item));

        /* Point probe to the next node */
        probe = &(*probe)->next;
    }

    return dup;
}

linked_listT *linked_list_filter(linked_listT *obj, lambda filter) {
    linked_list *list = (linked_list*)object_get_value(obj);
    if(list == NULL || filter == NULL) return NULL;

    linked_listT *dup = new_linked_listT();

    /* Typecast and use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(list->head);

    /* Dereference once */
    while(*probe) {
        object *item = (*probe)->item;
        if(filter(item)) {
            linked_list_add(dup, item);
        }

        /* Point probe to the next node */
        probe = &(*probe)->next;
    }

    return dup;
}

void *linked_list_reduce(linked_listT *obj, lambda2 fold) {
    linked_list *list = (linked_list*)object_get_value(obj);
    if(list == NULL || fold == NULL) return NULL;

    llnode **probe = (&list->head);

    /* Get the initial value */
    /* Create the value that gets returned with the accumulation of the vector elements */
    void *accumulator = (*probe)->item;

    /* Start counting from the next */
    probe = &(*probe)->next;

    while(*probe) {
        void *current = (*probe)->item;
        accumulator = fold(accumulator, current);
        probe = &(*probe)->next;
    }
    
    return object_get_value(accumulator);
}