#include <iostream>
#include "BankSystem.hpp"

int main()
{
	BankSystem bank;
	bank.addAccount("Me", 1, 100.0);
	bank.addAccount("You", 2, 200.0);

	bank.transferFunds(1, 2, 100);
	
	bank.findAccount(1)->deposit(100);
	bank.findAccount(2)->withdraw(100);

	bank.displayAllAccounts();

	return 0;
}
