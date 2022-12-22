#include "s21_common.h"

FILE* open_file(const char* filename) {
    FILE* file = NULL;
    file = fopen(filename, "rt");
    return file;
}


int* get_line_count(int* length_arr, int* max_length_arr, FILE* file, int* line_count) {
    length_arr[*line_count] = 0;
    int length_line=0;
    char temp_char;
    while (1) {
        temp_char = getc(file);
        if (temp_char=='\n') {
            length_line++;
            length_arr[*line_count]=length_line;
            *line_count=*line_count+1;
            if (*line_count >= *max_length_arr) {
                *max_length_arr = *max_length_arr * 2;
                length_arr = (int*)realloc(length_arr, (*max_length_arr)*sizeof(int));
            } 
            length_line = 0;
        } else {
            length_line++;
        }
        if (temp_char== EOF) {
            length_arr[*line_count]=length_line-1;
             *line_count=*line_count+1;
            if (*line_count >= *max_length_arr) {
                *max_length_arr = *max_length_arr * 2;
                length_arr = (int*)realloc(length_arr, (*max_length_arr)*sizeof(int));
            }
            length_line = 0;
            break;
        }
    }
    rewind(file);
    return length_arr;
}

char** input_text(char** string_arr, int prev_line_count, FILE* txt, int* line_count, int* length_arr) {
    //char** string_arr = NULL;
    //string_arr = malloc(*line_count * sizeof(char *));
    if (string_arr == NULL) {
        return NULL;
    }
    for (int m = prev_line_count /*0*/; m < *line_count; m++) { 
        if (length_arr[m] != 0 ){
            string_arr[m] = malloc(length_arr[m]*sizeof(char));
        } else {
            string_arr[m] = malloc(sizeof(char));
        }
        
        for (int n = 0; n < length_arr[m]; n++){
            string_arr[m][n]=getc(txt);
        }
    }
    return string_arr;
}

void output_text(char **string_arr, int line_count, int* length_arr) {
    for (int m = 0; m < line_count; m++) { 
        for (int n = 0; n < length_arr[m]; n++){
            printf("%c", string_arr[m][n]);
        }
    }
}
