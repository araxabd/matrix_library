
#ifndef MATRIX_LIBRARY_H
#define MATRIX_LIBRARY_H

double** mtrx_create(int, int); // args: width, height

void mtrx_free(double**, int); // args: matrix, height

void mtrx_txt_display(double**, int, int); // args: matrix, width, height

void mtrx_input(double**, int, int); // args: matrix, width, height

double** mtrx_add(double**, double**, int, int); // args: matrix, matrix, width, height
double** mtrx_sub(double**, double**, int, int); // args: matrix, matrix, width, height

double** mtrx_multiply(double**, int, int, double**, int, int); // args: matrix, width, height, matrix, width, height
double** mtrx_multiply_scalar(double**, int, int, double); // args: matrix, width, height, scalar

double** mtrx_transpose(double**, int, int); // args: matrix, width, height

double mtrx_determinant(double**, int); // args: matrix, width&height

double** mtrx_cofactor(double**, int); // args: matrix, width&height
double** mtrx_inverse(double**, int); // args: matrix, width&height

#endif
