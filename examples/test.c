#include "../export/cDataLib.h"

#include <stdio.h> /* printf */

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
    char *str = "Hello World";
    char *num = "42";
    puts("My num is: ", num, " and my string is: ", str, "\n");
    printf("TESTING STRING ITERATION\n");
    string *iter = new_string("oblivious");
    string_iterate(iter, print_chars);
    printf("\n");
    printf("TESTING STRING SPLIT\n");
    string *str_to_split = new_string("cut me in pieces");
	string *delimeter_to_use = new_string(" ");
	
	vector *list_of_tokens = string_split(str_to_split, delimeter_to_use);
	vector_map(list_of_tokens, print_strings);
    printf("ORIGINAL: %s\n", string_get(str_to_split));
    printf("\n");
    printf("TESTING STRING EQUALITY\n");
    string *one = new_string("test");
    string *two = new_string("test");
    if(string_equals(one, two)) printf("strings `one(\"test\")` and `two(\"test\")` are equal\n\n");

    printf("TESTING (LITTERBIN) -> STRING\n");
    string *strValue1 = new_string("test value 1");
    string *strValue2 = new_string("test value 2");
    string *strValue3 = new_string("test value 3");
    string *strValue4 = new_string("test value 4");
    string *strValue5 = new_string("test value 5");
    
    printf("BEFORE: %s, %s, %s, %s, %s\n", string_get(strValue1), string_get(strValue2), string_get(strValue3), string_get(strValue4), string_get(strValue5));
    free(strValue1);
    free(strValue2);
    free(strValue3);
    free(strValue4);
    free(strValue5);
    printf("AFTER:  %s, %s, %s, %s, %s\n\n", string_get(strValue1), string_get(strValue2), string_get(strValue3), string_get(strValue4), string_get(strValue5));






    printf("TESTING VECTOR MAP FILTER REDUCE\n");
    vector *testv = new_vector();

    vector_add(testv, 1);
    vector_add(testv, 2);
    vector_add(testv, -3);
    vector_add(testv, -4);
    vector_add(testv, 5);
    vector_add(testv, -1);
    vector_add(testv, -2);
    vector_add(testv, 3);
    vector_add(testv, 4);
    vector_add(testv, -5);

    vector *double_testv = vector_map(testv, double_item);
    vector *positive_double_testv = vector_filter(double_testv, positive_filter);
    int sum = vector_reduce(positive_double_testv, adder);
    printf("SUM: %d\n\n", sum);






    hashmap *testh = new_hashmap();
    hashmap_add(testh, "1", -11);
    hashmap_add(testh, "20", -2);
    hashmap_add(testh, "3", 3);
    hashmap_add(testh, "42", -4);
    hashmap_add(testh, "5", 5);
    hashmap_add(testh, "56", 5);
    hashmap_add(testh, "500", 6);
    hashmap_add(testh, "64", 1);
    hashmap_add(testh, "7", 1);

    printf("TESTING NON EXISTENT HASHMAP ELEMENT\n");
    void *null_value = hashmap_get(testh, "1241241");
    if(null_value == NULL) printf("its null\n");
    else printf("its not null\n");

    printf("TESTING HASH MAP FILTER REDUCE\n");
    hashmap *double_hashmap = hashmap_map(testh, double_item, VALUES);
    hashmap *positive_double_hashmap = hashmap_filter(double_hashmap, positive_filter, VALUES);
    int hsum = hashmap_reduce(positive_double_hashmap, adder, VALUES);
    printf("HASH SUM: %d\n\n", hsum);

    




    printf("TESTING STACK\n");
    stack *st = new_stack();
    stack_push(st, 2);
    stack_push(st, 3);
    stack_push(st, -1);
    printf("item %d, should be -1\n", stack_pop(st));
    printf("item %d, should be 3\n", stack_pop(st));
    printf("peek item %d should be 2\n", stack_peek(st));
    printf("item %d, should be 2\n", stack_pop(st));
    printf("\n");






    printf("TESTING LINKED LIST\n");
    linked_list *llist = new_linked_list();
    linked_list_add(llist, -1);
    linked_list_add(llist, -2);
    linked_list_add(llist, -3);
    linked_list_add(llist, 1);
    linked_list_add(llist, 2);
    linked_list_add(llist, -4);
    linked_list_add(llist, -5);
    linked_list_add(llist, 3);
    linked_list_add(llist, 4);
    linked_list_add(llist, 5);
    
    linked_list *double_list = linked_list_map(llist, double_item);
    linked_list *positive_double_list = linked_list_filter(double_list, positive_filter);
    int lsum = linked_list_reduce(positive_double_list, adder);
    printf("LL SUM: %d\n", lsum);

/* #if defined(_WIN32)
    getch();
#endif */

    return 0;
/* }); */
}
