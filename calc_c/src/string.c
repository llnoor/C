#include "string.h"

#include "stack.h"

#define SIZE 37

double calc(char *string, char *char_arg, int *f) {
  int flag = OK;
  double result = 0.0;
  function_t arr[SIZE];
  set_fun_data(&arr);
  int size = 256;
  char *str[5];
  for (int i = 0; i < 5; i++) {
    str[i] = (char *)calloc(size, sizeof(char));
  }
  strcpy(str[0], string);
  flag = replacer(str[0], str[1], arr);
  if (flag == OK) flag = unary_minus(str[1], str[2]);
  if (flag == OK) flag = check_operators(str[2]);
  if (flag == OK) flag = to_stack(str[2], str[3]);
  if (flag == OK) flag = check_x(char_arg);
  if (flag == OK) convert_to_RPN(str[3], str[4], arr);
  if (flag == OK) calc_RPN(str[4], char_arg, &result);
  if (flag != OK) result = 0.0;
  for (int i = 0; i < 5; i++) {
    free(str[i]);
  }
  *f = flag;
  return result;
}

void set_fun_data(function_t *arr) {
  function_t temp_arr[SIZE] = {
      {'N', " ", 1, 0},    {'(', "(", 1, 0},    {')', ")", 1, 0},
      {'.', ",", 1, 0},    {'0', "0", 1, 0},    {'1', "1", 1, 0},
      {'2', "2", 1, 0},    {'3', "3", 1, 0},    {'4', "4", 1, 0},
      {'5', "5", 1, 0},    {'6', "6", 1, 0},    {'7', "7", 1, 0},
      {'8', "8", 1, 0},    {'9', "9", 1, 0},    {'+', "+", 1, 1},
      {'-', "-", 1, 1},    {'*', "*", 1, 2},    {'/', "/", 1, 2},
      {'M', "mod", 3, 2},  {'e', "exp", 3, 4},  {'q', "sqrt", 4, 4},
      {'l', "log", 3, 4},  {'L', "ln", 2, 4},   {'s', "sin", 3, 4},
      {'c', "cos", 3, 4},  {'t', "tan", 3, 4},  {'g', "cot", 3, 4},
      {'S', "asin", 4, 4}, {'C', "acos", 4, 4}, {'T', "atan", 4, 4},
      {'G', "acot", 4, 4}, {'^', "^", 1, 3},    {'E', "e", 1, 0},
      {'E', "E", 1, 0},    {'.', ".", 1, 0},    {'~', "~", 1, 5},
      {'x', "x", 1, 0}};
  for (int i_t = 0; i_t < SIZE; i_t++) {
    arr[i_t] = temp_arr[i_t];
  }
}

int check_x(char *char_arg) {
  int flag = OK;
  int point1 = 0;
  if (*(char_arg + point1) == '-') point1++;
  while (*(char_arg + point1) && flag == OK) {
    if (strchr(".0123456789", *(char_arg + point1))) {
      int point_count = 0;
      while ((*(char_arg + point1) >= '0' && *(char_arg + point1) <= '9') ||
             *(char_arg + point1) == '.') {
        if (*(char_arg + point1) == '.') point_count++;
        point1++;
      }
      if (point_count > 1) flag = 13;
    } else {
      flag = 14;
      point1++;
    }
  }
  return flag;
}

int get_priority(char temp, function_t *arr) {
  int priority = -1;
  for (int i_t = 14; i_t < SIZE; i_t++) {
    if (temp == arr[i_t].short_fun) {
      priority = arr[i_t].priority;
      break;
    }
  }
  return priority;
}

int replacer(char *input_str, char *out_str, function_t *arr) {
  if (strlen(input_str) > 255) return -1;
  int flag = OK;
  int point1, point2, checker, bracket;
  point1 = point2 = checker = bracket = 0;
  while (*(input_str + point1) && flag == OK) {
    checker = 0;
    for (int i_t = 0; i_t < SIZE; i_t++) {
      if (!strncmp(input_str + point1, arr[i_t].fun, arr[i_t].size)) {
        if (i_t != 0) *(out_str + point2++) = arr[i_t].short_fun;
        point1 += arr[i_t].size;
        if (arr[i_t].short_fun == '(')
          bracket++;
        else if (arr[i_t].short_fun == ')')
          bracket--;
        checker++;
      }
    }
    if (checker == 0) flag = INCORRECT_STR;
  }
  *(out_str + point2) = '\0';
  if (bracket != 0) flag = INCORRECT_STR;
  return flag;
}

