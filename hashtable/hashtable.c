#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "hash.h"
#include "mem.h"

typedef struct hashtable
{
    set_t** set;
} hashtable_t;

hashtable_t* hashtable_new(const int num_slots)
{
    hashtable_t *ht = (hashtable_t *)mem_malloc(sizeof(hashtable_t));

    if (ht == NULL)
    {
        return NULL; // error allocating hashtable
    }
    else
    {
        ht->set = mem_calloc(num_slots, sizeof(set_t*));
        set_t** set;
        set = ht->set;
        for(int i = 0; i < num_slots; i++){
            set[i] = set_new();
        }
        return ht;
    }
}

int main(const int argc, const char* argv[]){

    hashtable_t* ht = hashtable_new(10);
    if (ht == NULL)
    {
        printf("set_new failed\n");
        return 0;
    }

    return 0;
}