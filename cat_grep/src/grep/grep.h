#ifndef SRC_GREP_GREP_H_
#define SRC_GREP_GREP_H_

#include <errno.h>
#include <getopt.h>
#include <regex.h>
#include <stddef.h>
#include <string.h>

regex_t regex;

struct flag_struct {
  int e_flag;
  int i_flag;
  int v_flag;
  int c_flag;
  int l_flag;
  int n_flag;
  int h_flag;
  int s_flag;
  int f_flag;
  int o_flag;
  int number_template;
  int number_file_name;
  int number_current_file_name;
  int number_file_pattern;
  char arr_template[10][255];
  char arr_file_name[10][255];
  char arr_file_pattern[10][255];
};

void get_flags(int argc, char **argv, struct flag_struct *grep_flag);
void get_file_pattern(struct flag_struct *grep_flag);
void get_file_name(int argc, char **argv, struct flag_struct *grep_flag);
int regex_text(char *regex_string, char *regex_template,
               struct flag_struct grep_flag);
void grep_text(char **string_arr, int line_count, const int *length_arr,
               struct flag_struct grep_flag);
void corr_text(char **string_arr, int *line_count, int *length_arr);

#endif  // SRC_GREP_GREP_H_
