#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

class float_matrix
{
public:
	float a, b;
	int rows, cols;
	float **arr;
	float_matrix(int = 5, int = 7, float = -20.0, float = 20.0);
	~float_matrix(void);
	void print(void);
};

class float_matrix_solver : public float_matrix
{
public:
	void reverse_rows(void);
	float_matrix_solver(int = 5, int = 7, float = -20.0, float = 20.0);
	~float_matrix_solver(void);
};

float_matrix::float_matrix(int rows_, int cols_, float a_, float b_)
{
	a = a_; b = b_;
	rows = rows_;
	cols = cols_;
	arr = new float *[rows];
	for (int i = 0; i < rows; ++i) 
		arr[i] = new float [cols];
	
	srand((unsigned int)time(0));

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
		{
			float temp = ((float)(rand() % 100)) / 100;
			arr[i][j] = (b - a) * temp + a;
		}
}

float_matrix::~float_matrix(void)
{
	for (int i = 0; i < rows; ++i)
		delete[] arr[i];
	delete[] arr;
}

void float_matrix::print(void)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	return;
}

void float_matrix_solver::reverse_rows(void)
{
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols / 2; ++j)
		{
			float tmp = arr[i][j];
			arr[i][j] = arr[i][cols - j - 1];
			arr[i][cols - j - 1] = tmp;
		}
	return;
}

float_matrix_solver::float_matrix_solver(int rows_, int cols_, float a_, float b_) : float_matrix(rows_, cols_, a_, b_) { }

float_matrix_solver::~float_matrix_solver(void) { }

int main(void)
{
	int n, m;
	cout << "Insert n: "; cin >> n;
	cout << "Insert m: "; cin >> m;
	float_matrix_solver arr(m, n);
	arr.print();
	
	arr.reverse_rows();

	cout << "\n";
	arr.print();
	return 0;
}