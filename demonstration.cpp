#include "matrix_library.h"
#include <iostream>

using namespace std;

void multiply(void);
void add(void);


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
			case 'a':
				add();
				break;
			case 'e':
				exit_flag = true;
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

	int** first = mtrx_create(fw, fh);

	cout << "---Enter first matrix values---" << endl;
	mtrx_input(first, fw, fh);


	int sw = 0;
	int sh = 0;
	cout << "Enter the number of rows : ";
	cin >> sh;
	cout << "Enter the number of columns : ";
	cin >> sw;

	int** second = mtrx_create(sw, sh);

	cout << "---Enter second matrix values---" << endl;
	mtrx_input(second, sw, sh);




	int** answer = mtrx_multiply(first, fw, fh, second, sw, sh);
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
	int **first = mtrx_create(w,h);
	int **second = mtrx_create(w,h);
	cout << "---Enter first matrix values---" << endl;
	mtrx_input(first, w, h);
	cout << "---Enter second matrix values---" << endl;
	mtrx_input(second, w, h);

	int** answer = mtrx_add(first, second, w, h);
	mtrx_free(first, h);
	mtrx_free(second, h);
	mtrx_txt_display(answer, w, h);
	mtrx_free(answer, h);
	return;
}
