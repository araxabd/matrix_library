#include "matrix_library.h"
#include <stdlib.h>


int** mtrx_create(int w, int h)
{
	int** matrix = (int**)malloc(sizeof(int*)*h);
	//TODO: memory allocation check
	for(int i=0;i<h;i++)
	{
		matrix[i]  = (int*)malloc(sizeof(int)*w);
	}
	return matrix;
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
