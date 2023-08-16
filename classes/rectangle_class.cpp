#include <iostream>
using namespace std;
class Rectangle
{
private:
    // data:
    double len, wid;

public:
    void Set_len(double l)
    {
        len = l;
    }

    void Set_wid(double w)
    {
        wid = w;
    }
    double get_len();
    double get_wid();
};

class testR
{
public:
    // data:
    double testR_len1, testR_wid1;

public:
    void test_Set_len1(double l)
    {
        testR_len1 = l;
    }

    void test_Set_wid1(double w)
    {
        testR_wid1 = w;
    }
    double test_get_len1();
    double test_get_wid1();
};
int main()
{
    Rectangle R;
    // R.len=15; will give a C.E Cuz len is a private class member

    testR testR;
    testR.testR_len1 = 15;
    R.Set_len(5);
}