#include "grep.h"

#include <stdio.h>
#include <stdlib.h>

#include "../common/common.h"

int main(int argc, char **argv) {
  int no_error = 0;
  struct flag_struct grep_flag = {
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
      {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
      {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"}};
  if (argc == 1) {
    return 0;
  } else {
    get_flags(argc, argv, &grep_flag);
    get_file_pattern(&grep_flag);
    get_file_name(argc, argv, &grep_flag);
  }

  for (int i = 0; i < grep_flag.number_file_name; i++) {
    grep_flag.number_current_file_name = i;
    int max_line = 10;
    int line_count = 0;
    char **string_arr = malloc(max_line * sizeof(char *));
    int max_length_arr = 100;
    int *length_arr = malloc(max_length_arr * sizeof(int));

    FILE *file = open_file(grep_flag.arr_file_name[i]);
    if (file != NULL) {
      int prev_line_count = line_count;
      length_arr =
          get_line_count(length_arr, &max_length_arr, file, &line_count);
      if (length_arr != NULL) {
        char **temp_string_arr =
            (char **)realloc(string_arr, line_count * sizeof(char *));
        if (temp_string_arr) {
          string_arr = temp_string_arr;
          string_arr = input_text(string_arr, prev_line_count, file,
                                  &line_count, length_arr);
        }
        // string_arr = realloc(string_arr, line_count * sizeof(char *));
        // string_arr = input_text(string_arr, prev_line_count, file,
        // &line_count, length_arr);
      } else {
        no_error = 1;
      }
      fclose(file);
    } else {
      if (grep_flag.s_flag == 0) {
        char error[300];
        sprintf(error, "grep: %s", grep_flag.arr_file_name[i]);
        perror(error);
      }
    }
    corr_text(string_arr, &line_count, length_arr);
    grep_text(string_arr, line_count, length_arr, grep_flag);
    for (int ik = 0; ik < line_count; ik++) {
      free(string_arr[ik]);
    }
    free(string_arr);
    string_arr = NULL;
    free(length_arr);
    length_arr = NULL;
  }
  return no_error;
}

void get_file_name(int argc, char **argv, struct flag_struct *grep_flag) {
  if (grep_flag->number_template == 0) {
    int first_arg = 0;
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] != '-') {
        if (first_arg == 0) {
          strcpy(grep_flag->arr_template[grep_flag->number_template++],
                 argv[i]);
          first_arg = 1;
        } else {
          if (grep_flag->number_file_name < 10)
            strcpy(grep_flag->arr_file_name[grep_flag->number_file_name++],
                   argv[i]);
        }
      }
    }
  } else {
    for (int i = 1; i < argc; i++) {
      int bool_template = 0;
      for (int l = 0; l < grep_flag->number_template; l++) {
        if (strcmp(grep_flag->arr_template[l], argv[i]) == 0) bool_template = 1;
      }
      for (int l = 0; l < grep_flag->number_file_pattern; l++) {
        if (strcmp(grep_flag->arr_file_pattern[l], argv[i]) == 0)
          bool_template = 1;
      }
      if (bool_template == 0 && argv[i][0] != '-') {
        strcpy(grep_flag->arr_file_name[grep_flag->number_file_name++],
               argv[i]);
      }
    }
  }
  if (grep_flag->number_file_name == 1 && grep_flag->l_flag == 0) {
    grep_flag->h_flag = 1;
  }
}

void get_file_pattern(struct flag_struct *grep_flag) {
  if (grep_flag->number_file_pattern > 0) {
    for (int i = 0; i < grep_flag->number_file_pattern; i++) {
      FILE *file_pattern;
      if ((file_pattern = open_file(grep_flag->arr_file_pattern[i])) != NULL) {
        char line[255];
        int length_line = 0;
        while (1) {
          char temp_char = getc(file_pattern);
          if (temp_char == '\n') {
            line[length_line++] = '\0';
            if (grep_flag->number_template < 10)
              strcpy(grep_flag->arr_template[grep_flag->number_template++],
                     line);
            length_line = 0;
          } else {
            line[length_line++] = temp_char;
          }
          if (temp_char == (char)EOF) {
            if (length_line > 1) {
              line[length_line - 1] = '\0';
              if (grep_flag->number_template < 10)
                strcpy(grep_flag->arr_template[grep_flag->number_template++],
                       line);
              length_line = 0;
            }
            break;
          }
        }
        fclose(file_pattern);
      } else {
        if (grep_flag->s_flag == 0) {
          char error[300];
          sprintf(error, "grep: %s", grep_flag->arr_file_pattern[i]);
          perror(error);
        }
      }
    }
  }
}

void get_flags(int argc, char **argv, struct flag_struct *grep_flag) {
  int rez = 0;
  int optindex = 0;
  const char *short_options = "e:ivclnhsf:o";
  const struct option long_options[] = {{NULL, 0, NULL, 0}};
  while ((rez = getopt_long(argc, argv, short_options, long_options,
                            &optindex)) != -1) {
    switch (rez) {
      case 'e':
        grep_flag->e_flag = 1;
        if (grep_flag->number_template < 10)
          strcpy(grep_flag->arr_template[grep_flag->number_template++], optarg);
        break;
      case 'i':
        grep_flag->i_flag = 1;
        break;
      case 'v':
        grep_flag->v_flag = 1;
        break;
      case 'c':
        grep_flag->c_flag = 1;
        break;
      case 'l':
        grep_flag->l_flag = 1;
        break;
      case 'n':
        grep_flag->n_flag = 1;
        break;
      case 'h':
        grep_flag->h_flag = 1;
        break;
      case 's':
        grep_flag->s_flag = 1;
        break;
      case 'f':
        grep_flag->f_flag = 1;
        strcpy(grep_flag->arr_file_pattern[grep_flag->number_file_pattern++],
               optarg);
        break;
      case 'o':
        grep_flag->o_flag = 1;
        break;
    }
  }
}

