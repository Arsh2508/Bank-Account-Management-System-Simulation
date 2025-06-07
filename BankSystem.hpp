#include <vector>
#ifndef BANKSYSTEM_HPP
#define BANKSYSTEM_HPP
#include "BankAccount.hpp"


class BankSystem{
public:
	void addAccount(const std::string&, int, double);
	BankAccount* findAccount(int);
	void transferFunds(int, int, double);
	void displayAllAccounts();
private:
	std::vector<BankAccount> system;
};

#endif
