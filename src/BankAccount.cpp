#include <iostream>
#include <string>
#include <exception>
#include "BankAccount.hpp"
#include "InvalidTransaction.hpp"

BankAccount::BankAccount()
	: accountHolder{"Unknown"}
	, accountNumber{0}
	, balance{0}
	{}

BankAccount::BankAccount(const std::string& name, int number, double balance_)
	: accountHolder{name}
	, accountNumber{number}
	, balance{balance_}
	{}

BankAccount::BankAccount(const BankAccount& other)
	: accountHolder{other.accountHolder}
	, accountNumber{other.accountNumber}
	, balance{other.balance}
	{}


void BankAccount::deposit(double amount){
	if(amount <= 0){
		throw InvalidTransaction("Deposit failed: Amount must be positive!");
	}

	balance += amount;

}

bool BankAccount::withdraw(double amount){
	if(amount <= 0){
		throw InvalidTransaction("Withdraw failed: amount must be positive!");
	}
	if(balance < amount){
		throw InvalidTransaction("Error! Withdraw failed: Not enough balance!");
	}

	balance -= amount;
	return true;
}

void BankAccount::display() const{
	std::cout<<"\nAccount holder - "<<accountHolder<<"\nAccount number - "<<accountNumber<<"\nBalance - "<<balance<<std::endl;
}

int BankAccount::getAccountNumber() const{
	return accountNumber;
}

double BankAccount::get_balance() const{
	return balance;
}
