#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char **names;
    int number_of_names;
    cin >> number_of_names;
    number_of_names++;
    names = new char *[number_of_names];
    for (int i = 0; i < number_of_names; i++)
    {
        char *temp = new char[1000];
        cin.getline(temp, 1000);
        names[i] = new char[strlen(temp) + 1];
        strcpy(names[i], temp);
        delete[] temp;
    }
    for (int i = 0; i < number_of_names; i++)
    {
        for (int j = i + 1; j < number_of_names; j++)
        {
            if (strcmp(names[i], names[j]) >= 1)
            {
                char *temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < number_of_names; i++)
    {
        cout << names[i] << endl;
    }
}