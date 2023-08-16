#include <iostream>
#include <fstream>

using namespace std;

class Circle
{
public:
    // data
    double radius;
    const double PI = 22 / 7.0;
    // operation
    double getDig()
    {
        return 2 * radius;
    }
    double getArea()
    {
        return radius * radius * PI;
    }
    double getCirum()
    {
        return 2 * radius * PI;
    }
};

int main()
{
    fstream circleFile;
    Circle c;
    circleFile.open("C:\\Users\\Omark\\Documents\\VS\\university\\C2\\classes\\data_for_the_first_class", ios::out);
    if (!circleFile.is_open())
    {
        cout << "1";
        return 0;
    }
    cout << "Enter the radius" << endl;
    cin >> c.radius;
    circleFile << c.getDig() << endl;
    circleFile << "The area is " << c.getArea() << endl;
    circleFile << "The cirum is " << c.getCirum() << endl;
    circleFile.close();

    circleFile.open("C:\\Users\\Omark\\Documents\\VS\\university\\C2\\classes\\data_for_the_first_class", ios::in);
    if (!circleFile.is_open())
    {
        cout << "1";
        return 0;
    }
    float a;
    circleFile >> a;
    
}