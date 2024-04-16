#ifndef TRANSFORMS_H
#define TRANSFORMS_H
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "matrix.h"

// typedef struct vert_array {
//   double *vertex;
//   int count;
// } vertices;

void move_matrix(vertices *verts, double a, double b, double c);
void scale_matrix(vertices *verts, double a, double b, double c);
void rotate_matrix(vertices *verts, double x, double y, double z);

double **init_move_matrix(double a, double b, double c);
double **init_scale_matrix(double a, double b, double c);
void free_matrix(double **matrix);

double **array_for_x_rotation(double x);
double **array_for_y_rotation(double y);
double **array_for_z_rotation(double z);
double **array_rotation(double x, double y, double z);
void free_array(double **array);

#endif  // TRANSFORMS_H
