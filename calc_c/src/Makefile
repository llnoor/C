CC = -Wall -Werror -Wextra -std=c11 -pedantic
OS := $(shell uname)

ifeq ($(OS),Linux)
FLAGS = -lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
FYLE = calc/calc
PROGOPEN = ./build/calc
PROG = calc
else
FLAGS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
FYLE = calc/calc.app
PROGOPEN = open ./build/calc.app
PROG = calc.app
endif

all: clean smart_calc.a test gcov_report dvi

install:
	make clean
	mkdir build
	cd calc && qmake && make && make clean && rm Makefile && cd ../ && mv $(FYLE) build

uninstall:
	rm -rf build*

dist:
	rm -rf Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/src
	mv ./build/$(PROG) Archive_SmartCalc_v1.0/src/
	tar cvzf Archive_SmartCalc_v1.0.tgz Archive_SmartCalc_v1.0/
	rm -rf Archive_SmartCalc_v1.0/

dvi:
	open description.md

clean:
	rm -rf *.o *.a unit_test
	rm -rf *.gcno *gcda *.gcov gcov
	rm -rf report report.info
	rm -rf *.dSYM

test: clean smart_calc.a
	gcc tests/test.c smart_calc.a $(FLAGS) -o unit_test
	./unit_test

gcov_report: clean
	gcc tests/test.c bank.c stack.c string.c $(FLAGS) -o unit_test
	./unit_test
	lcov -t "./unit_test" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html
	rm -rf *.gcno *gcda *.gco

smart_calc.a:
	gcc $(CC)  -c bank.c
	gcc $(CC)  -c stack.c
	gcc $(CC)  -c string.c
	ar -crs smart_calc.a bank.o stack.o string.o

clang:
	clang-format --style=Google -n *.c *.h
	clang-format --style=Google -n ./calc/*.cpp ./calc/*.h

leak: test
	leaks --atExit -- ./unit_test

open:
	$(PROGOPEN)
