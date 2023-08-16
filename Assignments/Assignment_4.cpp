#include <iostream>
#include <string>
using namespace std;
class complex
{
private:
    float rp;
    float ip;

public:
    complex()
    {
        rp = 0;
        ip = 0;
    }
    complex(float a, float b)
    {
        rp = a;
        ip = b;
    }
    complex(float a)
    {
        rp = a;
        ip = 0;
    }
    complex(const complex &a)
    {
        this->rp = a.rp;
        this->ip = a.ip;
    }
    ~complex()
    {
    }
    complex operator=(const complex &a)
    {
        rp = a.rp;
        ip = a.ip;
        return *this;
    }
    complex operator+(const complex &a)
    {
        complex temp(rp + a.rp, ip + a.ip);

        return temp;
    }

    float get_real()
    {
        return rp;
    }
    float get_image()
    {
        return ip;
    }
    void set_real(float a)
    {
        rp = a;
    }
    void set_image(float b)
    {
        ip = b;
    }
    string toString()
    {
        string a;
        a = to_string(rp);
        a += " + ";
        a += to_string(ip);
        a += "i";

        return a;
    }
};

int main()
{
    complex a(3.2, 4.3);
    complex d(2.1);
    complex c;
    float x, y;
    cin >> x >> y;
    c.set_real(x);
    c.set_image(y);
    cout << a.toString() << "         " << d.toString() << endl;
    c = a + d;
    cout << c.toString();
}