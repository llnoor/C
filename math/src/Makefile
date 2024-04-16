CC=gcc
STDFLAGS=-std=c11 -Wall -Werror -Wextra 
TEST_CFLAGS= -g $(STDFLAGS) #-fsanitize=address
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
LINUX_FLAGS=-lpthread -lcheck -pthread -lrt -lm
LIBS=-lcheck
VALGRIND_FLAGS=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose

TARGET=math.a

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o, ${SRC})
# HEADER=$(wildcard *.h)

PREF_TEST_SRC=./unit_tests/
TEST_SRC=$(wildcard $(PREF_TEST_SRC)/*.c)
# TEST_OBJ = $(patsubst %.c,%.o, ${TEST_SRC})

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

test: math_test.c
ifeq ($(OS), Darwin)
	${CC} $(STDFLAGS) ${TEST_SRC} $< $(TARGET) -o unit_test $(LIBS)
else
	${CC} $(STDFLAGS) ${TEST_SRC} $< $(TARGET) -o unit_test $(LIBS) $(LINUX_FLAGS)
endif
	./unit_test

gcov_report: clean_test
ifeq ($(OS), Darwin)
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) ${TEST_SRC} ${SRC} math_test.c -o test $(LIBS)
else
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) ${TEST_SRC} ${SRC} math_test.c -o test $(LIBS) $(LINUX_FLAGS)
endif
	./test
	lcov -t "stest" -o test.info -c -d .
	genhtml -o report test.info
	$(OPEN_CMD) ./report/index.html

valgrind: math_test.c
	$(CC) $(TEST_CFLAGS) ${TEST_SRC} $< $(TARGET) -o test $(LIBS) $(LINUX_FLAGS)
	CK_FORK=no valgrind $(VALGRIND_FLAGS) --log-file=RESULT_VALGRIND.txt ./test

clang:
	clang-format -style=Google -n *.c *.h;

leaks:
	CK_FORK=no leaks --atExit -- ./unit_test

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
	rm -rf RESULT_VALGRIND.txt

.PHONY: all clean check lcov
