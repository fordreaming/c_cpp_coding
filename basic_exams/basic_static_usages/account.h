#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
using namespace std;

class Account
{
public:
    void applyint() {
        amount += amount * interestRate;
    }

    static double rate() {
        return interestRate;
    }

    static void rate(double);

private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

#endif // ACCOUNT_H
