#include "../../headers/_data_structures.h"

garbage_collector *new_garbage_collector(const size_t stack_max) {
    garbage_collector *gc = malloc(sizeof(garbage_collector));
    gc->stack = malloc(stack_max);
    gc->stack_size = 0;
    gc->first_object = NULL;
    gc->num_of_objects = 0;
    gc->max_objects = 8;
    return gc;
}

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
    /* If already marked, return */
    if(item->marked) {
        return;
    }

    /* Mark */
    item->marked = 1;
}

/**
 * @func: garbage_collector_mark_all
 * @desc: Mark all elements stored in the garbage collector
 * @param gc -> The gc which elements we mark
 **/
static void garbage_collector_mark_all(garbage_collector *gc) {
    /* In iteration call mark on all elements of the stack */
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
        /* Special case for the first element to avoid pointer arithmetics */
        if(gc->num_of_objects == 1) {
            /* Typecast the object to a typed_object */
            typed_object *item = (typed_object*)(gc->first_object->value);

            /* Switch on the item type */
            switch(typed_object_get_type(item)) {
                /* Use the custom free function */
                /* Free the pointer to the gc item */
                case STRING:
                    string_free(item);
                    free(gc->first_object->value);
                    break;
                case VECTOR:
                    vector_free(item);
                    free(gc->first_object->value);
                    break;
                case HASHMAP:
                    hashmap_free(item);
                    free(gc->first_object->value);
                    break;
                case LINKED_LIST:
                    linked_list_free(item);
                    free(gc->first_object->value);
                    break;
                case CHAR:
                case SHORT:
                case INT:
                case LONG:
                case LONG_LONG:
                case UNSIGNED_CHAR:
                case UNSIGNED_SHORT:
                case UNSIGNED_INT:
                case UNSIGNED_LONG:
                case UNSIGNED_LONG_LONG:
                case FLOAT:
                case DOUBLE:
                case LONG_DOUBLE:
                    typed_object_free(item);
                    free(gc->first_object->value);
                    break;
                default:
                    free(gc->first_object->value);
                    break;
            }
            gc->num_of_objects--;
            break;
        }

        /* If the object is not marked */
        if(!obj->marked) {
            /* This object wasnt reached, so remove it from the list and free it */
            gc_item *untracked = obj;
            
            /* Get the address and free the memory address */
            obj = untracked->next;

            /* Typecast the object to a typed_object */
            typed_object *item = (typed_object*)(untracked->next->value);

            /* Switch on the item type */
            switch(typed_object_get_type(item)) {
                /* Use the custom free function */
                /* Free the pointer to the gc item */
                case STRING:
                    string_free(item);
                    free(untracked->next->value);
                    break;
                case VECTOR:
                    vector_free(item);
                    free(untracked->next->value);
                    break;
                case HASHMAP:
                    hashmap_free(item);
                    free(untracked->next->value);
                    break;
                case LINKED_LIST:
                    linked_list_free(item);
                    free(gc->first_object->value);
                    break;
                case CHAR:
                case SHORT:
                case INT:
                case LONG:
                case LONG_LONG:
                case UNSIGNED_CHAR:
                case UNSIGNED_SHORT:
                case UNSIGNED_INT:
                case UNSIGNED_LONG:
                case UNSIGNED_LONG_LONG:
                case FLOAT:
                case DOUBLE:
                case LONG_DOUBLE:
                    typed_object_free(item);
                    free(untracked->next->value);
                    break;
                default:
                    free(untracked->next->value);
                    break;
            }

            /* Decrease the number of stored objects */
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

void garbage_collector_collect(garbage_collector *gc) {
    int num_of_objects = gc->num_of_objects;

    /* Mark all elements in the gc */
    garbage_collector_mark_all(gc);

    /* Sweep and free all memory stored */
    garbage_collector_sweep(gc);

    /* Double the max object size */
    gc->max_objects = gc->num_of_objects * 2;
}

/**
 * @func: garbage_collector_new_object
 * @desc: Create a new object to store to the gc
 * @param gc -> The gc to add the gc_item to
 * @return The newly created object
 **/
static gc_item *garbage_collector_new_object(garbage_collector *gc) {
    /* In case we reached the max number of objects perform a collection */
    if(gc->num_of_objects == gc->max_objects) {
        garbage_collector_collect(gc);
    }

    /* Allocate space for the new object */
    gc_item *obj = malloc(sizeof(gc_item));
    
    /* Set the next pointer to the first object */
    obj->next = gc->first_object;

    /* Store the object to the linked list */
    gc->first_object = obj;
    obj->marked = 0;

    /* Increase the number of objects */
    gc->num_of_objects++;

    return obj;
}

void garbage_collector_push_value(garbage_collector *gc, void *value) {
    /* Create a new gc_item */
    gc_item *obj = garbage_collector_new_object(gc);

    /* Set the value */
    obj->value = value;

    /* Push the object to the gc */
    garbage_collector_push(gc, obj);
}

void garbage_collector_free(garbage_collector *gc) {
    /* Zero out the stack size */
    gc->stack_size = 0;
    garbage_collector_collect(gc);
    free(gc);
}

garbage_collector *gc;