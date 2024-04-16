#include "transforms.h"

void move_matrix(vertices *verts, double a, double b, double c) {
  double **move_matrix = init_move_matrix(a, b, c);
  for (int i = 0; i < verts->count; i++) {
    verts->vertex[3 * i] =
        verts->vertex[3 * i] * move_matrix[0][0] + 1 * move_matrix[0][3];
    verts->vertex[3 * i + 1] =
        verts->vertex[3 * i + 1] * move_matrix[1][1] + 1 * move_matrix[1][3];
    verts->vertex[3 * i + 2] =
        verts->vertex[3 * i + 2] * move_matrix[2][2] + 1 * move_matrix[2][3];
  }
  free_matrix(move_matrix);
}

void scale_matrix(vertices *verts, double a, double b, double c) {
  double **scale_matrix = init_scale_matrix(a, b, c);
  for (int i = 0; i < verts->count; i++) {
    double result[3];
    mult_matrix(scale_matrix, verts->vertex + i * 3, result);
    verts->vertex[3 * i] = result[0];
    verts->vertex[3 * i + 1] = result[1];
    verts->vertex[3 * i + 2] = result[2];
  }
  free_matrix(scale_matrix);
}

void rotate_matrix(vertices *verts, double x, double y, double z) {
  x = M_PI / 180 * x;
  y = M_PI / 180 * y;
  z = M_PI / 180 * z;
  double **array = array_rotation(x, y, z);
  double result[3];

  for (int i = 0; i < verts->count; i++) {
    mult_matrix(array, verts->vertex + i * 3, result);
    verts->vertex[3 * i] = result[0];
    verts->vertex[3 * i + 1] = result[1];
    verts->vertex[3 * i + 2] = result[2];
  }
  free_matrix(array);
}

void free_matrix(double **matrix) {
  for (int i = 0; i < 3; i++) free(matrix[i]);
  free(matrix);
}

double **init_move_matrix(double a, double b, double c) {
  double **move_matrix = (double **)malloc(3 * sizeof(double *));
  for (int i = 0; i < 3; i++)
    move_matrix[i] = (double *)malloc(4 * sizeof(double));

  move_matrix[0][0] = 1;
  move_matrix[0][1] = 0;
  move_matrix[0][2] = 0;
  move_matrix[0][3] = a;

  move_matrix[1][0] = 0;
  move_matrix[1][1] = 1;
  move_matrix[1][2] = 0;
  move_matrix[1][3] = b;

  move_matrix[2][0] = 0;
  move_matrix[2][1] = 0;
  move_matrix[2][2] = 1;
  move_matrix[2][3] = c;

  return move_matrix;
}

double **init_scale_matrix(double a, double b, double c) {
  double **scale_matrix = (double **)malloc(3 * sizeof(double *));
  for (int i = 0; i < 3; i++)
    scale_matrix[i] = (double *)malloc(3 * sizeof(double));

  scale_matrix[0][0] = a;
  scale_matrix[0][1] = 0;
  scale_matrix[0][2] = 0;

  scale_matrix[1][0] = 0;
  scale_matrix[1][1] = b;
  scale_matrix[1][2] = 0;

  scale_matrix[2][0] = 0;
  scale_matrix[2][1] = 0;
  scale_matrix[2][2] = c;

  return scale_matrix;
}

double **array_for_x_rotation(double x) {
  double **result = (double **)malloc(3 * sizeof(double *));
  for (int i = 0; i < 3; i++) result[i] = (double *)malloc(3 * sizeof(double));

  result[0][0] = 1;
  result[0][1] = 0;
  result[0][2] = 0;

  result[1][0] = 0;
  result[1][1] = cos(x);
  result[1][2] = sin(x);

  result[2][0] = 0;
  result[2][1] = -sin(x);
  result[2][2] = cos(x);

  return result;
}

double **array_for_y_rotation(double y) {
  double **result = (double **)malloc(3 * sizeof(double *));
  for (int i = 0; i < 3; i++) result[i] = (double *)malloc(3 * sizeof(double));

  result[0][0] = cos(y);
  result[0][1] = 0;
  result[0][2] = sin(y);

  result[1][0] = 0;
  result[1][1] = 1;
  result[1][2] = 0;

  result[2][0] = -sin(y);
  result[2][1] = 0;
  result[2][2] = cos(y);

  return result;
}

double **array_for_z_rotation(double z) {
  double **result = (double **)malloc(3 * sizeof(double *));
  for (int i = 0; i < 3; i++) result[i] = (double *)malloc(3 * sizeof(double));

  result[0][0] = cos(z);
  result[0][1] = sin(z);
  result[0][2] = 0;

  result[1][0] = -sin(z);
  result[1][1] = cos(z);
  result[1][2] = 0;

  result[2][0] = 0;
  result[2][1] = 0;
  result[2][2] = 1;

  return result;
}

double **array_rotation(double x, double y, double z) {
  double **x_matrix = array_for_x_rotation(x);
  double **y_matrix = array_for_y_rotation(y);
  double **z_matrix = array_for_z_rotation(z);
  double **tmp_result = __mult_matrix(y_matrix, x_matrix);
  double **result = __mult_matrix(z_matrix, tmp_result);

  free_matrix(x_matrix);
  free_matrix(y_matrix);
  free_matrix(z_matrix);
  free_matrix(tmp_result);

  return result;
}
