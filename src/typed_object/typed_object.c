#include "../../headers/_data_structures.h"

void *typed_object_get_value(typed_object *object) {
    return object->value;
}

object_type typed_object_get_type(typed_object *object) {
    return object->type;
}

void typed_object_set_value(typed_object *object, void *value) {
    object->value = value;
}

void typed_object_set_type(typed_object *object, object_type type) {
    object->type = type;
}

charT *new_charT(char value) {
    charT *obj = malloc(sizeof(charT));
    typed_object_set_type(obj, CHAR);
    typed_object_set_value(obj, value);
    return obj;
}

shortT *new_shortT(short value) {
    shortT *obj = malloc(sizeof(shortT));
    typed_object_set_type(obj, SHORT);
    typed_object_set_value(obj, value);
    return obj;
}

intT *new_intT(int value) {
    intT *obj = malloc(sizeof(intT));
    typed_object_set_type(obj, INT);
    typed_object_set_value(obj, value);
    return obj;
}

longT *new_longT(long value) {
    longT *obj = malloc(sizeof(longT));
    typed_object_set_type(obj, LONG);
    typed_object_set_value(obj, value);
    return obj;
}

longlongT *new_longlongT(long long value) {
    longlongT *obj = malloc(sizeof(longlongT));
    typed_object_set_type(obj, LONG_LONG);
    typed_object_set_value(obj, value);
    return obj;
}

unsignedcharT *new_unsignedcharT(unsigned char value) {
    unsignedcharT *obj = malloc(sizeof(unsignedcharT));
    typed_object_set_type(obj, UNSIGNED_CHAR);
    typed_object_set_value(obj, value);
    return obj;
}

unsignedshortT *new_unsignedshortT(unsigned short value) {
    unsignedshortT *obj = malloc(sizeof(unsignedshortT));
    typed_object_set_type(obj, UNSIGNED_SHORT);
    typed_object_set_value(obj, value);
    return obj;
}

unsignedintT *new_unsignedintT(unsigned int value) {
    unsignedintT *obj = malloc(sizeof(unsignedintT));
    typed_object_set_type(obj, UNSIGNED_INT);
    typed_object_set_value(obj, value);
    return obj;
}

unsignedlongT *new_unsignedlongT(unsigned long value) {
    unsignedlongT *obj = malloc(sizeof(unsignedlongT));
    typed_object_set_type(obj, UNSIGNED_LONG);
    typed_object_set_value(obj, value);
    return obj;
}

unsignedlonglongT *new_unsignedlonglongT(unsigned long value) {
    unsignedlonglongT *obj = malloc(sizeof(unsignedlonglongT));
    typed_object_set_type(obj, UNSIGNED_LONG_LONG);
    typed_object_set_value(obj, value);
    return obj;
}

floatT *new_floatT(float *value) {
    floatT *obj = malloc(sizeof(floatT));
    typed_object_set_type(obj, FLOAT);
    typed_object_set_value(obj, value);
    return obj;
}

doubleT *new_doubleT(double *value) {
    doubleT *obj = malloc(sizeof(doubleT));
    typed_object_set_type(obj, DOUBLE);
    typed_object_set_value(obj, value);
    return obj;
}

longdoubleT *new_longdoubleT(long double *value) {
    longdoubleT *obj = malloc(sizeof(longdoubleT));
    typed_object_set_type(obj, LONG_DOUBLE);
    typed_object_set_value(obj, value);
    return obj;
}

// void *typed_object_typecast(void *obj) {
//     /* First typecast to a typed object */
//     typed_object *t_obj = (typed_object*)obj;

//     /* Check if the object is typed or not */
//     if(NULL == typed_object_get_type(t_obj)) {
//         printf("ERROR NO TYPE\n");
//         return obj; /* Cant typecast a base object */
//     }

//     switch(typed_object_get_type(t_obj)) {
//         case STRING:
//             return (string*)t_obj;
//         case VECTOR:
//             return (vector*)t_obj;
//         case HASHMAP:
//             return (hashmap*)t_obj;
//         case CHAR:
//             return (char)t_obj;
//         case SHORT:
//             return (short)t_obj;
//         case INT:
//             return (int)t_obj;
//         case LONG:
//             return (long)t_obj;
//         case LONG_LONG:
//             return (long long)t_obj;
//         case UNSIGNED_CHAR:
//             return (unsigned char)t_obj;
//         case UNSIGNED_SHORT:
//             return (unsigned short)t_obj;
//         case UNSIGNED_INT:
//             return (unsigned int)t_obj;
//         case UNSIGNED_LONG:
//             return (unsigned long)t_obj;
//         case UNSIGNED_LONG_LONG:
//             return (unsigned long long)t_obj;
//         case FLOAT:
//             return (float*)t_obj;
//         case DOUBLE:
//             return (double*)t_obj;
//         case LONG_DOUBLE:
//             return (long double*)t_obj;
//         default:
//             return obj;
//     }
// }

void typed_object_free(typed_object *obj) {
    free(obj->value);
    free(obj);
}