#include "../../headers/_data_structures.h"

stringT *string_dup(stringT *obj) {
    /* Typecast the value to a string so that it can be manipulated */
    string *sb = (string*)obj->value;

    /* In case of empty input */
    if(sb == NULL) {
        return NULL;
    }
    
    /* Allocate space for a new string */
    stringT *dup = new_stringT("");

    /* Add the string from one pointer to another */
    string_add_str(dup, string_get(obj));

    /* Return the duplicate */
    return dup;
}
