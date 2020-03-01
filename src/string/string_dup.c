#include "../../headers/_data_structures.h"

stringT *string_dup(stringT *obj) {
    string *sb = (string*)obj->value;
    if(sb == NULL) return NULL;
    
    stringT *dup = new_stringT("");
    string_add_str(dup, string_get(obj));
    return dup;
}
