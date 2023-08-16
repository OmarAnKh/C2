#include <iostream>
#include <string>
using namespace std;
class employee
{
private:
    string name;
    int id;
    float salary;

public:
    employee()
    {
        name = "";
        id = 0;
        salary = 0;
    }
    employee(string name1, int id1, float salary1)
    {
        name = name1;
        id = id1;
        salary = salary1;
    }
    string getName()
    {
        return name;
    }
    int getId()
    {
        return id;
    }
    float getSalary()
    {
        return salary;
    }
    void setName(string name1)
    {
        name = name1;
    }
    void setId(int id1)
    {
        id = id1;
    }
    void setSalary(float salary1)
    {
        salary = salary1;
    }
    float getAnnualSalary()
    {
        return salary * 12;
    }
    string toString()
    {
        string str = "Employee{name=";
        str += name;
        str += ", ID=";
        str += to_string(id);
        str += ", salary=";
        str += to_string(salary);
        str += "}";
        return str;
    }
};

int main()
{

    employee e("omar", 12217955, 5000.12);
    string str = e.toString();
    cout << str << endl;
}