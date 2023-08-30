// Checkings.h
#pragma once
#include "BankAccount.h"

class Checkings : public BankAccount 
{
    private:
        double interestRate;
        double minimumBalance;
        double serviceCharge;
        double monthlyFee;

    public:
        Checkings(std::string, int accountNumber, double balance, double minBalance, double interestRate = 0.0, double serviceCharge = 0.0, double monthlyFee = 0.0);
        // 
        double getMinimumBalance();
        void setMinimumBalance(double minBalance);
        double getMonthlyFee();
        void setMonthlyFee(double monthlyFee);
        double getInterestRate();
        void setInterestRate(double rate);
        double getServiceCharge();
        void setServiceCharge(double charge);
        //
        void postInterest();
        void writeCheck(double amount);
        void withdraw(double amount);
        void print();
        void createMonthlyStatement() override;
};
