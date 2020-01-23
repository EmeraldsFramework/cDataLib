#include "../../headers/_data_structures.h"

extern garbage_collector *gc;

linked_listT *new_linked_list(void) {
    /* Create a new list and set the base elements */
    linked_list *list = malloc(sizeof(linked_list));
    list->gc = gc;
    list->head = NULL;

    /* We insert the head at the beginning */
    list->length = 0;
    
    /* Created a typed wrapper */
    linked_listT *obj = malloc(sizeof(linked_listT));

    /* Set the type */
    obj->type = LINKED_LIST;

    /* Set the value */
    obj->value = list;
    
    /* Push the value to the garbage collector and return it */
    garbage_collector_push_value(list->gc, obj);
    return obj;
}

void linked_list_add(linked_listT *list, typed_object *obj) {
    /* Typecast and use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(((linked_list*)typed_object_get_value(list))->head);

    /* Create a new node */
    /* Allocate size for the node as well as its contents */
    llnode *newnode = malloc(sizeof(llnode));
    newnode->item = malloc(sizeof(typed_object));

    /* Set the value inside the new node */
    newnode->item->value = obj->value;

    /* Traverse to the end of the linked list */
    while(*probe) {
        probe = &(*probe)->next;
    }

    /* Fix the linked list */
    newnode->next = *probe;
    *probe = newnode;

    /* Increase the size of the linked list */
    linked_list *llist = typed_object_typecast(list);
    llist->length++;
}

void linked_list_remove(linked_listT *list, typed_object *obj) {
    /* Typecast and use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(((linked_list*)typed_object_get_value(list))->head);

    while((*probe) && typed_object_get_value((*probe)->item) != typed_object_get_value(obj)) {
        probe = &(*probe)->next;
    }

    /* Remove the object and fix the linked list */
    llnode *old = *probe;
    *probe = (*probe)->next;

    /* Free the item value */
    free(old);
}

linked_listT *linked_list_dup(linked_listT *list) {
    /* Typecast and use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(((linked_list*)typed_object_get_value(list))->head);

    /* Allocate new space for the duplicate */
    linked_listT *dup = new_linked_list();

    while(*probe) {
        /* Add the item to the linked list */
        linked_list_add(dup, (*probe)->item);

        /* Move to the next item */
        probe = &(*probe)->next;
    }

    /* Return the copy */
    return dup;
}

void linked_list_free(linked_listT *list) {
    /* Typecast and use the address to take advantage of a pointer to pointer approach */
    llnode **probe = &(((linked_list*)typed_object_get_value(list))->head);

    /* Dereference once */
    while(*probe) {
        /* Dereference once more to get the typed object */
        typed_object *to_be_freed = (*probe)->item;

        /* Save the last element and point probe to the next before freeing */
        probe = &(*probe)->next;
        
        /* Finally free the node */
        free(to_be_freed);
    }
    free(probe);
    free(list);
}