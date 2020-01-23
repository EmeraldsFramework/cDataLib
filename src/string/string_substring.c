#include "../../headers/_data_structures.h"

stringT *string_substring(stringT *str, size_t from, size_t to) {
    stringT *strdup = string_dup(str);

    /* Drop from the front */
    string_skip(strdup, from);

    /* Truncate from the back */
    string_shorten(strdup, to - from + 1);

    /* Return the new substring */
    return strdup;
}