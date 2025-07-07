#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <string>
class BankAccount{
public:
	BankAccount();
	BankAccount(const std::string&, int, double);
	BankAccount(const BankAccount&);
	~BankAccount() = default;

	void deposit(double amount);
	bool withdraw(double amount);
	void display() const;	

	int getAccountNumber() const;
	double get_balance() const;

private:
	std::string accountHolder;
	int accountNumber;
	double balance;
};

#endif
