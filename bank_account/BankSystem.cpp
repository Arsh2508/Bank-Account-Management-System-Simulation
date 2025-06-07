#include <iostream>
#include <vector>
#include "BankSystem.hpp"

void BankSystem::addAccount(const std::string& name, int accountNumber, double initialBalance){
	BankAccount obj(name, accountNumber, initialBalance);
	system.push_back(obj);
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
		std::cout<<"Sender or receiver account not found!"<<std::endl;
		return;
	}

	if(sender->get_balance() < amount){
		std::cout<<"Transfer failed! No enough balance."<<std::endl;
		return;
	}

	sender->withdraw(amount);
	receiver->deposit(amount);
}


void BankSystem::displayAllAccounts(){
	for(int i = 0; i < system.size(); ++i){
		system[i].display();
	}
}
