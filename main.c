#include <stdio.h>
#include "hash.h"
#include "hashtable.h"


int main() {
    struct ht* table = hashtable_create(naive_hash);
    hashtable_set(table, "a", "value of A");
    hashtable_set(table, "b", "value of B");
    hashtable_set(table, "b", "value of B with collision");
    hashtable_set(table, "c", "value of C");
    hashtable_show(table);

    if(hashtable_contains(table, "c")) {
        printf("c is in hashtable\n");
    }

    if(!hashtable_contains(table, "d")) {
        printf("d isn't in hashtable\n");
    }

    printf("Get value for key [c] is equal: [%s]", hashtable_get(table, "c"));

    return 0;
}
