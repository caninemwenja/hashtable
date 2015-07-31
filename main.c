#include <stdio.h>
#include "hash.h"

int main(){
    HashTable* hashtable;
    char c;
    int a, res;
    void* data;

    c = 'k';
    a = 24;

    hashtable = hashtable_init(NULL);
    if(hashtable == NULL){
        printf("Init did not work.\n");
        return 1;
    }

    res = hashtable_set(hashtable, "name", &c);
    if(res != 0){
        printf("Set 'name' did not work.\n");
        return 1;
    }

    res = hashtable_set(hashtable, "age", &a);
    if(res != 0){
        printf("Set 'age' did not work.\n");
        return 1;
    }

    data = hashtable_get(hashtable, "name");
    if(data == NULL){
        printf("Get 'name' did not work.\n");
        return 1;
    }
    printf("Retrieved name: %c.\n", *(char *)data);

    data = hashtable_get(hashtable, "age");
    if(data == NULL){
        printf("Get 'age' did not work.\n");
        return 1;
    }
    printf("Retrieved age: %i.\n", *(int *)data);

    hashtable_del(hashtable, "name");
    data = hashtable_get(hashtable, "name");
    if(data != NULL){
        printf("Delete didnt work.\n");
        return 1;
    }

    hashtable_destroy(hashtable);

    return 0;
}
