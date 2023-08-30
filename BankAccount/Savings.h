#include "BankAccount.h"
#define SAVINGS_H
//Yup make the classes here
//atleast it feels more organized.
class Savings : public BankAccount 
{
    private:
        double interestRate;

    public:
        Savings(std::string name, int accountNumber, double balance, double rate);
        //
        double getInterestRate();
        void setInterestRate(double rate);
        void postInterest();
        void withdraw(double amount);
        void print();

        void createMonthlyStatement() override;
}; 