#include <iostream>
#include <cstring>
using namespace std;

struct book
{
    char title[50];
    char auther[50];
    float price;
};

void read(book a[], int number);
void max_price(book a[], int number, float &max, float &min);
void reduce_price(book a[], int number);
void print(book a[], int number, const char *auther);

int main()
{
    int number_of_books;
    cin >> number_of_books;
    book *book_shelf = new book[number_of_books];
    read(book_shelf, number_of_books);
    float max, min;
    char *name;
    cin >> name;
    max_price(book_shelf, number_of_books, max, min);
    reduce_price(book_shelf, number_of_books);
    print(book_shelf, number_of_books, name);
}

void read(book a[], int number)
{
    for (int i = 0; i < number; i++)
    {
        cout << " enter the title of the book\n";
        cin >> a[i].title;
        cout << "enther the name of the auther \n";
        cin >> a[i].auther;
        cout << "enter the price of the book \n";
        cin >> a[i].price;
    }
}

void max_price(book a[], int number, float &max, float &min)
{
    max = a[0].price;
    min = a[0].price;
    for (int i = 0; i < number; i++)
    {
        if (a[i].price > max)
        {
            max = a[i].price;
        }
        if (a[i].price < min)
        {
            min = a[i].price;
        }
    }
}

void reduce_price(book a[], int number)
{
    for (int i = 0; i < number; i++)
    {
        a[i].price = a[i].price - ((a[i].price * 10) / 100);
    }
}

void print(book a[], int number, const char *auther)
{
    for (int i = 0; i < number; i++)
    {
        if (!(strcmp(a[i].auther, auther)))
        {
            cout << "he/she wrote " << a[i].title << " and the price of the book after the discount is   " << a[i].price << endl;
        }
    }
}