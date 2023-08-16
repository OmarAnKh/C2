#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

struct Students
{
    double number;
    char name[20];
    float marks[5];
};

void read(Students *&a, ifstream &file, int size);

bool failed(float marks[]);

int main()
{
    ifstream file;
    file.open("Students_file");
    if (!file)
    {
        cout << "cant read the file ";
        return 1;
    }
    string temp;
    int counter = 0;
    while (getline(file, temp))
    {
        counter++;
    }
    file.close();

    file.open("Students_file");
    if (!file)
    {
        cout << "cant read the file ";
        return 1;
    }
    Students *students;
    students = new Students[counter];
    read(students, file, counter);

    for (int i = 0; i < counter; i++)
    {
        if (!failed(students[i].marks))
        {
            cout << students[i].name << endl;
        }
    }
    file.close();
    delete[] students;
}

void read(Students *&a, ifstream &file, int size)
{
    for (int i = 0; i < size; i++)
    {
        file >> a[i].number;
        file >> a[i].name;
        for (int j = 0; j < 5; j++)
        {
            file >> a[i].marks[j];
        }
    }
}

bool failed(float marks[])
{
    int counter = 0;
    for (int i = 0; i < 5; i++)
    {
        if (marks[i] < 60)
        {
            counter++;
        }
    }
    if (counter > 1)
    {
        return 1;
    }
    return 0;
}
