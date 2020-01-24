#include "../../headers/_data_structures.h"

linked_listT *linked_list_map(linked_listT *obj, lambda modifier) {
    /* Typecast the value to a string so that it can be manipulated */
    linked_list *list = (linked_list*)object_get_value(obj);

    /* Check for invalid input */
    if(list == NULL || modifier == NULL) {
        return NULL;
    }

    /* Create a new linked list duplicate */
    linked_listT *dup = new_linked_listT();

    /* Typecast and use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(list->head);

    /* Dereference once */
    while(*probe) {
        /* Grab the item */
        object *item = (*probe)->item;

        /* Set the modified element */
        linked_list_add(dup, modifier(item));

        /* Point probe to the next node */
        probe = &(*probe)->next;
    }

    /* Return the new linked list */
    return dup;
}

linked_listT *linked_list_filter(linked_listT *obj, lambda filter) {
    /* Typecast the value to a string so that it can be manipulated */
    linked_list *list = (linked_list*)object_get_value(obj);

    /* Check for invalid input */
    if(list == NULL || filter == NULL) {
        return NULL;
    }

    /* Create a new linked list duplicate */
    linked_listT *dup = new_linked_listT();

    /* Typecast and use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(list->head);

    /* Dereference once */
    while(*probe) {
        /* Grab the item */
        object *item = (*probe)->item;

        /* Set the modified element */
        if(filter(item)) {
            linked_list_add(dup, item);
        }

        /* Point probe to the next node */
        probe = &(*probe)->next;
    }

    /* Return the new linked list */
    return dup;
}

void *linked_list_reduce(linked_listT *obj, lambda fold) {
    /* Typecast the value to a string so that it can be manipulated */
    linked_list *list = (linked_list*)object_get_value(obj);

    /* Check for invalid input */
    if(list == NULL || fold == NULL) {
        return NULL;
    }

    /* Create the value that gets returned with the accumulation of the vector elements */
    void *folded_value;

    /* The functionality all lies in the function pointer passed in */
    folded_value = fold(list);

    /* This function only works as a wrapper */
    return folded_value;
}