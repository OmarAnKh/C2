#include <iostream>
#include <cstring>
using namespace std;
char *removeSubstring(char *str, const char *substr);
// given the following main function and the needed methods
// to the string class  that make the main works correctly without any errors.
class String
{
private:
    char *st;

public:
    String()
    {
        st = NULL;
    }
    String(const char *s)
    {
        st = new char[strlen(s) + 1];
        strcpy(st, s); // or we can use strcpy_s(st,strlen(s)+1,s);
    }
    String(const String &obj)
    {
        st = new char[strlen((obj.st) + 1)];
        strcpy_s(st, strlen((obj.st) + 1), obj.st);
    }
    ~String()
    { // the destructor cant be overloaded cuz it does not take parameters
        if (st)
        {
            delete[] st;
            st = NULL;
        }
    }

    // operator overloading

    String &operator=(const String &obj /*this will call the copy constructor*/)
    {
        if (this == &obj)
        {
            return *this;
        }
        if (this->st != NULL)
            delete[] this->st;
        int len = strlen(obj.st) + 1;
        this->st = new char[len];
        strcpy(this->st, obj.st);
        return *this;
    }
    String operator+(const String &src)
    {
        // for me its better to creat an object of type String and store in it and return it
        // but in the string class it does it like this it will change on the caller class

        char *res = new char[strlen(this->st) + strlen(src.st) + 2];
        strcpy(res, this->st);
        strcat(res, " ");
        strcat(res, src.st);
        delete[] st;
        this->st = res;
        return *this;
    }
    String &operator+=(const String &src)
    {
        char *res = new char[strlen(this->st) + strlen(src.st) + 2];
        strcpy(res, this->st);
        strcat(res, " ");
        strcat(res, src.st);
        delete[] st;
        this->st = res;
        // or another solution
        /*

        *this =*this + ob;
        we are using the + operater we created

        */
        return *this;
    }
    bool operator==(const String &src)
    {
        if (!(strcmp(this->st, src.st)))
        {
            return true;
        }
        return false;
    }
    char operator[](int number)
    {
        return this->st[number];
    }
    String operator-(const char *a)
    {
        st = removeSubstring(st, a);
        return *this;
    }
    char *getString()
    {
        return this->st;
    }
};

int main()
{

    String f("omar"), s("khalili"), m;
    m = f + s;
    if (f == s)
    {
        cout << "the same string";
    }
    cout << f[0];
    f += s;
    f - "a";
    cout << f.getString();

    // given the followings
    /*class Mystring {
        private:
        char*st;
        public:
        Mystring(const char *s)
    {
        st = new char[strlen(s) + 1];
        strcpy(st, s);
    }
    Mystring(const Mystring &obj)
    {
        st = new char[strlen((obj.st) + 1)];
        strcpy_s(st, strlen((obj.st) + 1), obj.st);
    }
    ~Mystring()
    {
        if (st)
        {
            delete[] st;
            st = NULL;
        }
    }
    };



    Mystring st1,st2("this");
    Mystring st3;
    st3
    st3=f(st1);
    cout <<
    if (f == s)
    {
        cout << "the same string";
    }
    cout << f[0];
    f += s;
    f - "a";




    */

    // notes:
    int x = 1;           // 4 bytes
    char y = '1';        // 1 byte
    const char *z = "1"; // 2 bytes for the data it self and 4 or 16 bytes for the pointer
}
char *removeSubstring(char *str, const char *substr)
{
    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);
    char *result = new char[str_len + 1];
    size_t i = 0;
    size_t j = 0;

    while (i < str_len)
    {
        if (strncmp(&str[i], substr, substr_len) == 0)
        {
            i += substr_len;
        }
        else
        {
            result[j] = str[i];
            i++;
            j++;
        }
    }
    result[j] = '\0';
    return result;
}