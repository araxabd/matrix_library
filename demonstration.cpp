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
	int fw = 0;
	int fh = 0;
	cout << "Enter the number of rows : ";
	cin >> fh;
	cout << "Enter the number of columns : ";
	cin >> fw;

	int** sample_1 = mtrx_create(fw, fh);

	cout << "---Enter first matrix values---" << endl;
	mtrx_input(sample_1, fw, fh);


	int sw = 0;
	int sh = 0;
	cout << "Enter the number of rows : ";
	cin >> sh;
	cout << "Enter the number of columns : ";
	cin >> sw;

	int** sample_2 = mtrx_create(sw, sh);

	cout << "---Enter second matrix values---" << endl;
	mtrx_input(sample_2, sw, sh);




	int** answer = mtrx_multiply(sample_1, fw, fh, sample_2, sw, sh);
	text_display_matrix(answer, sw, fh);
	return 0;
}
