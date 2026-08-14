// Object-Oriented Programming (OOP) is a programming paradigm that organizes programs around classes and objects.
// There are four main pillars of OOP: Encapsulation, Abstraction, Inheritance, and Polymorphism, which are defined and demonstrated in this folder.
// Also, this file contains the demonstration of all the four pillars of OOP together in a single program.

#include <iostream>
using namespace std;

class BankAccount
{
private:
    int balance;
    string accountNumber;
    string customerName;
    string contactNumber;

public:
    BankAccount(int balance, string accountNumber, string customerName, string contactNumber)
    {
        this->balance = max(balance, 0);
        this->accountNumber = accountNumber;
        this->customerName = customerName;
        this->contactNumber = contactNumber;
    }

    int getBalance() const
    {
        return balance;
    }

    string getAccountNumber() const
    {
        return accountNumber;
    }

    void deposit(int amount)
    {
        if (amount < 0)
        {
            cout << "Invalid Amount" << endl;
            return;
        }

        balance += amount;
        cout << amount << " deposited successfully. The new balance is " << balance << endl;
    }

    void withdraw(int amount)
    {
        if (amount > balance || amount < 0)
        {
            cout << "Invalid Amount" << endl;
            return;
        }

        balance -= amount;
        cout << "Withrew " << amount << " successfully. The new balance is " << balance << endl;
    }

    void changeName(string name)
    {
        if (name.empty())
        {
            cout << "Please provide a name" << endl;
            return;
        }

        customerName = name;
        cout << "Customer name updated to " << name << endl;
    }

    bool isValid(string number)
    {
        if (number.size() != 10)
            return false;

        for (int i = 0; i < 10; i++)
        {
            if (number[i] < '0' || number[i] > '9')
                return false;
        }

        return true;
    }

    void changeContactNumber(string number)
    {
        if (isValid(number))
        {
            contactNumber = number;
            cout << "Contact number updated to " << number << endl;
        }
        else
        {
            cout << "Invalid contact number. Please check again." << endl;
        }
    }

    virtual double calculateInterest(int principalAmount, int timeInMonths) = 0;

    // method to calculate interest for the deposited amount for this quarter at this point
    virtual double calculateInterest() = 0;

    virtual ~BankAccount() = default;
};

class SavingsAccount : public BankAccount
{
public:
    SavingsAccount(int balance, string accountNumber, string customerName, string contactNumber) : BankAccount(balance, accountNumber, customerName, contactNumber) {}

    double calculateInterest(int principalAmount, int timeInMonths) override
    {
        double interest;

        // Interest rate for savings account is 3.5%
        interest = (principalAmount * 3.5 * timeInMonths) / 1200;

        return interest;
    }

    double calculateInterest() override
    {
        double interest;

        // Rate is 2.5%
        interest = (getBalance() * 2.5 * 3) / 1200;

        return interest;
    }
};

class CurrentAccount : public BankAccount
{
public:
    CurrentAccount(int balance, string accountNumber, string customerName, string contactNumber) : BankAccount(balance, accountNumber, customerName, contactNumber) {}

    double calculateInterest(int principalAmount, int timeInMonths) override
    {
        double interest;

        // Interest rate for Current Account is 3%
        interest = (principalAmount * 3 * timeInMonths) / 1200;

        return interest;
    }

    double calculateInterest() override
    {
        double interest;

        // Rate is 2%
        interest = (getBalance() * 2 * 3) / 1200;

        return interest;
    }
};

int main()
{
    BankAccount *savingsAccount = new SavingsAccount(0, "39972485679", "Ama Kulwal", "8457965874");
    BankAccount *currentAccount = new CurrentAccount(0, "39232545220", "Vedant Kulwal", "9858745896");

    savingsAccount->deposit(1000);
    savingsAccount->getBalance();

    double interest = savingsAccount->calculateInterest();
    cout << "The interest for the current quarter based on current balance will be " << interest << endl;

    savingsAccount->changeName("Aman Kulwal");
    savingsAccount->getAccountNumber();
    savingsAccount->withdraw(2500);
    savingsAccount->withdraw(100);

    cout << "-----------------------------------------------------" << endl;

    currentAccount->deposit(1000);
    currentAccount->getBalance();

    interest = currentAccount->calculateInterest(10000, 9);
    cout << "The interest based on the given details will be " << interest << endl;

    currentAccount->changeContactNumber("6369584759");
    currentAccount->deposit(interest);

    delete savingsAccount;
    delete currentAccount;
}