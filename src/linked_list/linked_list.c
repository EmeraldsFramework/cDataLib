#include "../../../cSuite.h"

linked_list *linked_list_create(void) {
    linked_list *list = mmalloc(sizeof(linked_list));
    list->head = NULL;
    list->length = 0;
    list->persistence = false;
    return list;
}

linked_list *linked_list_persistent_create(void) {
    linked_list *list = malloc(sizeof(linked_list));
    list->head = NULL;
    list->length = 0;
    list->persistence = true;
    return list;
}

void linked_list_add(linked_list *list, void *item) {
    if(list == NULL || item == NULL) return;

    /* Use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(list->head);

    /* Create a new node */
    llnode *newnode;

    if(list->persistence) {
        newnode = mmalloc(sizeof(llnode));
        newnode->item = mmalloc(sizeof(item));
    }
    else {
        newnode = mmalloc(sizeof(llnode));
        newnode->item = malloc(sizeof(item));
    }
    newnode->item = item;

    /* Traverse to the end of the linked list */
    while(*probe)
        probe = &(*probe)->next;

    newnode->next = *probe;
    *probe = newnode;
    list->length++;
}

void linked_list_remove(linked_list *list, void *item) {
    if(list == NULL || item == NULL) return;

    llnode **probe = &(list->head);

    while((*probe) && (*probe)->item != list)
        probe = &(*probe)->next;

    *probe = (*probe)->next;
}