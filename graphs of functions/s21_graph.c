#include "s21_graph.h"
#include "s21_notation.h"
#include <stdio.h>
#include <math.h>

void s21_graph(char *output) {
    output = output;
    float i_def =  4 * M_PI / 79;
    float j_def =  2./ 24;
    float function;
    for (float j = -1; j <= 1 ; j = j + j_def) {
        for (float i = 0; i <= 4 * M_PI ; i = i + i_def) {
            function = start_notation(output, i);
            if ( (j-j_def) <= function && function <= (j+j_def) ) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

