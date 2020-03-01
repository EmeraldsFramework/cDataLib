#include "../../headers/_data_structures.h"

object *object_dup(object *obj) {
    switch(obj->type) {
        case CHAR: return new_charT(obj->value);
        case SHORT: return new_shortT(obj->value);
        case INT: return new_intT(obj->value);
        case LONG: return new_longT(obj->value);
        case LONG_LONG: return new_longlongT(obj->value);
        case UNSIGNED_CHAR: return new_unsignedcharT(obj->value);
        case UNSIGNED_SHORT: return new_unsignedshortT(obj->value);
        case UNSIGNED_INT: return new_unsignedintT(obj->value);
        case UNSIGNED_LONG: return new_unsignedlongT(obj->value);
        case UNSIGNED_LONG_LONG: return new_unsignedlonglongT(obj->value);
        case FLOAT: return new_floatT(obj->value);
        case DOUBLE: return new_doubleT(obj->value);
        case LONG_DOUBLE: return new_longdoubleT(obj->value);
        case STRING: return string_dup(obj);
        case VECTOR: return vector_dup(obj);
        case HASHMAP: return hashmap_dup(obj);
        case LINKED_LIST: return linked_list_dup(obj);
        default: return NULL;
    }
}