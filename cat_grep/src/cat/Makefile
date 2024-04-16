CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
CAT = cat

.PHONY: all clean

all: cat

clean:
	rm -rf *.o $(CAT)

cat: cat.o common.o
	$(CC) cat.o common.o -o $(CAT)

cat.o: cat.h cat.c
	$(CC) $(CFLAGS) -c cat.c -o cat.o

common.o: ../common/common.h ../common/common.c
	$(CC) $(CFLAGS) -c ../common/common.c -o common.o
