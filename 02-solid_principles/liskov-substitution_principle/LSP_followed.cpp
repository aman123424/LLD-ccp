// In this case, the client will have two lists of accounts, withdrawable and non withdrawable accounts, this way when we make fixed deposit account we don't have to throw an exception, we just inherit it directly from the Non-withdrawable account class, and now the child class can directly subsitute the base class, even in the case of the savings and current account, they can directly subsitute their parents classes.

// Guidelines to follow to not violate LSP
//  1. Signature Rule: the methods name, return type and input parameters, and the exceptions also,(the child can have narrow exception or return type, but not broader) basically the signature should be same when you are overriding a method from parent class in child class
//  2. Property Rule: Invariant means rules
//           Class Invariant states that the rules set for the parent class should be also followed by the child class (for ex. Account class has a rule that the balance cannot be negative but then we create a CheatAccount class which sets the balance to a negative value, then the CheatAccount (child class here) cannot subsitute Account Class (parent class), and hence violates the LSP)
//           History Constraint states that the history of any state should be maintained by the child class, as set by the parent class (FixedDepositAccount example below)
//  3. Method Rule:
//           Pre-condition: If a method from parent class, which child class overrides, has a pre-condition, it should be followed even when child class is overrding the method from the parent class, or it can weaken condition, but not add constraints
//           Post-condition: If a method from parent class, which child class overrides, has a post condition, it should be followed even when child class is overriding the method from the parent class, or it can strngthen the condition, but not weaken or remove the constraints

// Immutatable class and methods -> The classes and methods which cannot be inherited or overriden, we use final keyword to define such classes and methods

#include <iostream>
#include <vector>

using namespace std;

class NonWithdrawableAccounts
{
public:
    virtual void deposit() = 0;
};

class WithdrawableAccounts : public NonWithdrawableAccounts
{
public:
    virtual void withdraw() = 0;
};

class SavingsAccount : public WithdrawableAccounts
{
public:
    void deposit() override
    {
        cout << "Money deposited to the savings account" << endl;
    }

    void withdraw() override
    {
        cout << "Withdrew money from the savings account" << endl;
    }
};

class CurrentAccount : public WithdrawableAccounts
{
public:
    void deposit() override
    {
        cout << "Money deposited to the current account" << endl;
    }

    void withdraw() override
    {
        cout << "Withdrew money from the current account" << endl;
    }
};

class FixedDepositAccount : public NonWithdrawableAccounts
{
public:
    void deposit() override
    {
        cout << "Money deposited to the fixed deposit account" << endl;
    }
};

class BankClient
{
private:
    vector<NonWithdrawableAccounts *> nonwithdrawableaccounts;
    vector<WithdrawableAccounts *> withdrawableaccounts;

public:
    BankClient(vector<NonWithdrawableAccounts *> nonwithdrawableaccounts, vector<WithdrawableAccounts *> withdrawableaccounts)
    {
        this->nonwithdrawableaccounts = nonwithdrawableaccounts;
        this->withdrawableaccounts = withdrawableaccounts;
    }

    void ProcessTransactions()
    {
        for (NonWithdrawableAccounts *account : nonwithdrawableaccounts)
        {
            account->deposit();
        }

        for (WithdrawableAccounts *account : withdrawableaccounts)
        {
            account->deposit();
            account->withdraw();
        }
    }
};

int main()
{
    vector<NonWithdrawableAccounts *> nonwithdrawableaccounts;
    nonwithdrawableaccounts.push_back(new FixedDepositAccount());

    vector<WithdrawableAccounts *> withdrawableaccounts;
    withdrawableaccounts.push_back(new SavingsAccount());
    withdrawableaccounts.push_back(new CurrentAccount());

    BankClient *client = new BankClient(nonwithdrawableaccounts, withdrawableaccounts);

    client->ProcessTransactions();
}