int unary_minus(char *input_str, char *out_str) {
  int flag = OK;
  int point1, point2;
  point1 = point2 = 0;
  if (*(input_str + point1) == '-') {
    *(out_str + point2++) = '~';
    point1++;
  } else if (*(input_str + point1) == '+') {
    point1++;
  } else if (strchr("(0123456789x-+eqlLsctgSCTG", *(input_str + point1))) {
    *(out_str + point2++) = *(input_str + point1++);
  } else
    flag = INCORRECT_STR;
  while (*(input_str + point1 + 1) && flag == OK) {
    if (*(input_str + point1) == '-' &&
        strchr("(+-*M/^", *(input_str + point1 - 1)) &&
        strchr("(0123456789x~eqlLsctgSCTG", *(input_str + point1 + 1))) {
      *(out_str + point2++) = '~';
      point1++;
    } else if (*(input_str + point1) == '+' &&
               strchr("(+-*M/^", *(input_str + point1 - 1)) &&
               strchr("(0123456789x~eqlLsctgSCTG", *(input_str + point1 + 1))) {
      point1++;
    } else if (*(input_str + point1) == 'E') {
      if (*(input_str + point1 + 1) == '+') {
        strcpy(out_str + point2, "*10^");
        point2 += 4;
        point1 += 2;
      } else if (*(input_str + point1 + 1) == '-') {
        strcpy(out_str + point2, "*10^~");
        point2 += 5;
        point1 += 2;
      } else {
        strcpy(out_str + point2, "*10^");
        point2 += 4;
        point1++;
      }
    } else {
      *(out_str + point2++) = *(input_str + point1++);
    }
  }
  if (*(input_str + point1 + 1) == '\0' &&
      strchr(")0123456789x", *(input_str + point1))) {
    *(out_str + point2++) = *(input_str + point1);
    *(out_str + point2++) = '\0';
  } else {
    flag = INCORRECT_STR;
  }
  return flag;
}

int check_operators(char *input_str) {
  int flag = OK;
  int point1, point2;
  point1 = point2 = 0;
  while (*(input_str + point1 + 1) && flag == OK) {
    if (strchr("+-*M/^", *(input_str + point1)) &&
        (!strchr(")0123456789x", *(input_str + point1 - 1)) ||
         !strchr("(0123456789x~eqlLsctgSCTG", *(input_str + point1 + 1)))) {
      flag = 3;
    } else if (strchr("eqlLsctgSCTG", *(input_str + point1)) &&
               (!strchr("()+-*M/^~", *(input_str + point1 - 1)) ||
                !strchr("(", *(input_str + point1 + 1)))) {
      flag = 4;
    } else if (strchr("~", *(input_str + point1)) &&
               (!strchr("(+-*M/^", *(input_str + point1 - 1)) ||
                !strchr("(0123456789xeqlLsctgSCTG",
                        *(input_str + point1 + 1)))) {
      flag = 8;
    } else if (strchr("0123456789", *(input_str + point1)) &&
               (!strchr("0123456789.(+-*M/^~", *(input_str + point1 - 1)) ||
                !strchr("0123456789.)+-*M/^", *(input_str + point1 + 1)))) {
      flag = 5;
    } else if (strchr(".", *(input_str + point1)) &&
               (!strchr("0123456789", *(input_str + point1 - 1)) ||
                !strchr("0123456789", *(input_str + point1 + 1)))) {
      flag = 6;
    } else if (strchr("x", *(input_str + point1)) &&
               (!strchr("(+-*M/^~", *(input_str + point1 - 1)) ||
                !strchr(")+-*M/^", *(input_str + point1 + 1)))) {
      flag = 7;
    }
    point1++;
  }
  if (!(*(input_str + point1 + 1) == '\0' &&
        strchr(")0123456789x", *(input_str + point1)))) {
    if (flag == 0) flag = 9;
  }
  return flag;
}

