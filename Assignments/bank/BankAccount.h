#include <iostream>
#include "customer.h"
#include <cstring>
using namespace std;
class BankAccount : public customer
{
private:
    int accountNumber;
    double balance;
    double overdraftLimit;
    double interestRate;

public:
    BankAccount()
    {
        accountNumber = 0;
        balance = 0;
        overdraftLimit = 0;
        interestRate = 0;
    }
    BankAccount(const char *name, const char *address, const char *email
    , int accountNumber, double balance, 
    double overdraftLimit, double interestRate) : customer(name, address, email)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->overdraftLimit = overdraftLimit;
        this->interestRate = interestRate;
    }
    BankAccount(const BankAccount &obj) : customer(obj.getName(), obj.getAddress(), obj.getEmail())
    {

        this->accountNumber = obj.accountNumber;
        this->balance = obj.balance;
        this->overdraftLimit = obj.overdraftLimit;
        this->interestRate = obj.interestRate;
    }
    ~BankAccount()
    {
    }
    void setAccountNumber(int accountNumber)
    {
        this->accountNumber = accountNumber;
    }
    void setBalance(double balance)
    {
        this->balance = balance;
    }
    void setOverdraftLimit(double overdraftLimit)
    {
        this->overdraftLimit = overdraftLimit;
    }
    void setInterestRate(double interestRate)
    {
        this->interestRate = interestRate;
    }
    int getAccountNumber() const
    {
        return this->accountNumber;
    }
    double getBalance() const
    {
        return this->balance;
    }
    double getOverdraftLimit() const
    {
        return this->overdraftLimit;
    }
    double getInterestRate() const
    {
        return this->interestRate;
    }
    void deposit(double amount)
    {
        this->balance += (amount * interestRate) + amount;
    }
    bool withdraw(double amount)
    {
        if (amount <= this->overdraftLimit)
        {
            this->balance -= amount;
            return true;
        }
        return false;
    }
    friend ostream &operator<<(ostream &out, const BankAccount &obj)
    {
        out << "Account holder:" << obj.getName() << endl;
        out << "Account Number: " << obj.getAccountNumber() << endl;
        out << "Balance:" << obj.getBalance() << endl;
    }
    BankAccount operator=(const BankAccount &obj)
    {
        this->setName(obj.getName());
        this->setAddress(obj.getAddress());
        this->setEmail(obj.getEmail());
        this->accountNumber = obj.accountNumber;
        this->balance = obj.balance;
        this->overdraftLimit = obj.overdraftLimit;
        this->interestRate = obj.interestRate;
    }
};