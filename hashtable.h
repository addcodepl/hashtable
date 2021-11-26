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

struct ht* hashtable_create(unsigned int(*)(char *));
struct ht_entry* hashtable_add_entry(char*, char*);
int hashtable_set(struct ht*, char*, char*);
int hashtable_contains(struct ht*, char*);
void hashtable_show(struct ht*);

#endif //HASHTABLE_HASHTABLE_H
