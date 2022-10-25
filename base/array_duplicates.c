#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input(int *array, int *length);
void delete(int *array, int *length);
void output(int *array, int length);

int main(){
    int *array = malloc(sizeof(int));
    array[0]=0;
    int length = 0;
    input(array, &length);
    delete(array, &length);
    output(array, length);
    free(array);
    return 0;
}

int input(int *array, int *length) {
    int flag_no_err = 1;
    int number = 0;
    while (1) {
        scanf("%d", &number);
        array[*length] = number;
        *length = *length + 1;
        array = realloc(array, *length*sizeof(int));
        if ( number == -1) {
            break;
        }
    }
    return flag_no_err;
}

void delete(int *array, int *length) {
    
    for (int i = 0; i < (*length)-1; i++){
        for (int j = i+1; j < *length; j++){
            if ( array[i] == array[j] ) {
                for ( int k = j; k < (*length)-1; k++){
                    array[k]=array[k+1];
                }
                j--;
                *length = *length - 1;
            }
        }
    }
}

void output(int *array, int length) {
    if (length > 0) {
        printf("%d", array[0]);
        for (int i = 1; i < length; i++){
            printf(" %d", array[i]);
        }
    } else {
        printf("n/a\n");
    }
    
}
