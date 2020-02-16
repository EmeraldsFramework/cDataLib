#include "../../headers/_data_structures.h"

/**
 * @func: garbage_collector_push
 * @desc: Pushes a new gc_item into the stack of items
 * @param gc -> The gc to add to
 * @param value -> The item to store
 **/
static void garbage_collector_push(garbage_collector *gc, gc_item *value) {
    gc->stack[gc->stack_size++] = value;
}

/**
 * @func: garbage_collector_pop
 * @desc: Pops the top item from the item stack
 * @param gc -> The gc to pop from
 * @return The value we just popped
 **/
static gc_item *garbage_collector_pop(garbage_collector *gc) {
    return gc->stack[--gc->stack_size];
}

/**
 * @func: garbage_collector_mark
 * @desc: Mark a gc_item to be freed
 * @param item -> The item to mark
 **/
static void garbage_collector_mark(gc_item *item) {
    if(item->marked) return;

    /* Mark the item */
    item->marked = 1;
}

/**
 * @func: garbage_collector_mark_all
 * @desc: Mark all elements stored in the garbage collector
 * @param gc -> The gc which elements we mark
 **/
static void garbage_collector_mark_all(garbage_collector *gc) {
    for(size_t i = 0; i < gc->stack_size; i++) {
        garbage_collector_mark(gc->stack[i]);
    }
}

/**
 * @func: garbage_collector_sweep
 * @desc: Sweeps for used elements inside the gc stack and frees them
 * @param gc -> The gc to free
 **/
static void garbage_collector_sweep(garbage_collector *gc) {
    /* Get the address of the head node */
    gc_item *obj = gc->first_object;

    while(obj) {
        if(!obj->marked) {
            /* This object wasnt reached, so remove it from the list and free it */
            gc_item *untracked = obj;
            
            /* Get the address and free the memory address */
            obj = untracked->next;

            /* Special case for the first element to avoid pointer arithmetics */
            /* TODO TRY IMPLEMENT WITH POINTERS TO POINTERS */
            object *item;
            if(gc->num_of_objects == 1) {
                item = (object*)(gc->first_object->value);
            }
            else {
                item = (object*)(untracked->next->value);
            }

            switch(object_get_type(item)) {
                /* Use the custom free function */
                /* Free the pointer to the gc item */
                case STRING:
                    string_free(item);
                    free(item);
                    break;
                case VECTOR:
                    vector_free(item);
                    free(item);
                    break;
                case HASHMAP:
                    hashmap_free(item);
                    free(item);
                    break;
                case LINKED_LIST:
                    linked_list_free(item);
                    free(item);
                    break;
                default:
                    free(item);
                    free(untracked);
                    break;
            }

            gc->num_of_objects--;
        }
        /* We find unmarked values in case we want to expand the collector */
        /* Instead of deleting the values we reassign the linked list with the updated size */
        else {
            /* This object was reached so unmark it (For the next garbage collection) and move on to the next */
            obj->marked = 0;
            obj = obj->next;
        }
    }
    return;
}

/**
 * @func: garbage_collector_new_object
 * @desc: Create a new object to store to the gc
 * @param gc -> The gc to add the gc_item to
 * @return The newly created object
 **/
static gc_item *garbage_collector_new_object(garbage_collector *gc) {
    if(gc->num_of_objects == gc->max_objects) {
        garbage_collector_collect(gc);
    }

    gc_item *obj = malloc(sizeof(gc_item));
    obj->next = gc->first_object;

    /* Store the object to the linked list */
    gc->first_object = obj;
    obj->marked = 0;
    gc->num_of_objects++;

    return obj;
}

garbage_collector *new_garbage_collector(const size_t stack_max) {
    garbage_collector *gc = malloc(sizeof(garbage_collector));
    gc->stack = malloc(stack_max);
    gc->stack_size = 0;
    gc->first_object = NULL;
    gc->num_of_objects = 0;
    gc->max_objects = 8;
    return gc;
}

void garbage_collector_collect(garbage_collector *gc) {
    int num_of_objects = gc->num_of_objects;

    garbage_collector_mark_all(gc);
    garbage_collector_sweep(gc);
    gc->max_objects = gc->num_of_objects * 2;
}

void garbage_collector_push_value(garbage_collector *gc, void *value) {
    gc_item *obj = garbage_collector_new_object(gc);
    obj->value = value;
    garbage_collector_push(gc, obj);
}

void garbage_collector_free(garbage_collector *gc) {
    gc->stack_size = 0;
    garbage_collector_collect(gc);
    free(gc);
}

garbage_collector *gc;