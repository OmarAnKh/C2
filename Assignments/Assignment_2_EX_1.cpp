#include <iostream>
using namespace std;

int find_min(int a[]);
void input_array(int a[]);
void subtrac_elements(int a[], int b[], int smaller);
void print_array(int subtract_array[]);

int main()
{
    int array[5] = {0};
    int subtract_array[5] = {0};
    input_array(array);
    int min_num = find_min(array);
    subtrac_elements(array, subtract_array, min_num);
    print_array(subtract_array);
}

void input_array(int a[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << "enter the element number " << i + 1 << endl;
        cin >> a[i];
    }
}

int find_min(int a[])
{
    int number = a[0];
    for (int i = 1; i < 5; i++)
    {
        if (a[i] < number)
        {
            number = a[i];
        }
    }
    return number;
}

void subtrac_elements(int a[], int b[], int smaller)
{
    for (int i = 0; i < 5; i++)
    {
        b[i] = smaller - a[i];
    }
}

void print_array(int subtract_array[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << subtract_array[i] << endl;
    }
}