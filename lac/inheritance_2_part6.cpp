#include <iostream>
using namespace std;
class A
{
private:
    int privateA;

protected:
    int protectedA;

public:
    int publicA;
};
class B : public A
{
public:
    void func()
    {
        int a;
        // a=privateA; error not accessible
        a = protectedA;
        a = publicA;
    }
};
class C : private A
{
public:
    void func()
    {
        int a;
        // a=privateA; error not accessible
        a = protectedA;
        a = publicA;
    }
};
int main()
{
    int a;
    B objB;
    // a=objB.privateA;//not accessible
    // a=objB.protectedA;//not accessible
    a = objB.publicA;

    C objC;
    // a=objC.privateA;//not accessible
    // a=objC.protectedA;//not accessible
    // a=objC.publicA;//not accessible because C has a private inheritance
    int x = 5;
    int *ip = &x;
    cout << ++*ip << endl
         << ++(*ip);
}