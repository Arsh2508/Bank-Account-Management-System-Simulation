#include <string>
#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

class BankAccount{
public:
	BankAccount();
	BankAccount(const std::string&, int, double);
	BankAccount(const BankAccount&);
	BankAccount(std::initializer_list<std::string>);
	~BankAccount();

	void deposit(double amount);
	bool withdraw(double amount);
	void display();	

	int getAccountNumber() const;
	double get_balance() const;

private:
	std::string accountHolder;
	int accountNumber;
	double balance;
};

#endif
