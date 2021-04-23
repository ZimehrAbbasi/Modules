#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "set.h"
#include "hash.h" 
#include "mem.h"


typedef struct hashtable{
    set_t** set;
    int size;
    int num_items;
} hashtable_t;

hashtable_t* hashtable_new(const int num_slots){

    hashtable_t* hashtable = (hashtable_t*)mem_malloc(sizeof(hashtable_t));

    if (hashtable == NULL)
    {
        return NULL; // error allocating counter
    }
    else
    {
        hashtable->set = mem_calloc(num_slots, sizeof(set_t*));
        set_t** sets = mem_calloc(num_slots, sizeof(set_t*));
        sets = hashtable->set;

        for(int i = 0; i < num_slots; i++){
            sets[i] = set_new();
        }
        hashtable->size = num_slots;
        hashtable->num_items = 0;

        return hashtable;
    }
}

bool hashtable_insert(hashtable_t* ht, const char* key, void* item){
    if(ht != NULL && key != NULL){
        char *keycpy = (char *)mem_malloc(strlen(key) * sizeof(char));
        strcpy(keycpy, key);

        set_t** sets;
        sets = ht->set;

        if(hashtable_find(ht, keycpy) != NULL){
            return false;
        }

        unsigned long index = hash_jenkins(keycpy, ht->size);
        bool success = set_insert(sets[index], keycpy, item);
        if(success){
            ht->num_items += 1;
            return true;
        }
    }
    return false;
}

void* hashtable_find(hashtable_t* ht, const char* key){
    if(ht != NULL && key != NULL){
        set_t** sets;
        sets = ht->set;

        for(int i = 0; i < ht->size;i++){
            void *item = set_find(sets[i], key);
            if(item != NULL){
                return item;
            }
        }
    }

    return NULL;
}

void hashtable_print(hashtable_t* ht, FILE* fp, void (*itemprint)(FILE* fp, const char* key, void* item)){
    if(fp != NULL){
        if(ht != NULL){
            set_t** sets;
            sets = ht->set;
            for(int i = 0; i < ht->size;i++){
                if(itemprint == NULL){
                    fputs("{}\n", fp);
                    continue;
                }
                set_print(sets[i], fp, itemprint);
            }
        }else{
            fputs("(null)", fp);
        }
    }
}

void hashtable_iterate(hashtable_t* ht, void* arg, void (*itemfunc)(void* arg, const char* key, void* item)){
    if(ht != NULL && itemfunc != NULL){
        set_t** sets;
        sets = ht->set;
        for(int i = 0; i < ht->size;i++){
            set_iterate(sets[i], arg, itemfunc);
        }
    }
}

void hashtable_delete(hashtable_t* ht, void (*itemdelete)(void* item) ){
    if (ht != NULL)
    {
        set_t** sets;
        sets = ht->set;
        for(int i = 0; i < ht->size;i++){
            set_delete(sets[i], itemdelete);
        }
    }
}