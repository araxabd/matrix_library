#include "matrix_library.h"
#include <iostream>
#include <fstream>

using namespace std;

ofstream O("./output.html");

void init_html(void);
void add_matrix_to_html(double**, int, int);
void end_html(void);

void multiply(void);
void add(void);
void sub(void);
void multiply_scalar(void);
void transpose(void);
void det(void);
void inverse(void);


int main()
{
	init_html();
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
	}
	end_html();
	return 0;
}


void multiply()
{
	O << "<header>Matrix Multiplication</header>";
	O << "<section>";

	int fw = 0;
	int fh = 0;
	cout << "Enter the number of rows : ";
	cin >> fh;
	cout << "Enter the number of columns : ";
	cin >> fw;

	double** first = mtrx_create(fw, fh);

	if (first == NULL)
		return;
	cout << "---Enter first matrix values---" << endl;
	mtrx_input(first, fw, fh);

	int sw = 0;
	int sh = 0;
	cout << "Enter the number of rows : ";
	cin >> sh;
	cout << "Enter the number of columns : ";
	cin >> sw;

	double** second = mtrx_create(sw, sh);

	if(second == NULL)
		return;
	cout << "---Enter second matrix values---" << endl;
	mtrx_input(second, sw, sh);

	add_matrix_to_html(first, fw, fh);
	O << "<span>*</span>";
	add_matrix_to_html(second, sw, sh);
	O << "<span>=</span>";

	double** answer = mtrx_multiply(first, fw, fh, second, sw, sh);
	if (answer == NULL)
		return;
	mtrx_free(first, fh);
	mtrx_free(second, sh);
	mtrx_txt_display(answer, sw, fh);
	add_matrix_to_html(answer, sw, fh);
	mtrx_free(answer, fh);
	O << "</section>";
	return;
}

void add()
{
	O << "<header>Matrix Addition</header>";
	O << "<section>";
	int w = 0;
	int h = 0;
	cout << "Enter the number of rows : ";
	cin >> h;
	cout << "Enter the number of columns : ";
	cin >> w;
	double** first = mtrx_create(w,h);
	if(first == NULL)
		return;
	double** second = mtrx_create(w,h);
	if(second == NULL)
		return;
	cout << "---Enter first matrix values---" << endl;
	mtrx_input(first, w, h);
	cout << "---Enter second matrix values---" << endl;
	mtrx_input(second, w, h);

	add_matrix_to_html(first, w, h);
	O << "<span>+</span>";
	add_matrix_to_html(second, w, h);
	double** answer = mtrx_add(first, second, w, h);
	if(answer == NULL)
		return;
	mtrx_free(first, h);
	mtrx_free(second, h);
	mtrx_txt_display(answer, w, h);
	O << "<span>=</span>";
	add_matrix_to_html(answer, w, h);
	mtrx_free(answer, h);
	O << "</section>";
	return;
}

void sub()
{
	O << "<header>Matrix Subtraction</header>";
	O << "<section>";
	int w = 0;
	int h = 0;
	cout << "Enter the number of rows : ";
	cin >> h;
	cout << "Enter the number of columns : ";
	cin >> w;

	double** first = mtrx_create(w,h);
	if(first == NULL)
		return;
	double** second = mtrx_create(w,h);
	if(second == NULL)
		return;
	cout << "---Enter first matrix values---" << endl;
	mtrx_input(first, w, h);
	cout << "---Enter second matrix values---" << endl;
	mtrx_input(second, w, h);

	add_matrix_to_html(first, w, h);
	O << "<span>-</span>";
	add_matrix_to_html(second, w, h);
	O << "<span>=</span>";
	double** answer = mtrx_sub(first, second, w, h);
	if(answer == NULL)
		return;
	mtrx_free(first, h);
	mtrx_free(second, h);
	mtrx_txt_display(answer, w, h);
	add_matrix_to_html(answer, w, h);
	mtrx_free(answer, h);
	O << "</section>";
	return;
}

