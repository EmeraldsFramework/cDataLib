#include "../../../cSuite.h"

string *string_dup(string *sb) {
    if(sb == NULL) return NULL;

    string *dup;
    if(sb->persistance) dup = new_persistent_string("");
    else dup = new_string("");
    
    string_add_str(dup, string_get(sb));
    dup->persistance = sb->persistance;
    return dup;
}
