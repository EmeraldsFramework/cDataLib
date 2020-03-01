#include "../../headers/_data_structures.h"

extern garbage_collector *gc;

void *object_get_value(object *object) {
    return object->value;
}

object_type object_get_type(object *object) {
    return object->type;
}

void object_set_value(object *object, void *value) {
    object->value = value;
}

void object_set_type(object *object, object_type type) {
    object->type = type;
}

charT *new_charT(char value) {
    /* Create a typed wrapper */
    charT *obj = malloc(sizeof(charT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(value));
    object_set_type(obj, CHAR);
    object_set_value(obj, value);

    garbage_collector_push_value(gc, obj);
    return obj;
}

shortT *new_shortT(short value) {
    /* Create a typed wrapper */
    shortT *obj = malloc(sizeof(shortT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(value));
    object_set_type(obj, SHORT);
    object_set_value(obj, value);

    garbage_collector_push_value(gc, obj);
    return obj;
}

intT *new_intT(int value) {
    /* Create a typed wrapper */
    intT *obj = malloc(sizeof(intT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(value));
    object_set_type(obj, INT);
    object_set_value(obj, value);

    garbage_collector_push_value(gc, obj);
    return obj;
}

longT *new_longT(long value) {
    /* Create a typed wrapper */
    longT *obj = malloc(sizeof(longT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(value));
    object_set_type(obj, LONG);
    object_set_value(obj, value);

    garbage_collector_push_value(gc, obj);
    return obj;
}

longlongT *new_longlongT(long long value) {
    /* Create a typed wrapper */
    longlongT *obj = malloc(sizeof(longlongT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(value));
    object_set_type(obj, LONG_LONG);
    object_set_value(obj, value);

    garbage_collector_push_value(gc, obj);
    return obj;
}

unsignedcharT *new_unsignedcharT(unsigned char value) {
    /* Create a typed wrapper */
    unsignedcharT *obj = malloc(sizeof(unsignedcharT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(value));
    object_set_type(obj, UNSIGNED_CHAR);
    object_set_value(obj, value);

    garbage_collector_push_value(gc, obj);
    return obj;
}

unsignedshortT *new_unsignedshortT(unsigned short value) {
    /* Create a typed wrapper */
    unsignedshortT *obj = malloc(sizeof(unsignedshortT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(value));
    object_set_type(obj, UNSIGNED_SHORT);
    object_set_value(obj, value);

    garbage_collector_push_value(gc, obj);
    return obj;
}

unsignedintT *new_unsignedintT(unsigned int value) {
    /* Create a typed wrapper */
    unsignedintT *obj = malloc(sizeof(unsignedintT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(value));
    object_set_type(obj, UNSIGNED_INT);
    object_set_value(obj, value);

    garbage_collector_push_value(gc, obj);
    return obj;
}

unsignedlongT *new_unsignedlongT(unsigned long value) {
    /* Create a typed wrapper */
    unsignedlongT *obj = malloc(sizeof(unsignedlongT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(value));
    object_set_type(obj, UNSIGNED_LONG);
    object_set_value(obj, value);

    garbage_collector_push_value(gc, obj);
    return obj;
}

unsignedlonglongT *new_unsignedlonglongT(unsigned long value) {
    /* Create a typed wrapper */
    unsignedlonglongT *obj = malloc(sizeof(unsignedlonglongT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(value));
    object_set_type(obj, UNSIGNED_LONG_LONG);
    object_set_value(obj, value);

    garbage_collector_push_value(gc, obj);
    return obj;
}

floatT *new_floatT(float *value) {
    /* Create a typed wrapper */
    floatT *obj = malloc(sizeof(floatT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(value));
    object_set_type(obj, FLOAT);
    object_set_value(obj, value);

    garbage_collector_push_value(gc, obj);
    return obj;
}

doubleT *new_doubleT(double *value) {
    /* Create a typed wrapper */
    doubleT *obj = malloc(sizeof(doubleT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(value));
    object_set_type(obj, DOUBLE);
    object_set_value(obj, value);

    garbage_collector_push_value(gc, obj);
    return obj;
}

longdoubleT *new_longdoubleT(long double *value) {
    /* Create a typed wrapper */
    longdoubleT *obj = malloc(sizeof(longdoubleT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(value));
    object_set_type(obj, LONG_DOUBLE);
    object_set_value(obj, value);

    garbage_collector_push_value(gc, obj);
    return obj;
}

stringT *new_stringT(char *value) {
    /* Create a typed wrapper */
    stringT *obj = malloc(sizeof(stringT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(value));
    object_set_type(obj, STRING);
    object_set_value(obj, string_create());

    /* Set the initial value */
    string_add_str(obj, value);

    garbage_collector_push_value(gc, obj);
    return obj;
}

vectorT *new_vectorT(void) {
    /* Create a typed wrapper */
    vectorT *obj = malloc(sizeof(vectorT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(vector));
    object_set_type(obj, VECTOR);
    object_set_value(obj, vector_create());

    garbage_collector_push_value(gc, obj);
    return obj;
}

hashmapT *new_hashmapT(void) {
    /* Create a typed wrapper */
    hashmapT *obj = malloc(sizeof(hashmapT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(hashmap));
    object_set_type(obj, HASHMAP);
    object_set_value(obj, hashmap_create());

    garbage_collector_push_value(gc, obj);
    return obj;
}

linked_listT *new_linked_listT(void) {
    /* Create a typed wrapper */
    linked_listT *obj = malloc(sizeof(linked_listT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(linked_list));
    object_set_type(obj, LINKED_LIST);
    object_set_value(obj, linked_list_create());

    garbage_collector_push_value(gc, obj);
    return obj;
}

binary_treeT *new_binary_treeT(void) {
    /* Create a typed wrapper */
    binary_treeT *obj = malloc(sizeof(binary_treeT));

    /* Allocate enough space and set value and type */
    obj->value = malloc(sizeof(binary_tree));
    object_set_type(obj, BINARY_TREE);
    object_set_value(obj, binary_tree_create());

    garbage_collector_push_value(gc, obj);
    return obj;
}