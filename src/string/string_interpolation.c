#include "../../headers/string/string_interpolation.h"

void display(size_t argc, ...) {
    string *sb = new_string("");
    
    va_list vars;
    va_start(vars, argc);
        int i;
        for(i = 0; i < argc; i++)
            string_add_str(sb, va_arg(vars, void*));
    va_end(vars);
    
    printf("displaying: %s\n", string_get(sb));
    string_delete(sb);
}