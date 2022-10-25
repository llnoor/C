CC=gcc
CFLAGS=-Wall -Wextra -Werror

.PHONY: all clean rebuild

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests

clean:
	rm -rf *.o *.a *.so

rebuild: 
	clean all

strlen_tests:
	$(CC) $(CFLAGS) s21_string_test.c s21_string.c -DSTRLEN -o ../build/Quest_1

strcmp_tests:
	$(CC) $(CFLAGS) s21_string_test.c s21_string.c -DSTRCMP -o ../build/Quest_2

strcpy_tests:
	$(CC) $(CFLAGS) s21_string_test.c s21_string.c -DSTRCPY -o ../build/Quest_3

strcat_tests:
	$(CC) $(CFLAGS) s21_string_test.c s21_string.c -DSTRCAT -o ../build/Quest_4

strchr_tests:
	$(CC) $(CFLAGS) s21_string_test.c s21_string.c -DSTRCHR -o ../build/Quest_5

strstr_tests:
	$(CC) $(CFLAGS) s21_string_test.c s21_string.c -DSTRSTR -o ../build/Quest_6

strtok_tests:
	$(CC) $(CFLAGS) s21_string_test.c s21_string.c -DSTRSTR -o ../build/Quest_7