int regex_text(char *regex_string, char *regex_template,
               struct flag_struct grep_flag) {
  if (1 == grep_flag.i_flag) {
    regcomp(&regex, regex_template, REG_EXTENDED | REG_ICASE | REG_NEWLINE);
  } else {
    regcomp(&regex, regex_template, REG_EXTENDED | REG_NEWLINE);
  }
  int regex_temp = regexec(&regex, regex_string, 0, NULL, 0);
  regfree(&regex);
  return !regex_temp;
}

int regex_match_text(char *regex_string, char *regex_template,
                     struct flag_struct grep_flag) {
  if (1 == grep_flag.i_flag) {
    regcomp(&regex, regex_template, REG_EXTENDED | REG_ICASE | REG_NEWLINE);
  } else {
    regcomp(&regex, regex_template, REG_EXTENDED | REG_NEWLINE);
  }
  regmatch_t regex_string_match;
  int regex_eflags = 0;
  int regex_match = 0;
  size_t regex_shift = 0;
  size_t string_length = strlen(regex_string);
  while (regexec(&regex, regex_string + regex_shift, 1, &regex_string_match,
                 regex_eflags) == 0) {
    regex_eflags = REG_NOTBOL | REG_NOTEOL;
    regex_match++;
    regex_shift += regex_string_match.rm_eo;
    if (regex_string_match.rm_so == regex_string_match.rm_eo) regex_shift += 1;
    if (regex_shift > string_length) break;
  }
  regfree(&regex);
  return regex_match;
}

void grep_text(char **string_arr, int line_count, const int *length_arr,
               struct flag_struct grep_flag) {
  int number_of_regex_line = 0;
  int last_line_used = 0;
  for (int m = 0; m < line_count; m++) {
    char *int_str = malloc((length_arr[m] + 4) * sizeof(char));
    for (int i = 0; i < length_arr[m]; i++) {
      if (string_arr[m][i] == '\n') {
        int_str[i] = '\0';
      } else {
        int_str[i] = string_arr[m][i];
      }
    }
    int_str[length_arr[m]] = '\0';
    if (1 == grep_flag.o_flag &&
        (0 == grep_flag.c_flag && 0 == grep_flag.l_flag)) {
      for (int i = 0; i < grep_flag.number_template; i++) {
        int temp_return =
            regex_match_text(int_str, grep_flag.arr_template[i], grep_flag);
        if (temp_return > 0 && 0 == grep_flag.v_flag) {
          for (int t = 0; t < temp_return; t++) {
            if (0 == grep_flag.h_flag) {
              printf(
                  "%s:",
                  grep_flag.arr_file_name[grep_flag.number_current_file_name]);
            }
            if (1 == grep_flag.n_flag) {
              printf("%d:", m + 1);
            }
            printf("%s\n", grep_flag.arr_template[i]);
          }
        }
      }
    } else {
      int true_one_or_more_templates = 0;
      for (int i = 0; i < grep_flag.number_template; i++) {
        if (regex_text(int_str, grep_flag.arr_template[i], grep_flag) == 1) {
          true_one_or_more_templates = 1;
        }
      }
      if ((1 == true_one_or_more_templates && 0 == grep_flag.v_flag) ||
          (0 == true_one_or_more_templates && 1 == grep_flag.v_flag)) {
        if (length_arr[m] > 0) {
          number_of_regex_line++;
          if (0 == grep_flag.c_flag && 0 == grep_flag.l_flag) {
            if (0 == grep_flag.h_flag)
              printf(
                  "%s:",
                  grep_flag.arr_file_name[grep_flag.number_current_file_name]);
            if (1 == grep_flag.n_flag) printf("%d:", m + 1);
            for (int n = 0; n < length_arr[m]; n++) {
              printf("%c", string_arr[m][n]);
            }
            if (m == line_count - 1) last_line_used = 1;
          }
        }
      }
    }
    free(int_str);
  }
  if ((0 == grep_flag.o_flag && 1 == last_line_used) &&
      (length_arr[line_count - 1] > 0 &&
       string_arr[line_count - 1][length_arr[line_count - 1] - 1] != '\n')) {
    printf("\n");
  }
  if (1 == grep_flag.c_flag && 0 == grep_flag.l_flag) {
    if (0 == grep_flag.h_flag)
      printf("%s:",
             grep_flag.arr_file_name[grep_flag.number_current_file_name]);
    printf("%d\n", number_of_regex_line);
  } else if (1 == grep_flag.l_flag && number_of_regex_line > 0) {
    printf("%s\n", grep_flag.arr_file_name[grep_flag.number_current_file_name]);
  }
}

void corr_text(char **string_arr, int *line_count, int *length_arr) {
  for (int it = 0; it < *line_count - 1; it++) {
    if (string_arr[it][length_arr[it] - 1] != '\n') {
      int temp = length_arr[it] + length_arr[it + 1];
      char *int_str = malloc(temp * sizeof(char));
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
