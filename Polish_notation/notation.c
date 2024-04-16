#include "notation.h"
#include "dynamic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int stack_top = -1;
char stack[200];

float start_notation(char *data, float x) {
    char e_x;
    char output[100] = "";
    char output_temp[100];
    while (*data != '\0') {
        if (C_isalnum(*data)) {
            if (C_isalnum(*(data+1))) {
              sprintf(output_temp, "%c", *data);
              strcat(output, output_temp);
            } else {
              sprintf(output_temp, "%c ", *data);
              strcat(output, output_temp);
            }
        } else if (*data == '(') {
            C_push(*data);
        } else if (*data == ')') {
            while ((e_x = C_pop()) != '(') {
                sprintf(output_temp, "%c ", e_x);
                strcat(output, output_temp);
            }
        } else {
            while ( C_priority(&stack[stack_top]) >= C_priority(data) ) {
                sprintf(output_temp, "%c ", C_pop());
                strcat(output, output_temp);
            }
            C_push(*data);
        }
        data++;
    }
    while (stack_top != -1) {
        sprintf(output_temp, "%c ", C_pop());
        strcat(output, output_temp);
    }
    return calc_notation(output, x);
}

void check_sin_cos_tan_ctg(char *d, char *sin_cos_tan_ctg) {
  int len = strlen(d);
  for (int k=0; k < len; k++) {
    int flag_of_sin = 0;
    int number = 0;
    if (d[k] == sin_cos_tan_ctg[0] && d[k+1] == sin_cos_tan_ctg[1] &&
        d[k+2] == sin_cos_tan_ctg[2] && d[k+3] == '(') {
        for (int j=k+4; j < len; j++) {
          if (d[j] == '(') {
            flag_of_sin++;
          }
          if (d[j] == ')' && flag_of_sin == 0) {
              number = j;
              break;
          }
          if (d[j] == ')' && flag_of_sin != 0) {
              flag_of_sin--;
          }
        }
        for (int u=k; u < (number-2) ; u++) {
          d[u] = d[u+3];
        }
        d[number-2] = sin_cos_tan_ctg[0];
        d[number-1] = sin_cos_tan_ctg[1];
        d[number] = sin_cos_tan_ctg[2];
    }
  }
}

void check_ln(char *d) {
  int len = strlen(d);
  for (int k=0; k < len; k++) {
    int flag_of_sin = 0;
    int number = 0;
    if ( d[k] == 'l' && d[k+1] == 'n' && d[k+2] == '(' ) {
        for (int j=k+3; j < len; j++) {
          if (d[j] == '(') {
            flag_of_sin++;
          }
          if (d[j] == ')' && flag_of_sin == 0) {
              number = j;
              break;
          }
          if (d[j] == ')' && flag_of_sin != 0) {
              flag_of_sin--;
          }
        }
        for (int u=k; u < (number-1) ; u++) {
          d[u] = d[u+2];
        }
        d[number-1]='l';
        d[number]='n';
    }
  }
}

void check_sqrt(char *d) {
  int len = strlen(d);
  for (int k=0; k < len; k++) {
    int flag_of_sin = 0;
    int number = 0;
    if ( d[k] == 's' && d[k+1] == 'q' && d[k+2] == 'r' && d[k+3] == 't' && d[k+4] == '(' ) {
        for (int j=k+5; j < len; j++) {
          if (d[j] == '(') {
            flag_of_sin++;
          }
          if (d[j] == ')' && flag_of_sin == 0) {
              number = j;
              break;
          }
          if (d[j] == ')' && flag_of_sin != 0) {
              flag_of_sin--;
          }
        }
        for (int u=k; u < (number-3) ; u++) {
          d[u] = d[u+4];
        }
        d[number-3] = 's';
        d[number-2] = 'q';
        d[number-1] = 'r';
        d[number] = 't';
    }
  }
}

int priority(char *x) {
    if ( *x == '(' )
        return 0;
    if ( *x == '+' || *x == '-' )
        return 1;
    if ( *x == '*' || *x == '/' )
        return 2;
    return 0;
}

float calc_notation(char *output, float x) {
    char *sep = " ";
    char *istr;
    float op2;
    char str[20];
    istr = strtok(output, sep);
    while ( istr != NULL ) {
      if ( atof(istr) != 0 ) {
        push(atof(istr));
      } else {
        str[0] = (char) *istr;
          if ( str[0] == '+' ) {
              push(pop() + pop());
          } else if ( str[0] == '*' ) {
              push(pop() * pop());
          } else if ( str[0] == '-' ) {
              op2 = pop();
              push(pop() - op2);
          } else if ( str[0] == '/' ) {
              op2 = pop();
              if ( op2 == 0.0 ) {
                  printf("Divide zero\n");
              } else {
                  push(pop() / op2);
              }
          } else if ( str[0] == 'x' ) {
              push(x);
          } else if ( strcmp(istr, "sin") == 0 ) {
              op2 = pop();
              push(sin(op2));
          } else if ( strcmp(istr, "cos") == 0 ) {
              op2 = pop();
              push(cos(op2));
          } else if ( strcmp(istr, "tan") == 0 ) {
              op2 = pop();
              push(tan(op2));
          } else if ( strcmp(istr, "ctg") == 0 ) {
              op2 = pop();
              push(1./tan(op2));
          } else if ( strcmp(istr, "ln") == 0 ) {
              op2 = pop();
              push(log10(op2));
          } else if ( strcmp(istr, "sqrt") == 0 ) {
              op2 = pop();
              push(sqrt(op2));
          }
      }
      istr = strtok(NULL, sep);
    }
    return pop();
}

void push(char str) {
    stack[++stack_top] = str;
}

char pop() {
    if ( stack_top == -1 ) {
      return -1;
    } else {
      return stack[stack_top--];
    }
}

int isalnum(const char sym) {
       return ( ((sym >= 'A')  &&  (sym <= 'Z')) || ((sym >= 'a')
       &&  (sym <= 'z')) || ((sym >= '0')  &&  (sym <= '9')) || (sym == '.'));
}
