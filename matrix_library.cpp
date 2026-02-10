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
