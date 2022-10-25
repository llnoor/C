#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

int input_n(int *n);
int input(int *a, int n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int n = NMAX;
    int *data;
    if ( input_n(&n) == 1 ) {
        data = (int*)malloc(n * sizeof(int));
    } else {
        printf("n/a");
        return 0;
    }
    if ( input(data, n) == 1 ) {
        sort(data, n);
        output(data, n);
        free(data);
    } else {
        printf("n/a");
        free(data);
    }
    return 0;
}

int input_n(int *n) {
    char char_temp;
    int flag_return = 1;
    scanf("%d%c", n, &char_temp);
    if ( char_temp != '\n' || *n == 0 || *n > NMAX ) {
        flag_return = 0;
    } else {
        flag_return = 1;
    }
    if ( 1 == flag_return ) {
        return 1;
    } else {
        return 0;
    }
}

int input(int *a, int n) {
    char char_temp;
    int flag_return = 1;
    for ( int *p = a; p - a < n; p++ ) {
        scanf("%d%c", p, &char_temp);
        if ( char_temp != '\n' && char_temp != ' ' ) {
            flag_return = 0;
        } else if ( char_temp == ' ' && (p - a == n-1) ) {
            flag_return = 0;
        }
    }
    if ( 1 == flag_return ) {
        return 1;
    } else {
        return 0;
    }
}

void output(int *a, int n) {
    for ( int *p = a; p - a < n; p++ ) {
        printf("%d", *p);
        if ( p - a < n - 1 ) {
            printf(" ");
        }
    }
}

void sort(int *a, int n) {
    int temp;
    for ( int i=1; i < n; i++ ) {
        for ( int *p = a + 1; p - a < n; p++ ) {
            if ( *p < *(p-1) ) {
                temp = *p;
                * p = *(p-1);
                *(p-1) = temp;
            }
        }
    }
}
