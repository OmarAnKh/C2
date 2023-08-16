#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <fstream>
#include <string.h>

using namespace std;

class Employee
{
protected:
    string name;
    int hireYear;

public:
    Employee(string name1 = "\0", int year = 0)
    {
        name = name1;
        hireYear = year;
    }
    virtual double monthlyPay()
    {
        return 0;
    }
    virtual double annualPay()
    {
        return 0;
    }
    virtual void printInfo()
    {
        cout << name << "\t"
             << "Monthly\tPay:" << monthlyPay() << "\t"
             << "Annual\tPay: " << annualPay() << endl
             << endl;
    }
};
class SalariedEmployee : public Employee
{
protected:
    int annualSalary;

public:
    SalariedEmployee(string name1 = "\0", int year = 0, int temp = 0) : Employee(name1, year)
    {
        annualSalary = temp;
    }
    double monthlyPay()
    {
        return annualSalary / 12;
    }
    void printInfo()
    {
        cout << name << "\t"
             << "Monthly\tPay:" << monthlyPay() << "\t"
             << "Annual\tPay: " << annualPay() << endl
             << endl;
    }
};
class HourlyEmployee : public Employee
{
protected:
    int hoursPerWeek;
    double HourlyWage;

public:
    HourlyEmployee(string name1 = "\0", int year = 0, int hours = 0, double wage = 0) : Employee(name1, year)
    {
        hoursPerWeek = hours;
        HourlyWage = wage;
    }
    double monthlyPay()
    {
        return hoursPerWeek * 4 * HourlyWage;
    }
    void printInfo()
    {
        cout << name << "\t"
             << "Monthly\tPay:" << monthlyPay() << "\t"
             << "Annual\tPay: " << annualPay() << endl
             << endl;
    }
};
class Manager : public SalariedEmployee
{
public:
    Manager(string name1 = "\0", int year = 0, int temp = 0) : SalariedEmployee(name1, year, temp)
    {
    }
    double annualPay()
    {
        return annualSalary + (10 / annualSalary * 100);
    }
    void printInfo()
    {
        cout << name << "\t"
             << "Monthly\tPay:" << monthlyPay() << "\t"
             << "Annual\tPay: " << annualPay() << endl
             << endl;
    }
};
class Staff : public SalariedEmployee
{
public:
    Staff(string name1 = "\0", int year = 0, int temp = 0) : SalariedEmployee(name1, year, temp)
    {
    }
    double annualPay()
    {
        time_t t = time(nullptr);
        tm *const pTInfo = localtime(&t);
        if ((1900 + pTInfo->tm_year) - hireYear >= 5)
        {
            return annualSalary + (annualSalary / 10 * 100);
        }
        else if ((1900 + pTInfo->tm_year) - hireYear == 4)
        {
            return annualSalary + (annualSalary / 8 * 100);
        }
        else if ((1900 + pTInfo->tm_year) - hireYear == 3)
        {
            return annualSalary + (annualSalary / 6 * 100);
        }
        else if ((1900 + pTInfo->tm_year) - hireYear == 2)
        {
            return annualSalary + (annualSalary / 4 * 100);
        }
        else if ((1900 + pTInfo->tm_year) - hireYear == 1)
        {
            return annualSalary + (annualSalary / 2 * 100);
        }
        else
        {
            return annualSalary;
        }
    }
    void printInfo()
    {
        cout << name << "\t"
             << "Monthly\tPay:" << monthlyPay() << "\t"
             << "Annual\tPay: " << annualPay() << endl
             << endl;
    }
};
class FullTime : public HourlyEmployee
{
public:
    FullTime(string name1 = "\0", int year = 0, int hours = 0, double wage = 0) : HourlyEmployee(name1, year, hours, wage)
    {
    }
    double annualPay()
    {
        return (50 * HourlyWage + 2 * HourlyWage);
    }
    void printInfo()
    {
        cout << name << "\t"
             << "Monthly\tPay:" << monthlyPay() << "\t"
             << "Annual\tPay: " << annualPay() << endl
             << endl;
    }
};
class PartTime : public HourlyEmployee
{
public:
    PartTime(string name1 = "\0", int year = 0, int hours = 0, double wage = 0) : HourlyEmployee(name1, year, hours, wage)
    {
    }
    double annualPay()
    {
        return (50 * HourlyWage);
    }
    void printInfo()
    {
        cout << name << "\t"
             << "Monthly\tPay:" << monthlyPay() << "\t"
             << "  Annual\tPay: " << annualPay() << endl
             << endl;
    }
};
string toLower(string str);

int main()
{
    ifstream Employee_s;
    Employee_s.open("emp_project");
    if (!Employee_s.is_open())
    {
        return 0;
    }
    string line;
    int counter = 0;
    while (getline(Employee_s, line))
    {
        counter++;
    }
    Employee_s.close();
    Employee_s.open("emp_project");
    Employee **workers = new Employee *[counter];
    string type;
    string name;
    int year;
    double pay;
    int workHours;
    for (int i = 0; i < counter; i++)
    {
        Employee_s >> type;
        type = toLower(type);
        if (type == "staff")
        {
            Employee_s >> name;
            Employee_s >> year;
            Employee_s >> pay;
            workers[i] = new Staff(name, year, pay);
        }
        else if (type == "manager")
        {
            Employee_s >> name;
            Employee_s >> year;
            Employee_s >> pay;
            workers[i] = new Manager(name, year, pay);
        }
        else if (type == "parttime")
        {
            Employee_s >> name;
            Employee_s >> year;
            Employee_s >> workHours;
            Employee_s >> pay;
            workers[i] = new PartTime(name, year, workHours, pay);
        }
        else if (type == "fulltime")
        {
            Employee_s >> name;
            Employee_s >> year;
            Employee_s >> workHours;
            Employee_s >> pay;
            workers[i] = new FullTime(name, year, workHours, pay);
        }
        else
        {
            cout << "error in job position ";
            return 0;
        }
    }

    for (int i = 0; i < counter; i++)
    {
        workers[i]->printInfo();
    }
}

string toLower(string str)
{
    string temp = str;
    for (int i = 0; temp[i]; i++)
    {
        if (temp[i] >= 'A' && temp[i] <= 'Z')
        {
            temp[i] = temp[i] + 32;
        }
    }
    return temp;
}