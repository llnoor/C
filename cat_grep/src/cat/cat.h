#ifndef SRC_CAT_CAT_H_
#define SRC_CAT_CAT_H_

#include <errno.h>
#include <getopt.h>
#include <stddef.h>
#include <string.h>

struct flag_struct {
  int corr_flag;
  int v_flag;
  int b_flag;
  int e_flag;
  int n_flag;
  int s_flag;
  int t_flag;
};

int get_flags(int argc, char **argv, struct flag_struct *cat_flag);
int cat_text(char **string_arr, int *line_count, int *length_arr,
             struct flag_struct *cat_flag);
void n_text(char **string_arr, int line_count, int *length_arr);
void b_text(char **string_arr, int line_count, int *length_arr);
void e_text(char **string_arr, int line_count, int *length_arr);
void s_text(char **string_arr, int *line_count, int *length_arr);
void corr_text(char **string_arr, int *line_count, int *length_arr);
void t_text(char **string_arr, int line_count, int *length_arr);
void v_text(char **string_arr, int line_count, int *length_arr);

#endif  // SRC_CAT_CAT_H_
