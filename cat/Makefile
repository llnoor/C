CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11

.PHONY: all clean

all: grep

clean:
	rm -rf *.o cat/*.o grep/*.o common/*.o cat/s21_cat grep/s21_grep

cat: clean cat_main

grep: clean grep_main

cat_main: cat/s21_cat.o common/s21_common.o
	$(CC) cat/s21_cat.o common/s21_common.o -o cat/s21_cat

s21_cat.o: cat/s21_cat.h cat/s21_cat.c
	$(CC) $(CFLAGS) -c cat/s21_cat.c -o cat/s21_cat.o



grep_main: grep/s21_grep.o common/s21_common.o
	$(CC) grep/s21_grep.o common/s21_common.o -o grep/s21_grep

s21_grep.o: grep/s21_grep.h grep/s21_grep.c
	$(CC) $(CFLAGS) -c grep/s21_grep.c -o grep/s21_grep.o

s21_common.o: common/s21_common.h common/s21_common.c
	$(CC) $(CFLAGS) -c common/s21_common.c -o common/s21_common.o
