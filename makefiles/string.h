#ifndef SRC_STRING_H_
#define SRC_STRING_H_
#include <stdlib.h>

size_t C_strlen(const char *str);
int C_strcmp(const char *, const char *);
char *C_strcpy(char *toHere, const char *fromHere);
char *C_strcat(char *toHere, const char *fromHere);
char *C_strchr(const char *str, int ch);
char *C_strstr(const char *searchHere, const char *findThis);
int C_strstr_match(const char *searchHere, const char *findThis);

#endif  // SRC_STRING_H_
