#include "../../headers/string/string_functional_functions.h"

string *string_iterate(string *sb, lambda apply) {
    /* TODO -> Convert check to asserts */
    if(sb == NULL || apply == NULL) return NULL;

    char *sb_str = string_get(sb);

    size_t i;
    for(i = 0; i < string_length(sb); i++)
        apply(sb_str[i]);
}