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

void mtrx_add(int** first, int** second, int w, int h)
{
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			first[i][j] += second[i][j];
		}
	}
}
