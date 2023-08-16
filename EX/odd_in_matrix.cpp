#include <iostream>
using namespace std;


void make_matrix(int **&matrix,int &row, int &culm);
void input(int **matrix,int row);
int number_of_odds(int **matrix,int row,int culm);
int *find_odds(int **matrix,int row,int culm);
void print(int array[],int size);



int main(){

int **matrix;
int row,culm;
make_matrix(matrix,row,culm);
input(matrix,row);
int number=number_of_odds(matrix,row,culm);
int *number_of_odds=new int[number];
number_of_odds=find_odds(matrix,row,culm);
print(number_of_odds,number);

}



void make_matrix(int **&matrix,int &row, int &culm){
    cout <<"enter the number of rows you want to make\n";
    cin>>row;
    matrix=new int*[row];
    for (int i=0;i<row;i++){
        cout <<"enter the size of the row you want \n";
        cin >> culm;
        culm++;
        matrix[i]=new int[culm];
        matrix[i][0]=culm;
    }
}


void input(int **matrix,int row){
    for (int i=0;i<row;i++){
        for(int j=1;j<matrix[i][0];j++){
            cout << "enter the element number "<<j+1<<" in the "<<i+1<<" row";
            cin>>matrix[i][j];
        }
    }
}


int number_of_odds(int **matrix,int row,int culm){
    int counter=0;
    for (int i=0;i<row;i++){
        for(int j=1;j<matrix[i][0];j++){
            if(matrix[i][j]%2!=0){
                counter++;
            }
        }
    }
    return counter;
}



int *find_odds(int **matrix,int row,int culm){
    int number=number_of_odds(matrix,row,culm);
    int *ODDS=new int[number]{0};
    for (int i=0;i<row;i++){
        for(int j=0;j<matrix[i][0];j++){
            if(matrix[i][j]%2!=0){
                ODDS[i]=matrix[i][j];
            }
        }
    }
    return ODDS;
}


void print(int array[],int size){
    for (int i=0;i<size;i++){
        cout<<array[i]<<"\t";
    }
}