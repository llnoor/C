CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
GREP = grep

.PHONY: all clean

all: grep

clean:
	rm -rf *.o $(GREP)

grep: grep.o common.o
	$(CC) grep.o common.o -o $(GREP)

grep.o: grep.h grep.c
	$(CC) $(CFLAGS) -c grep.c -o grep.o

common.o: ../common/common.h ../common/common.c
	$(CC) $(CFLAGS) -c ../common/common.c -o common.o
