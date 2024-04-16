#include <stdlib.h>
#include <stdio.h>
#include "string.h"

#ifdef STRLEN
#define C_test C_strlen_test()
#endif

#ifdef STRCMP
#define C_test C_strcmp_test()
#endif

#ifdef STRCPY
#define C_test C_strcpy_test()
#endif

#ifdef STRCAT
#define C_test C_strcat_test()
#endif

#ifdef STRCHR
#define C_test C_strchr_test()
#endif

#ifdef STRSTR
#define C_test C_strstr_test()
#endif

void C_strlen_test();
void C_strcmp_test();
void C_strcpy_test();
void C_strcat_test();
void C_strchr_test();
void C_strstr_test();

int main() {
    C_test;
    return 0;
}

void C_strlen_test() {
    char *test[5]= {"Hello, c!", "Hello, User!", "\n", "Hello,\tc!", " "};
    int result[5] = {11, 12, 1, 11, 1};
    int output;
    for (int i=0; i < 5; i++) {
        output = (int) C_strlen(test[i]);
        printf("Test %d. Input: \"%s\". Output: \"%d\". Result: ", i, test[i], output);
        if ( output ==  result[i] ) {
            printf("SUCCESS\n");
        } else {
            printf("FAIL\n");
        }
    }
}

void C_strcmp_test() {
    char *test1[5]= {"Hello, c!", "Are you coder?", "\n", "processor", " "};
    char *test2[5]= {"Hello, S22!", "Are you programmer?", "\t", "processor\t", ""};
    int result[5] = {-1, -13, 1, -9, 32};
    int output;
    for (int i=0; i < 5; i++) {
        output = C_strcmp(test1[i], test2[i]);
        printf("Test %d. Input: \"%s - %s\". Output: \"%d\". Result: ", i, test1[i], test2[i], output);
        if ( output ==  result[i] ) {
            printf("SUCCESS\n");
        } else {
            printf("FAIL\n");
        }
    }
}

void C_strcpy_test() {
    const char *fromHere[5]= {"Hello, c!", "Are you coder?", "\n", "processor", " "};
    char *result[5] = {"Hello, c!", "Are you coder?", "\n", "processor", " "};
    char buf[64];
    for (int i=0; i < 5; i++) {
        C_strcpy(buf, fromHere[i]);
        printf("Test %d. Input: \"%s\". Output: \"%s\". Result: ", i, fromHere[i], buf);
        if ( C_strcmp(buf, result[i]) == 0 ) {
            printf("SUCCESS\n");
        } else {
            printf("FAIL\n");
        }
    }
}

void C_strcat_test() {
    const char *fromHere[5]= {"Hello, c!", "Are you coder?", "\n", "processor", " "};
    char *result[5] = {"First PartHello, c!", "First PartAre you coder?",
     "First Part\n", "First Partprocessor", "First Part "};
    for (int i=0; i < 5; i++) {
        char buf[64] = "First Part";
        C_strcat(buf, fromHere[i]);
        printf("Test %d. Input: \"%s\". Output: \"%s\". Result: ", i, fromHere[i], buf);
        if ( C_strcmp(buf, result[i]) == 0 ) {
            printf("SUCCESS\n");
        } else {
            printf("FAIL\n");
        }
    }
}

void C_strchr_test() {
    const char *fromHere[5]= {"Hello, c!", "Are you coder?", "\n", "processor", " "};
    char ch1 = 'S';
    char ch2 = 'y';
    char ch3 =  '\n';
    char ch4 =  'c';
    char ch5 =  ' ';
    char ch_result1 = 'S';
    char ch_result2 = 'y';
    char ch_result3 =  '\n';
    char ch_result4 =  'c';
    char ch_result5 =  ' ';
    for (int i=0; i < 5; i++) {
        char temp_ch;
        char ch_result;
        switch (i) {
            case 0: temp_ch = ch1; ch_result = ch_result1; break;
            case 1: temp_ch = ch2; ch_result = ch_result2; break;
            case 2: temp_ch = ch3; ch_result = ch_result3; break;
            case 3: temp_ch = ch4; ch_result = ch_result4; break;
            case 4: temp_ch = ch5; ch_result = ch_result5; break;
        }
        char *temp = C_strchr(fromHere[i], temp_ch);
        printf("Test %d. Input: \"%s - %c\". ", i, fromHere[i], temp_ch);
        printf("Output: \"%ld\". Result: ", temp - fromHere[i] +1);
        if ( temp[0] == ch_result ) {
            printf("SUCCESS\n");
        } else {
            printf("FAIL\n");
        }
    }
}

void C_strstr_test() {
    char *searchHere[5]= {"Hello, c!", "Are you coder?", "programmer", "processor", "  "};
    char *findThis[5]= {"c", "you", "r", "ss", " "};
    int result[5] = {8, 5, 2, 6, 1};
    for (int i=0; i < 5; i++) {
        char *temp = C_strstr(searchHere[i], findThis[i]);
        printf("Test %d. Input: \"%s - %s\". ", i, searchHere[i], findThis[i]);
        printf("Output: \"%ld\". Result: ", temp - searchHere[i] +1);
        if ( (temp - searchHere[i] +1) == result[i] ) {
            printf("SUCCESS\n");
        } else {
            printf("FAIL\n");
        }
    }
}
