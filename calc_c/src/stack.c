#include "stack.h"

void push_char(struct node_t **head, char char_temp) {
  struct node_t *ptr = (struct node_t *)malloc(sizeof(struct node_t));
  if (*head == NULL) {
    ptr->val_char = char_temp;
    ptr->next = NULL;
    *head = ptr;
  } else {
    ptr->val_char = char_temp;
    ptr->next = *head;
    *head = ptr;
  }
}

char pop_char(struct node_t **head) {
  struct node_t *ptr = NULL;
  char char_temp = '\0';
  if (*head != NULL) {
    char_temp = (*head)->val_char;
    ptr = *head;
    *head = (*head)->next;
    free(ptr);
  }
  return char_temp;
}

char peek_char(struct node_t **head) {
  char char_temp = '\0';
  if (*head != NULL) char_temp = (*head)->val_char;
  return char_temp;
}

int isEmpty_char(struct node_t **head) { return 1 ? *head == NULL : 0; }

void push_double(struct node_double_t **head, double arg) {
  struct node_double_t *ptr =
      (struct node_double_t *)malloc(sizeof(struct node_double_t));
  if (*head == NULL) {
    ptr->val_double = arg;
    ptr->next = NULL;
    *head = ptr;
  } else {
    ptr->val_double = arg;
    ptr->next = *head;
    *head = ptr;
  }
}

double pop_double(struct node_double_t **head) {
  struct node_double_t *ptr = NULL;
  double double_temp = 0.0;
  if (*head != NULL) {
    double_temp = (*head)->val_double;
    ptr = *head;
    *head = (*head)->next;
    free(ptr);
  }
  return double_temp;
}
