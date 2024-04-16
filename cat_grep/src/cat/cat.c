#include "cat.h"

#include <stdio.h>
#include <stdlib.h>

#include "../common/common.h"

int main(int argc, char** argv) {
  int no_error = 0;
  if (argc == 1) {
    return 0;
  } else {
    int max_line = 10;
    int line_count = 0;
    char** string_arr = malloc(max_line * sizeof(char*));
    int max_length_arr = 10;
    int* length_arr = malloc(max_length_arr * sizeof(int));
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] != '-') {
        FILE* file = open_file(argv[i]);
        if (file != NULL) {
          int prev_line_count = line_count;
          length_arr =
              get_line_count(length_arr, &max_length_arr, file, &line_count);
          if (length_arr != NULL) {
            char** temp_string_arr =
                (char**)realloc(string_arr, line_count * sizeof(char*));
            if (temp_string_arr) {
              string_arr = temp_string_arr;
              string_arr = input_text(string_arr, prev_line_count, file,
                                      &line_count, length_arr);
            }
          } else {
            perror("cat: Empty file: ");
            no_error = 1;
          }
          fclose(file);
        } else {
          perror("cat: error: ");
        }
      }
    }
    struct flag_struct cat_flag = {0, 0, 0, 0, 0, 0, 0};
    get_flags(argc, argv, &cat_flag);
    cat_text(string_arr, &line_count, length_arr, &cat_flag);
    output_text(string_arr, line_count, length_arr);
    for (int i = 0; i < line_count; i++) {
      free(string_arr[i]);
    }
    free(string_arr);
    string_arr = NULL;
    free(length_arr);
    length_arr = NULL;
  }
  return no_error;
}

int get_flags(int argc, char** argv, struct flag_struct* cat_flag) {
  int rez = 0;
  int optindex = 0;
  const char* short_options = "benstvET";
  const struct option long_options[] = {{"number-nonblank", 0, NULL, 'b'},
                                        {"number", 0, NULL, 'n'},
                                        {"squeeze-blank", 0, NULL, 's'},
                                        {NULL, 0, NULL, 0}};
  cat_flag->corr_flag = 1;
  while ((rez = getopt_long(argc, argv, short_options, long_options,
                            &optindex)) != -1) {
    switch (rez) {
      case 'v':
        cat_flag->v_flag = 1;
        break;
      case 'b':
        cat_flag->b_flag = 1;
        cat_flag->n_flag = 0;
        break;
      case 'e':
        cat_flag->e_flag = 1;
        cat_flag->v_flag = 1;
        break;
      case 'E':
        cat_flag->e_flag = 1;
        break;
      case 'n':
        if (cat_flag->b_flag == 0) cat_flag->n_flag = 1;
        break;
      case 's':
        cat_flag->s_flag = 1;
        break;
      case 't':
        cat_flag->t_flag = 1;
        cat_flag->v_flag = 1;
        break;
      case 'T':
        cat_flag->t_flag = 1;
        break;
    }
  }
  return 0;
}

int cat_text(char** string_arr, int* line_count, int* length_arr,
             struct flag_struct* cat_flag) {
  if (cat_flag->corr_flag == 1) corr_text(string_arr, line_count, length_arr);
  if (cat_flag->s_flag == 1) s_text(string_arr, line_count, length_arr);
  if (cat_flag->t_flag == 1) t_text(string_arr, *line_count, length_arr);
  if (cat_flag->b_flag == 1) b_text(string_arr, *line_count, length_arr);
  if (cat_flag->n_flag == 1) n_text(string_arr, *line_count, length_arr);
  if (cat_flag->e_flag == 1) e_text(string_arr, *line_count, length_arr);
  if (cat_flag->v_flag == 1) v_text(string_arr, *line_count, length_arr);
  return 0;
}

void corr_text(char** string_arr, int* line_count, int* length_arr) {
  for (int it = 0; it < *line_count - 1; it++) {
    if (string_arr[it][length_arr[it] - 1] != '\n') {
      int temp = length_arr[it] + length_arr[it + 1];
      char* int_str = malloc(temp * sizeof(char));
      for (int i = 0; i < length_arr[it]; i++) {
        int_str[i] = string_arr[it][i];
      }
      for (int i = length_arr[it]; i < temp; i++) {
        int_str[i] = string_arr[it + 1][i - length_arr[it]];
      }
      string_arr[it] = realloc(string_arr[it], temp * sizeof *string_arr[it]);
      length_arr[it] = temp;
      for (int i = 0; i < length_arr[it]; i++) {
        string_arr[it][i] = int_str[i];
      }
      free(int_str);
      for (int k = it + 1; k < *line_count - 1; k++) {
        free(string_arr[k]);
        string_arr[k] = string_arr[k + 1];
        string_arr[k + 1] = NULL;
        length_arr[k] = length_arr[k + 1];
      }
      *line_count = *line_count - 1;
    }
  }
}

void n_text(char** string_arr, int line_count, int* length_arr) {
  for (int it = 0; it < line_count; it++) {
    if ((it == line_count - 1) && (length_arr[it] == 0)) {
      break;
    }
    int add_i = 7;
    char temp[12];  // it is int => argument in the range [1, 2147483647] = > 12
                    // bytes
    sprintf(temp, "%6d\t", it + 1);
    length_arr[it] = length_arr[it] + add_i;
    char* int_str = malloc(length_arr[it] * sizeof(char));
    for (int i = 0; i < add_i; i++) {
      int_str[i] = temp[i];
    }
    for (int i = add_i; i < length_arr[it]; i++) {
      int_str[i] = string_arr[it][i - add_i];
    }
    string_arr[it] =
        realloc(string_arr[it], length_arr[it] * sizeof *string_arr[it]);
    for (int i = 0; i < length_arr[it]; i++) {
      string_arr[it][i] = int_str[i];
    }
    free(int_str);
  }
}

