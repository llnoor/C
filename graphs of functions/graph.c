#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "C_dynamic.h"
#include "C_notation.h"
#include "C_graph.h"

char * no_space_in(char * S, char * res) {
    int i, j;
    for (i = j = 0; S[i] != '\0'; i++)
        if (S[i] != ' ') {
            res[j++] = S[i];
        }
    res[j] = '\0';
    return (res);
}

int SymCount(char* S, char c) {
    int size = strlen(S);
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (S[i] == c) {
            counter++;
        }
    }
    return counter;
}

int valid(char* S) {
    char * d1 = S;
    int flag = 1;
    if (SymCount(d1, '(') != SymCount(d1, ')')) {
    flag = 0;
    }
    return flag;
}
int main() {
    char expression[100];
    char *d;
    scanf("%s", expression);
    d = expression;
    char res[100];
    d = no_space_in(d, res);
    if (valid(d)) {
    check_sin_cos_tan_ctg(d, "sin");
    check_sin_cos_tan_ctg(d, "cos");
    check_sin_cos_tan_ctg(d, "tan");
    check_sin_cos_tan_ctg(d, "ctg");
    check_ln(d);
    check_sqrt(d);
    C_graph(d);
    } else {
        printf("Incorrect string");
    }
    return 0;
}
