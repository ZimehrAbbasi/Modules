# CS50 Lab 3
## CS50 Spring 2021

### counters

### Usage

The *counters* module, defined in `counters.h` and implemented in `counters.c`, implements a set of `int` keys with an `int` count.

```c
counters_t* counters_new(void);
int counters_add(counters_t* ctrs, const int key);
int counters_get(counters_t* ctrs, const int key);
bool counters_set(counters_t* ctrs, const int key, const int count);
void counters_print(counters_t* ctrs, FILE* fp);
void counters_iterate(counters_t* ctrs, void* arg, void (*itemfunc)(void* arg, const int key, const int count));
void counters_delete(counters_t* ctrs);
```

### Implementation

We implement the counters as a linked list.
The *counters* itself is represented as a `struct counters` containing a pointer to the head of the list and the size of the counter.

Each node in the list is a `struct counternode`, a type defined internally to the module.
Each counternode includes `int count`, `int key`, and a pointer to the next counternode on the list.

To insert a new item in the set we create a new counternode to hold the `key` and the `count`, and insert it at the head of the list.

The `counters_find` method returns the count value associated with the respective key; it initializes the key if it is not in the set and sets the value to 1.

The `counters_print` method prints a little syntax around the list, and between items, but mostly calls the `itemprint` function on each item by scanning the linked list.

The `counters_iterate` method calls the `itemfunc` function on each item by scanning the linked list.

The `counters_delete` method calls the `itemdelete` function on each item by scanning the linked list, freeing nodes as it proceeds.
It concludes by freeing the `struct counters`.

### Assumptions

No assumptions beyond those that are clear from the spec.

The `item` or `key` inserted cannot be NULL.

### Files

* `Makefile` - compilation procedure
* `set.h` - the interface
* `set.c` - the implementation
* `settest.c` - unit test driver
* `test.names` - test data
* `testing.out` - result of `make test &> testing.out`


