#include <iostream>
using namespace std;

class point1
{
private:
    double x, y; // private data members (it will allways be private if we dont spicify it )
public:
    point1(double x0, double y0)
    {
        x = x0;
        y = y0;
        cout << "hello\n";
    }
    point1()
    {
        x = 0;
        y = 0;
        cout << "hello\n";
    }
    double get_x()
    {
        return x;
    }
    double get_y()
    {
        return y;
    }
    void move();
};
void point1 ::move()
{
    double temp = x;
    x = y;
    y = temp;
}
int main()
{
    point1 p1(10, 20);
    point1 p2;
    cout << p1.get_x() << "\t" << p1.get_y() << "\n";
    cout << p2.get_x() << "\t" << p2.get_y() << "\n";
    p1.move();
    cout << p1.get_x() << "\t" << p1.get_y() << "\n";
}