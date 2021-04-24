# Makefile for 'hashtable' module
#
# David Kotz, April 2016, 2017, 2019, 2021
# updated by Xia Zhou, July 2016, 2018, January 2019

PROG = hashtabletest
OBJS = hashtabletest.o hashtable.o ../lib/file.o ../lib/mem.o hash.o ../set/set.o
LIBS =

# uncomment the following to turn on verbose memory logging
#TESTING=-DMEMTEST

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

hashtabletest.o: hashtable.h ../lib/file.h
hashtable.o: hashtable.h
hash.o: hash.h
set.o: ../set/set.h
../lib/file.o: ../lib/file.h

.PHONY: test valgrind clean

test: $(PROG)
	./$(PROG)

valgrind: $(PROG)
	valgrind ./$(PROG)

clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o
	rm -f $(PROG)
	rm -rf core

