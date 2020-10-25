#include "../headers/string_dup.h"

string *string_dup(string *sb) {
    if(sb == NULL) return NULL;

    string *dup = new_string("");
    string_add_str(dup, string_get(sb));

    return dup;
}
