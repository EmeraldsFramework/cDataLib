#include "export/cDataLib/cDataLib.h"

extern garbage_collector *gc;

void *double_item(object *item) {
    return new_intT((int)object_get_value(item) * 2);
}

void *positive_filter(object *item) {
    return (int)(object_get_value(item)) > 0;
}

void *adder(object *accumulator, object *current) {
    return new_intT((int)object_get_value(accumulator) + (int)object_get_value(current));
}

void print_strings(stringT *element) {
    printf("%s\n", string_get(element));
}

void print_ints(intT *obj) {
    printf("%d\n", object_get_value(obj));
}

void print_keys(char *key) {
    printf("key: %s\n", key);
}

int main(void) {
    gc = new_garbage_collector(4096);

    printf("TESTING VECTOR MAP FILTER REDUCE\n");
    vectorT *testv = new_vectorT();

    vector_add(testv, new_intT(1));
    vector_add(testv, new_intT(2));
    vector_add(testv, new_intT(-3));
    vector_add(testv, new_intT(-4));
    vector_add(testv, new_intT(5));
    vector_add(testv, new_intT(-1));
    vector_add(testv, new_intT(-2));
    vector_add(testv, new_intT(3));
    vector_add(testv, new_intT(4));
    vector_add(testv, new_intT(-5));

    vectorT *double_testv = vector_map(testv, double_item);
    vectorT *positive_double_testv = vector_filter(double_testv, positive_filter);
    int sum = vector_reduce(positive_double_testv, adder);
    printf("SUM: %d\n\n", sum);



    hashmapT *testh = new_hashmapT();
    hashmap_add(testh, "1", new_intT(-11));
    hashmap_add(testh, "20", new_intT(-2));
    hashmap_add(testh, "3", new_intT(3));
    hashmap_add(testh, "42", new_intT(-4));
    hashmap_add(testh, "5", new_intT(5));
    hashmap_add(testh, "56", new_intT(5));
    hashmap_add(testh, "500", new_intT(6));
    hashmap_add(testh, "64", new_intT(1));
    hashmap_add(testh, "7", new_intT(1));

    printf("TESTING HASH MAP FILTER REDUCE\n");
    hashmapT *double_hashmap = hashmap_map(testh, double_item, VALUES);
    hashmapT *positive_double_hashmap = hashmap_filter(double_hashmap, positive_filter, VALUES);
    int hsum = hashmap_reduce(positive_double_hashmap, adder, VALUES);
    printf("HASH SUM: %d\n\n", hsum);


    
    printf("TESTING STRING SPLIT\n");
    stringT *str_to_split = new_stringT("cut me in pieces");
	stringT *delimeter_to_use = new_stringT(" ");
	
	vectorT *list_of_tokens = string_split(str_to_split, delimeter_to_use);
	vector_map(list_of_tokens, print_strings);
    printf("ORIGINAL: %s\n", string_get(str_to_split));
    printf("\n");

    

    printf("TESTING LINKED LIST\n");
    linked_listT *llist = new_linked_listT();
    linked_list_add(llist, new_intT(-1));
    linked_list_add(llist, new_intT(-2));
    linked_list_add(llist, new_intT(-3));
    linked_list_add(llist, new_intT(1));
    linked_list_add(llist, new_intT(2));
    linked_list_add(llist, new_intT(-4));
    linked_list_add(llist, new_intT(-5));
    linked_list_add(llist, new_intT(3));
    linked_list_add(llist, new_intT(4));
    linked_list_add(llist, new_intT(5));
    
    linked_listT *double_list = linked_list_map(llist, double_item);
    linked_listT *positive_double_list = linked_list_filter(double_list, positive_filter);
    int lsum = linked_list_reduce(positive_double_list, adder);
    printf("LL SUM: %d\n\n", lsum);



    printf("TESTING STACK\n");
    stackT *st = new_stackT();
    stack_push(st, 2);
    stack_push(st, 3);
    stack_push(st, -1);
    printf("item %d, should be -1\n", (int)stack_pop(st));
    printf("item %d, should be 3\n", (int)stack_pop(st));
    printf("peek item %d should be 2\n", (int)stack_peek(st));
    printf("item %d, should be 2\n", (int)stack_pop(st));
    printf("\n");



    printf("TESTING GARBAGE COLLECTOR\n");
    stringT *strValue1 = new_stringT("test value 1");
    stringT *strValue2 = new_stringT("test value 2");
    stringT *strValue3 = new_stringT("test value 3");
    stringT *strValue4 = new_stringT("test value 4");
    stringT *strValue5 = new_stringT("test value 5");
    
    printf("BEFORE: %s, %s, %s, %s, %s\n", string_get(strValue1), string_get(strValue2), string_get(strValue3), string_get(strValue4), string_get(strValue5));
    garbage_collector_free(gc);
    printf("AFTER:  %p, %p, %p, %p, %p\n", string_get(strValue1), string_get(strValue2), string_get(strValue3), string_get(strValue4), string_get(strValue5));

    return 0;
}
