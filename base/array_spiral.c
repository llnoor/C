#include <stdio.h>
#include <stdlib.h>
​
void input(int** a, int n, int m);
void output(int** a, int n, int m);
​
int main() {
    int n, m;
    int** a;
    scanf("%d", &n);
    m = n;
    a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
       a[i] = (int*)malloc(m * sizeof(int));
    }
    
    input(a, n, m);
    output(a,n,m);
    ​
    for (int i = 0; i < n; i++) {
       free(a[i]);
    }
    free(a);
       return 0;
}
​
void input(int** a, int n, int m) {
    int top = 0, bottom = n -1, left = 0, right = m -1, sum = 1;
    while (1) {
        
        for (int j = left; j <= right; j++) {
           a[top][j] = sum++;
        }
        
        if (sum > n * m) break;
        ​
        for (int i = top + 1; i <= bottom; i++) {
        a[i][right] = sum++;
        }
        
        if (sum > n * m) break;
        ​
        for (int j = right - 1; j >= left; j--) {
            a[bottom][j] = sum++;
        }
        ​
        if (sum > n * m) break;
        ​
        for (int i = bottom - 1; i > top; i--) {
            a[i][left] = sum++;
        }
        
        if (sum > n * m) break;
        
        right--;
        top++;
        left++;
        bottom--;
    }
}
​
void output(int** a, int n, int m) {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           if (j == m - 1) {
           printf("%d", a[i][j]);}
           else {
             printf("%d ", a[i][j]);
           }
        }
        if( i != n - 1) {
           printf("\n");
        }
    }
}

