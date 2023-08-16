#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString
{
private:
    char *st;
public:
    MyString()
    {
        cout << "hello from defult constructor " << endl;
        st = NULL;
    }
    MyString(const char *a)
    {
        cout << "hello from constructor with par." << endl;
        if (st)
        {
            delete[] st;
        }
        st = new char[strlen(a) + 1];
        strcpy(st, a);
    }
    MyString(const MyString &a)
    {
        cout << "hello from copy constructor " << endl;
        if (st)
        {
            delete[] st;
        }
        st = new char[strlen(a.st) + 1];
        strcpy(this->st, a.st);
    }
    ~MyString()
    {
        cout << "hello from  destructor " << endl;
        if (st)
        {
            delete[] st;
        }
    }
    char *getString()
    {
        return st;
    }
    char operator[](const int number)
    {
        return this->st[number];
    }

    MyString operator=(const char *a)
    {
        if (this->st)
        {
            delete[] st;
        }
        st = new char[strlen(a) + 1];
        strcpy(this->st, a);
        return *this;
    }

    MyString operator=(const char a)
    {
        if (this->st)
        {
            delete[] st;
        }
        st = new char[2];
        this->st[0] = a;
        this->st[1] = '\0';
        return *this;
    }
};
MyString f(const MyString &obj)
{
    MyString x = "omar";
    return x;
}
int main()
{
    MyString st1, st2("this");
    MyString st3;
    st3 = f(st1);
    st3 = "omar";
    cout << st3[0] << endl;
    st2 = 'a';
    cout << st2.getString() << endl;
}