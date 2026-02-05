#include "matrix_library.h"
#include <iostream>

using namespace std;

void text_display_matrix(int** matrix, int w, int h)
{
	for(int i=0;i<h;i++) {
		for(int j=0;j<w;j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
}

int main()
{
	int** sample_1 = mtrx_create(2, 2);
	int** sample_2 = mtrx_create(2, 2);
	sample_1[0][0] = 1;
	sample_1[0][1] = 2;
	sample_1[1][0] = 3;
	sample_1[1][1] = 4;
	sample_2[0][0] = 4;
	sample_2[0][1] = 3;
	sample_2[1][0] = 2;
	sample_2[1][1] = 1;
	mtrx_add(sample_1, sample_2, 2, 2);
	text_display_matrix(sample_1, 2, 2);
	return 0;
}
