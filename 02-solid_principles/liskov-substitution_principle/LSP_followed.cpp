// In this case, the client will have two lists of accounts, withdrawable and non withdrawable accounts, this way when we make fixed deposit account we don't have to throw an exception, we just inherit it directly from the Non-withdrawable account class, and now the child class can directly subsitute the base class, even in the case of the savings and current account, they can directly subsitute their parents classes.

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

class BankClient {
    private:
        vector<NonWithdrawableAccounts*> nonwithdrawableaccounts;
        vector<WithdrawableAccounts*> withdrawableaccounts;

    public:
        BankClient(vector<NonWithdrawableAccounts*> nonwithdrawableaccounts, vector<WithdrawableAccounts*> withdrawableaccounts) {
            this->nonwithdrawableaccounts = nonwithdrawableaccounts;
            this->withdrawableaccounts = withdrawableaccounts;
        }

        void ProcessTransactions() {
            for(NonWithdrawableAccounts* account : nonwithdrawableaccounts) {
                account->deposit();
            }

            for(WithdrawableAccounts* account : withdrawableaccounts) {
                account->deposit();
                account->withdraw();
            }
        }
};

int main() {
    vector<NonWithdrawableAccounts*> nonwithdrawableaccounts;
    nonwithdrawableaccounts.push_back(new FixedDepositAccount());

    vector<WithdrawableAccounts*> withdrawableaccounts;
    withdrawableaccounts.push_back(new SavingsAccount());
    withdrawableaccounts.push_back(new CurrentAccount());

    BankClient* client = new BankClient(nonwithdrawableaccounts, withdrawableaccounts);

    client->ProcessTransactions();
}