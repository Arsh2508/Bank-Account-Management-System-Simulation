#include <iostream>
#include <vector>
#include "BankSystem.hpp"
#include "InvalidTransaction.hpp"
#include "AccountNotFound.hpp"

void BankSystem::addAccount(const std::string& name, int accountNumber, double initialBalance){
	system.emplace_back(name, accountNumber, initialBalance);
}

BankAccount* BankSystem::findAccount(int accountNumber){
	for(int i = 0; i < system.size(); ++i){
		if(system[i].getAccountNumber() == accountNumber){
			return &system[i];
		}
	}	
	return nullptr;
}

void BankSystem::transferFunds(int senderAcc, int receiverAcc, double amount){
	BankAccount* sender = findAccount(senderAcc);
	BankAccount* receiver = findAccount(receiverAcc);
	
	if(!sender || !receiver){
		throw AccountNotFound("Sender or receiver account not found!");
	}

	try{
		sender->withdraw(amount);
		receiver->deposit(amount);
	}
	catch(InvalidTransaction& inv){
		std::cout<<inv.what()<<std::endl;
	}
}


void BankSystem::displayAllAccounts() const{
	for(int i = 0; i < system.size(); ++i){
		system[i].display();
	}
}
