#include <iostream>
using namespace std;

int main()
{
    // we are making an array of arrays

    // declare a matrix to store the those employe salary
    float *m[10];
    // m is an array of  10 cell's  each  cell is a pointer with type float
    int size;

    // B) allocate memory for each department

    for (int i = 0; i < 10; i++)
    {

        cout << " enter the length of the cell number " << i + 1 << endl;
        cin >> size;
        m[i] = new float[size + 1];
        m[i][0] = size;

        // here we made an array of each cell (m is matrix right now )
    }

    // C) read the matrix salary from the KB
    for (int i = 0; i < 10; i++)
    {
        for (int j = 1; j < m[i][0]; j++)
        {
            cout << "enter the element number " << j << " in the " << i + 1 << " row " << endl;
            cin >> m[i][j];
        }
    }

    // D) De-allocate the occupied memory location

    for (int i = 0; i < 10; i++)
    {
        delete[] m[i];
        m[i] = NULL;
    }
}