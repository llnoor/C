#ifndef SRC_STRING_H_
#define SRC_STRING_H_
#include <stdlib.h>

size_t s21_strlen(const char *str);
int s21_strcmp(const char *, const char *);
char *s21_strcpy(char *toHere, const char *fromHere);
char *s21_strcat(char *toHere, const char *fromHere);
char *s21_strchr(const char *str, int ch);
char *s21_strstr(const char *searchHere, const char *findThis);
int s21_strstr_match(const char *searchHere, const char *findThis);

#endif  // SRC_STRING_H_
