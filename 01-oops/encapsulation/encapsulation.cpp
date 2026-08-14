// Encapsulation means bundling the data and methods into a single unit (class) and restricting access to the internal representation of the object. It helps in protecting the data from unauthorized access and modifications.
// There are three access modifiers to acheive this -> public, private and protected.
// Public members can be accessed from anywhere, private members can only be accessed within the class, and protected members can be accessed within the class and the child classes.

// 1. All th characters and behaviors of a class are encapsulated in the class.
// 2. We need to provide data security to the members of the class.
// 3. We provide getters and setters to access the private members of the class. Getters provide the value of the private members without letting user alter the value. Setters allow the user to set the value of the private members but with some validation checks to ensure that the value being set is valid, this way the the validations stays within the class and the user does not have to worry about it.

#include <iostream>
using namespace std;

class BankAccount
{
private:
    int balance;
    string contactNumber;

public:
    BankAccount(string contactNumber, int balance)
    {
        this->balance = balance ? balance : 0; // Ensure balance is non-negative
        this->contactNumber = contactNumber;
    }

    // Getter for balance
    int getBalance()
    {
        return balance;
    }

    // Getter for contact number
    string getContactNumber()
    {
        return contactNumber;
    }

    // Setter for contact number
    void setContactNumber(string contactNumber)
    {
        // Validation check for contact number
        if (contactNumber.length() == 10)
        {
            this->contactNumber = contactNumber;
            cout << "Contact number updated successfully." << endl;
        }
        else
        {
            cout << "Invalid contact number. It should be 10 digits long." << endl;
        }
    }

    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited: " << amount << ". New balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(int amount)
    {
        if (amount < 0)
        {
            cout << "Invalid withdrawal amount." << endl;
            return;
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance." << endl;
            return;
        }
        else
        {
            balance -= amount;
            cout << "Withdrew: " << amount << ". New balance: " << balance << endl;
        }
    }
};

int main()
{
    BankAccount account("1234567890", 0);

    account.deposit(500);
    account.withdraw(200);
    cout << "Current balance: " << account.getBalance() << endl;
    return 0;
}