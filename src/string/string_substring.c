#include "../../headers/_data_structures.h"

string *string_substring(string *str, size_t from, size_t to) {
    string *strdup = string_dup(str);
    string_skip(strdup, from);
    string_shorten(strdup, to - from + 1);
    return strdup;
}