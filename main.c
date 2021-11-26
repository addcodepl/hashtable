#include "hash.h"
#include "hashtable.h"


int main() {
    struct ht* table = hashtable_create(naive_hash);
    hashtable_set(table, "a", "value of A");
    hashtable_set(table, "b", "value of B");
    hashtable_set(table, "b", "value of B with collision");
    hashtable_set(table, "c", "value of C");
    hashtable_show(table);

    return 0;
}
