CC=gcc
STDFLAGS=-std=c11 -Wall -Werror -Wextra 
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
LINUX_FLAGS=-lpthread -lcheck -pthread -lrt -lm -lsubunit
LIBS=-lcheck

TARGET=decimal.a

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o, ${SRC})

OS := $(shell uname -s)
USERNAME=$(shell whoami)

ifeq ($(OS),Linux)
	OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

all: clean $(TARGET)

$(TARGET): ${SRC}
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rc $@ $(OBJ)
	ranlib $@
	cp $@ lib$@

test: clean decimal.a
ifeq ($(OS), Darwin)
	$(CC) $(STDFLAGS) -c ./tests/*.c
	$(CC) $(STDFLAGS) $(TARGET) *.o -o unit_test $(LIBS)
else
	$(CC) $(STDFLAGS) -c ./tests/*.c
	$(CC) $(STDFLAGS) $(TARGET) *.o -o unit_test $(LIBS) $(LINUX_FLAGS)
endif
	./unit_test

gcov_report: clean_test
ifeq ($(OS), Darwin)
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) ./tests/*.c floor.c from_int_to_decimal.c is_less.c  negate.c  truncate.c  add.c  from_decimal_to_float.c  is_equal.c  is_less_or_equal.c  round.c  from_decimal_to_int.c  is_greater.c  is_not_equal.c  sub.c  div.c  from_float_to_decimal.c  is_greater_or_equal.c  mul.c  sub_functions.c -o test $(LIBS)
else
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) ./tests/*.c floor.c from_int_to_decimal.c is_less.c  negate.c  truncate.c  add.c  from_decimal_to_float.c  is_equal.c  is_less_or_equal.c  round.c  from_decimal_to_int.c  is_greater.c  is_not_equal.c  sub.c  div.c  from_float_to_decimal.c  is_greater_or_equal.c  mul.c  sub_functions.c -o test $(LIBS) $(LINUX_FLAGS)
endif
	./test
	lcov -t "stest" -o test.info -c -d .
	genhtml -o report test.info
	$(OPEN_CMD) ./report/index.html

clang:
	clang-format -style=Google -n *.c *.h

leaks: test
	CK_FORK=no leaks --atExit -- ./unit_test

brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

lcov:
ifeq ($(OS),Linux)
	sudo apt install lcov
endif
ifeq ($(OS),Darwin)
	brew install lcov
endif

clean_obj:
	rm -rf *.o

clean_lib: 
	rm -rf *.a

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report

clean: clean_lib clean_lib clean_test clean_obj
	rm -rf unit_test

.PHONY: all clean check lcov
