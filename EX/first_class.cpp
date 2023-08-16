#include <iostream>
#include <cmath>
using namespace std;
#define pi 3.14
class circle
{

public:
    float raduis;

    float getdig()
    {
        return raduis * 2;
    }
    float getArea()
    {
        return (pow(raduis, 2) * pi);
    }
    float getCircum()
    {
        return (2 * pi * raduis);
    }
};

int main()
{
    circle first_circle;
    cin >> first_circle.raduis;
    cout << first_circle.getdig();
}
