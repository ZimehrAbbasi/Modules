#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counters.h"
#include "file.h"

int main(const int argc, const char *argv[])
{
    counters_t *counters = counters_new();
    int a = counters_add(counters, 1);
    a = counters_add(counters, 2);
    a = counters_add(counters, 3);
    a = counters_add(counters, 4);
    a = counters_add(counters, 1);
    printf("%d\n", a);
    counters_set(counters, 5, 100);
    counters_print(counters, stdout);
    return 0;
}