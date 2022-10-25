#include <stdio.h>
#include <stdlib.h>

int input_type(int *type);
int input_size(int *m, int *n);
int static_arr(int m, int n);
int dynamic_arr_1(int m, int n);
int dynamic_arr_2(int m, int n);
int dynamic_arr_3(int m, int n);
int input(int** a, int m, int n);
void output(int** a, int m, int n);
void output_one(int* a, int m);
int input_stat(int a[][100], int m, int n);
void output_stat(int a[][100], int m, int n);

int max_row_array(int** a, int m, int n, int* b);
int min_column_array(int** a, int m, int n, int* b);
int max_row_array_stat(int a[][100], int m, int n, int* b);
int min_column_array_stat(int a[][100], int m, int n, int* b);

int main() {
    int type;
    int m, n;
    int flag_return = 1;
    if ( input_type(&type) == 1 ) {
        if ( input_size(&m, &n) == 1 ) {
            switch (type) {
                case 1 :
                    if (m <= 100 || n <= 100) {
                        static_arr(m, n);
                    } else {
                        flag_return = 0;
                    }
                    break;
                case 2 :
                    dynamic_arr_1(m, n);
                    break;
                case 3 :
                    dynamic_arr_3(m, n);
                    break;
                case 4 :
                    dynamic_arr_3(m, n);
                    break;
            }
        } else {
            flag_return = 0;
        }
    } else {
        flag_return = 0;
    }
    if ( 0 == flag_return ) {
        printf("n/a");
    }
    return 0;
}

int static_arr(int m, int n) {
    int a[100][100];
    int max_row[100];
    int min_column[100];
    int flag_return = 1;
    if ( 1 == input_stat(a, m, n) ) {
        output_stat(a, m, n);
        printf("\n");
        max_row_array_stat(a, m, n, max_row);
        output_one(max_row, m);
        printf("\n");
        min_column_array_stat(a, m, n, min_column);
        output_one(min_column, n);
    } else {
        printf("n/a");
    }
    return flag_return;
}

int max_row_array_stat(int a[][100], int m, int n, int* b) {
    int flag_return = 1;
    for (int i=0; i < m; i++) {
        b[i] = a[i][0];
        for (int j=0; j < n; j++) {
            if ( a[i][j] > b[i] ) b[i] = a[i][j];
        }
    }
    return flag_return;
}

int min_column_array_stat(int a[][100], int m, int n, int* b) {
    int flag_return = 1;
    for ( int i=0; i < n; i++ ) {
        b[i] = a[0][i];
        for ( int j=0; j < m; j++ ) {
            if ( a[j][i] < b[i] ) b[i] = a[j][i];
        }
    }
    return flag_return;
}

int input_stat(int a[][100], int m, int n) {
    char char_temp;
    int flag_return = 1;
    for ( int i=0; i < m; i++ ) {
        for ( int j=0; j < n; j++ ) {
            scanf("%d%c", &a[i][j], &char_temp);
            if ( char_temp != '\n' && char_temp != ' ' ) {
                flag_return = 0;
            } else if ( char_temp == ' ' && (j == n-1) ) {
                flag_return = 0;
            }
        }
    }
    return flag_return;
}

void output_stat(int a[][100], int m, int n) {
    for ( int i=0; i < m; i++ ) {
        for ( int j=0; j < n; j++ ) {
            printf("%d", a[i][j]);
            if ( j < n - 1 ) {
                printf(" ");
            }
        }
        if ( i < m - 1 ) {
            printf("\n");
        }
    }
}

int dynamic_arr_1(int m, int n) {
    int** array = malloc(m * sizeof(int*));
    int* max_row = (int*)malloc(m * sizeof(int));
    int* min_column = (int*)malloc(n * sizeof(int));
    for ( int i=0; i < m; i++ ) {
        array[i] = malloc(n * sizeof(int));
    }
    if ( 1 == input(array, m, n) ) {
        output(array, m, n);
        printf("\n");
        max_row_array(array, m, n, max_row);
        output_one(max_row, m);
        printf("\n");
        min_column_array(array, m, n, min_column);
        output_one(min_column, n);
    } else {
        printf("n/a");
    }
    for ( int i=0; i < m; i++ ) {
        free(array[i]);
    }
    free(max_row);
    free(min_column);
    free(array);
    return 0;
}

