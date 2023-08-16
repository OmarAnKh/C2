#include <iostream>
using namespace std;


void sort(int to_be_sorted[],int size);
double median(int array[],int size);

int main(){
    int size;
    cout <<"enter the size of the array you want to input\n";
    cin>>size;
    int *array=new int[size];
    for (int i=0;i<size;i++){
        cout<<"enter the element number " <<i+1<<" in the array\n";
        cin>>array[i];
    }
    cout << median(array,size);
}











double median(int array[],int size){
    int *dynamic_array=new int[size];
    for (int i=0;i<size;i++){
        dynamic_array[i]=array[i];
    }
    sort(dynamic_array,size);
    if (size%2==0){
        double median=double((dynamic_array[size/2]+dynamic_array[(size/2)+1]))/2;
        delete []dynamic_array;
        return median;
    }
    else {
        double median=dynamic_array[size/2];
        delete []dynamic_array;
        return median;
    }
}



void sort(int to_be_sorted[],int size){
    for (int i=0;i<size-1;i++){
        for(int j=0;j<size-i;j++){
            if (to_be_sorted[j]>to_be_sorted[j+1]){
                int temp=to_be_sorted[j];
                to_be_sorted[j]=to_be_sorted[j+1];
                to_be_sorted[j+1]=temp;
            }
        }
    }
}