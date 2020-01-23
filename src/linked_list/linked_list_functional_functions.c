#include "../../headers/_data_structures.h"

linked_listT *linked_list_map(linked_listT *obj, lambda modifier) {
    /* Create a new linked list duplicate */
    // linked_listT *dup = linked_list_dup(obj);
    linked_listT *dup = new_linked_listT();

    /* Typecast and use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(((linked_list*)object_get_value(obj))->head);

    /* Dereference once */
    while(*probe) {
        /* Grab the item */
        object *item = (*probe)->item;

        /* Set the modified element */
        // modifier(item);
        linked_list_add(dup, modifier(item));

        /* Point probe to the next node */
        probe = &(*probe)->next;
    }

    /* Return the new linked list */
    return dup;
}

linked_listT *linked_list_filter(linked_listT *obj, lambda filter) {
    /* Create a new linked list duplicate */
    linked_listT *dup = new_linked_listT();

    /* Typecast and use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(((linked_list*)object_get_value(obj))->head);

    /* Dereference once */
    while(*probe) {
        /* Grab the item */
        object *item = (*probe)->item;

        /* Set the modified element */
        // modifier((*probe)->item);
        if(filter(item)) {
            linked_list_add(dup, item);
        }

        /* Point probe to the next node */
        probe = &(*probe)->next;
    }

    /* Return the new linked list */
    return dup;
}
/* MIGHT NOT NEED A DUPLICATE FOR READ ONLY ALGORITHMS */
void *linked_list_reduce(linked_listT *obj, lambda fold) {
    /* Create a duplicate of the linked list */
    linked_listT *dup = linked_list_dup(obj);

    /* Create the value that gets returned with the accumulation of the vector elements */
    void *folded_value;

    /* The functionality all lies in the function pointer passed in */
    folded_value = fold(dup);

    /* This function only works as a wrapper */
    return folded_value;
}