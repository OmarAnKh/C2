#include <iostream>
#include <string>
using namespace std;

bool Pal(string a){
    int count=0;
    for (int i=0,j=(a.length()-1);a[i];i++,j--){
        if (a[i]==a[j]){
            count++;
        }
    }
    if (count == a.length()){
        return 1;
    }
    return 0;

}
int CountPal(string if_palindrome){
    static int counter_of_palindromes=0;
    if (Pal(if_palindrome)==1){
        counter_of_palindromes++;
    }
    
    return counter_of_palindromes;
}

int main(){
    char a;
    int counter=0;
 do{
    string word="";
    cout << "enter the word you want to check it\n";
    cin>>word;
    counter=CountPal(word);

    cout << "do u want to test another word if yes pleas enter Y/y if no enter anything else\n";
    cin>>a;
    
 }while(a=='y'||a=='Y');
 cout <<counter;
 


}