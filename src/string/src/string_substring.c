#include "../headers/string_substring.h"

string *string_substring(string *str, size_t from, size_t __to) {
    string *strdup = string_dup(str);
    string_skip(strdup, from);
    string_shorten(strdup, __to - from + 1);
    return strdup;
}
