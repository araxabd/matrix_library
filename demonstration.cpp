#include "matrix_library.h"
#include <iostream>

using namespace std;

void multiply(void);
void add(void);
void sub(void);
void multiply_scalar(void);
void transpose(void);
void det(void);
void inverse(void);


int main()
{
	while(1) {

		char job;
		cout << "What do you want to do (h for help) :";
		cin >> job;

		bool exit_flag = false;
		switch(job) {
			case 'h':
				cout << "e for exit\na for add matrices\ns for subtract matrices\nm for multiply matrices\nh for showing this help\nx for scalar times matrix\nt for matrix transpose\nd for matrix determinant\ni for matrix inverse\n" << endl;
				break;
			case 'm':
				multiply();
				break;
			case 'x':
				multiply_scalar();
				break;
			case 'a':
				add();
				break;
			case 's':
				sub();
				break;
			case 't':
				transpose();
				break;
			case 'd':
				det();
				break;
			case 'i':
				inverse();
				break;
			case 'e':
				exit_flag = true;
				break;
			default:
				cout << "*** Please enter valid option ***" << endl;
				break;
		}
		if(exit_flag)
			break;
		// TODO: free matrices after allocation
	}
	return 0;
}


void multiply()
{
	int fw = 0;
	int fh = 0;
	cout << "Enter the number of rows : ";
	cin >> fh;
	cout << "Enter the number of columns : ";
	cin >> fw;

	double** first = mtrx_create(fw, fh);

	cout << "---Enter first matrix values---" << endl;
	mtrx_input(first, fw, fh);


	int sw = 0;
	int sh = 0;
	cout << "Enter the number of rows : ";
	cin >> sh;
	cout << "Enter the number of columns : ";
	cin >> sw;

	double** second = mtrx_create(sw, sh);

	cout << "---Enter second matrix values---" << endl;
	mtrx_input(second, sw, sh);




	double** answer = mtrx_multiply(first, fw, fh, second, sw, sh);
	mtrx_free(first, fh);
	mtrx_free(second, sh);
	mtrx_txt_display(answer, sw, fh);
	mtrx_free(answer, fh);
	return;
}

void add()
{
	int w = 0;
	int h = 0;
	cout << "Enter the number of rows : ";
	cin >> h;
	cout << "Enter the number of columns : ";
	cin >> w;
	double** first = mtrx_create(w,h);
	double** second = mtrx_create(w,h);
	cout << "---Enter first matrix values---" << endl;
	mtrx_input(first, w, h);
	cout << "---Enter second matrix values---" << endl;
	mtrx_input(second, w, h);

	double** answer = mtrx_add(first, second, w, h);
	mtrx_free(first, h);
	mtrx_free(second, h);
	mtrx_txt_display(answer, w, h);
	mtrx_free(answer, h);
	return;
}

void sub()
{
	int w = 0;
	int h = 0;
	cout << "Enter the number of rows : ";
	cin >> h;
	cout << "Enter the number of columns : ";
	cin >> w;
	double** first = mtrx_create(w,h);
	double** second = mtrx_create(w,h);
	cout << "---Enter first matrix values---" << endl;
	mtrx_input(first, w, h);
	cout << "---Enter second matrix values---" << endl;
	mtrx_input(second, w, h);

	double** answer = mtrx_sub(first, second, w, h);
	mtrx_free(first, h);
	mtrx_free(second, h);
	mtrx_txt_display(answer, w, h);
	mtrx_free(answer, h);
	return;
}

void multiply_scalar()
{
	int w = 0;
	int h = 0;
	double number = 1.0;
	cout << "Enter the number of rows : ";
	cin >> h;
	cout << "Enter the number of columns : ";
	cin >> w;
	cout << "Enter the number you want to multiply the matrix with : ";
	cin >> number;
	double** matrix = mtrx_create(w, h);
	cout << "---Enter the matrix values---" << endl;
	mtrx_input(matrix, w, h);


	double** answer = mtrx_multiply_scalar(matrix, w, h, number);
	mtrx_free(matrix, h);
	mtrx_txt_display(answer, w, h);
	mtrx_free(answer, h);
	return;
}

void transpose()
{
	int w = 0;
	int h = 0;
	cout << "Enter the number of rows : ";
	cin >> h;
	cout << "Enter the number of heights : ";
	cin >> w;
	double** matrix = mtrx_create(w, h);
	cout << "---Enter the matrix values---" << endl;
	mtrx_input(matrix, w, h);
	double** answer = mtrx_transpose(matrix, w, h);
	mtrx_free(matrix, h);
	mtrx_txt_display(answer, h, w);
	mtrx_free(answer, w);
	return;

}

void det()
{
	int n = 0;
	cout << "Enter the width and the height of the matrix : ";
	cin >> n;
	double** matrix = mtrx_create(n, n);
	cout << "---Enter the matrix values---" << endl;
	mtrx_input(matrix, n, n);
	
	double answer = mtrx_determinant(matrix, n);
	cout << "The answer is  : " << answer << endl;
	mtrx_free(matrix, n);
	return;
}

void inverse()
{
	int n = 0;
	cout << "Enter the width and height of the matrix : ";
	cin >> n;
	double** matrix = mtrx_create(n, n);
	cout << "--Enter the matrix values---" << endl;
	mtrx_input(matrix, n, n);

	double** answer = mtrx_inverse(matrix, n);
	mtrx_free(matrix, n);
	mtrx_txt_display(answer, n, n);
	mtrx_free(answer, n);
	return;
}
