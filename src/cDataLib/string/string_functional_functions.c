#include "headers/string_functional_functions.h"

void string_iterate(string *sb, string_lambda apply) {
    /* TODO -> Convert check to asserts */
    if(sb == NULL || apply == NULL) return;

    char *sb_str = string_get(sb);

    size_t i;
    for(i = 0; i < string_length(sb); i++)
        apply(sb_str[i]);
}

string *string_map(string *sb, string_lambda modifier) {
    if(sb == NULL || modifier == NULL) return NULL;

    char *sb_str = string_get(sb);
    string *sb_dup = new_string("");

    size_t i;
    for(i = 0; i < string_length(sb); i++)
        string_add_char(sb_dup, modifier(sb_str[i]));

    return sb_dup;
}

string *string_filter(string *sb, string_lambda filter) {
    if(sb == NULL || filter == NULL) return NULL;

    char *sb_str = string_get(sb);
    string *sb_dup = new_string("");

    size_t i;
    for(i = 0; i < string_length(sb); i++)
        if(filter(sb_str[i]))
            string_add_char(sb_dup, sb_str[i]);

    return sb_dup;
}
