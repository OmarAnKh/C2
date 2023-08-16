#include <iostream>
using namespace std;
class bank_acc
{
private:
    int accNumber;
    float balance;

public:
    bank_acc(int acc, float m)
    {
        accNumber = acc;
        balance = m;
    }
    bank_acc()
    {
        accNumber = 0;
        balance = 0;
    }
    void deposit(float amount)
    {
        balance += amount;
    }
    int isEmpty(float number)
    {
        if (balance - number > 0)
        {
            balance -= number;
            return 0;
        }
        return 1;
    }
    float withdraw(float m)
    {
        if (!isEmpty(m))
        {
            return balance;
        }
        return -1;
    }
    void display()
    {
        cout << " your ACC number is " << accNumber << endl;
        cout << " your ACC balance is  " << balance << endl;
    }
};
int main()
{
    bank_acc b;
    int id;
    float m;
    cin >> id >> m;
    bank_acc c(id, m);
    b.deposit(10);
    b.withdraw(50);
    b.display();
}