
#ifndef MATRIX_LIBRARY_H
#define MATRIX_LIBRARY_H

int** mtrx_create(int, int); // args: width, height


void mtrx_input(int**, int, int); // args: matrix, width, height

int** mtrx_add(int**, int**, int, int); // args: matrix, matrix, width, height

int** mtrx_multiply(int**, int, int, int**, int, int); // args: matrix, width, height, matrix, width, height
#endif
