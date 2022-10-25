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

int sum_row_array(int** a, int m, int n, int* b);
int array_order(int m, int* b, int* order);
void output_order(int** a, int m, int n, int* order);

int main() {
    int type;
    int m, n;
    int flag_return = 1;
    if ( input_type(&type) == 1 ) {
        if ( input_size(&m, &n) == 1 ) {
            switch (type) {
                case 1 :
                    dynamic_arr_1(m, n);
                    break;
                case 2 :
                    dynamic_arr_3(m, n);
                    break;
                case 3 :
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

int sum_row_array(int** a, int m, int n, int* b) {
    int flag_return = 1;
    for (int i=0; i < m; i++) {
        b[i] = 0;
        for (int j=0; j < n; j++) {
            b[i] = b[i] + a[i][j];
        }
    }
    return flag_return;
}

int array_order(int m, int* b, int* order) {
    int flag_return = 1;
    int temp;
    for ( int i=0; i < m; i++ ) {
        order[i] = i;
    }
    for ( int l=0; l < m; l++ ) {
        for ( int i=1; i < m; i++ ) {
            if ( b[i] < b[i-1] ) {
                temp = b[i];
                b[i]  = b[i-1];
                b[i-1]  = temp;
                temp = order[i];
                order[i]  = order[i-1];
                order[i-1]  = temp;
                temp = temp;
            }
        }
    }
    return flag_return;
}

void output_order(int** a, int m, int n, int* order) {
    for ( int i=0; i < m; i++ ) {
        for ( int j=0; j < n; j++ ) {
            printf("%d", a[order[i]][j]);
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
    int* sum_row = (int*)malloc(m * sizeof(int));
    int* order = (int*)malloc(m * sizeof(int));
    for ( int i=0; i < m; i++ ) {
        array[i] = malloc(n * sizeof(int));
    }
    if ( 1 == input(array, m, n) ) {
        sum_row_array(array, m, n, sum_row);
        array_order(m, sum_row, order);
        output_order(array, m, n, order);
    } else {
        printf("n/a");
    }
    free(sum_row);
    free(order);
    for ( int i=0; i < m; i++ ) {
        free(array[i]);
    }
    free(array);
    return 0;
}

int dynamic_arr_2(int m, int n) {
    int** array = malloc(m * sizeof(int*));
    int* values_array = malloc(m * n * sizeof(int));
    int* sum_row = (int*)malloc(m * sizeof(int));
    int* order = (int*)malloc(m * sizeof(int));
    for ( int i=0; i < m; i++ ) {
        array[i] = values_array + n * i;
    }
    if ( 1 == input(array, m, n) ) {
        sum_row_array(array, m, n, sum_row);
        array_order(m, sum_row, order);
        output_order(array, m, n, order);
    } else {
        printf("n/a");
    }
    free(sum_row);
    free(order);
    free(values_array);
    free(array);
    return 0;
}

int dynamic_arr_3(int m, int n) {
    int** array = malloc(m * n * sizeof(int) + m * sizeof(int*));
    int* ptr = (int*) (array + m);
    int* sum_row = (int*)malloc(m * sizeof(int));
    int* order = (int*)malloc(m * sizeof(int));
    for ( int i=0; i < m; i++ ) {
        array[i] = ptr + n * i;
    }
    if ( 1 == input(array, m, n) ) {
        sum_row_array(array, m, n, sum_row);
        array_order(m, sum_row, order);
        output_order(array, m, n, order);
    } else {
        printf("n/a");
    }
    free(sum_row);
    free(order);
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
