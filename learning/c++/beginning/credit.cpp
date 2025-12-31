#include <iostream>
using namespace std;

class e_wallet
{
    float balance;
    string owner;
    string card_number;
public:
    e_wallet(string owner_name, string card_num, float initial_balance)
    {
        owner = owner_name;
        card_number = card_num;
        balance = initial_balance;
    }
    void add_balance(float amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Added $" << amount << " to the wallet." << endl;
        }
        else
        {
            cout << "Invalid amount. Please enter a positive value." << endl;
        }
    }
    void make_payment(float amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Payment of $" << amount << " made successfully." << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance for the payment." << endl;
        }
        else
        {
            cout << "Invalid amount. Please enter a positive value." << endl;
        }
    }
};

int main()
{
    e_wallet myWallet("John Doe", "1234-5678-9012-3456", 100.0);
    myWallet.add_balance(50.0);
    myWallet.make_payment(30.0);
    myWallet.make_payment(150.0);
    return 0;
}