#include <iostream>
#include <cmath>

using namespace std;

struct points
{
    float x;
    float y;
};

void read_points(points point[], int number);
float find_dis(points point, points point2);
void calculate_dis(points point[], int number, float **dis);

int main()
{
    int number_of_points;
    cin >> number_of_points;
    points *point = new points[number_of_points];
    read_points(point, number_of_points);
    float **dis;
    dis = new float *[number_of_points];
    for (int i = 0; i < number_of_points; i++)
    {
        dis[i] = new float[number_of_points];
    }
    calculate_dis(point, number_of_points, dis);
    for (int i = 0; i < number_of_points; i++)
    {
        for (int j = 0; j < number_of_points; j++)
        {
            cout << dis[i][j] << "      ";
        }
        cout << endl;
    }
}

void read_points(points point[], int number)
{
    for (int i = 0; i < number; i++)
    {
        cout << "enter the X point \n";
        cin >> point[i].x;
        cout << "enter the Y point \n";
        cin >> point[i].y;
    }
}

float find_dis(points point, points point2)
{

    float dis;
    dis = sqrt(pow((point.x - point2.x), 2) + pow((point.y - point2.y), 2));
    return dis;
}

void calculate_dis(points point[], int number, float **dis)
{
    for (int i = 0; i < number ; i++)
    {
        for (int j = 0; j < number; j++)
        {
            dis[i][j] = find_dis(point[i], point[j]);
        }
    }
}