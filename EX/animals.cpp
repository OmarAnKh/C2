#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;
class Animals
{
protected:
    char *name;

public:
    virtual void MakeSound()
    {
        cout << "woff woff woff";
    }
    virtual void setName(char *newName)
    {
        strcpy(name, newName);
    }
    virtual char *getName()
    {
        return this->name;
    }
    Animals(const char *name1 = "unknown")
    {
        name = new char[strlen(name1) + 1];
        strcpy(name, name1);
    }

    ~Animals()
    {

        delete[] name;
    }
    friend ofstream &operator<<(ofstream &out, Animals &a)
    {
        out << a.name;
        return out;
    }
    friend ifstream &operator>>(ifstream &in, Animals &a)
    {
        in >> a.name;
        return in;
    }
};
class Dogs : public Animals
{
public:
    Dogs(const char *name2 = "unknown") : Animals(name2)
    {
        cout << "from woff const ";
    }
    void MakeSound()
    {
        cout << "woff woff woff";
    }
    void setName(char *newName)
    {
        strcpy(name, newName);
    }
    char *getName()
    {
        return this->name;
    }
    friend ofstream &operator<<(ofstream &out, Animals &a)
    {
        out << a.name;
        return out;
    }
    friend ifstream &operator>>(ifstream &in, Animals &a)
    {
        in >> a.name;
        return in;
    }
};
class Cats : public Animals
{
public:
    Cats(const char *name2 = "unknown") : Animals(name2)
    {
        cout << "from meow const ";
    }
    void MakeSound()
    {
        cout << "meow  meow meow";
    }
    void setName(char *newName)
    {
        strcpy(name, newName);
    }
    char *getName()
    {
        return this->name;
    }
    friend ofstream &operator<<(ofstream &out, Animals &a)
    {
        out << a.name;
        return out;
    }
    friend ifstream &operator>>(ifstream &in, Animals &a)
    {
        in >> a.name;
        return in;
    }
};
int main()
{
    ifstream shop;
    shop.open("Text.txt");
    if (!shop.is_open())
    {
        return 0;
    }
    string row;
    int size = 0;
    while (getline(shop, row))
    {
        size++;
    }
    shop.close();
    shop.open("Text.txt");
    Animals **store;
    store = new Animals *[size];
    char temp[5];

    for (int i = 0; i < size; i++)
    {
        shop >> temp;

        if (!strcpy(temp, "dog"))
        {
            store[i] = new Dogs;
            store[i]->setName("wofwof");
        }

        else if (!strcpy(temp, "cat"))
        {
            store[i] = new Cats;
        }
    }
}