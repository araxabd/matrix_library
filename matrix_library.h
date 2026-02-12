
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





double* vctr_create(int); // args: number of dimensions
void vctr_free(double*); // args: vector

void vctr_input(double*, int); // args: vector, number of dimensions

double* vctr_add(double*, double*, int); // args: vector, vector, number of dimensions
double* vctr_sub(double*, double*, int); // args: vector, vector, number of dimensions

double* vctr_multiply_scalar(double*, int, double); // args: vector, number of dimensions, scalar
double vctr_dotp(double*, double*, int); // args: vector, vector, number of dimensions
double* vctr_crossp(double*, double*, int); // args: vector, vector, number of dimensions

double vctr_size(double*, int); // args: vector, number of dimensions
//TODO: ADD THIS TO REFs : https://www.khanacademy.org/computing/computer-programming/programming-natural-simulations/programming-vectors/a/vector-magnitude-normalization
double* vctr_normalize(double*, int); // args: vector, number of dimensions

#endif
