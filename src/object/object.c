// #include "../../headers/_data_structures.h"

// void *object_get_value(object *object) {
//     return object->value;
// }

// object_type object_get_type(object *object) {
//     return object->type;
// }

// void object_set_value(object *object, void *value) {
//     object->value = value;
// }

// void object_set_type(object *object, object_type type) {
//     object->type = type;
// }

// stringT *new_stringT(char *value) {
//     /* Create a typed wrapper */
//     stringT *obj = mmalloc(sizeof(stringT));

//     /* Allocate enough space and set value and type */
//     obj->value = mmalloc(sizeof(value));
//     object_set_type(obj, STRING);
//     object_set_value(obj, string_create());

//     /* Set the initial value */
//     string_add_str(obj, value);
//     return obj;
// }

// vectorT *new_vectorT(void) {
//     /* Create a typed wrapper */
//     vectorT *obj = mmalloc(sizeof(vectorT));

//     /* Allocate enough space and set value and type */
//     obj->value = mmalloc(sizeof(vector));
//     object_set_type(obj, VECTOR);
//     object_set_value(obj, vector_create());
//     return obj;
// }

// hashmapT *new_hashmapT(void) {
//     /* Create a typed wrapper */
//     hashmapT *obj = mmalloc(sizeof(hashmapT));

//     /* Allocate enough space and set value and type */
//     obj->value = mmalloc(sizeof(hashmap));
//     object_set_type(obj, HASHMAP);
//     object_set_value(obj, hashmap_create());
//     return obj;
// }

// linked_listT *new_linked_listT(void) {
//     /* Create a typed wrapper */
//     linked_listT *obj = mmalloc(sizeof(linked_listT));

//     /* Allocate enough space and set value and type */
//     obj->value = mmalloc(sizeof(linked_list));
//     object_set_type(obj, LINKED_LIST);
//     object_set_value(obj, linked_list_create());
//     return obj;
// }

// binary_treeT *new_binary_treeT(void) {
//     /* Create a typed wrapper */
//     binary_treeT *obj = mmalloc(sizeof(binary_treeT));

//     /* Allocate enough space and set value and type */
//     obj->value = mmalloc(sizeof(binary_tree));
//     object_set_type(obj, BINARY_TREE);
//     object_set_value(obj, binary_tree_create());
//     return obj;
// }

// stackT *new_stackT(void) {
//     /* Create a typed wrapper */
//     stackT *obj = mmalloc(sizeof(stackT));

//     /* Allocate enough space and set value and type */
//     obj->value = mmalloc(sizeof(stack));
//     object_set_type(obj, STACK);
//     object_set_value(obj, stack_create());
//     return obj;
// }
