/*A.Implement a strcut Account.An account has a balance variable, .functions to add and withdraw money,
and a function to inquire the current balance.Instantiate an object of type Account and
initialize the balance member with any value.
Charge a $5 penalty if an attempt is made to withdraw more money than available
in the account.Enhance the Account strcut to compute interest on the current balance.

b)B. Implement a strcut Bank. This bank has two objects .checking and savings of the
type Account that was developed in the preceding exercise. Implement four instance methods:
deposit (double amount, char* account) withdraw (double amount, account)
char* transfer (double amount, char* account) printBalances () Here the
account string is "S" or"C". For the deposit or withdrawal,it indicates which
account is affected. For a transfer it indicates the account from which the money is taken;
the money is automatically transferred to the

*/
#include <iostream>
using namespace std;
struct Accunt
{
    double balance;
    double interest;
};
struct Bank
{
    Accunt checking;
    Accunt saving;
    void deposit(double amount, char *accunt)
    {

        if (strcmp(accunt, "s") == 0)
        {
            saving.balance;
        }
        else if (strcmp(accunt, "c") == 0)
        {
            checking.balance;
        }
    }
    void withdraw(double amount, char *accunt)
    {
        if (strcmp(accunt, "s") == 0)
        {
            checking.balance;
        }
        else if (strcmp(accunt, "c") == 0)
        {
            saving.balance;
        }
        else
        {
            cout << " not exist. please enter 'c'or 's'";
        }
    }
    char *transferred(double amount, char *accunt)
    {
        if (strcmp(accunt, "s") == 0)
        {
            if (checking.balance >= amount)
            {
            }
        }
        else if (strcmp(accunt, "c") == 0)
        {
            if (saving.balance >= amount)
            {
            }
        }
    }

        void printBalances()
        {
            cout << "checking balance: " << endl;
            cout << "savings balance: " << endl;
        }
    
    };
    void addMony(Accunt z)
    {
        double amount;
        cout << "enter the number you want to add";
        cin >> amount;
        z.balance += amount;
    }
    void withdrawMony(Accunt z, double &p)
    {
        cout << "enter the number you want to take";
        cin >> p;
        if (z.balance < p)
        {
            z.balance -= 5;
        }
        else
        {
            z.balance -= p;
            cout << z.balance;
        }
    }
    double inquireMony(Accunt z)
    {
        return z.balance;
    }
    void interestMony(Accunt z)
    {
        double inst = z.balance + z.interest;
        z.balance = inst;
    }
    int main()
    {
        double p;
    }