#ifndef _HASH_H
#define _HASH_H

#include<stdint.h>

typedef struct HashNode_s {
    char* key;
    void* value;
    struct HashNode_s* next;
} HashNode;

typedef struct HashTable_s {
    size_t (*fn) (const char*);
    HashNode** nodes;
} HashTable;

HashTable* hashtable_init(uint32_t(*)(const char*));
void hashtable_destroy(HashTable*);

void hashtable_set(HashTable*, const char*, void*);
void* hashtable_get(HashTable*, const char*);
void hashtable_del(HashTable*, const char*);

#endif
