#include "string.h"
#include <stdlib.h>

size_t C_strlen(const char *str) {
    int i = 0;
    while ( *str != '\0' ) {
        i++;
        str++;
    }
    return i;
}

int C_strcmp(const char *str1, const char *str2) {
    char char1, char2;
    const char *p_char1 = (const char *) str1;
    const char *p_char2 = (const char *) str2;
    do {
        char1 = *p_char1;
        char2 = *p_char2;
        p_char1++;
        p_char2++;
        if (char1 == '\0')
        return char1 - char2;
    } while (char1 == char2);
    return char1 - char2;
}

char *C_strcpy(char *toHere, const char *fromHere) {
    if (toHere == NULL) {
        return NULL;
    }
    char *temp_toHere = toHere;
    while ( *fromHere != '\0' ) {
        *toHere = *fromHere;
        toHere++;
        fromHere++;
    }
    *toHere = '\0';
    return temp_toHere;
}

char *C_strcat(char *toHere, const char *fromHere) {
    if (toHere == NULL) {
        return NULL;
    }
    char *temp_toHere = toHere;
    while ( *toHere != '\0' ) {
        toHere++;
    }
    while ( *fromHere != '\0' ) {
        *toHere = *fromHere;
        toHere++;
        fromHere++;
    }
    *toHere = '\0';
    return temp_toHere;
}

char *C_strchr(const char *str, int ch) {
    int i = 0;
    while (str[i] && str[i] != ch) {
        i++;
    }
    if (ch == str[i]) {
        return ((char*)str + i);
    } else {
        return NULL;
    }
}

int C_strstr_match(const char *searchHere, const char *findThis) {
    while (*searchHere && *findThis) {
        if (*searchHere != *findThis) {
            return 0;
        }
        searchHere++;
        findThis++;
    }
    return (*findThis == '\0');
}

char *C_strstr(const char *searchHere, const char *findThis) {
    while ( *searchHere != '\0' ) {
        if ( (*searchHere == *findThis) && (C_strstr_match(searchHere, findThis)) ) {
            return (char*)searchHere;
        }
        searchHere++;
    }
    return NULL;
}
