#include <iostream>
using namespace std;
void input(int matrix[2][2]);
int **make_the_matrix(int &row, int &culm)
{
    int **matrix;
    cout << "enter the number of row ";
    cin >> row;
    matrix = new int *[row];

    cout << "enter the number of culms ";
    cin >> culm;
    for (int i = 0; i < row; i++)
    {

        matrix[i] = new int[culm]{0};
    }
    return matrix;
}

int **mul(int **matrix1, int **matrix2, int &row, int &culm, int &row1, int &culm1)
{
    int **matrix = new int *[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[culm1]{0};
    }

    if (row1 == culm)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < culm1; j++)
            {
                for (int g = 0; g < row; g++)
                {
                    matrix[i][j] += matrix1[i][g] * matrix2[g][j];
                }
            }
        }
    }
    return matrix;
}

void mul1(int matrix[2][2], int &row, int &culm)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < culm; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    int **first_matrix;
    int **seconed_matrix;
    int **sum;
    int row1;
    int culm1;
    int row2;
    int culm2;
    first_matrix = make_the_matrix(row1, culm1);
    seconed_matrix = make_the_matrix(row2, culm2);

    sum = mul(first_matrix, seconed_matrix, row1, culm1, row2, culm2);
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < culm2; j++)
        {
            cout << sum[row1][culm2] << "\t";
        }
        cout << "\n";
    }
}

void input(int matrix[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "enter the element number " << j + 1 << " in the " << i + 1 << " row \n";
            cin >> matrix[i][j];
        }
    }
}
