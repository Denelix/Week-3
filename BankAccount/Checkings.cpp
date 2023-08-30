// Checkings.cpp
#include "Checkings.h"
#include <iostream>

Checkings::Checkings(std::string name, int accountNumber, double balance, double minimumBalance, double interestRate, double serviceCharge, double monthlyFee)
    : BankAccount(accountNumber, balance), interestRate(interestRate), monthlyFee(monthlyFee), serviceCharge(serviceCharge)
{
}

double Checkings::getMinimumBalance()
{
    return minimumBalance;
}

void Checkings::setMinimumBalance(double minBalance)
{
    minimumBalance = minBalance;
}

double Checkings::getMonthlyFee()
{
    return monthlyFee;
}

void Checkings::setMonthlyFee(double m)
{
    monthlyFee = m;
}

double Checkings::getInterestRate() 
{
    return interestRate;
}

void Checkings::setInterestRate(double rate) 
{
    interestRate = rate;
}

double Checkings::getServiceCharge() 
{
    return serviceCharge;
}

void Checkings::setServiceCharge(double charge) 
{
    serviceCharge = charge;
}

void Checkings::postInterest() 
{
    balance += balance * interestRate; //values are under .01
}

void Checkings::writeCheck(double amount) 
{
    this->withdraw(amount);
}

void Checkings::withdraw(double amount) 
{
    //to remove 999 if statements just added returns
    if (balance < amount) 
    {
        std::cout << "Warning: Insufficient balance for withdrawal\n";
        return;
    }
    if (balance - amount < minimumBalance && balance - amount - serviceCharge < 0) 
    {
        std::cout << "Error: Insufficient balance after service charge\n";
        return;
    }
    balance -= (amount + serviceCharge);
}

void Checkings::createMonthlyStatement() {
    postInterest();
    if (balance - monthlyFee < 0)
    {
        std::cout << "Warning: Monthly fee exceeds balance.\n";
    }
    else
    {
        balance -= monthlyFee;
    }
}

void Checkings::print() 
{
    std::cout << "Interest Checking " << accountNumber << ": ";
    std::cout << "Balance: " << balance << " ";
    std::cout << "Interest Rate: " << interestRate << " \n";
}
