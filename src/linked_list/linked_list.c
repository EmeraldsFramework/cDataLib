#include "../../headers/_data_structures.h"

linked_list *linked_list_create(void) {
    linked_list *list = malloc(sizeof(linked_list));
    list->head = NULL;

    /* We insert the head at the beginning */
    list->length = 0;
    
    return list;
}

void linked_list_add(linked_listT *obj, void *item) {
    linked_list *list = (linked_list*)object_get_value(obj);
    if(list == NULL || item == NULL) return;

    /* Use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(list->head);

    /* Create a new node */
    llnode *newnode = malloc(sizeof(llnode));
    newnode->item = malloc(sizeof(item));
    newnode->item = item;

    /* Traverse to the end of the linked list */
    while(*probe) {
        probe = &(*probe)->next;
    }

    /* Fix the linked list */
    newnode->next = *probe;
    *probe = newnode;

    /* Increase the size of the linked list */
    list->length++;
}

void linked_list_remove(linked_listT *obj, void *item) {
    linked_list *list = (linked_list*)object_get_value(obj);
    if(list == NULL || item == NULL) return;

    /* Use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(list->head);

    while((*probe) && (*probe)->item != obj) {
        probe = &(*probe)->next;
    }

    /* Remove the object and fix the linked list */
    llnode *old = *probe;
    *probe = (*probe)->next;
    free(old);
}

void linked_list_free(linked_listT *obj) {
    linked_list *list = (linked_list*)object_get_value(obj);
    if(list == NULL) return;
    free(list->head);
    free(list);
}