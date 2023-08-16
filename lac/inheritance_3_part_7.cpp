#include <iostream>
using namespace std;
class shape
{
protected:
    string name;

public:
    shape(const string &name = "unknown")
    {
        cout << "shape constructor is called "<<endl;
        this->name = name;
    }
    ~shape()
    {
        cout << "shape destructor is called "<<endl;
    }
    string getName()const{
        return name;
    }
};
class circle : public shape //circle is a shape
{
    protected:
    float radius;
    public:
    circle(float r=0):shape("Circle"){
        cout << "circle constructor is called "<<endl;//the defult constructor of the shape is called if there is no defult const. it will cuz an error
        //or we can call it by doing circle():shape("circle") 
        radius=r;
    } 
    ~circle(){
        cout << "circle destructor is called "<<endl;
        
    }
};

int main(){
    circle c(10);
    //shape s;
    cout << c.getName()<<endl;
}