# CS50 Lab 3
## CS50 Spring 2021

### hashtable

### Usage

The *hashtable* module, defined in `hashtable.h` and implemented in `hashtable.c`, implements a hashtable of `void*` items with `char*` keys, and exports the following functions:

```c
hashtable_t* hashtable_new(void);
bool hashtable_insert(hashtable_t* hashtable, const char* key, void* item);
void* hashtable_find(hashtable_t* hashtable, const char* key);
void hashtable_print(hashtable_t* hashtable, FILE* fp, void (*itemprint)(FILE* fp, const char* key, void* item) );
void hashtable_iterate(hashtable_t* hashtable, void* arg, void (*itemfunc)(void* arg, const char* key, void* item) );
void hashtable_delete(hashtable_t* hashtable, void (*itemdelete)(void* item) );
```

### Implementation

We implement this hashtable as an array of sets.
The *hashtable* itself is represented as a `struct hashtable` containing a pointer to the head of the array.

Each datapoint in `struct hashtable`, is an individual set.

To insert a new item in the hashtable we pass the key through a hash function and append the key:item pair to the set at that position.

The `hashtable_find` method returns the item value associated with the respective key; it returns null if the key is not in the hashtable.

The `hashtable_print` method prints a little syntax around the list, and between items.

The `hashtable_iterate` method calls the `itemfunc` function on each item by scanning the linked list.

The `hashtable_delete` method frees the `struct hashtable`, as well as the keys in all the sets, and teh sets themselves.

### Assumptions

No assumptions beyond those that are clear from the spec.

The `key` or `item` inserted cannot be NULL.

### Files

* `Makefile` - compilation procedure
* `hash.h` - the interface of the hash function
* `hash.c` - the implementation of the hash function
* `hashtable.h` - the interface
* `hashtable.c` - the implementation
* `hashtabletest.c` - unit test driver
* `test.names` - test data
* `testing.out` - result of `make test &> testing.out`


