#include <stdio.h>
#include <math.h>

int fibonacci(int);
int abs(int);

char char_temp;
int number1;

int main() {
    scanf("%d%c", &number1, &char_temp);
    if (char_temp == '\n') {
        printf("%d\n", fibonacci(number1));
    } else {
        printf("n/a");
    }
    return 0;
}

int fibonacci(int number) {
    int abs_number = abs(number);
    if (0 == abs_number) {
        return 0;
    }
    if (1 == abs_number) {
        return 1;
    }
    if (number > 0) {
        return (fibonacci(abs_number-1)+fibonacci(abs_number-2));
    } else {
        return (pow(-1, (abs_number+1))*fibonacci(abs_number));
    }
}

int abs(int a) {
    if (a > 0) {
        return a;
    } else {
        return (-1*a);
    }
}