int dynamic_arr_2(int m, int n) {
    int** array = malloc(m * sizeof(int*));
    int* values_array = malloc(m * n * sizeof(int));
    int* max_row = (int*)malloc(m * sizeof(int));
    int* min_column = (int*)malloc(n * sizeof(int));
    for ( int i=0; i < m; i++ ) {
        array[i] = values_array + n * i;
    }
    if ( 1 == input(array, m, n) ) {
        output(array, m, n);
        printf("\n");
        max_row_array(array, m, n, max_row);
        output_one(max_row, m);
        printf("\n");
        min_column_array(array, m, n, min_column);
        output_one(min_column, n);
    } else {
        printf("n/a");
    }
    free(max_row);
    free(min_column);
    free(values_array);
    free(array);
    return 0;
}

int dynamic_arr_3(int m, int n) {
    int** array = malloc(m * n * sizeof(int) + m * sizeof(int*));
    int* ptr = (int*) (array + m);
    int* max_row = (int*)malloc(m * sizeof(int));
    int* min_column = (int*)malloc(n * sizeof(int));
    for ( int i=0; i < m; i++ ) {
        array[i] = ptr + n * i;
    }
    if ( 1 == input(array, m, n) ) {
        output(array, m, n);
        printf("\n");
        max_row_array(array, m, n, max_row);
        output_one(max_row, m);
        printf("\n");
        min_column_array(array, m, n, min_column);
        output_one(min_column, n);
    } else {
        printf("n/a");
    }
    free(max_row);
    free(min_column);
    free(array);
    return 0;
}

int input(int **a, int m, int n) {
    char char_temp;
    int flag_return = 1;
    for ( int i=0; i < m; i++ ) {
        for ( int j=0; j < n; j++ ) {
            scanf("%d%c", &a[i][j], &char_temp);
            if ( char_temp != '\n' && char_temp != ' ' ) {
                flag_return = 0;
            } else if ( char_temp == ' ' && (j == n-1) ) {
                flag_return = 0;
            }
        }
    }
    return flag_return;
}

void output(int **a, int m, int n) {
    for ( int i=0; i < m; i++ ) {
        for ( int j=0; j < n; j++ ) {
            printf("%d", a[i][j]);
            if ( j < n - 1 ) {
                printf(" ");
            }
        }
        if ( i < m - 1 ) {
            printf("\n");
        }
    }
}

void output_one(int *a, int m) {
    for ( int i=0; i < m; i++ ) {
        printf("%d", a[i]);
        if ( i < m - 1 ) {
            printf(" ");
        }
    }
}

int max_row_array(int** a, int m, int n, int* b) {
    int flag_return = 1;
    for ( int i=0; i < m; i++ ) {
        b[i] = a[i][0];
        for ( int j=0; j < n; j++ ) {
            if ( a[i][j] > b[i] ) b[i] = a[i][j];
        }
    }
    return flag_return;
}

int min_column_array(int** a, int m, int n, int* b) {
    int flag_return = 1;
    for ( int i=0; i < n; i++ ) {
        b[i] = a[0][i];
        for ( int j=0; j < m; j++ ) {
            if ( a[j][i] < b[i] ) b[i] = a[j][i];
        }
    }
    return flag_return;
}

int input_type(int *type) {
    char char_temp;
    int flag_return = 1;
    scanf("%d%c", type, &char_temp);
    if ( char_temp != '\n' || *type == 0 || *type > 4 ) {
        flag_return = 0;
    } else {
        flag_return = 1;
    }
    return flag_return;
}

int input_size(int *n, int *m) {
    char char_temp;
    int flag_return = 1;
    scanf("%d%d%c", n, m, &char_temp);
    if ( char_temp != '\n' || *n == 0 || *m == 0 ) {
        flag_return = 0;
    } else {
        flag_return = 1;
    }
    return flag_return;
}
