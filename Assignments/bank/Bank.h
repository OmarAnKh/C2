#include <iostream>
#include "BankAccount.h"
#include <cstring>
using namespace std;
class Bank
{
private:
    int count;
    int size;
    BankAccount *Dynamic;
    int isExist(int accountNumber)
    {

        for (int i = 0; i < this->count; i++)
        {
            if (accountNumber == Dynamic[i].getAccountNumber())
            {
                return i;
            }
        }
        return -1;
    }

public:
    Bank(int count = 0, int size = 100)
    {
        Dynamic = new BankAccount[size];
    }
    Bank(const Bank &obj)
    {
        this->count = obj.count;
        this->size = obj.size;
        if (Dynamic)
        {
            delete[] Dynamic;
        }
        Dynamic = new BankAccount[size];
        for (int i = 0; i < count; i++)
        {
            Dynamic[i] = obj.Dynamic[i];
        }
    }
    ~Bank()
    {

        if (Dynamic)
        {
            delete[] Dynamic;
        }
        Dynamic = NULL;
    }
    void addAccount(const char *name, const char *address, const char *email, int accountNumber, double balance, double overdraftLimit, double interestRate)
    {
        Dynamic[count].setName(name);
        Dynamic[count].setAddress(address);
        Dynamic[count].setEmail(email);
        Dynamic[count].setAccountNumber(accountNumber);
        Dynamic[count].setBalance(balance);
        Dynamic[count].setOverdraftLimit(overdraftLimit);
        Dynamic[count].setInterestRate(interestRate);
        count++;
    }
    bool removeAccount(int accountNumber)
    {
        int accountIndex = isExist(accountNumber);
        if (accountIndex != -1)
        {
            for (int i = accountIndex; i < count - 1; i++)
            {
                Dynamic[i] = Dynamic[i + 1];
            }
            count--;
            return 1;
        }
        return 0;
    }
    void displayAllAccounts() const
    {
        for (int i = 0; i < count; i++)
        {
            cout << Dynamic[i];
        }
    }
    void deposit(BankAccount bankaccount, double amount)
    {
        bankaccount.deposit(amount);
    }
    bool withdraw(BankAccount bankaccount, double amount)
    {
        return bankaccount.withdraw(amount);
    }
};
