#ifndef S21_NOTATION_H_
#define S21_NOTATION_H_

#define MAXOPSIZE       20      /* maximum size of operand, operator */
#define NUMBER          '0'     /* indicates number found */
#define TOOBIG          '9'     /* indicates string is too big */


float start_notation(char *d, float x);
void check_sin_cos_tan_ctg(char *d, char *sin_cos_tan_ctg);
void check_ln(char *d);
void check_sqrt(char *d);
int s21_priority(char *x);
float calc_notation(char *output, float x);
void s21_push(char x);
char s21_pop();
int s21_isalnum(const char sym);

#endif  // S21_NOTATION_H_

