#include <iostream>
using namespace std;

int  main(){
    // advance pointer (pointer to pointer)

// print value of x in 3 different  ways
    int x=10;
    int *p=&x;
    int **q=&p;
    cout << **q << *p <<x <<endl;


//print address x in 3 different ways

cout <<  p <<"    " << *q <<"    " << &x;

}