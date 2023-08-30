//BankACcount.cpp
#include <iostream>
#include <string>
#include "Checkings.h"
#include "Savings.h"
#include "BankAccount.h"
//Apperently, dont make the classes here : )  
BankAccount::BankAccount(int accountNumber, double balance)
	: accountNumber(accountNumber), balance(balance)
{
}

std::string BankAccount::getAccountHolderName() const { return name; }
int BankAccount::getAccountNumber() const { return accountNumber; }
std::string BankAccount::getAccountType() const { return type; }
double BankAccount::getBalance() const { return balance; }
double BankAccount::getInterestRate() const { return interestRate; }

void BankAccount::deposit(double add) 
{
	balance += add;
}

void BankAccount::withdraw(double subtract) 
{
	//This is withdraw, people shouldn't get negative balances... unless rightfully charged lol.
	if (balance >= subtract)
	{
		balance -= subtract;
	}
	else
	{
		std::cout << "Warning: Insufficient balance for withdrawal\n";
	}
}

double BankAccount::calculateInterest() 
{
	return interestRate * balance;
}

void BankAccount::updateBalance() 
{
	balance += calculateInterest();
}

void BankAccount::print() 
{
	std::cout << "Account Number: " << accountNumber << "\nBalance: " << balance << "\n";
}

//int accountNumber = 1000;
////Pokemon names were easier to think of.
//Checkings Meowstic(accountNumber++, 1337);
//Checkings Delphox(accountNumber++, 4200);
//Savings Lucario(accountNumber++, 3926);
//Savings Lopunny(accountNumber++, 3621);
//Meowstic.deposit(1000);
//Delphox.deposit(2300);
//Lucario.deposit(800);
//Lopunny.deposit(500);
//Meowstic.postInterest();
//Delphox.postInterest();
//Lucario.postInterest();
//Lopunny.postInterest();
//std::cout << "***********************************" << std::endl;
//Meowstic.print();
//Delphox.print();
//Lucario.print();
//Lopunny.print();
//std::cout << "***********************************" << std::endl;
//Meowstic.writeCheck(250);
//Delphox.writeCheck(350);
//Lucario.withdraw(120);
//Lopunny.withdraw(290);
//std::cout << "********After withdrawals ***************" << std::endl;
//Meowstic.print();
//Delphox.print();
//Lucario.print();
//Lopunny.print();
//std::cout << "***********************************" << std::endl;
//return 0;

BankAccount* accountsList[6];
int main() 
{
	accountsList[0] = new Checkings("Bill", 12200, 24000, 100, 0.042, 12.00);
	accountsList[1] = new Checkings("Bob", 15210, 9000, 100, 0.0099, 13.00);
	accountsList[2] = new Savings("Susan", 96001, 10000, 0.021);
	accountsList[3] = new Savings("Steve", 98802, 40000, 0.021);
	accountsList[4] = new Checkings("Sally", 10520, 3999, 100, 0.0059, 25.00);
	accountsList[5] = new Savings("Frad", 90403, 2000, 0.011);
	std::cout << "\nJanurary:\n-------------" << std::endl;
	for (int i = 0; i < 6; ++i) {
		accountsList[i]->createMonthlyStatement();
		accountsList[i]->print();
	}

	std::cout << "\nFebruary:\n-------------" << std::endl;
	for (int i = 0; i < 6; ++i) {
		accountsList[i]->createMonthlyStatement();
		accountsList[i]->print();
	}

	std::cout << "\nMarch:\n-------------" << std::endl;
	for (int i = 0; i < 6; ++i) {
		accountsList[i]->withdraw(500);
		accountsList[i]->createMonthlyStatement();
		accountsList[i]->print();
	}

	return 0;
}