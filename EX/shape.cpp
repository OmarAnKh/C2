#include <iostream>
#include <math.h>
using namespace std;
class Shape
{

public:
    Shape()
    {
        cout << "Shape const" << endl;
    }
    virtual double calculateArea()
    {

        cout << "shape cal";
        return 0;
    }
    virtual ~Shape()
    {
        cout << "Shape des";
    }
};
class Circle : public Shape
{
private:
    double r;

public:
    double calculateArea()
    {
        cout << "Circle cal";
        return (3.14 * pow(r, 2));
    }
    Circle(double r1 = 0)
    {
        cout << "Circle const" << endl;
        r = r1;
    }
    ~Circle()
    {
        cout << "Circle des";
    }
};
class Rectangle : public Shape
{
private:
    double W;
    double l;

public:
    double calculateArea()
    {
        cout << "Rectangle cal" << endl;
        return (l * W);
    }
    Rectangle(double l1 = 0, double w1 = 0)
    {
        cout << "Rectangle const" << endl;
        W = w1;
        l = l1;
    }
    ~Rectangle()
    {
        cout << "Rectangle des";
    }
};

int main()
{
    Shape **matrix;
    matrix = new Shape *[10];
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            matrix[i] = new Circle(i);
        }
        else
        {
            matrix[i] = new Rectangle(i, i);
        }
    }
    cout << matrix[5]->calculateArea() << endl;
    for (int i = 0; i < 10; i++)
    {
        delete matrix[i];
    }
    delete[] matrix;
}