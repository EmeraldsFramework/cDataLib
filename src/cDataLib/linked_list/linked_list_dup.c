#include "headers/linked_list_dup.h"

linked_list *linked_list_dup(linked_list *list) {
    struct llnode **probe = NULL;
    linked_list *dup = NULL;

    if(list == NULL) return NULL;

    /* Use the address to take advantage of a pointer to pointer approach */
    probe = &(list->head);
    dup = linked_list_new();

    while(*probe) {
        linked_list_add(dup, (*probe)->item);

        /* Move to the next item */
        probe = (struct llnode**)&(*probe)->next;
    }

    return dup;
}
