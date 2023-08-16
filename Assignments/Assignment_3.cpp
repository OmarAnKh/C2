#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
#define max_size 1000
struct Cars
{
    int id;
    char comp[20];
    char model[20];
    int year;
    char color[20];
    int engine;
    int price;
};
void stor_data(Cars *car, int number);
int show_menu();
int if_exist(Cars *car, int size, int id);
void updateRec(Cars *car, int size);
void add_record(Cars *car, int &size);
void delete_record(Cars *&car, int &size);
void display(Cars *car, int size);
void display_by_price(Cars *car, int size, int price);
void display_by_price(Cars *car, int size);
void display_by_ID(Cars *car, int size);
void save(Cars *car, int size, ofstream &Cars_catalog);
void display_by_year(Cars *car, int size, int year);
void display_by_model(Cars *car, int size, char *model);
int main()
{
    fstream Cars_catalog;
    Cars_catalog.open("Assignment_3_text_file", ios::in);
    if (!Cars_catalog.is_open())
    {
        cout << " the shop is closed";
        return 1;
    }
    int a;
    Cars_catalog >> a;
    Cars *car = new Cars[max_size];
    for (int i = 0; i < a; i++)
    {
        Cars_catalog >> car[i].id;
        Cars_catalog >> car[i].comp;
        Cars_catalog >> car[i].model;
        Cars_catalog >> car[i].year;
        Cars_catalog >> car[i].color;
        Cars_catalog >> car[i].engine;
        Cars_catalog >> car[i].price;
    }
    int operation = show_menu();
    Cars_catalog.close();
    ofstream Cars_catalog1;
    Cars_catalog1.open("Assignment_3_text_file", ios::in);
    while (operation != 11)
    {
        if (operation == 1)
        {
            add_record(car, a);
        }
        else if (operation == 2)
        {
            delete_record(car, a);
        }
        else if (operation == 3)
        {
            updateRec(car, a);
        }
        else if (operation == 4)
        {
            display(car, a);
        }
        else if (operation == 5)
        {
            float price;
            cout << "enter the price\n";
            cin >> price;
            display_by_price(car, a, price);
        }
        else if (operation == 6)
        {
            char model[100];
            cin >> model;
            display_by_model(car, a, model);
        }
        else if (operation == 7)
        {
            display_by_price(car, a);
        }
        else if (operation == 8)
        {
            int year;
            cout << "enter the year of the car ";
            cin >> year;
            display_by_year(car, a, year);
        }
        else if (operation == 9)
        {
            save(car, a, Cars_catalog1);
        }
        else if (operation == 10)
        {
            display_by_ID(car, a);
        }
        int yes_or_no;
        cout << "do u want to see the operations menu? (1) for yes and (0) for no \n";
        cin >> yes_or_no;
        if (yes_or_no == 0)
        {
            Cars_catalog.close();
            return 0;
        }
        operation = show_menu();
        if (operation == 11)
        {
            Cars_catalog.close();
            return 0;
        }
    }
}

int show_menu()
{
    cout << "what do you want to do today" << endl;
    int ope;
    cout << "1) Add a car record\n";
    cout << "2) Delete a car record\n";
    cout << "3) Update a car record\n";
    cout << "4) view all car records \n";
    cout << "5) view Cars with price less than value \n";
    cout << "6) view Cars by  car make\n";
    cout << "7) view all Cars sorted by price\n";
    cout << "8) view all Cars sorted by year\n";
    cout << "9) save\n";
    cout << "10) view all Cars sorted by ID\n";
    cout << "11) quit\n";
    cin >> ope;
    return ope;
}
void updateRec(Cars *car, int size)
{
    cout << "enter the ID of the car you want to update it \n";
    int ID;
    cin >> ID;

    ID = if_exist(car, size, ID);
    if (ID != -1)
    {
        stor_data(car, ID);
    }
}

