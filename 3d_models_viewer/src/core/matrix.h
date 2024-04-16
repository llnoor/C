#ifndef MATRIX_H
#define MATRIX_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define INCORRECT_MATRIX 1
#define INCORRECT_VALUE 2
#define INCORRECT_ALLOCATION 3
#define INCORRECT_FILENAME 4

typedef struct matrix_struct {  // структура матриц хранит в себе марицу, инфу о
                                // столбцах и строках
  double **matrix;              // сам массив
  int rows;                     // количество вершн
  int columns;                  // количество осей (x, y, z)
} matrix_t;

typedef struct vert_array {
  double *vertex;
  int count;
} vertices;

typedef struct polygon_struct {
  int *vertex;  // массив вершин, связанных в полигон
  unsigned int value;  // количество вершин, из которых состоит полигон
} polygon_t;

typedef struct object_struct {
  vertices *vert;  // Указатель на матрицу с вершинами
  polygon_t *polygons;          // Массив полигонов
  unsigned int count_polygons;  // количество полигонов
} object_t;

int numFaces(char *str);
void gotoStart(FILE *file);
void fulling(object_t *obj, FILE *file);
void sortFV(object_t *obj, char *str);
void numFV(object_t *obj, FILE *file);
// Создание матрицы
int create_matrix(int rows, int columns, matrix_t *result);
// Удаление матрицы
void remove_matrix(matrix_t *A);
// Умножение матриц (Переделанное под афинные преобразования)
void mult_matrix(double **A, double *B, double *result);
// Умножение двумерных массивов
double **__mult_matrix(double **A, double **B);
// Проверка матрицы на корректность
int isCorrect(matrix_t *A);
// Очистить выделенную для полигона память
void remove_polygon(polygon_t *polygons);
// Очистить всю выделенную память
void free_all(object_t *obj);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~ ПАРСИНГ .OBJ ~~~~~~~~~~

// Открыть файл для чтения
int openFile(char *fileName, FILE **file);

// возвращает указатель на object_t в котором записаны все данные из файла.
// fileName = название файла, numObj указатель на любой инт, в который
// впоследствие будет записано сколько обьектов было создано при парсинге(это
// значение нужно для функции free_all)
object_t *parseObj(char *fileName);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~  ВЕРШИНЫ ~~~~~~~~~~

// Функция для записи в массив инфы о вершинах из файла .obj
void fullingMatrix(matrix_t *matrix, FILE *fileName, int begin /*, int end*/);
// Вспомогательная функция для fullingMatrix. Разбивает полученную строку на
// подстроки с инфой о координатах по 3 осям и записывает эти данные в матрицу
void writeVertices(vertices *vrtx, char *str, int num);
void writeFaces(polygon_t *polygons, char *str, int num, int countVert);
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~ ПОЛИГОНЫ ~~~~~~~~~~

// из строки с инфой о полигоне заполняет массив с индексами вершин. Учтено что
// отсчет начинается с 1, а не с 0. Записанный в массив результат уменьшен на 1.
int *vertexFilling(char *str, unsigned int value, int numVrtx);
void fullingPolygon(object_t *obj, FILE *fileName, int begin);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~ ТЕСТОВЫЕ ФУНКЦИИ ~~~~~~~~~~

// Тестовая функция для принта в том виде,
// в каком хранятся данные в .obj файле
void printMatrix(matrix_t *matrix);
// принт всех элементов массива обьектов
void printObject_t(object_t *obj);

int checkIndex(object_t *obj, int num);
int checkFaces(object_t *obj, int num);
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#endif  // MATRIX_H
