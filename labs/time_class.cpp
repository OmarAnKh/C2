#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Mytime
{
private:
    int hour, min, sec;
    char form[2];

public:
    bool check_time()
    {

        if (!strcmp(form, "24"))
        {
            if (hour > 24 || hour < 0)
            {
                return 0;
            }
        }
        else if (!strcmp(form, "am") || !strcmp(form, "pm"))
        {
            if (hour > 12 || hour < 0)
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
        if (min > 60 || min < 0)
        {
            return 0;
        }
        if (sec > 60 || sec < 0)
        {
            return 0;
        }

        return 1;
    }
    void print_time()
    {
        cout << hour << " : " << min << " : " << sec << " " << form << endl;
    }
    void set_hour(int h)
    {
        hour = h;
    }
    void set_mim(int m)
    {
        min = m;
    }
    void set_sec(int s)
    {
        sec = s;
    }
    void set_form(char *f)
    {
        strcpy(form, f);
    }
};

int main()
{
    fstream times;
    times.open("time", ios::in);
    Mytime *clocks;
    int number;
    times >> number;
    clocks = new Mytime[number];
    int a;
    char *form;
    form = new char[2];
    for (int i = 0; i < number; i++)
    {

        times >> a;
        clocks[i].set_hour(a);
        times >> a;
        clocks[i].set_mim(a);
        times >> a;
        clocks[i].set_sec(a);
        times >> form;
        clocks[i].set_form(form);
    }
    times.close();
    int operation;
    cin >> operation;
    if (operation == 1)
    {

        for (int i = 0; i < number; i++)
        {
            clocks[i].print_time();
        }
    }
    else if (operation == 2)
    {
        for (int i = 0; i < number; i++)
        {
            if (clocks[i].check_time() == 1)
            {
                cout << "correct" << endl;
            }
            else
            {
                cout << "false " << endl;
            }
        }
    }
    else
    {

        return 0;
    }
}