// In this code, both Savings and Current Accounts can substitute the BankAccount class (base class), but as the Fixed Deposit Account throws an exception on withdraw method from the bank account class, it cannot substitute the base class and hence violates the liskov substitution principle.

#include <iostream>
#include <vector>

using namespace std;

class BankAccount
{
public:
    virtual void deposit() = 0;

    virtual void withdraw() = 0;
};

class SavingsAcccount : public BankAccount
{
public:
    void deposit() override
    {
        cout << "Money deposited to the Savings Account" << endl;
    }

    void withdraw() override
    {
        cout << "Withdrew money from the Savings Account" << endl;
    }
};

class CurrentAcccount : public BankAccount
{
public:
    void deposit() override
    {
        cout << "Money deposited to the Current Account" << endl;
    }

    void withdraw() override
    {
        cout << "Withdrew money from the Current Account" << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
public:
    void deposit() override
    {
        cout << "Money deposited to the fixed deposit account" << endl;
    }

    void withdraw() override
    {
        throw logic_error("Withdraw not allowed from fixed deposit account until maturity");
    }
};

class BankClient
{
private:
    vector<BankAccount *> accounts;

public:
    BankClient(vector<BankAccount *> accounts)
    {
        this->accounts = accounts;
    }

    void ProcessTransactions()
    {
        for (BankAccount *account : accounts)
        {
            account->deposit();

            try
            {
                account->withdraw();
            }
            catch (const logic_error &e)
            {
                cout << "Exception: " << e.what() << endl;
            }
        }
    }
};

int main()
{
    vector<BankAccount *> accounts;

    accounts.push_back(new SavingsAcccount());
    accounts.push_back(new CurrentAcccount());
    accounts.push_back(new FixedDepositAccount());

    BankClient *client = new BankClient(accounts);

    client->ProcessTransactions();
}