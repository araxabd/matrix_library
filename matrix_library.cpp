#include "matrix_library.h"
#include <stdlib.h>
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
			answer[i][j] = acc;
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
			answer[r][c] = mtrx_determinant(smaller, n-1);
		}
	}
	mtrx_free(smaller, n-1);
	return answer;
}

double** mtrx_inverse(double** matrix, int n)
{
	// using gauss - jordan method
	double det = mtrx_determinant(matrix, n);
	if(det == 0) {
		cout << "MATRIX IS NOT INVERTIBLE!" << endl;
		return NULL;
	}
	//TODO: change everything to double (because i can't calculate inverse correctly with integers)


}

