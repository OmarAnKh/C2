#include <iostream>
#include <cstring>
using namespace std;
class customer
{
private:
    char *name;
    char *address;
    char *email;

public:
    customer(const char *name, const char *address, const char *email)
    {
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
        this->address = new char[strlen(address)];
        strcpy(this->address, address);
        this->email = new char[strlen(email)];
        strcpy(this->email, email);
    }
    customer()
    {
        this->name = NULL;
        this->address = NULL;
        this->email = NULL;
    }
    customer(const customer &obj)
    {
        this->name = new char[strlen(obj.name)];
        strcpy(this->name, obj.name);
        this->address = new char[strlen(obj.address)];
        strcpy(this->address, obj.address);
        this->email = new char[strlen(obj.email)];
        strcpy(this->email, obj.email);
    }
    ~customer()
    {
        if (name)
        {
            delete[] this->name;
            delete[] this->address;
            delete[] this->email;
        }
    }
    char *getName() const
    {
        return this->name;
    }
    char *getAddress() const
    {
        return this->address;
    }
    char *getEmail() const
    {
        return this->email;
    }
    void setName(const char *name)
    {
        if (this->name)
        {
            delete[] this->name;
        }
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
    }
    void setAddress(const char *address)
    {
        if (this->address)
        {
            delete[] this->address;
        }
        this->address = new char[strlen(address)];
        strcpy(this->address, address);
    }
    void setEmail(const char *email)
    {
        if (this->email)
        {
            delete[] this->email;
        }
        this->email = new char[strlen(email)];
        strcpy(this->email, email);
    }
};