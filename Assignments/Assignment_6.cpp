#include <iostream>
using namespace std;
class bankAccount
{
private:
    int accNumber;
    double accBalance;

public:
    bankAccount(int number = 0, double balance = 0)
    {
        accBalance = number;
        accBalance = balance;
    }
    void deposit(int amount)
    {
        accBalance += amount;
    }
    void withdraw(int amount)
    {
        if (accBalance - amount > 0)
        {
            accBalance -= amount;
        }
        else
        {
            cout << "the operation you are trying to do is invalid ";
        }
    }
    void displayAccountInfo()
    {
        cout << "the account number: " << accNumber << "\t"
             << " have: " << accBalance << "at is balance";
    }
};
class savingsAccount : public bankAccount
{
private:
    float transactionFee;

public:
    savingsAccount(int number = 0, double balance, float transaction) : bankAccount(number, balance)
    {
        transactionFee = transaction;
    }
};