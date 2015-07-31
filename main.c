#include <stdio.h>
#include "hash.h"

int main(){
    HashTable* hashtable;
    char c;
    int a;
    void* data;

    c = 'k';
    a = 24;

    hashtable = hashtable_init(NULL);
    hashtable_set(hashtable, "name", &c);
    hashtable_set(hashtable, "age", &a);

    data = hashtable_get(hashtable, "name");
    printf("Retrieved name: %c.\n", *(char *)data);

    data = hashtable_get(hashtable, "age");
    printf("Retrieved age: %i.\n", *(int *)data);

    hashtable_del(hashtable, "name");

    data = hashtable_get(hashtable, "name");
    if(data == NULL){
        printf("Delete worked.\n");
    }
    else{
        printf("Delete didnt work.\n");
    }

    hashtable_destroy(hashtable);

    return 0;
}
