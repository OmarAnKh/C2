#include <cmath>
#include <iostream>
using namespace std;
void creat_matrix(int **&matrix, int row, int culm);
void input_matrix(int **&matrix, int row, int culm);
void print_matrix(int **matrix, int row, int culm);
int find_size_of_new_matrix(int row, int culm);
void mov_matrix(int **matrixB, int **&matrixC, int row, int culm);

int main()
{
    int row, culm;
    cout << "enter the many of row you want ";
    cin >> row;
    cout << "enter the many of culm you want ";
    cin >> culm;
    int **matrixA;
    creat_matrix(matrixA, row, culm);
    input_matrix(matrixA, row, culm);
    int size_of_new_matrix = find_size_of_new_matrix(row, culm);
    int **matrixC;
    creat_matrix(matrixC, size_of_new_matrix, size_of_new_matrix);
    mov_matrix(matrixA, matrixC, row, culm);
    print_matrix(matrixC, size_of_new_matrix, size_of_new_matrix);
}

void creat_matrix(int **&matrix, int row, int culm)
{

    matrix = new int *[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[culm]{0};
    }
}

void input_matrix(int **&matrix, int row, int culm)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < culm; j++)
        {
            cout << "enter the element number " << j + 1 << " in the " << i + 1 << " row ";
            cin >> matrix[i][j];
        }
    }
}



void print_matrix(int **matrix, int row, int culm)
{
    for (int i = 0; i < culm; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

int find_size_of_new_matrix(int row, int culm)
{
    int size = row * culm;
    for (int i = 2; i < pow(size, 2); i++)
    {
        if (size <= pow(i, 2))
        {
            return i;
        }
    }
    return 0;
}

void mov_matrix(int **matrixB, int **&matrixC, int row, int culm)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < culm; j++)
        {
            matrixC[i][j] = matrixB[i][j];
        }
    }
}