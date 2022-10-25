#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *array =malloc(sizeof(char));

    char ch;
    int len = 0, flag = 0;
    while ((ch = getchar()) != '\n') {
        if (ch >= 65 && ch < 91) {
            ch += 32;
        }
        array[len] = ch;
        len++;
        array = realloc(array, len*sizeof(char));
        
    }
    //len = i;
    for (int i = 0; i < len / 2 && flag != 1; i++) {
        if (array[i] != array[len - 1 - i]) {
            flag = 1;
        }
            
    }
       
    if (flag > 0) {
        printf("NO");
    } else {
        printf("YES");
    }
    printf("%d,%d,%d", ('A'+32), 'a', ' ');
    free(array);
    return 0;
}
