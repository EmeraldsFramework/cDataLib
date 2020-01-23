#include "../../headers/_data_structures.h"

linked_listT *linked_list_map(linked_listT *obj, lambda modifier) {
    /* Create a new linked list */
    linked_listT *dup = linked_list_dup(obj);

    /* Typecast and use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &((linked_list*)object_get_value(dup))->head;

    /* Dereference once */
    while(*probe) {
        /* Set the modified element */
        modifier((*probe)->item);

        /* Point probe to the next node */
        probe = &(*probe)->next;
    }

    /* Return the new vector */
    return dup;
}
