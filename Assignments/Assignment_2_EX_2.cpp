#include <iostream>
using namespace std;

bool find(int a[], int number);
void input_array(int a[]);

int main()
{
    int to_search[5] = {0};
    int to_find;
    input_array(to_search);
    cout << "enter the numebr you want to search for \n";
    cin >> to_find;
    if (find(to_search, to_find))
    {
        cout << to_find << " is in the array";
    }
    else
    {
        cout << "the number is not in the array";
    }
}

bool find(int a[], int number)
{
    for (int i = 0; i < 5; i++)
    {
        if (a[i] == number)
        {
            return true;
        }
    }
    return false;
}

void input_array(int a[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << "enter the element number " << i + 1 << endl;
        cin >> a[i];
    }
}
