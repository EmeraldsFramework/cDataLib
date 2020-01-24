#include "../../headers/_data_structures.h"

/* Define helper methods for wrapping a garbage collector in function calls */

static void string_ensure_space(stringT *obj, size_t add_len) {
    /* Typecast the value to a string so that it can be manipulated */
    string *sb = (string*)obj->value;

    /* In case of NULL input of empty string */
    if(sb == NULL || add_len == 0) {
        return;
    }

    /* If out allocated space is big enough */
    if(sb->alloced >= sb->length+add_len+1) {
        return;
    }

    /* In case our allocated space is not large for the concatenation */
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
    /* Reallocate the space */
    sb->str = realloc(sb->str, sb->alloced);
}

string *string_create(void) {
    /* Get a string builder object */
    string *sb;

    /* Allocate the size of the object */
    sb = calloc(1, sizeof(*sb));

    /* Allocate the min size */
    sb->str = malloc(string_init_capacity);

    /* NULL terminate the string */
    *sb->str = '\0';

    /* Store the allocated size */
    sb->alloced = string_init_capacity;

    /* Initial length to 0 */
    sb->length = 0;

    /* Return the object */
    return sb;
}

void string_add_str(stringT *obj, const char *str) {
    /* Typecast the value to a string so that it can be manipulated */
    string *sb = (string*)obj->value;

    /* In case of empty inputs */
    if(sb == NULL || str == NULL || *str == '\0') {
        return;
    }

    size_t len = strlen(str);

    /* Make sure enough space is allocated */
    string_ensure_space(obj, len);

    /* Copy the value into memory */
    memmove(sb->str+sb->length, str, len);

    /* Reset length and NULL terminate */
    sb->length += len;
    sb->str[sb->length] = '\0';
}

void string_add_char(stringT *obj, char c) {
    /* Typecast the value to a string so that it can be manipulated */
    string *sb = (string*)obj->value;

    /* In case of NULL input */
    if(sb == NULL) {
        return;
    }

    /* In any case we try to overflow the input */
    if(c > 255 || c < 0) {
        return;
    }

    /* Make sure enough space is allocated */
    string_ensure_space(obj, 1);

    /* Add the char to the end of the string, reset length and NULL terminate */
    sb->str[sb->length] = c;
    sb->length++;
    sb->str[sb->length] = '\0';
}

void string_add_int(stringT *obj, size_t val) {
    /* Typecast the value to a string so that it can be manipulated */
    string *sb = (string*)obj->value;

    char str[12];

    /* In case of empty string */
    if(sb == NULL) {
        return;
    }

    /* Add as a string to an str array */
    snprintf(str, sizeof(str), "%d", val);

    /* Add the value */
    string_add_str(obj, str);
}

char *string_get(stringT *obj) {
    /* Typecast the value to a string so that it can be manipulated */
    string *sb = (string*)obj->value;

    /* In case of empty input */
    if(sb == NULL) {
        return NULL;
    }
    return sb->str;
}

void string_shorten(stringT *obj, size_t len) {
    /* Typecast the value to a string so that it can be manipulated */
    string *sb = (string*)obj->value;

    /* In case of invalid input */
    if(sb == NULL || len >= sb->length) {
        return;
    }

    /* Reset the length and NULL terminate, essentially
        ingoring all values right to the NULL from memory */
    sb->length = len;
    sb->str[sb->length] = '\0';
}

void string_delete(stringT *obj) {
    /* Typecast the value to a string so that it can be manipulated */
    string *sb = (string*)obj->value;

    /* In case of empty input */
    if(sb == NULL) {
        return;
    }

    /* Call truncate with 0, essentially clearing out the string */
    string_shorten(obj, 0);
}

void string_skip(stringT *obj, size_t len) {
    /* Typecast the value to a string so that it can be manipulated */
    string *sb = (string*)obj->value;

    /* In case of invalid inputs */
    if(sb == NULL || len == 0) {
        return;
    }

    /* If we choose to drop more bytes than the string has */
    if(len >= sb->length) {
        /* Simply clear the string */
        string_delete(obj);
        return;
    }

    sb->length -= len;

    /* +1 to move the NULL. */
    memmove(sb->str, sb->str+len, sb->length+1);
}

size_t string_length(stringT *obj) {
    /* Typecast the value to a string so that it can be manipulated */
    string *sb = (string*)obj->value;

    /* In case of empty input */
    if(sb == NULL) {
        return 0;
    }
    return sb->length;
}

void string_free(stringT *obj) {
    /* Typecast the value to a string so that it can be manipulated */
    string *sb = (string*)obj->value;

    /* In case of NULL input */
    if(sb == NULL) {
        return;
    }

    /* Free the allocated string */
    free(sb->str);

    /* Free the pointer itself */
    free(sb);
}
