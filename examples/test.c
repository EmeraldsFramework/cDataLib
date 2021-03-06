#include "../export/cDataLib.h"

/* For displaying purposes */
/* #if defined (_WIN32)
    #include <conio.h>
#endif */

int double_item(int item) {
    return item * 2;
}

int positive_filter(int item) {
    return item > 0;
}

int adder(int accumulator, int current) {
    return accumulator + current;
}

void print_strings(string *element) {
    printf("%s\n", string_get(element));
}

void print_chars(char c) {
    printf("char: `%c`\n", c);
}

/*void print_ints(int *item) {
    printf("%d\n", item);
}

void print_keys(char *key) {
    printf("key: %s\n", key);
} */

/* main({ */
int main(void) {
    printf("TESTING STRING INTERPOLATION\n");
    /* char *str = "Hello World"; */
    /* char *num = "42"; */
    /* puts("Num: `", num, "` should be `42` and String: `", str, "` should be `Hello World`", "\n"); */
    /* puts("My num is: ", num, " and my string is: ", str, "\n"); */
    printf("TESTING STRING ITERATION\n");
    string *iter = string_new("oblivious");
    printf("Iteration of `o b l i v i o u s`\n");
    string_iterate(iter, (string_lambda)print_chars);
    printf("\n");
    printf("TESTING STRING SPLIT\n");
    string *str_to_split = string_new("cut me in pieces");
	string *delimeter_to_use = string_new(" ");
	
	vector *list_of_tokens = string_split(str_to_split, delimeter_to_use);
	vector_map(list_of_tokens, (vector_lambda)print_strings);
    printf("ORIGINAL: %s\n", string_get(str_to_split));
    printf("\n");
    printf("TESTING STRING EQUALITY\n");
    string *one = string_new("test");
    string *two = string_new("test");
    if(string_equals(one, two)) printf("strings `one(\"test\")` and `two(\"test\")` are equal\n\n");

    printf("TESTING (LITTERBIN) -> STRING\n");
    string *strValue1 = string_new("test value 1");
    string *strValue2 = string_new("test value 2");
    string *strValue3 = string_new("test value 3");
    string *strValue4 = string_new("test value 4");
    string *strValue5 = string_new("test value 5");
    
    printf("BEFORE: %s, %s, %s, %s, %s\n", string_get(strValue1), string_get(strValue2), string_get(strValue3), string_get(strValue4), string_get(strValue5));
    free(strValue1);
    free(strValue2);
    free(strValue3);
    free(strValue4);
    free(strValue5);
    printf("AFTER:  %p, %p, %p, %p, %p\n\n", string_get(strValue1), string_get(strValue2), string_get(strValue3), string_get(strValue4), string_get(strValue5));






    printf("TESTING VECTOR MAP FILTER REDUCE\n");
    vector *testv = vector_new();

    vector_add(testv, (void*)1);
    vector_add(testv, (void*)2);
    vector_add(testv, (void*)-3);
    vector_add(testv, (void*)-4);
    vector_add(testv, (void*)5);
    vector_add(testv, (void*)-1);
    vector_add(testv, (void*)-2);
    vector_add(testv, (void*)3);
    vector_add(testv, (void*)4);
    vector_add(testv, (void*)-5);

    vector *double_testv = vector_map(testv, (vector_lambda)double_item);
    vector *positive_double_testv = vector_filter(double_testv, (vector_lambda)positive_filter);
    void *sum = vector_reduce(positive_double_testv, (vector_lambda)adder);
    printf("SUM: `%d` should be `30`\n\n", sum);






    hashmap *testh = hashmap_new();
    hashmap_add(testh, "1", (void*)-11);
    hashmap_add(testh, "20", (void*)-2);
    hashmap_add(testh, "3", (void*)3);
    hashmap_add(testh, "42", (void*)-4);
    hashmap_add(testh, "5", (void*)5);
    hashmap_add(testh, "56", (void*)5);
    hashmap_add(testh, "500", (void*)6);
    hashmap_add(testh, "64", (void*)1);
    hashmap_add(testh, "7", (void*)1);

    printf("TESTING NON EXISTENT HASHMAP ELEMENT\n");
    void *null_value = hashmap_get(testh, "1241241");
    if(null_value == NULL) printf("its null\n");
    else printf("its not null\n");

    printf("TESTING HASH MAP FILTER REDUCE\n");
    hashmap *double_hashmap = hashmap_map(testh, (hashmap_lambda)double_item, VALUES);
    hashmap *positive_double_hashmap = hashmap_filter(double_hashmap, (hashmap_lambda)positive_filter, VALUES);
    void *hsum = hashmap_reduce(positive_double_hashmap, (hashmap_lambda)adder, VALUES);
    printf("HASH SUM: `%d` should be `42`\n\n", hsum);

    




    printf("TESTING STACK\n");
    stack *st = stack_new();
    stack_push(st, (void*)2);
    stack_push(st, (void*)3);
    stack_push(st, (void*)-1);
    printf("item %d, should be -1\n", stack_pop(st));
    printf("item %d, should be 3\n", stack_pop(st));
    printf("peek item %d should be 2\n", stack_peek(st));
    printf("item %d, should be 2\n", stack_pop(st));
    printf("\n");






    printf("TESTING LINKED LIST\n");
    linked_list *llist = linked_list_new();
    linked_list_add(llist, (void*)-1);
    linked_list_add(llist, (void*)-2);
    linked_list_add(llist, (void*)-3);
    linked_list_add(llist, (void*)1);
    linked_list_add(llist, (void*)2);
    linked_list_add(llist, (void*)-4);
    linked_list_add(llist, (void*)-5);
    linked_list_add(llist, (void*)3);
    linked_list_add(llist, (void*)4);
    linked_list_add(llist, (void*)5);
    
    linked_list *double_list = linked_list_map(llist, (linked_list_lambda)double_item);
    linked_list *positive_double_list = linked_list_filter(double_list, (linked_list_lambda)positive_filter);
    void *lsum = linked_list_reduce(positive_double_list, (linked_list_lambda)adder);
    printf("LL SUM: `%d` should be `30`\n", lsum);

/* #if defined(_WIN32)
    getch();
#endif */

    return 0;
/* }); */
}
