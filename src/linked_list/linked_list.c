#include "../../headers/_data_structures.h"

linked_list *linked_list_create(void) {
    /* Create a new list and set the base elements */
    linked_list *list = malloc(sizeof(linked_list));
    list->head = NULL;

    /* We insert the head at the beginning */
    list->length = 0;
    
    /* Return the list */
    return list;
}

void linked_list_add(linked_listT *obj, void *item) {
    /* Typecast the value to a linked_list so that it can be manipulated */
    linked_list *list = (linked_list*)object_get_value(obj);

    /* In case of empty inputs */
    if(list == NULL || item == NULL) {
        return;
    }

    /* Use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(list->head);

    /* Create a new node */
    /* Allocate size for the node as well as its contents */
    llnode *newnode = malloc(sizeof(llnode));
    newnode->item = malloc(sizeof(item));

    /* Set the value inside the new node */
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
    /* Typecast the value to a linked_list so that it can be manipulated */
    linked_list *list = (linked_list*)object_get_value(obj);

    /* In case of empty inputs */
    if(list == NULL || item == NULL) {
        return;
    }

    /* Use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(list->head);

    while((*probe) && (*probe)->item != obj) {
        probe = &(*probe)->next;
    }

    /* Remove the object and fix the linked list */
    llnode *old = *probe;
    *probe = (*probe)->next;

    /* Free the item value */
    free(old);
}

void linked_list_free(linked_listT *obj) {
    /* Typecast the value to a linked_list so that it can be manipulated */
    linked_list *list = (linked_list*)object_get_value(obj);

    /* In case of empty inputs */
    if(list == NULL) {
        return;
    }

    free(list->head);
    free(list);
}