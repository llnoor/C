#include "s21_dynamic.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

static int stack_pointer = 0;
static double values[MAX_SIZE];

double push(double number) {
  if ( stack_pointer < MAX_SIZE ) {
    values[stack_pointer++] = number;
  } else {
    printf("Error: stack is full.\n");
    exit(0);
  }
  return number;
}

double pop() {
  if ( stack_pointer > 0 ) {
    return values[--stack_pointer];
  } else {
    printf("Error: stack is empty.\n");
    clear_stack();
    exit(0);
    return 0;
  }
}

void clear_stack() {
  stack_pointer = 0;
}

