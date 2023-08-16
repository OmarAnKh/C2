#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

class Country
{
private:
    char *country;
    double area;
    int population;

public:
    Country(const char *name = nullptr, double area1 = 1, int pop = 1)
    {
        if (name)
        {
            country = new char[strlen(name) + 1];
            strcpy(country, name);
        }
        else
        {
            country = nullptr;
        }

        area = area1;
        population = pop;
    }
    Country(const Country &a)
    {
        if (this->country)
        {
            delete[] this->country;
        }
        this->country = new char[strlen(a.country) + 1];
        strcpy(this->country, a.country);
        this->area = a.area;
        this->population = a.population;
    }
    ~Country()
    {
        if (country)
        {
            delete[] country;
        }
        this->country = nullptr;
    }
    char *getcountry()
    {
        return country;
    }

    double getArea()
    {
        return area;
    }

    int getpop()
    {
        return population;
    }
    void setcountry(const char *name)
    {
        if (country)
        {
            delete[] country;
        }
        country = new char[strlen(name) + 1];
        strcpy(country, name);
    }
    void setArea(double area1)
    {
        area = area1;
    }
    void setPop(int pop)
    {
        population = pop;
    }

    Country &operator=(const Country &a)
    {
        if (this->country)
        {
            delete[] this->country;
        }
        this->country = new char[strlen(a.country) + 1];
        strcpy(this->country, a.country);
        this->area = a.area;
        this->population = a.population;
        return *this;
    }
};
Country largestArea(Country temp[], int size);
Country largestPop(Country temp[], int size);
Country largestdin(Country temp[], int size);
int main()
{
    Country *country;
    int size = 0;
    cout << "enter the number of country's\n";
    cin >> size;
    country = new Country[size];

    for (int i = 0; i < size; i++)
    {
        char countryName[100];
        double areaSize;
        int Pop;
        cout << "enter the country name followed by the area size followed by the population\n";
        cin >> countryName >> areaSize >> Pop;
        country[i].setcountry(countryName);
        country[i].setArea(areaSize);
        country[i].setPop(Pop);
    }

    Country temp = largestArea(country, size);
    cout << temp.getcountry() << "\t" << temp.getArea() << "\t" << temp.getpop();

    delete[] country;
}

Country largestArea(Country temp[], int size)
{
    Country tepmArea = temp[0];
    int largest = 0;
    for (int i = 0; i < size; i++)
    {
        if (tepmArea.getArea() < temp[i].getArea())
        {
            tepmArea = temp[i];
        }
    }
    return tepmArea;
}
Country largestPop(Country temp[], int size)
{
    Country tepmPop = temp[0];
    int largest = 0;
    for (int i = 0; i < size; i++)
    {
        if (tepmPop.getpop() < temp[i].getpop())
        {
            tepmPop = temp[i];
        }
    }
    return tepmPop;
}
Country largestdin(Country temp[], int size)
{
    double tempdin = temp[0].getpop() / temp[0].getArea();
    Country temp1 = temp[0];
    int largest = 0;
    for (int i = 0; i < size; i++)
    {
        if (tempdin < (temp[i].getpop() / temp[i].getArea()))
        {
            temp1 = temp[i];
        }
    }
    return temp1;
}