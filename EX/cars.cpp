#include <iostream>
#include <cstring>
using namespace std;
struct car
{
    double price;
    char name[100];
};
car *find(car *matrix, int number)
{
    car *min = &matrix[0];
    for (int i = 0; i < number; i++)
    {
        if (matrix[i].price < min->price)
        {
            min = &matrix[i];
        }
    }
    return min;
}

int main()
{
    int number_of_cars;
    cin >> number_of_cars;
    car *cars = new car[number_of_cars + 1];
    for (int i = 0; i < number_of_cars; i++)
    {
        cout << "enter the name of the car\n";
        cin >> cars[i].name;
        cout << "enter the price of it \n";
        cin >> cars[i].price;
    }
    car *cheapest = find(cars, number_of_cars);

    cout << cheapest->name << "\t " << cheapest->price;
}