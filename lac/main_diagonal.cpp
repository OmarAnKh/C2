#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
int returnIndex(int* array, int size, int number) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (number <= array[i]) {
            index = i + 1;
            break;
        }
    }
    return index;
}
bool cheakElement(int* array, int size, int number) {
    for (int i = 0; i < size; i++) {
        if (number == array[i]) {
            return true;
        }
    }
    return false;
}


using namespace std;

int main()
{
    int cells;
    cin >> cells;
    int *arr = new int[cells];
    for (int i = 0; i < cells; i++)
    {
        cin >> arr[i];
    }
    int numbers,number;

    cin >> numbers;
    sort(arr, arr + cells);
    int *search_for = new int[numbers];
    string *exist = new string[numbers];


for (int i = 0; i < numbers; i++) {
        cin >> number;
        int index1;
        index1 = returnIndex(arr, cells, number);
        if (cheakElement(arr, cells, number)) {
            exist[i] = "Yes";
            search_for[i] = index1;
        }
        else {
            exist[i] = "No";
            search_for[i] = index1;
        }

    }
    for (int i = 0; i < numbers; i++) {
        cout << exist[i] << " " << search_for[i] << endl;
    }

    

    return 0;
}
