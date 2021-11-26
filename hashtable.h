#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

struct ht_entry {
    char* key;
    char* value;
};

struct ht {
    unsigned int size;
    struct ht_entry** entries;
    unsigned int (*hash)(char *);
};

#endif //HASHTABLE_HASHTABLE_H
