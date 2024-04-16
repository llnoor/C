#ifndef SRTING_H
#define SRTING_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct function_t {
  char short_fun;
  char fun[8];
  int size;
  int priority;
} function_t;

void set_fun_data();
int check_x(char *char_arg);
double calc(char *string, char *char_arg, int *f);

int replacer(char *input_str, char *out_str, function_t *arr);
int unary_minus(char *input_str, char *out_str);
int check_operators(char *input_str);
int check_x(char *char_arg);
int get_priority(char temp, function_t *arr);
int to_stack(char *input_str, char *out_str);
double calc_fun(char string, double a, double b);
int convert_to_RPN(char *input_str, char *out_str, function_t *arr);
int calc_RPN(char *input_str, char *char_arg, double *result);

#define MAX 5
#define OK 0
#define INCORRECT_STR 1
#define CALC_ERROR 2
#define EPS 0.0000001

#endif /* SRTING_H */
