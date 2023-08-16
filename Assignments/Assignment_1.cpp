#include <iostream>
using namespace std;

void add(int id[], int salary[], int phone_number[], int size);
int search(int id[], int salary[], int phone_number[], int size);
int to_check(int cells);
int *add_one(int arr[], int oldSize);
int *delete_one(int arr[], int id[], int oldSize, int index);

int main()
{
    int *ID = new int[3]{11, 12, 13};
    int *salary = new int[3]{100, 150, 250};
    int *phone_number = new int[3]{2388888, 2377777, 2355555};
    int operation = 0, cells = 3, index;

    cout << "pleas choose the  operation code you want to make :\n1-add  2-delete  3-search  4-Exit : \n";
    cin >> operation;
    while (operation < 0 && operation > 4)
    {
        cout << "you have entered a wrong operation code, pleas try again\n";
        cin >> operation;
    }

    while (operation != 4)
    {
        if (operation == 1)
        {

            ID = add_one(ID, cells);
            salary = add_one(salary, cells);
            phone_number = add_one(phone_number, cells);
            add(ID, salary, phone_number, cells);
            cells++;
        }

        else if (operation == 2)
        {
            cout << "which salesman id that you want to delete \n";
            cin >> index;
            ID = delete_one(ID, ID, cells, index);
            salary = delete_one(salary, ID, cells, index);
            phone_number = delete_one(phone_number, ID, cells, index);
        }
        else if (operation == 3)
        {
            cout << "what is the id of the salesman you want to search for \n";
            cin >> cells;

            if (to_check(cells) == 0)
            {
                if (search(ID, salary, phone_number, cells) == 0)
                {
                    cout << "does not exist\n";
                }
            }
            else
            {
                cout << "sorry this worker is not in the company\n ";
            }
        }
        cout << "pleas choose the  operation code you want to make : \n1-add  2-delete  3-search  4-Exit : ";
        cin >> operation;
    }
}
void add(int id[], int salary[], int phone_number[], int size)
{

    id[size] = ((id[size - 1]) + 1);
    cout << "enter his/her salary\n";
    cin >> salary[size];
    cout << "enter his/her phone number\n";
    cin >> phone_number[size];
}

int search(int id[], int salary[], int phone_number[], int size)
{
    for (int i = 0; i < 20; i++)
    {
        if (id[i] == size)
        {
            cout << "this is his/her salary " << salary[i] << endl;
            cout << "this is his/here phone number " << phone_number[i] << endl;
            return 1;
        }
    }

    return 0;
}

int *add_one(int arr[], int oldSize)
{
    int *temp = new int[oldSize + 1];
    for (int i = 0; i < oldSize; i++)
    {
        temp[i] = arr[i];
    }

    delete[] arr;
    arr = NULL;

    return temp;
}

int *delete_one(int arr[], int id[], int oldSize, int index)
{
    int *temp = new int[oldSize - 1];
    for (int i = 0; i < oldSize; i++)
    {
        if (id[i] != index)
        {
            temp[i] = arr[i];
        }
    }
    delete[] arr;
    arr = NULL;
    return temp;
}
int to_check(int cells)
{
    if (cells > 19 || cells < 0)
    {
        return 1;
    }
    return 0;
}