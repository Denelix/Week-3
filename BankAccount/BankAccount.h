#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
//idk why this works but it does ^^^
#include <iostream>
#include <string>
//Bank account Class
class BankAccount 
{
    protected:
        std::string name;
        int accountNumber;
        std::string type;
        double balance;
        double interestRate;

    public:
        BankAccount(std::string name, int accountNumber, double balance, double interestRate, double monthlyFee);
        BankAccount(int accountNumber, double balance);
        //
        std::string getAccountHolderName() const;
        int getAccountNumber() const;
        std::string getAccountType() const;
        double getBalance() const;
        double getInterestRate() const;
        void deposit(double add);
        double calculateInterest();
        void updateBalance();
        virtual void withdraw(double subtract);
        virtual void print() = 0;
        virtual void createMonthlyStatement() = 0;
};
//idk why this works but it does vvv 
#endif