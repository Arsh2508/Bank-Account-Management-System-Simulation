#include <iostream>
#include <initializer_list>
#include <string>
#include "BankAccount.hpp"


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

BankAccount::BankAccount(std::initializer_list<std::string> init){
	auto it = init.begin();
	if(init.size() == 3){
		accountHolder = *it;
		accountNumber = std::stoi(*(it + 1));
		balance = std::stod(*(it + 2));
	}
	else{
		accountHolder = "Unknown";
		accountNumber = 0;
		balance = 0.0;
	}
}

BankAccount::~BankAccount(){
	std::cout<<"Destructor is called"<<std::endl;
}

void BankAccount::deposit(double amount){
	if(amount <= 0){
		std::cout<<"Deposit failed: Amount must be positive"<<std::endl;
		return;
	}

	balance += amount;

}

bool BankAccount::withdraw(double amount){
	if(amount <= 0){
		std::cout<<"Withdraw failed: amount must be positive"<<std::endl;
		return false;
	}
	if(balance < amount){
		std::cout<<"Error! Withdraw failed: Not enough balance"<<std::endl;
		return false;
	}

	balance -= amount;
	return true;
}

void BankAccount::display(){
	std::cout<<"\nAccount holder - "<<accountHolder<<"\nAccount number - "<<accountNumber<<"\nBalance - "<<balance<<std::endl;
}

int BankAccount::getAccountNumber() const{
	return accountNumber;
}

double BankAccount::get_balance() const{
	return balance;
}
