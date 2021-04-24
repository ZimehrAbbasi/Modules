#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "file.h"

void printstuff(FILE *fp, const char *key, void *item);
static void itemcount(void *arg, const char *key, void *item);
void namedelete(void *item);

int main(const int argc, const char *argv[])
{
    int count = 0;
    int *countptr = &count;
    int namecount = 0;
    set_t *set;
    set = set_new();
    if (set == NULL)
    {
        printf("set_new failed\n");
        return 0;
    }

    printf("testing set_insert...\n");
    while (!feof(stdin)) {
        char *key = file_readLine(stdin);
        char *d = " ";
        char *ptr = strtok(key, d);
        if (key != NULL) {
            key = ptr;
            ptr = strtok(NULL, d);
            set_insert(set, key, ptr);
            namecount++;
        }
    }

    printf("test with null set, good key, good item...\n");
    set_insert(NULL, "Dartmouth", "College");
    printf("test with null key, good item...\n");
    set_insert(set, NULL, "Dartmouth"); 
    printf("test with good key, null item...\n");
    set_insert(set, "Dartmouth", NULL); 
    printf("test with null set, null key, null item...\n");
    set_insert(NULL, NULL, NULL);
    printf("\n");
    
    printf("testing set_find...\n");
    void *item = set_find(set, "key1");
    void *item1 = set_find(set, "3");
    printf("Key: key1 Item: %s\n", (char *)item);
    printf("Key: 3 Item: %s\n", (char *)item1);
    printf("\n");

    printf("The set:\n");
    set_print(set, stdout, printstuff);
    printf("\n");

    set_iterate(set, countptr, itemcount);
    printf("count: %d\n", count);
    printf("\n");

    printf("Deleting the set\n");
    set_delete(set, NULL);

    return 0;
}

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
    if (item != NULL)
    {
        free(item);
    }
}