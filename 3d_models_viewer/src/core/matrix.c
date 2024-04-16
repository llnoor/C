#include "matrix.h"

void mult_matrix(double **A, double *B, double *result) {
  for (int i = 0; i < 3; i++) {
    result[i] = 0;
    for (int k = 0; k < 3; k++) {
      result[i] += A[i][k] * B[k];
    }
  }
}

double **__mult_matrix(double **A, double **B) {
  double **result = (double **)malloc(3 * sizeof(double *));
  for (int i = 0; i < 3; i++) {
    result[i] = (double *)calloc(3, sizeof(double));
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        result[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  return result;
}

void remove_polygon(polygon_t *polygon) {
  polygon->value = 0;
  free(polygon->vertex);
}

int openFile(char *fileName, FILE **file) {
  int result = INCORRECT_FILENAME;
  *file = fopen(fileName, "r+");
  if (*file != NULL) {
    result = OK;
  }
  return result;
}

object_t *parseObj(char *fileName) {
  object_t *obj = NULL;
  FILE *file = 0;
  if (openFile(fileName, &file) == OK) {
    obj = malloc(sizeof(object_t));
    numFV(obj, file);
    fulling(obj, file);
    fclose(file);
  }

  return obj;
}

void gotoStart(FILE *file) { fseek(file, 0, SEEK_SET); }

void fulling(object_t *obj, FILE *file) {
  char str[100];
  gotoStart(file);
  obj->vert->count = 0;
  obj->count_polygons = 0;
  while (!feof(file)) {
    fgets(str, sizeof(str), file);
    sortFV(obj, str);
  }
}

void sortFV(object_t *obj, char *str) {
  if (str[0] == 'v' && str[1] == ' ') {
    writeVertices(obj->vert, str, obj->vert->count);
    obj->vert->count += 1;
  } else if (str[0] == 'f' && str[1] == ' ') {
    writeFaces(obj->polygons, str, obj->count_polygons, obj->vert->count);
    obj->count_polygons += 1;
  }
}

void writeFaces(polygon_t *polygon, char *str, int num, int countVert) {
  char sStr[100];
  strcpy(sStr, str);
  polygon[num].value = 2 * numFaces(sStr);
  polygon[num].vertex = vertexFilling(str, polygon[num].value, countVert);
}

void numFV(object_t *obj, FILE *file) {
  char str[100];
  int v = 0;
  int f = 0;
  gotoStart(file);
  while (!feof(file)) {
    fgets(str, sizeof(str), file);
    if (str[0] == 'v' && str[1] == ' ') {
      v++;
    } else if (str[0] == 'f' && str[1] == ' ') {
      f++;
    }
  }
  obj->count_polygons = f;
  obj->vert = malloc(sizeof(vertices));
  obj->vert->count = v;
  obj->vert->vertex = malloc(3 * v * sizeof(double));
  obj->polygons = malloc(f * sizeof(polygon_t));
}

void free_all(object_t *obj) {
  free(obj->vert->vertex);
  free(obj->vert);
  for (unsigned int j = 0; j < obj->count_polygons; j++) {
    remove_polygon(&obj->polygons[j]);
  }
  free(obj->polygons);
  free(obj);
}

void writeVertices(vertices *vrtx, char *str, int num) {
  char *delimiter = " ";
  char *token = strtok(str, delimiter);
  for (int i = 0; i < 3; i++) {
    token = strtok(NULL, delimiter);
    vrtx->vertex[3 * num + i] = atof(token);
  }
}

int *vertexFilling(char *str, unsigned int value, int numVrtx) {
  int *vertices = calloc(value, sizeof(int));
  char *delimiter = " ";
  char *token = strtok(str, delimiter);
  for (unsigned int i = 0; i < value - 1;) {
    token = strtok(NULL, delimiter);
    int index = atoi(token);
    if (index < 0) index += numVrtx + 1;
    vertices[i++] = index - 1;
    if (i > 1) {
      vertices[i++] = index - 1;
    }
  }
  vertices[value - 1] = vertices[0];
  return vertices;
}

int numFaces(char *str) {
  int result = 0;
  char *delimiter = " ";
  char *token = strtok(str, delimiter);
  while (token != NULL) {
    token = strtok(NULL, delimiter);
    if (token != NULL &&
        (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))) {
      result++;
    }
  }
  return result;
}
