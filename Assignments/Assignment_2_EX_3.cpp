#include <iostream>
using namespace std;

int sum_of_row(int a[][3], int row);
int sum_of_diagonal(int a[][3]);
int sum_of_colm(int a[][3], int colm);
bool if_magic(int a[][3]);
void input(int a[][3]);

int main()
{
    int to_check[3][3] = {0};
    input(to_check);

    if (if_magic(to_check))
    {
        cout << " its a magic matrix  with a magic constant " << sum_of_row(to_check, 1);
    }
    else
    {
        cout << "its not a matrix";
    }
}

void input(int a[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "enter the value you want for the element " << i + 1 << "  " << j + 1 << endl;
            cin >> a[i][j];
        }
    }
}

bool if_magic(int a[][3])
{
    int row = 0, colm = 0;
    if ((sum_of_row(a, row) == sum_of_row(a, ++row)) &&
        (sum_of_row(a, row) == sum_of_row(a, ++row)) &&
        ((sum_of_row(a, row) == sum_of_colm(a, colm))) &&
        (sum_of_colm(a, colm) == sum_of_colm(a, ++colm)) &&
        (sum_of_colm(a, colm) == sum_of_colm(a, ++colm)) &&
        ((sum_of_colm(a, colm) == sum_of_diagonal(a))))
    {
        return true;
    }
    return false;
}

int sum_of_row(int a[][3], int row)
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum = a[row][i] + sum;
    }
    return sum;
}

int sum_of_colm(int a[][3], int colm)
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum = a[i][colm] + sum;
    }
    return sum;
}

int sum_of_diagonal(int a[][3])
{
    int sum = 0;
    for (int i = 0, j = 2; i < 3; i++, j--)
    {
        sum = a[i][j] + sum;
    }
    return sum;
}
