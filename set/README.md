# CS50 Lab 3
## CS50 Spring 2021

### set

### Usage

The *set* module, defined in `set.h` and implemented in `set.c`, implements a set of `void*` items with `char*` keys, and exports the following functions:

```c
set_t* set_new(void);
bool set_insert(set_t* set, const char* key, void* item);
void* set_find(set_t* set, const char* key);
void set_print(set_t* set, FILE* fp, void (*itemprint)(FILE* fp, const char* key, void* item) );
void set_iterate(set_t* set, void* arg, void (*itemfunc)(void* arg, const char* key, void* item) );
void set_delete(set_t* set, void (*itemdelete)(void* item) );
```

### Implementation

We implement this set as a linked list.
The *set* itself is represented as a `struct set` containing a pointer to the head of the list and the size of the set; the head.

Each node in the list is a `struct setnode`, a type defined internally to the module.
Each setnode includes a pointer to the `void *item`, a pointer to the `char* key`, and a pointer to the next setnode on the list.

To insert a new item in the set we create a new setnode to hold the `key` and the `item`, and insert it at the head of the list.

The `set_find` method returns the item value associated with the respective key; it returns null if the key is not in the set.

The `set_print` method prints a little syntax around the list, and between items.

The `set_iterate` method calls the `itemfunc` function on each item by scanning the linked list.

The `set_delete` method frees the `struct set`.

### Assumptions

No assumptions beyond those that are clear from the spec.

The `key` inserted cannot be NULL.

### Files

* `Makefile` - compilation procedure
* `counter.h` - the interface
* `counter.c` - the implementation
* `countertest.c` - unit test driver
* `test.names` - test data
* `testing.out` - result of `make test &> testing.out`


