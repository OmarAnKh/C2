#include <iostream>
using namespace std;
int main()
{
    int row, colm;
    cin >> row >> colm;
    int **a;
    a = new int *[row];
    for (int i = 0; i < row; i++)
    {
        a[i] = new int[colm]{1};
    }

    int counter = 0;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < colm; j++)
        {
            sum += a[i][j];
        }
        if (sum < 0)
        {
            counter++;
        }
    }
    cout << counter;

    for (int i = 0; i < row; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}