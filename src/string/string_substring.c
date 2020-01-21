#include "../../headers/_data_structures.h"

typed_object *string_substring(typed_object *sb, size_t from, size_t to) {
    typed_object *sbdup = string_dup(sb);

    /* Drop from the front */
    string_skip(sbdup, from);

    /* Truncate from the back */
    string_shorten(sbdup, to - from + 1);

    /* Return the new substring */
    return sbdup;
}