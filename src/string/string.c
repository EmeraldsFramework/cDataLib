#include "../../headers/_data_structures.h"

static void string_ensure_space(stringT *obj, size_t add_len) {
    string *sb = (string*)obj->value;
    if(sb == NULL || add_len == 0) return;

    /* If out allocated space is big enough */
    if(sb->alloced >= sb->length+add_len+1) return;

    while (sb->alloced < sb->length+add_len+1) {
        /* Doubling growth strategy */
        sb->alloced <<= 1;
        if(sb->alloced == 0) {
            /* Left shift of max bits will go to 0. An unsigned type set to
             * -1 will return the maximum possible size. However, we should
             *  have run out of memory well before we need to do this. Since
             *  this is the theoretical maximum total system memory we don't
             *  have a flag saying we can't grow any more because it should
             *  be impossible to get to this point */
            sb->alloced--;
        }
    }
    sb->str = realloc(sb->str, sb->alloced);
}

string *string_create(void) {
    string *sb;
    sb = calloc(1, sizeof(*sb));
    sb->str = malloc(string_init_capacity);

    /* NULL terminate the string */
    *sb->str = '\0';

    sb->alloced = string_init_capacity;
    sb->length = 0;
    return sb;
}

void string_add_str(stringT *obj, const char *str) {
    string *sb = (string*)obj->value;
    if(sb == NULL || str == NULL || *str == '\0') return;

    size_t len = strlen(str);
    string_ensure_space(obj, len);

    /* Copy the value into memory */
    memmove(sb->str+sb->length, str, len);

    /* Reset length and NULL terminate */
    sb->length += len;
    sb->str[sb->length] = '\0';
}

void string_add_char(stringT *obj, char c) {
    string *sb = (string*)obj->value;
    if(sb == NULL) return;

    /* In any case we try to overflow the input */
    if(c > 255 || c < 0) return;

    string_ensure_space(obj, 1);

    /* Add the char to the end of the string, reset length and NULL terminate */
    sb->str[sb->length] = c;
    sb->length++;
    sb->str[sb->length] = '\0';
}

void string_add_int(stringT *obj, int val) {
    string *sb = (string*)obj->value;
    char str[1024];

    if(sb == NULL) return;

    /* Add as a string to an str array */
    snprintf(str, sizeof(str), "%d", val);
    string_add_str(obj, str);
}

void string_add_double_precision(stringT *obj, double val) {
    string *sb = (string*)obj->value;
    char str[1024];

    if(sb == NULL) return;

    /* Add as a string to an str array */
    snprintf(str, sizeof(str), "%g", val);
    string_add_str(obj, str);
}

char *string_get(stringT *obj) {
    string *sb = (string*)obj->value;
    if(sb == NULL) return NULL;
    return sb->str;
}

char string_get_char_at_index(stringT *obj, size_t index) {
    string *sb = (string*)obj->value;
    if(sb == NULL || index < 0) return NULL;
    return sb->str[index];
}

void string_shorten(stringT *obj, size_t len) {
    string *sb = (string*)obj->value;
    if(sb == NULL || len >= sb->length) return;

    /* Reset the length and NULL terminate, ingoring
        all values right to the NULL from memory */
    sb->length = len;
    sb->str[sb->length] = '\0';
}

void string_delete(stringT *obj) {
    string *sb = (string*)obj->value;
    if(sb == NULL) return;

    /* Call truncate with 0, clearing out the string */
    string_shorten(obj, 0);
}

void string_skip(stringT *obj, size_t len) {
    string *sb = (string*)obj->value;
    if(sb == NULL || len == 0) return;

    if(len >= sb->length) {
        /* If we choose to drop more bytes than the string has simply clear the string */
        string_delete(obj);
        return;
    }

    sb->length -= len;

    /* +1 to move the NULL. */
    memmove(sb->str, sb->str+len, sb->length+1);
}

size_t string_length(stringT *obj) {
    string *sb = (string*)obj->value;
    if(sb == NULL) return 0;
    return sb->length;
}

void string_free(stringT *obj) {
    string *sb = (string*)obj->value;
    if(sb == NULL) return;

    free(sb->str);
    free(sb);
}
