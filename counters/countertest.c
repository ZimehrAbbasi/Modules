/* 
 * countertest.c
 *
 * @Author Zimehr Abbasi
 * Testfile for counters.c
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counters.h"
#include "file.h"

static void itemcount(void *arg, const int key, int item);

int main(const int argc, const char *argv[])
{
    counters_t *counters = counters_new();

    printf("testing counters_add...\n");
    int a = counters_add(counters, 1);
    a = counters_add(counters, 2);
    a = counters_add(counters, 3);
    a = counters_add(counters, 4);
    a = counters_add(counters, 1);
    printf("Count of 1: %d\n", a);
    printf("\n");

    printf("testing counters_get...\n");
    counters_print(counters, stdout);
    int b = counters_get(counters, 1);
    int c = counters_get(counters, 8);
    printf("Count of 1: %d\n", b);
    printf("Count of 8: %d\n", c);
    printf("\n");
    
    printf("testing counters_set...\n");
    printf("Before:\n");
    counters_print(counters, stdout);
    counters_set(counters, 5, 100);
    printf("After:\n");
    counters_print(counters, stdout);
    printf("\n");

    printf("testing counters_iterate...\n");
    int* totalcount;
    int x = 0;
    totalcount = &x;
    counters_iterate(counters, totalcount, itemcount);
    printf("Total count: %d\n", *totalcount);
    counters_print(counters, stdout);
    printf("\n");

    printf("deleting counter...\n");
    counters_delete(counters);
    return 0;
}

static void itemcount(void *arg, const int key, int item)
{
    int *nitems = arg;

    if (nitems != NULL)
        (*nitems)+=item;
}