int if_exist(Cars *car, int size, int id)
{
    for (int i = 0; i < size; i++)
    {
        if (car[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void add_record(Cars *car, int &size)
{
    stor_data(car, size);
    size++;
}

void stor_data(Cars *car, int number)
{
    Cars temp;
    cout << "enter the ID of the car\n";
    cin >> temp.id;
    cout << "enter the company that made the car\n";
    cin >> temp.comp;
    cout << "enter the model of the car\n";
    cin >> temp.model;
    cout << "enter the year the car was maden\n";
    cin >> temp.year;
    cout << "enter the color of the car\n";
    cin >> temp.color;
    cout << "enter the engine of the car\n";
    cin >> temp.engine;
    cout << "enter the price of the car \n";
    cin >> temp.price;
    cout << temp.id << "\t";
    cout << temp.comp << "\t";
    cout << temp.model << "\t";
    cout << temp.year << "\t";
    cout << temp.color << "\t";
    cout << temp.engine << "\t";
    cout << temp.price << "\t";
    cout << "\n";
    int con;
    cout << "enter 1 if u want to confirm the operation or 0 to cancel it\n";
    cin >> con;
    if (con == 1)
    {
        car[number] = temp;
    }
}

void delete_record(Cars *&car, int &size)
{

    int ID;
    cout << "enter the ID of the car you want to delete \n";
    cin >> ID;
    Cars *temp = new Cars[size - 1];
    for (int i = 0, k = 0; i < size; i++)
    {
        if (car[i].id != ID)
        {
            temp[k] = car[i];
            k++;
        }
        else
        {
            cout << car[i].comp << "\t";
            cout << car[i].model << "\t";
            cout << car[i].year << "\t";
            cout << car[i].color << "\t";
            cout << car[i].engine << "\t";
            cout << car[i].price << "\t";
            cout << "\n";
        }
    }

    int con;
    cout << "enter 1 if u want to confirm the operation or 0 to cancel it\n";
    cin >> con;
    if (con == 1)
    {
        --size;
        delete[] car;
        car = temp;
    }
}

void display(Cars *car, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << car[i].id << "\t";
        cout << car[i].comp << "\t";
        cout << car[i].model << "\t";
        cout << car[i].year << "\t";
        cout << car[i].color << "\t";
        cout << car[i].engine << "\t";
        cout << car[i].price << "\t";
        cout << "\n";
    }
}

void display_by_price(Cars *car, int size, int price)
{
    for (int i = 0; i < size; i++)
    {
        if (car[i].price < price)
        {
            cout << car[i].id << "\t";
            cout << car[i].comp << "\t";
            cout << car[i].model << "\t";
            cout << car[i].year << "\t";
            cout << car[i].color << "\t";
            cout << car[i].engine << "\t";
            cout << car[i].price << "\t";
            cout << "\n";
        }
    }
}

void display_by_model(Cars *car, int size, char *model)
{

    for (int i = 0; i < size; i++)
    {
        if (!strcmp(car[i].model, model))
        {
            cout << car[i].id << "\t";
            cout << car[i].comp << "\t";
            cout << car[i].model << "\t";
            cout << car[i].year << "\t";
            cout << car[i].color << "\t";
            cout << car[i].engine << "\t";
            cout << car[i].price << "\t";
            cout << "\n";
        }
    }
}

void display_by_year(Cars *car, int size, int year)
{

    for (int i = 0; i < size; i++)
    {
        if (car[i].year == year)
        {
            cout << car[i].id << "\t";
            cout << car[i].comp << "\t";
            cout << car[i].model << "\t";
            cout << car[i].year << "\t";
            cout << car[i].color << "\t";
            cout << car[i].engine << "\t";
            cout << car[i].price << "\t";
            cout << "\n";
        }
    }
}
void display_by_ID(Cars *car, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (car[j].id > car[j + 1].id)
            {
                Cars temp1 = car[j];
                car[j] = car[j + 1];
                car[j + 1] = temp1;
            }
        }
    }
    display(car, size);
}
void display_by_price(Cars *car, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (car[j].price > car[j + 1].price)
            {
                Cars temp1 = car[j];
                car[j] = car[j + 1];
                car[j + 1] = temp1;
            }
        }
    }
    display(car, size);
}

void save(Cars *car, int size, ofstream &Cars_catalog)
{

    Cars_catalog << size << endl;
    for (int i = 0; i < size; i++)
    {

        Cars_catalog << car[i].id << "\t";
        Cars_catalog << car[i].comp << "\t";
        Cars_catalog << car[i].model << "\t";
        Cars_catalog << car[i].year << "\t";
        Cars_catalog << car[i].color << "\t";
        Cars_catalog << car[i].engine << "\t";
        Cars_catalog << car[i].price << "\n";
    }
}