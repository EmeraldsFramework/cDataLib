#include "../../headers/_data_structures.h"

stringT *string_substring(stringT *str, size_t from, size_t to) {
    stringT *strdup = object_dup(str);
    string_skip(strdup, from);
    string_shorten(strdup, to - from + 1);
    return strdup;
}