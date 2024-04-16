#include "matrix.h"

int is_correct_matrix(matrix_t* A) {
  int flag = OK;
  if (A->columns > 0 && A->rows > 0) {
    if (A->matrix != NULL) {
      flag = OK;
    } else {
      flag = INCORRECT_MATRIX;
    }
  } else {
    flag = INCORRECT_MATRIX;
  }
  return flag;
}

int create_matrix(int rows, int columns, matrix_t* result) {
  int flag = OK;
  if (rows > 0 && columns > 0 && result != NULL /* && result!=NULL */) {
    result->matrix = (double**)calloc(rows, sizeof(double*));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double*)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          flag = INCORRECT_MATRIX;
        }
      }
      if (flag == INCORRECT_MATRIX) {
        remove_matrix(result);
      } else {
        result->rows = rows;
        result->columns = columns;
      }
    } else {
      flag = INCORRECT_MATRIX;
    }
  } else {
    flag = INCORRECT_MATRIX;
  }
  return flag;
}

void remove_matrix(matrix_t* A) {
  if (A->rows > 0 && A->columns > 0) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->rows = 0;
    A->columns = 0;
    A->matrix = NULL;
  }
}

int eq_matrix(matrix_t* A, matrix_t* B) {
  int flag = SUCCESS;
  if (is_correct_matrix(A) == INCORRECT_MATRIX ||
      is_correct_matrix(B) == INCORRECT_MATRIX) {
    flag = FAILURE;
  } else if (A->columns == B->columns && A->rows == B->rows) {
    for (int x = 0; x < A->rows; x += 1) {
      for (int y = 0; y < A->columns; y += 1) {
        if (fabs(A->matrix[x][y] - B->matrix[x][y]) >= EPS) {
          flag = FAILURE;
        }
      }
    }
  } else {
    flag = FAILURE;
  }
  return flag;
}

int sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int flag = OK;
  if (is_correct_matrix(A) == INCORRECT_MATRIX ||
      is_correct_matrix(B) == INCORRECT_MATRIX) {
    flag = INCORRECT_MATRIX;
  } else if (A->columns == B->columns && A->rows == B->rows && A->columns > 0 &&
             A->rows > 0) {
    flag = create_matrix(A->rows, A->columns, result);
    if (flag == 0) {
      result->rows = A->rows;
      result->columns = A->columns;
      for (int x = 0; x < A->rows; x += 1) {
        for (int y = 0; y < A->columns; y += 1) {
          result->matrix[x][y] = A->matrix[x][y] + B->matrix[x][y];
        }
      }
    }
  } else {
    flag = CALC_ERROR;
  }
  return flag;
}

int sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int flag = OK;
  if (is_correct_matrix(A) == INCORRECT_MATRIX ||
      is_correct_matrix(B) == INCORRECT_MATRIX) {
    flag = INCORRECT_MATRIX;
  } else if (A->columns == B->columns && A->rows == B->rows && A->columns > 0 &&
             A->rows > 0) {
    flag = create_matrix(A->rows, A->columns, result);
    if (flag == 0) {
      result->rows = A->rows;
      result->columns = A->columns;
      for (int x = 0; x < A->rows; x += 1) {
        for (int y = 0; y < A->columns; y += 1) {
          result->matrix[x][y] = A->matrix[x][y] - B->matrix[x][y];
        }
      }
    }
  } else {
    flag = CALC_ERROR;
  }
  return flag;
}

int mult_number(matrix_t* A, double number, matrix_t* result) {
  int flag = OK;
  if (is_correct_matrix(A) == INCORRECT_MATRIX) {
    flag = INCORRECT_MATRIX;
  } else if (fabs(number) == (0.0 / 0.0) || fabs(number) == (1.0 / 0.0)) {
    flag = CALC_ERROR;
  } else if (A->columns > 0 && A->rows > 0) {
    flag = create_matrix(A->rows, A->columns, result);
    if (flag == 0) {
      result->rows = A->rows;
      result->columns = A->columns;
      for (int x = 0; x < A->rows; x += 1) {
        for (int y = 0; y < A->columns; y += 1) {
          result->matrix[x][y] = number * A->matrix[x][y];
        }
      }
    }
  } else {
    flag = CALC_ERROR;
  }
  return flag;
}

int mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int flag = OK;
  // (A = m × k) (B = k × n) C = m × n = A × B
  // m = A->rows
  // k = A->columns = B->rows
  // n = B->columns
  if (is_correct_matrix(A) == INCORRECT_MATRIX) {
    flag = INCORRECT_MATRIX;
  } else if (A->columns == B->rows && A->columns > 0 && A->rows > 0 &&
             B->columns > 0) {
    flag = create_matrix(A->rows, B->columns, result);
    if (flag == 0) {
      result->rows = A->rows;
      result->columns = B->columns;
      for (int x = 0; x < A->rows; x += 1) {
        for (int y = 0; y < B->columns; y += 1) {
          result->matrix[x][y] = 0;
          for (int z = 0; z < A->columns; z += 1) {
            result->matrix[x][y] =
                result->matrix[x][y] + A->matrix[x][z] * B->matrix[z][y];
          }
        }
      }
    }
  } else {
    flag = CALC_ERROR;
  }
  return flag;
}

int transpose(matrix_t* A, matrix_t* result) {
  int flag = OK;
  if (is_correct_matrix(A) == INCORRECT_MATRIX) {
    flag = INCORRECT_MATRIX;
  } else if (A->columns > 0 && A->rows > 0) {
    flag = create_matrix(A->columns, A->rows, result);
    if (flag == OK) {
      result->rows = A->columns;
      result->columns = A->rows;
      for (int x = 0; x < A->rows; x += 1) {
        for (int y = 0; y < A->columns; y += 1) {
          result->matrix[y][x] = A->matrix[x][y];
        }
      }
    }
  } else {
    flag = CALC_ERROR;
  }
  return flag;
}

int calc_complements(matrix_t* A, matrix_t* result) {
  int flag = OK;
  if (is_correct_matrix(A) == INCORRECT_MATRIX) {
    flag = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    flag = CALC_ERROR;
  } else {
    int sign = 1;
    flag = create_matrix(A->columns, A->rows, result);
    if (flag == OK) {
      if (A->columns == 1) {
        result->matrix[0][0] = A->matrix[0][0];
      } else {
        for (int x = 0; x < A->rows; x += 1) {
          for (int y = 0; y < A->columns; y += 1) {
            matrix_t B = {0};
            double determinant = 0.0;
            flag = temp_matrix(x, y, A, &B);
            if (flag == OK) {
              determinant(&B, &determinant);
              if (0 == (x + y) % 2) {
                sign = 1;
              } else {
                sign = -1;
              }
              result->matrix[x][y] = determinant * sign;
            }
            remove_matrix(&B);
          }
        }
      }
    }
  }
  return flag;
}

int temp_matrix(int rows, int columns, matrix_t* A, matrix_t* result) {
  int flag = create_matrix(A->rows - 1, A->rows - 1, result);
  int minor_x = 0;
  for (int x = 0; x < A->rows - 1; x += 1) {
    if (x == rows) minor_x = 1;
    int minor_y = 0;
    for (int y = 0; y < A->columns - 1; y += 1) {
      if (y == columns) minor_y = 1;
      result->matrix[x][y] = A->matrix[x + minor_x][y + minor_y];
    }
  }
  return flag;
}

int determinant(matrix_t* A, double* result) {
  int flag = OK;
  int rang = 0;
  *result = 0;
  if (is_correct_matrix(A) == INCORRECT_MATRIX) {
    flag = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    flag = CALC_ERROR;
  } else {
    rang = A->columns;
  }
  int sign = 1;
  double minor_det = 0.0;
  switch (rang) {
    case 0:
      break;
    case 1:
      *result = A->matrix[0][0];
      break;
    case 2:
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
      break;
    default:
      for (int y = 0; y < A->columns; y += 1) {
        matrix_t B = {0};
        flag = temp_matrix(0, y, A, &B);
        determinant(&B, &minor_det);
        *result = *result + sign * A->matrix[0][y] * minor_det;
        sign = sign * -1;
        minor_det = 0;
        remove_matrix(&B);
      }
      break;
  }
  return flag;
}

int inverse_matrix(matrix_t* A, matrix_t* result) {
  int flag = OK;
  double determinant = 0.0;
  if (is_correct_matrix(A) == INCORRECT_MATRIX) {
    flag = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    flag = CALC_ERROR;
  } else {
    determinant(A, &determinant);
    if (0 != fabs(determinant)) {
      if (A->columns == 1) {
        flag = create_matrix(A->rows, A->rows, result);
        result->matrix[0][0] = 1.0 / (A->matrix[0][0]);
      } else {
        matrix_t B = {0};
        matrix_t D = {0};
        calc_complements(A, &B);
        transpose(&B, &D);
        mult_number(&D, 1.0 / determinant, result);
        remove_matrix(&B);
        remove_matrix(&D);
      }

    } else {
      flag = CALC_ERROR;
    }
  }
  return flag;
}
