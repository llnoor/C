#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node_double_t {
  double val_double;
  struct node_double_t *next;
} node_double_t;

typedef struct node_t {
  char val_char;
  struct node_t *next;
} node_t;

void push_double(struct node_double_t **head, double arg);
double pop_double(struct node_double_t **head);
double peek_double(struct node_double_t **head);
int isEmpty_double(struct node_double_t **head);

void push_char(struct node_t **head, char c);
char pop_char(struct node_t **head);
char peek_char(struct node_t **head);
int isEmpty_char(struct node_t **head);

#endif /* STACK_H */
