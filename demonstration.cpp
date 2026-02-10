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
	int w = 0;
	int h = 0;
	cout << "Enter the number of rows : ";
	cin >> h;
	cout << "Enter the number of columns : ";
	cin >> w;

	int** sample_1 = mtrx_create(w, h);
	int** sample_2 = mtrx_create(w, h);

	cout << "---Enter first matrix values---" << endl;
	mtrx_input(sample_1, w, h);
	cout << "---Enter second matrix values---" << endl;
	mtrx_input(sample_2, w, h);
	mtrx_add(sample_1, sample_2, w, h);
	text_display_matrix(sample_1, w, h);
	return 0;
}
