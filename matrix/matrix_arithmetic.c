#include <stdio.h>
#include <stdlib.h>

int input_type(int *type);
int input_size(int *m, int *n);
int input(int** a, int m, int n);
void output(int** a, int m, int n);
int sum(int **matrix_first, int m_first, int n_first,
        int **matrix_second, int m_second, int n_second,
        int **matrix_result, int *m_result, int *n_result);
int transpose(int **matrix_first, int m_first, int n_first,
              int **matrix_result, int *m_result, int *n_result);
int mul(int **matrix_first, int m_first, int n_first, int **matrix_second,
        int m_second, int n_second, int **matrix_result, int *m_result, int *n_result);
void sum_arr();
void mul_arr();
void transpose_arr();

int main() {
    int type;
    if ( input_type(&type) == 1 && (1 <= type && type <= 3) ) {
        switch (type) {
            case 1 :
                sum_arr();
                break;
            case 2 :
                mul_arr();
                break;
            case 3 :
                transpose_arr();
                break;
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int transpose(int **matrix_first, int m_first, int n_first,
              int **matrix_result, int *m_result, int *n_result) {
    int** temp = malloc(n_first * sizeof(int*));
    for ( int i=0; i < n_first; i++ ) {
        temp[i] = malloc(m_first * sizeof(int));
    }
    for ( int i=0; i < m_first; i++ ) {
        for ( int j=0; j < n_first; j++ ) {
            temp[j][i] = matrix_first[i][j];
        }
    }
    *m_result = n_first;
    *n_result = m_first;
    for ( int i=0; i < n_first; i++ ) {
        for ( int j=0; j < m_first; j++ ) {
            matrix_result[i][j] = temp[i][j];
        }
    }
    for ( int i=0; i < n_first; i++ ) {
        free(temp[i]);
    }
    free(temp);
    return 1;
}

void transpose_arr() {
    int m_first, n_first;
    int m_result, n_result;
    if ( input_size(&m_first, &n_first) == 1 ) {
        int** matrix_first = malloc(m_first * sizeof(int*));
        for ( int i=0; i < m_first; i++ ) {
            matrix_first[i] = malloc(n_first * sizeof(int));
        }
        if ( 1 == input(matrix_first, m_first, n_first) ) {
            m_result = n_first;
            n_result = m_first;
            int** matrix_result = malloc(m_result * sizeof(int*));
            for ( int i=0; i < m_result; i++ ) {
                matrix_result[i] = malloc(n_result * sizeof(int));
            }
            transpose(matrix_first, m_first, n_first, matrix_result, &m_result, &n_result);
            output(matrix_result, m_result, n_result);
            for ( int i=0; i < m_result; i++ ) {
                free(matrix_result[i]);
            }
            free(matrix_result);
        } else {
            printf("n/a");
        }
        for ( int i=0; i < m_first; i++ ) {
            free(matrix_first[i]);
        }
        free(matrix_first);
    } else {
        printf("n/a");
    }
}

int mul(int **matrix_first, int m_first, int n_first, int **matrix_second,
        int m_second, int n_second, int **matrix_result, int *m_result, int *n_result) {
    *m_result = m_second;  // del
    *m_result = m_first;
    *n_result = n_second;
    for ( int i=0; i < m_first; i++ ) {
        for ( int j=0; j < n_second; j++ ) {
            matrix_result[i][j] = 0;
            for ( int k=0; k < n_first; k++ ) {
                matrix_result[i][j] = matrix_result[i][j] + matrix_first[i][k] * matrix_second[k][j];
            }
        }
    }
    return 1;
}

void mul_arr() {
    int m_first, n_first, m_second, n_second;
    int m_result, n_result;
    if ( input_size(&m_first, &n_first) == 1 ) {
        int** matrix_first = malloc(m_first * sizeof(int*));
        for ( int i=0; i < m_first; i++ ) {
            matrix_first[i] = malloc(n_first * sizeof(int));
        }
        if ( 1 == input(matrix_first, m_first, n_first) ) {
            if ( input_size(&m_second, &n_second) == 1  && (n_first == m_second) ) {
                int** matrix_second = malloc(m_second * sizeof(int*));
                for ( int i=0; i < m_second; i++ ) {
                    matrix_second[i] = malloc(n_second * sizeof(int));
                }
                if ( 1 == input(matrix_second, m_second, n_second) ) {
                    m_result = m_first;
                    n_result = n_second;
                    int** matrix_result = malloc(m_result * sizeof(int*));
                    for ( int i=0; i < m_result; i++ ) {
                        matrix_result[i] = malloc(n_result * sizeof(int));
                    }
                    mul(matrix_first, m_first, n_first, matrix_second,
                        m_second, n_second, matrix_result, &m_result, &n_result);
                    output(matrix_result, m_result, n_result);
                    for ( int i=0; i < m_result; i++ ) {
                        free(matrix_result[i]);
                    }
                    free(matrix_result);
                } else {
                    printf("n/a");
                }
                for ( int i=0; i < m_second; i++ ) {
                    free(matrix_second[i]);
                }
                free(matrix_second);
            } else {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }
        for ( int i=0; i < m_first; i++ ) {
            free(matrix_first[i]);
        }
        free(matrix_first);
    } else {
        printf("n/a");
    }
}

int sum(int **matrix_first, int m_first, int n_first, int **matrix_second,
        int m_second, int n_second, int **matrix_result, int *m_result, int *n_result) {
    *m_result = m_second;  // del
    *n_result = n_second;  // del
    *m_result = m_first;
    *n_result = n_first;
    for ( int i=0; i < m_first; i++ ) {
        for ( int j=0; j < n_first; j++ ) {
            matrix_result[i][j] = matrix_first[i][j] + matrix_second[i][j];
        }
    }
    return 0;
}

void sum_arr() {
    int m_first, n_first, m_second, n_second;
    int m_result, n_result;
    if ( input_size(&m_first, &n_first) == 1 ) {
        int** matrix_first = malloc(m_first * sizeof(int*));
        for ( int i=0; i < m_first; i++ ) {
            matrix_first[i] = malloc(n_first * sizeof(int));
        }
        if ( 1 == input(matrix_first, m_first, n_first) ) {
            if ( input_size(&m_second, &n_second) == 1  && (m_first == m_second && n_first == n_second) ) {
                int** matrix_second = malloc(m_second * sizeof(int*));
                for ( int i=0; i < m_second; i++ ) {
                    matrix_second[i] = malloc(n_second * sizeof(int));
                }
                if ( 1 == input(matrix_second, m_second, n_second) ) {
                    m_result = m_first;
                    n_result = n_first;
                    int** matrix_result = malloc(m_result * sizeof(int*));
                    for ( int i=0; i < m_result; i++ ) {
                        matrix_result[i] = malloc(n_result * sizeof(int));
                    }
                    sum(matrix_first, m_first, n_first, matrix_second,
                        m_second, n_second, matrix_result, &m_result, &n_result);
                    output(matrix_result, m_result, n_result);
                    for ( int i=0; i < m_result; i++ ) {
                        free(matrix_result[i]);
                    }
                    free(matrix_result);
                } else {
                    printf("n/a");
                }
                for ( int i=0; i < m_second; i++ ) {
                    free(matrix_second[i]);
                }
                free(matrix_second);
            } else {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }
        for ( int i=0; i < m_first; i++ ) {
            free(matrix_first[i]);
        }
        free(matrix_first);
    } else {
        printf("n/a");
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
