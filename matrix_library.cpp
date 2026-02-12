#include "matrix_library.h"
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

double** mtrx_create(int w, int h)
{
	double** matrix = (double**)malloc(sizeof(double*)*h);
	if(matrix == NULL)
	{
		cout << "Memory allocation error" << endl;
		return NULL;
	}
	for(int i=0;i<h;i++)
	{
		matrix[i]  = (double*)malloc(sizeof(double)*w);
		if(matrix[i] == NULL)
		{
			cout << "Memory allocation error" << endl;
			return NULL;
		}
	}
	return matrix;
}

void mtrx_free(double** matrix, int h)
{
	for(int i=0;i < h;i++)
		free(matrix[i]);
	free(matrix);
	return;
}

void mtrx_txt_display(double** matrix, int w, int h)
{
	for(int i=0;i<h;i++) {
		for(int j=0;j<w;j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
}

void mtrx_input(double** matrix, int w, int h)
{
	for(int i=0;i < h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cout << "row " << i+1 << "column " << j+1 << " : ";
			cin >> matrix[i][j];
		}
	}
}

double** mtrx_add(double** first, double** second, int w, int h)
{
	double** answer = mtrx_create(w, h);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			answer[i][j] = first[i][j] + second[i][j];
		}
	}
	return answer;
}

double** mtrx_sub(double** first, double** second, int w, int h)
{
	double** answer = mtrx_create(w, h);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			answer[i][j] = first[i][j] - second[i][j];
		}
	}
	return answer;
}

double** mtrx_multiply(double** first, int fw, int fh, double** second, int sw, int sh)
{
	if(fw != sh) {
		cout << "CAN NOT BE MULTIPLIED (BAD DIMENSIONS)" << endl;
		return NULL;
	}
	double** answer = mtrx_create(sw, fh);
	double acc = 0;
	for(int i=0;i < fh;i++) {
		for(int j=0;j < sw;j++) {
			for(int e=0;e < fw;e++) {
				acc += first[i][e]*second[e][j];
			}
			if(acc < 10e-10) {
				answer[i][j] = 0;
			} else {
				answer[i][j] = acc;
			}
			acc = 0;
		}
	}
	return answer;
	
}

double** mtrx_multiply_scalar(double** matrix, int w, int h, double number)
{
	double** answer = mtrx_create(w, h);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			answer[i][j] = matrix[i][j] * number;
		}
	}
	return answer;
}

double** mtrx_transpose(double** matrix, int w, int h)
{
	double** answer = mtrx_create(h, w);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			answer[j][i] = matrix[i][j];
		}
	}
	return answer;
}

double mtrx_determinant(double** matrix, int n)
{
	if(n == 1)
		return matrix[0][0];

	if(n == 2)
		return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];

	double answer = 0.0;
	double** smaller = mtrx_create(n-1, n-1);
	int sign = 1;
	int si, sj;
	for(int e=0;e < n;e++)
	{
		si = 0;
		for(int i=1;i<n;i++)
		{
			sj = 0;
			for(int j=0;j<n;j++)
			{
				if(j == e)
					continue;
				smaller[si][sj] = matrix[i][j];
				sj++;
			}
			si++;
		}
		answer += sign * matrix[0][e] * mtrx_determinant(smaller, n-1);
		sign *= -1;
	}
	mtrx_free(smaller, n-1);
	return answer;
}

double** mtrx_cofactor(double** matrix, int n)
{
	double** answer = mtrx_create(n, n);
	double** smaller = mtrx_create(n-1, n-1);
	int si, sj;
	char sign;
	for(int r=0;r<n;r++)
	{
		for(int c=0;c<n;c++)
		{
			si = 0;
			for(int i = 0;i < n;i++)
			{
				if(i == r)
					continue;
				sj = 0;
				for(int j=0; j < n;j++)
				{
					if(j == c)
						continue;
					smaller[si][sj] = matrix[i][j];
					sj++;
				}
				si++;
			}
			sign = (((r+c)%2) == 0) ? 1 : -1;
			answer[r][c] = sign * mtrx_determinant(smaller, n-1);
		}
	}
	mtrx_free(smaller, n-1);
	return answer;
}

double** mtrx_inverse(double** matrix, int n)
{
	// using gauss - jordan method
	double det = mtrx_determinant(matrix, n);
	if(fabs(det) < 10e-12) {
		cout << "MATRIX IS NOT INVERTIBLE!" << endl;
		return NULL;
	}
	double** cofactor = mtrx_cofactor(matrix, n);
	double** answer = mtrx_transpose(cofactor,n,n);//adjoint
	mtrx_free(cofactor, n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			answer[i][j] = answer[i][j] / det;
		}
	}
	return answer;
}



double* vctr_create(int n)
{
	double* vector = (double*)malloc(sizeof(double)*n);
	if(vector==NULL)
		cout << "MEMORY ALLOCATION FAILED!" << endl;
	return vector;
}

void vctr_free(double* vector)
{
	free(vector);
}

void vctr_input(double* vector, int n)
{
	for (int i=0;i<n;i++) {
		cout << "Enter the component " << i << " : ";
		cin >> vector[i];
	}
	return;
}

double* vctr_add(double* first, double* second, int n)
{
	double* answer = vctr_create(n);
	for(int i=0;i < n;i++)
	{
		answer[i] = first[i] + second[i];
	}
	return answer;
}
double* vctr_sub(double* first, double* second, int n)
{
	double* answer = vctr_create(n);
	for(int i=0;i < n;i++)
	{
		answer[i] = first[i] - second[i];
	}
	return answer;
}

double* vctr_multiply_scalar(double* vector, int n, double scalar)
{
	double* answer = vctr_create(n);
	for(int i=0;i<n;i++)
	{
		answer[i] = vector[i] * scalar;
	}
	return answer;
}

double vctr_dotp(double* first, double* second, int n)
{
	double answer = 0;
	for(int i=0;i<n;i++)
	{
		answer += first[i]*second[i];
	}
	return answer;
}

double* vctr_crossp(double* first, double* second, int n)
{
	if(n != 3) {
		cout << "VECTORS SHOULD HAVE 3 DIMENSIONS!" << endl;
		return NULL;
	}
	double* answer = vctr_create(n);
	double** matrix = mtrx_create(2,2);
	int index, sign=1;
	for(int i=0;i<n;i++)
	{
		index = 0;
		for(int j=0;j<n;j++)
		{
			if( i == j )
				continue;
			matrix[0][index] = first[j];
			matrix[1][index] = second[j];
			index++;
		}
		answer[i] = sign * mtrx_determinant(matrix, 2);
		sign *= -1;
	}


	// Hard code approach
//	answer[0] = first[1]*second[2] - first[2]*second[1];
//	answer[1] = first[2]*second[0] - first[0]*second[2];
//	answer[2] = first[0]*second[1] - first[1]*second[0];
	return answer;
}

double vctr_size(double* vector, int n)
{
	double answer = 0;
	for(int i=0; i < n;i++)
	{
		answer += vector[i] * vector[i];
	}
	answer = sqrt(answer);
	return answer;
}

double* vctr_normalize(double* vector, int n)
{
	double* answer = vctr_create(n);
	double size = vctr_size(vector, n);
	for(int i=0; i<n; i++)
	{
		answer[i] = vector[i] / size;
	}
	return answer;
}
