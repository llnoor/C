#include <stdio.h>
#define NMAX 10000

int input(int *a, int *n);
void output(int *a, int n);
int squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if ( input(data, &n) == 1 ) {
        if (squaring(data, n) == 1) {
            output(data, n);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    char char_temp;
    scanf("%d%c", n, &char_temp);
    if ( char_temp != '\n' || *n == 0 || *n > NMAX ) {
        return 0;
    } else {
        for ( int *p = a; p - a < *n; p++ ) {
            scanf("%d%c", p, &char_temp);
            if ( char_temp != '\n' && char_temp != ' ' ) {
                return 0;
            } else if ( char_temp == ' ' && (p - a == *n-1) ) {
                return 0;
            }
        }
        return 1;
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

int squaring(int *a, int n) {
    for ( int *p = a; p - a < n; p++ ) {
        *p = *p * *p;
        if (*p < 0) {
            return 0;
        }
    }
    return 1;;
}
