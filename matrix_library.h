
#ifndef MATRIX_LIBRARY_H
#define MATRIX_LIBRARY_H

int** mtrx_create(int, int); // args: width, height

void mtrx_free(int**, int); // args: matrix, height

void mtrx_txt_display(int**, int, int); // args: matrix, width, height

void mtrx_input(int**, int, int); // args: matrix, width, height

int** mtrx_add(int**, int**, int, int); // args: matrix, matrix, width, height
int** mtrx_sub(int**, int**, int, int); // args: matrix, matrix, width, height

int** mtrx_multiply(int**, int, int, int**, int, int); // args: matrix, width, height, matrix, width, height
int** mtrx_multiply_scalar(int**, int, int, int); // args: matrix, width, height, scalar

int** mtrx_transpose(int**, int, int); // args: matrix, width, height

#endif