void b_text(char** string_arr, int line_count, int* length_arr) {
  int count = 1;
  for (int it = 0; it < line_count; it++) {
    if (length_arr[it] > 1) {
      int add_i = 7;
      char temp[12];  // it is int => argument in the range [1, 2147483647] = >
                      // 12 bytes
      sprintf(temp, "%6d\t", count++);
      length_arr[it] = length_arr[it] + add_i;
      char* int_str = malloc(length_arr[it] * sizeof(char));
      for (int i = 0; i < add_i; i++) {
        int_str[i] = temp[i];
      }
      for (int i = add_i; i < length_arr[it]; i++) {
        int_str[i] = string_arr[it][i - add_i];
      }
      string_arr[it] =
          realloc(string_arr[it], length_arr[it] * sizeof *string_arr[it]);
      for (int i = 0; i < length_arr[it]; i++) {
        string_arr[it][i] = int_str[i];
      }
      free(int_str);
    }
  }
}

void e_text(char** string_arr, int line_count, int* length_arr) {
  for (int it = 0; it < line_count; it++) {
    int number_of_t = 0;
    for (int i = 0; i < length_arr[it]; i++) {
      if (string_arr[it][i] == '\n' /*|| string_arr[it][i]=='\f'*/) {
        number_of_t++;
      }
    }
    if (number_of_t > 0) {
      char* int_str = malloc((length_arr[it] + number_of_t) * sizeof(char));
      int add_i = 0;
      for (int i = 0; i < length_arr[it]; i++) {
        if (string_arr[it][i] == '\n') {
          int_str[i + add_i] = 36;
          int_str[i + (++add_i)] = '\n';
        } else {
          int_str[i + add_i] = string_arr[it][i];
        }
      }
      length_arr[it] = length_arr[it] + number_of_t;
      string_arr[it] =
          realloc(string_arr[it], length_arr[it] * sizeof *string_arr[it]);
      for (int i = 0; i < length_arr[it]; i++) {
        string_arr[it][i] = int_str[i];
      }
      free(int_str);
    }
  }
}

void s_text(char** string_arr, int* line_count, int* length_arr) {
  for (int it = 1; it < *line_count; it++) {
    if (length_arr[it] == 1 && length_arr[it - 1] == 1) {
      for (int k = it; k < *line_count - 1; k++) {
        free(string_arr[k]);
        string_arr[k] = string_arr[k + 1];
        string_arr[k + 1] = NULL;

        length_arr[k] = length_arr[k + 1];
      }
      *line_count = *line_count - 1;
      it--;
    }
  }
}

void t_text(char** string_arr, int line_count, int* length_arr) {
  for (int it = 0; it < line_count; it++) {
    int number_of_t = 0;
    for (int i = 0; i < length_arr[it]; i++) {
      if (string_arr[it][i] == '\t' /*|| string_arr[it][i]=='\f'*/) {
        number_of_t++;
      }
    }
    if (number_of_t > 0) {
      char* int_str = malloc((length_arr[it] + number_of_t) * sizeof(char));
      int add_i = 0;
      for (int i = 0; i < length_arr[it]; i++) {
        if (string_arr[it][i] == '\t') {
          int_str[i + add_i] = '^';
          int_str[i + (++add_i)] = 'I';
        } else {
          int_str[i + add_i] = string_arr[it][i];
        }
      }
      length_arr[it] = length_arr[it] + number_of_t;
      string_arr[it] =
          realloc(string_arr[it], length_arr[it] * sizeof *string_arr[it]);
      for (int i = 0; i < length_arr[it]; i++) {
        string_arr[it][i] = int_str[i];
      }
      free(int_str);
    }
  }
}

void v_text(char** string_arr, int line_count, int* length_arr) {
  for (int it = 0; it < line_count; it++) {
    int number_of_t = 0;
    for (int i = 0; i < length_arr[it] - 1; i++) {
      if (string_arr[it][i] < 32 && string_arr[it][i] != 9) {
        number_of_t++;
      } else if (string_arr[it][i] == 127) {
        number_of_t++;
      }
    }
    if (number_of_t > 0) {
      char* int_str = malloc((length_arr[it] + number_of_t) * sizeof(char));
      int add_i = 0;
      for (int i = 0; i < length_arr[it] - 1; i++) {
        if (string_arr[it][i] < 32 && string_arr[it][i] != 9) {
          int_str[i + add_i] = '^';
          int_str[i + (++add_i)] = (int)(string_arr[it][i] + 64);
        } else if (string_arr[it][i] == 127) {
          int_str[i + add_i] = '^';
          int_str[i + (++add_i)] = '?';
        } else {
          int_str[i + add_i] = string_arr[it][i];
        }
      }
      int i = length_arr[it] - 1;
      int_str[i + add_i] = string_arr[it][i];
      length_arr[it] = length_arr[it] + number_of_t;
      string_arr[it] =
          realloc(string_arr[it], length_arr[it] * sizeof *string_arr[it]);
      for (int ik = 0; ik < length_arr[it]; ik++) {
        string_arr[it][ik] = int_str[ik];
      }
      free(int_str);
    }
  }
}
