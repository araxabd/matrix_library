#include "matrix_library.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int** mtrx_create(int w, int h)
{
	int** matrix = (int**)malloc(sizeof(int*)*h);
	if(matrix == NULL)
	{
		cout << "Memory allocation error" << endl;
		return NULL;
	}
	for(int i=0;i<h;i++)
	{
		matrix[i]  = (int*)malloc(sizeof(int)*w);
		if(matrix[i] == NULL)
		{
			cout << "Memory allocation error" << endl;
			return NULL;
		}
	}
	return matrix;
}

void mtrx_free(int** matrix, int h)
{
	for(int i=0;i < h;i++)
		free(matrix[i]);
	free(matrix);
	return;
}

void mtrx_txt_display(int** matrix, int w, int h)
{
	for(int i=0;i<h;i++) {
		for(int j=0;j<w;j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
}

void mtrx_input(int** matrix, int w, int h)
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

int** mtrx_add(int** first, int** second, int w, int h)
{
	int** answer = mtrx_create(w, h);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			answer[i][j] = first[i][j] + second[i][j];
		}
	}
	return answer;
}

int** mtrx_sub(int** first, int** second, int w, int h)
{
	int** answer = mtrx_create(w, h);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			answer[i][j] = first[i][j] - second[i][j];
		}
	}
	return answer;
}

int** mtrx_multiply(int** first, int fw, int fh, int** second, int sw, int sh)
{
	if(fw != sh) {
		cout << "CAN NOT BE MULTIPLIED (BAD DIMENSIONS)" << endl;
		return NULL;
	}
	int** answer = mtrx_create(sw, fh);
	int acc = 0;
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

int** mtrx_multiply_scalar(int** matrix, int w, int h, int number)
{
	int** answer = mtrx_create(w, h);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			answer[i][j] = matrix[i][j] * number;
		}
	}
	return answer;
}

int** mtrx_transpose(int** matrix, int w, int h)
{
	int** answer = mtrx_create(h, w);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			answer[j][i] = matrix[i][j];
		}
	}
	return answer;
}

int mtrx_determinant(int** matrix, int n)
{
	if(n == 1)
		return matrix[0][0];

	if(n == 2)
		return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];

	int answer = 0;
	int** smaller = mtrx_create(n-1, n-1);
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

int** mtrx_cofactor(int** matrix, int n)
{
	int** answer = mtrx_create(n, n);
	int** smaller = mtrx_create(n-1, n-1);
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

int** mtrx_inverse(int** matrix, int n)
{
	// using gauss - jordan method
	int det = mtrx_determinant(matrix, n);
	if(det == 0) {
		cout << "MATRIX IS NOT INVERTIBLE!" << endl;
		return NULL;
	}
	//TODO: change everything to double (because i can't calculate inverse correctly with integers)


}

