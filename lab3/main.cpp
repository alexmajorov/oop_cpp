#include <iostream>
#include <stdlib.h>
#include <ctime>

using std::cout;
using std::cin;

template <typename T> class float_matrix
{
public:
	T a, b;
	int rows, cols;
	T **arr;
	float_matrix(int = 5, int = 7, T = -20.0, T = 20.0);
	~float_matrix(void);
	void print(void);
};

template <typename T> 
class float_matrix_solver : public float_matrix<T>
{
public:
	void reverse_rows(void);
	float_matrix_solver(int = 5, int = 7, T = -20.0, T = 20.0);
	~float_matrix_solver(void);
};

template <typename T>
float_matrix<T>::float_matrix(int rows_, int cols_, T a_, T b_)
{
	a = a_; b = b_;
	rows = rows_;
	cols = cols_;
	arr = new T *[rows];
	for (int i = 0; i < rows; ++i)
		arr[i] = new T[cols];

	srand((unsigned int)time(0));

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
		{
			float temp = (rand() % 100) / 100.0f;
			arr[i][j] = (T)((b - a) * temp + a);
		}
}

template <typename T>
float_matrix<T>::~float_matrix(void)
{
	for (int i = 0; i < rows; ++i)
		delete[] arr[i];
	delete[] arr;
}


template <typename T>
void float_matrix<T>::print(void)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	return;
}

template <typename T>
void float_matrix_solver<T>::reverse_rows(void)
{
	for (int i = 0; i < this->rows; ++i)
		for (int j = 0; j < this->cols / 2; ++j)
		{
			T tmp = this->arr[i][j];
			this->arr[i][j] = this->arr[i][this->cols - j - 1];
			this->arr[i][this->cols - j - 1] = tmp;
		}
	return;
}

template <typename T>
float_matrix_solver<T>::float_matrix_solver(int rows_, int cols_, T a_, T b_) : float_matrix<T>::float_matrix(rows_, cols_, a_, b_) { }

template <typename T>
float_matrix_solver<T>::~float_matrix_solver(void) { }

int main(void)
{
	int n, m;
	cout << "Insert n: "; cin >> n;
	cout << "Insert m: "; cin >> m;
	float_matrix_solver<float> arr(m, n);
	arr.print();

	arr.reverse_rows();

	cout << "\n";
	arr.print();
	return 0;
}