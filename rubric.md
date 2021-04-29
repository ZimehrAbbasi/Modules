# Lab 3

## Zimehr Abbasi

## Katie Huang

Recall the [Assignment](https://www.cs.dartmouth.edu/~cs50/Labs/lab3).

**Total: 97/100 points**

### (28) set

28/28 points

### (30) counters

29/30 points:

* -1 Your `counters_get` increments by 1 when in `counters.h` it specifies that it should return the current value of the counter. This leads
to a bug where your counter is off by the number of times you use `counters_get`. 

```
\\ grader test
testing counters_get...
test counters_get(NULL): ok
test counters_get(-1): 0
test counters_get(0): 2    \\ should be 1
test counters_get(1): 9    \\ should be 8, etc.
test counters_get(2): 8
test counters_get(3): 13
test counters_get(4): 12
test counters_get(5): 11
test counters_get(6): 10
test counters_get(7): 16
test counters_get(8): 11
test counters_get(9): 8
test counters_get(10): 12
done

testing counters_iterate to sum the counters:
sum = 112: FAILED
```

### (34) hashtable

34/34 points:

* general comment: for set and hashtable, you do not check to see if mallocing the set(s) might cause you to run out of memory; no points off for this,
but in an ideal situation you would catch this and then free all the previous sets you had already malloc'd
* no points off, but you have multiple invalid read/writes in hashtable of size 1 when running with valgrind; these will be penalized on future labs
```
testing hashtable_insert...
==35386== Invalid write of size 1
==35386==    at 0x4C34E0D: strcpy (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==35386==    by 0x10982C: set_insert (set.c:60)
==35386==    by 0x109055: hashtable_insert (hashtable.c:61)
==35386==    by 0x108CB8: main (hashtabletest.c:53)
==35386==  Address 0x522f884 is 0 bytes after a block of size 4 alloc'd
==35386==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==35386==    by 0x10954F: mem_malloc (mem.c:53)
==35386==    by 0x109815: set_insert (set.c:59)
==35386==    by 0x109055: hashtable_insert (hashtable.c:61)
==35386==    by 0x108CB8: main (hashtabletest.c:53)
// there are seven of these, one for every insert I believe

testing hashtable_find...
==35386== Invalid read of size 1
==35386==    at 0x4C35DC4: strcmp (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==35386==    by 0x109911: set_find (set.c:102)
==35386==    by 0x1090D5: hashtable_find (hashtable.c:77)
==35386==    by 0x108E3A: main (hashtabletest.c:75)
==35386==  Address 0x522f884 is 0 bytes after a block of size 4 alloc'd
==35386==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==35386==    by 0x10954F: mem_malloc (mem.c:53)
==35386==    by 0x109815: set_insert (set.c:59)
==35386==    by 0x109055: hashtable_insert (hashtable.c:61)
==35386==    by 0x108CB8: main (hashtabletest.c:53)
==35386==
```

### (8) Overall

6/8 points:

* -2 poor git practices with commits; all of them occur on the submission date rather than being spaced out throughout the progress of the lab,
and have unclear/similar git commit messages

