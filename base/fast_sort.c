#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void sort(int *a, int n);
void heapsort(int *a, int n);
void swap(int *a, int v, int w);
void bunch(int *a, int n, int m);
void copy_arr(int *a, int *b, int n);

int main() {
    int n = NMAX;
    int data[NMAX];
    int data2[NMAX];
    if ( input(data, &n) == 1 ) {
        copy_arr(data, data2, n);
        sort(data, n);
        output(data, n);
        heapsort(data2, n);
        output(data2, n);
    } else {
        printf("n/a");
    }
    return 0;
}

void copy_arr(int *a, int *b, int n) {
    for (int i=0; i < n; i++) {
        b[i] = a[i];
    }
}

int input(int *a, int *n) {
    char char_temp;
    int flag_return = 1;
    for ( int *p = a; p - a < *n; p++ ) {
        scanf("%d%c", p, &char_temp);
        if ( char_temp != '\n' && char_temp != ' ' ) {
            flag_return =  0;
        } else if ( char_temp == ' ' && (p - a == *n-1) ) {
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
    printf("\n");
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

void heapsort(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        bunch(a, n, i);
    }
    for (int i=n-1; i >= 0; i--) {
    swap(a, 0, i);
    bunch(a, i, 0);
    }
}

void swap(int *p, int v, int w) {
    int temp;
    temp = p[v];
    p[v] = p[w];
    p[w] = temp;
}

void bunch(int *a, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(a, i, largest);
        bunch(a, n, largest);
    }
}

