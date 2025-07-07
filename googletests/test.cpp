#include <gtest/gtest.h>
#include "BankSystem.hpp"
#include "InvalidTransaction.hpp"
#include "AccountNotFound.hpp"


TEST(BankAccountTest, ThrowCheck){
    BankAccount ben("Ben", 1, 100);

    EXPECT_THROW(ben.withdraw(200), InvalidTransaction);

    try{
        ben.withdraw(500);
    }
    catch(InvalidTransaction& inv){
        EXPECT_STREQ(inv.what(), "Error! Withdraw failed: Not enough balance!");
    }
}

TEST(BankSystemTest, ThrowCheck){
    BankSystem bank;
    bank.addAccount("Tigran", 1, 1000);
    bank.addAccount("Arsen", 2, 2000);

    EXPECT_THROW(bank.transferFunds(2 , 3, 200), AccountNotFound);

    EXPECT_NO_THROW(bank.transferFunds(1, 2, 200));
}