void multiply_scalar()
{
	O << "<header>Matrix Multiplication With Scalar</header>";
	O << "<section>";
	int w = 0;
	int h = 0;
	double number = 1.0;
	cout << "Enter the number of rows : ";
	cin >> h;
	cout << "Enter the number of columns : ";
	cin >> w;
	cout << "Enter the number you want to multiply the matrix with : ";
	cin >> number;
	O << "<span>" << number << " * </span>";
	double** matrix = mtrx_create(w, h);
	if(matrix == NULL)
		return;
	cout << "---Enter the matrix values---" << endl;
	mtrx_input(matrix, w, h);

	add_matrix_to_html(matrix, w, h);
	double** answer = mtrx_multiply_scalar(matrix, w, h, number);
	if (answer == NULL)
		return;
	mtrx_free(matrix, h);
	mtrx_txt_display(answer, w, h);
	O << "<span>=</span>";
	add_matrix_to_html(answer, w, h);
	mtrx_free(answer, h);
	O << "</section>";
	return;
}

void transpose()
{
	O << "<header>Matrix Transpose</header>";
	O << "<section>";
	int w = 0;
	int h = 0;
	cout << "Enter the number of rows : ";
	cin >> h;
	cout << "Enter the number of heights : ";
	cin >> w;
	double** matrix = mtrx_create(w, h);
	if(matrix == NULL)
		return;
	cout << "---Enter the matrix values---" << endl;
	mtrx_input(matrix, w, h);
	O << "<span>A = </span>";
	add_matrix_to_html(matrix, w, h);
	double** answer = mtrx_transpose(matrix, w, h);
	if(answer == NULL)
		return;
	mtrx_free(matrix, h);
	mtrx_txt_display(answer, h, w);
	O << "<span>, A<sup>T</sup> = </span>";
	add_matrix_to_html(answer, h, w);
	mtrx_free(answer, w);
	O << "</section>";
	return;

}

void det()
{
	O << "<header>Determinant</header>";
	O << "<section>";
	int n = 0;
	cout << "Enter the width and the height of the matrix : ";
	cin >> n;
	double** matrix = mtrx_create(n, n);
	if(matrix == NULL)
		return;
	cout << "---Enter the matrix values---" << endl;
	mtrx_input(matrix, n, n);
	
	O << "<table style=\"border-top: 0;border-bottom: 0;\">";
	for(int i=0;i < n;i++)
	{
		O << "<tr>";
		for(int j=0;j<n;j++)
		{
			O << "<td>" << matrix[i][j] << "</td>";
		}
		O << "</tr>";
	}
	O << "</table>";

	double answer = mtrx_determinant(matrix, n);
	if(answer == NULL)
		return;
	cout << "The answer is  : " << answer << endl;
	O << "<span> = " << answer << "</span>";
	mtrx_free(matrix, n);
	O << "</section>";
	return;
}

void inverse()
{
	O << "<header>Matrix Inverse</header>";
	O << "<section>";

	int n = 0;
	cout << "Enter the width and height of the matrix : ";
	cin >> n;
	double** matrix = mtrx_create(n, n);
	if(matrix == NULL)
		return;
	cout << "--Enter the matrix values---" << endl;
	mtrx_input(matrix, n, n);

	O << "<span>A = </span>";
	add_matrix_to_html(matrix, n, n);
	O << "<span>, A<sup>-1</sup> = </span>";

	double** answer = mtrx_inverse(matrix, n);
	if(answer == NULL)
		return;
	mtrx_free(matrix, n);
	mtrx_txt_display(answer, n, n);
	add_matrix_to_html(answer, n, n);
	mtrx_free(answer, n);
	O << "</section>";
	return;
}


void init_html()
{
	O << "<!DOCTYPE html>"
	"<html><head><title>Matrix</title><style>"
"body { background-color:#0a0a0a;color:#b0b0b0;font-size:5rem; }"
"table { border:2px solid white;background-color:#0d0d0d;margin:1rem; }"
"td {padding: 1rem;}"
"section { padding:1rem 0;margin: 0;display:flex;justify-content:center;align-items:center;border-bottom:2px solid white; }"
"</style></head><body>\n";
}

void add_matrix_to_html(double** matrix, int w, int h)
{
	O << "<table>";
	for(int i=0;i < h;i++)
	{
		O << "<tr>";
		for(int j=0;j < w;j++)
		{
			O << "<td>" << matrix[i][j] << "</td>";
		}
		O << "</tr>";
	}
	O << "</table>";
}

void end_html()
{
	O << "</body></html>\n";
	O.close();
}
