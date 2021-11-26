#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "hash.h"
#include "hashtable.h"

#define HASHTABLE_SIZE 10



struct ht* hashtable_create(unsigned int(*hash_function)(char *)) {
    struct ht* hashtable = malloc(sizeof (struct ht) * 1);

    hashtable->entries = malloc(sizeof (struct ht_entry) * HASHTABLE_SIZE);
    hashtable->size = HASHTABLE_SIZE;
    hashtable->hash = hash_function;

    for(int i = 0; i < HASHTABLE_SIZE; i++) {
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}

struct ht_entry* hashtable_add_entry(char* key, char* value) {
    struct ht_entry* entry = malloc(sizeof (struct ht_entry) * 1);
    entry->key = malloc(strlen(key) + 1);
    entry->value = malloc(strlen(value) + 1);

    strcpy(entry->key, key);
    strcpy(entry->value, value);

    return entry;
}

int hashtable_set(struct ht* hashtable, char* key, char* value) {
    unsigned int offset = hashtable->hash(key) % HASHTABLE_SIZE;
    struct ht_entry* entry = hashtable->entries[offset];

    if (entry == NULL) {
        hashtable->entries[offset] = hashtable_add_entry(key, value);
        return 0;
    }

    fprintf(stderr, "Hashtable collision occurred!\n");
    return -1;
}

void hashtable_show(struct ht* hashtable) {
    for(int i = 0; i < 10; i++) {
        struct ht_entry* entry = hashtable->entries[i];
        if (entry == NULL) {
            continue;
        }

        printf("Entry [%d] - has key [%s] with value [%s]\n", i, entry->key, entry->value);
    }
}

int main() {
    struct ht* table = hashtable_create(naive_hash);
    hashtable_set(table, "a", "value of A");
    hashtable_set(table, "b", "value of B");
    hashtable_set(table, "b", "value of B with collision");
    hashtable_set(table, "c", "value of C");
    hashtable_show(table);

    return 0;
}
