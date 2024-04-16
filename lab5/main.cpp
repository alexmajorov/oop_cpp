#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

#define ROWS_MAX 256
#define COLS_MAX 256

class float_matrix
{
public:
    float a, b;
    int rows, cols;
    float **arr = new float*[COLS_MAX];
    float_matrix(string = "input.txt");
    ~float_matrix(void);
    void print(void);
    void read_file(string);
    void write_file(string);
};

class float_matrix_solver : public float_matrix
{
public:
    void reverse_rows(void);
    float_matrix_solver(string = "input.txt");
    ~float_matrix_solver(void);
};

float_matrix::float_matrix(string file_name)
{
    for (int i = 0; i < COLS_MAX; ++i)
        arr[i] = new float[ROWS_MAX];
    ifstream fin(file_name);
    fin >> rows >> cols;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            fin >> arr[i][j];
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

void float_matrix::write_file(string file_name)
{
    ofstream fout(file_name);
    fout << rows << " " << cols << "\n";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            fout << arr[i][j] << " ";
        fout << "\n";
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

float_matrix_solver::float_matrix_solver(string file_name) : float_matrix(file_name) { }

float_matrix_solver::~float_matrix_solver(void) { }

int main(void)
{
    string input_file_name = "input.txt";
    string output_file_name = "output.txt";
    float_matrix_solver arr(input_file_name);
    arr.print();
    arr.reverse_rows();
    cout << "\n";
    arr.print();
    arr.write_file(output_file_name);
    return 0;
}