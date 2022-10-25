#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int input_string(char *string);
void output(char *output);

int main() {
    char *string = malloc(1*sizeof(char));
    string[0] = '\0';
    input_string(string);
    output(string);
    free(string);
    return 0;
}

int input_string(char *string) {
    char char_temp;
    int length = 0;
    int flag_no_err = 1;
    if (string == NULL) {
        printf("n/a\n");
        flag_no_err = 0;
    } else {
        while (1) {
            scanf("%c", &char_temp);
            if (char_temp == '\n') {
                break;
            } else {
                string[length] = char_temp;
                length++;
                string = (char*)realloc(string, (length) * sizeof(char));
            }
        }
    }
    return flag_no_err;
}

void output(char *output) {
    char *istr;
    char *sep = " ";
    istr = strtok(output, sep);
    if ( istr != NULL ) {
        printf("%s", istr);
        istr = strtok(NULL, sep);
    }
    
    while ( istr != NULL ) {
        printf(" %s", istr);
        istr = strtok(NULL, sep);
    }
}

