#include "../../headers/_data_structures.h"

linked_listT *linked_list_dup(linked_listT *obj) {
    linked_list *list = (linked_list*)object_get_value(obj);
    if(list == NULL) return;

    /* Use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(list->head);
    linked_listT *dup = new_linked_listT();

    while(*probe) {
        linked_list_add(dup, (*probe)->item);

        /* Move to the next item */
        probe = &(*probe)->next;
    }

    return dup;
}
