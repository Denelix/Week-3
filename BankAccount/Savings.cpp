//Savings.cpp
#include "Savings.h"
//Apperently, dont make the classes here : )  
Savings::Savings(std::string name, int accountNumber, double balance, double intrestRate) 
    : BankAccount(accountNumber, balance), interestRate(intrestRate)
{
}

double Savings::getInterestRate() 
{
    return interestRate;
}

void Savings::setInterestRate(double rate) 
{
    interestRate = rate;
}

void Savings::postInterest() 
{
    balance += balance * interestRate;
}

void Savings::withdraw(double amount) 
{
    if (balance >= amount)
        balance -= amount;
    else
        std::cout << "Warning: Insufficient balance for withdrawal\n";
}

void Savings::createMonthlyStatement() 
{
    postInterest();
}

void Savings::print()
{
    std::cout << "Interest Savings " << accountNumber << ": ";
    std::cout << "Balance: " << balance << " ";
    std::cout << "Interest Rate: " << interestRate << " \n";
}