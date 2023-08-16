#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int cells;
    cin >> cells;
    int *arr = new int[cells];
    for (int i = 0; i < cells; i++)
    {
        cout << "enter the value of the element number " << i + 1;
        cin >> arr[i];
    }
    int numbers;
    cout << "enter the number of numbers you want to search for ";
    cin >> numbers;
    sort(arr, arr + cells);
    int *search_for = new int[numbers];
    for (int i = 0; i < numbers; i++)
    {
        cout << "enter the number to search for";
        cin >> search_for[i];
    }
    string *exist = new string[numbers];
    for (int i = 0; i < numbers; i++)
    {
        if (search_for[i] == arr[i])
        {
            search_for[i] = i;
            exist[i] = "Yes";
        }
        else if (search_for[i] != arr[i])
        {
            search_for[i] = i + 1;
            exist[i] = "NO";
        }
    }
    for (int i = 0; i < numbers; i++)
    {
        cout << exist[i] << "\t" << search_for[i] << endl;
    }
    return 0;
}
