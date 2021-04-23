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
    int namecount = 0;

    hashtable_t *hashtable;
    hashtable = hashtable_new(10);
    if (hashtable == NULL)
    {
        printf("hashtable_new failed\n");
        return 0;
    }

    while (!feof(stdin)) {
        char *key = file_readLine(stdin);
        char *d = " ";
        char *ptr = strtok(key, d);
        if (key != NULL) {
            key = ptr;
            ptr = strtok(NULL, d);
            hashtable_insert(hashtable, key, ptr);
            namecount++;
        }
    }

    hashtable_print(hashtable, stdout, printstuff);
    void *item = hashtable_find(hashtable, "key1");
    void *item1 = hashtable_find(hashtable, "3");
    hashtable_iterate(hashtable, countptr, itemcount);
    printf("count: %d\n", count);
    printf("key1: %s\n", (char *)item);
    printf("3: %s\n", (char *)item1);
    hashtable_delete(hashtable, namedelete);
    return 0;
}