int calc_RPN(char *input_str, char *char_arg, double *result) {
  int flag = OK;
  node_double_t *head = NULL;
  double arg1 = 0.0;
  double arg2 = 0.0;
  char *string = strtok(input_str, " ");
  while (NULL != string) {
    if (strchr("0123456789", *string)) {
      push_double(&head, atof(string));
    } else if (*string == 'x') {
      push_double(&head, atof(char_arg));
    } else if (strchr("+-*M/^", *string)) {
      arg1 = pop_double(&head);
      arg2 = pop_double(&head);
      push_double(&head, calc_fun(*string, arg1, arg2));
    } else if (strchr("~eqlLsctgSCTG", *string)) {
      arg1 = pop_double(&head);
      push_double(&head, calc_fun(*string, arg1, 0));
    } else {
      flag = 3;
    }
    string = strtok(NULL, " ");
  }
  *result = pop_double(&head);
  return flag;
}

double calc_fun(char string, double a, double b) {
  double result = 0.0;
  switch (string) {
    case '+': {
      result = b + a;
      break;
    }
    case '-': {
      result = b - a;
      break;
    }
    case '*': {
      result = b * a;
      break;
    }
    case '/': {
      result = b / a;
      break;
    }
    case 'M': {
      result = fmod(b, a);
      break;
    }
    case '^': {
      result = pow(b, a);
      break;
    }
    case '~': {
      result = a * (-1);
      break;
    }
    case 'e': {
      result = exp(a);
      break;
    }
    case 'q': {
      result = sqrt(a);
      break;
    }
    case 'l': {
      result = log10(a);
      break;
    }  // lg
    case 'L': {
      result = log(a);
      break;
    }  // ln
    case 's': {
      result = sin(a);
      break;
    }
    case 'c': {
      result = cos(a);
      break;
    }
    case 't': {
      result = tan(a);
      break;
    }
    case 'g': {
      result = 1.0 / tan(a);
      break;
    }
    case 'S': {
      result = asin(a);
      break;
    }
    case 'C': {
      result = acos(a);
      break;
    }
    case 'T': {
      result = atan(a);
      break;
    }
    case 'G': {
      result = 1.0 / atan(a);
      break;
    }
  }
  return result;
}

int to_stack(char *input_str, char *out_str) {
  int flag = OK;
  int point1, point2;
  point1 = point2 = 0;
  point2 = 0;
  while (*(input_str + point1) && flag == OK) {
    if (strchr("()~x+-*M/^eqlLsctgSCTG", *(input_str + point1))) {
      *(out_str + point2++) = *(input_str + point1++);
      *(out_str + point2++) = ' ';
    } else if (strchr(".0123456789", *(input_str + point1))) {
      int point_count = 0;
      while ((*(input_str + point1) >= '0' && *(input_str + point1) <= '9') ||
             *(input_str + point1) == '.') {
        if (*(input_str + point1) == '.') point_count++;
        *(out_str + point2++) = *(input_str + point1++);
      }
      if (point_count > 1) flag = INCORRECT_STR;
      *(out_str + point2++) = ' ';
    } else {
      flag = INCORRECT_STR;
    }
  }
  *(out_str + point2 - 1) = '\0';
  return flag;
}

int convert_to_RPN(char *input_str, char *out_str, function_t *arr) {
  int flag = OK;
  node_t *head = NULL;
  char val_char[2] = " ";
  char *string = strtok(input_str, " ");
  while (NULL != string) {
    if (strchr(".0123456789x", *string)) {
      strcat(out_str, string);
      strcat(out_str, " ");
    } else if ('(' == *string) {
      push_char(&head, '(');
    } else if (')' == *string) {
      while (peek_char(&head) != '(') {
        val_char[0] = pop_char(&head);
        strcat(out_str, &val_char[0]);
        strcat(out_str, " ");
      }
      pop_char(&head);
    } else {
      while (get_priority(peek_char(&head), arr) >=
             get_priority(*string, arr)) {
        if ((get_priority(peek_char(&head), arr) == 3) &&
            (get_priority(*string, arr) == 3))
          break;
        val_char[0] = pop_char(&head);
        strcat(out_str, &val_char[0]);
        strcat(out_str, " ");
      }
      push_char(&head, *string);
    }
    string = strtok(NULL, " ");
  }
  while (!isEmpty_char(&head)) {
    val_char[0] = pop_char(&head);
    strcat(out_str, &val_char[0]);
    strcat(out_str, " ");
  }
  return flag;
}
