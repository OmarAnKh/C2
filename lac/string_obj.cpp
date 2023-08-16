#include <iostream>
#include <cstring>
using namespace std;
class MyString
{
private:
    char *str;
    // int len; number of char is not an attribute
public:
    MyString()
    {               // defult constructor
        str = NULL; // the defult value for the string is NULL cuz we dont know the len of the string
    }
    MyString(const char *s)
    {
        str = NULL;
        set_string(s);
    }
    // copy constructor

    MyString(const MyString &obj)
    {
        this->str = new char[length(obj.str) + 1];
        copy(this->str, obj.str);
    }

    /*

    we can make it one constructor instead of 2 by doing this(putting a defult value for s) :

    MyString(const char *s=NULL)
    {
        set_string(s);
    }

    */
    void operator=(MyString obj)
    {
        cout << "hello";
    }
    void set_string(const char *s)
    {
        // str=s; this will give a C.E cuz the str is not a const and s is a const and non const variable cant point to a const variable and this is dangers
        //  this is called shallow copy (نسخ اعمى) and its a problem
        // deep copy steps :
        // 1)reallocat the memory
        if (str)
            delete[] str;

        str = new char[length(s + 1)];
        copy(str, s);
    }
    char *get_Mystring()
    {
        return str;
    }
    int length(const char *s);
    int length() const
    {
        int len;
        for (len = 0; str[len]; len++)
            ;
        return len;
    }
    void copy(char *s1, const char *s2)
    {
        while (*s1++ = *s2++)
            ;
    }
};
int MyString::length(const char *s)
{
    int len;
    for (len = 0; s[len]; len++)
        ;
    return len;
}

int main()
{
    // string = system defined non primitive data type
    // char* primitive data type
    // MyString user defined
    /*

    char *name;
    name = new char[1000];
    strcpy(name, "this is my name , ");
    strcat(name, "omar");
    cout << name << endl;
    delete[] name;
    string st = "is";
    if (st == "is")
    {
        cout << 1 << endl;
    }*/

    MyString st2("is");
    MyString st3(st2); // copy constructor
    cout << st3.get_Mystring() << endl;
    MyString a; // defult constructor
    MyString b; // defult constructor

    // a = b; // this does not call the copy constructor (every class will call the constructor one time only at the inti. time) here we use the equal OPE

    cout << a.get_Mystring() << 1 << endl;
}
