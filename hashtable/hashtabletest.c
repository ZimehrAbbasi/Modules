/* 
 * hashtabletest.c
 *
 * @Author Zimehr Abbasi
 * Testfile for hashtable.c
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "file.h"

void printstuff(FILE *fp, const char *key, void *item);
static void itemcount(void *arg, const char *key, void *item);
void namedelete(void *item);

void printstuff(FILE *fp, const char *key, void *item)
{
    const char *keyname = key;
    char *value = item;
    fprintf(fp, "(%s, %s)", keyname, value);
}

static void itemcount(void *arg, const char *key, void *item)
{
    int *nitems = arg;

    if (nitems != NULL && item != NULL)
        (*nitems)++;
}

void namedelete(void *item)
{
    printf("%s\n", (char *)item);
}

int main(const int argc, const char* argv[]){

    int count = 0;
    int *countptr = &count;
    int hashtablesize = 10;

    hashtable_t *hashtable;
    hashtable = hashtable_new(hashtablesize);
    if (hashtable == NULL)
    {
        printf("hashtable_new failed\n");
        return 0;
    }

    printf("testing hashtable_insert...\n");
    hashtable_insert(hashtable, "key1", "Alfonso");
    hashtable_insert(hashtable, "key2", "Amittai");
    hashtable_insert(hashtable, "key3", "Zimehr");
    hashtable_insert(hashtable, "key4", "Jessica");
    hashtable_insert(hashtable, "key5", "Ricky");
    hashtable_insert(hashtable, "key6", "Martin");
    hashtable_insert(hashtable, "key7", "Rabiniranath");
    printf("\n");
    hashtable_print(hashtable, stdout, printstuff);
    printf("\n");

    printf("test with null hashtable, good key, good item...\n");
    hashtable_insert(NULL, "Dartmouth", "College");
    printf("test with null key, good item...\n");
    hashtable_insert(hashtable, NULL, "Dartmouth"); 
    printf("test with good key, null item...\n");
    hashtable_insert(hashtable, "Dartmouth", NULL); 
    printf("test with null hashtable, null key, null item...\n");
    hashtable_insert(NULL, NULL, NULL);
    printf("\n");

    printf("testing hashtable_find...\n");
    void *item = hashtable_find(hashtable, "key1");
    void *item1 = hashtable_find(hashtable, "3");
    printf("Key: key1 Item: %s\n", (char *)item);
    printf("Key: 3 Value: %s\n", (char *)item1);
    printf("\n");

    printf("testing hashtable_iterate...\n");
    hashtable_iterate(hashtable, countptr, itemcount);
    printf("Total count: %d\n", count);
    printf("\n");

    printf("Deleting the hashtable\n");
    hashtable_delete(hashtable, namedelete);
    return 0;
}