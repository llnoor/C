GCC = gcc -Wall -Werror -Wextra -std=c11
FLAGS = -lm -lcheck
SRC = $(shell find core -name "*.c")
TEST_C = $(shell find test -name "*.c")
OS := $(shell uname -s)
QMAKE = qmake
ifeq ($(OS), Linux)
	QMAKE = qmake6
endif

all: clean dist install tests gcov_report dvi

install:
	mkdir -p build
	cd qt && $(QMAKE) 3DViewer.pro && make && make clean && rm Makefile
ifeq ($(OS), Darwin)
	mv qt/3DViewer.app build
else
	mv qt/3DViewer build
endif

uninstall:
	rm -rf build

dist: clean
	tar -czf 3DViewer.tar.gz core qt Makefile

dvi:
	open DVI.md

tests:
ifeq ($(OS), Darwin)
	$(GCC) -o tests.out $(TEST_C) $(SRC) $(FLAGS)
else
	$(GCC) -o tests.out $(TEST_C) $(SRC) $(FLAGS) -lsubunit -lpthread
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./tests.out
endif
	./tests.out

gcov_report:
ifeq ($(OS), Darwin)
	$(GCC) -o tests.out $(TEST_C) $(SRC) $(FLAGS) --coverage
else
	$(GCC) -o tests.out $(TEST_C) $(SRC) $(FLAGS) -lsubunit -lpthread --coverage
endif
	./tests.out
	lcov -t "tests" -o tests.info -c -d .
	genhtml -o report tests.info
	rm -rf *.gcno *.gcda *.info
	open report/index.html

clean: uninstall
	rm -rf $(shell find . -name "*.o" -o -name "*.out") *.gcno *.gcda *.info report 3DViewer.tar.gz

clang:
	clang-format --style=Google -n $(shell find . -name "*.c" -o -name "*.cpp" -o -name "*.h")
	clang-format --style=Google -i $(shell find . -name "*.c" -o -name "*.cpp" -o -name "*.h")
