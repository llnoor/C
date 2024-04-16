#ifndef SRC_COMMON_COMMON_H_
#define SRC_COMMON_COMMON_H_

#include <stdio.h>
#include <stdlib.h>

FILE* open_file(const char* filename);
int* get_line_count(int* length_arr, int* max_length_arr, FILE* file,
                    int* line_count);
char** input_text(char** string_arr, int prev_line_count, FILE* file,
                  const int* line_count, const int* length_arr);
void output_text(char** string_arr, int line_count, const int* length_arr);

#endif  // SRC_COMMON_COMMON_H_
