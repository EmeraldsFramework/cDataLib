#include "../../../cSuite.h"

linked_list *linked_list_dup(linked_list *list) {
    if(list == NULL) return NULL;

    /* Use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(list->head);
    linked_list *dup;
    if(list->persistence) dup = new_persistent_linked_list();
    else dup = new_linked_list();

    while(*probe) {
        linked_list_add(dup, (*probe)->item);

        /* Move to the next item */
        probe = &(*probe)->next;
    }

    return dup;
}
