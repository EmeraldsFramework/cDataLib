#include "../../headers/_data_structures.h"

linked_listT *linked_list_dup(linked_listT *obj) {
    /* Typecast the value to a string so that it can be manipulated */
    linked_list *list = (linked_list*)object_get_value(obj);

    /* In case of empty inputs */
    if(list == NULL) {
        return;
    }

    /* Use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(list->head);

    /* Allocate new space for the duplicate */
    linked_listT *dup = new_linked_listT();

    while(*probe) {
        /* Add the item to the linked list */
        linked_list_add(dup, (*probe)->item);

        /* Move to the next item */
        probe = &(*probe)->next;
    }

    /* Return the copy */
    return dup;
}
