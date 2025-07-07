#include <gtest/gtest.h>
#include "BankSystem.hpp"
#include "InvalidTransaction.hpp"

TEST(thrown, check){
    BankAccount ben("Ben", 1, 100);

    EXPECT_THROW({ben.withdraw(200);}, InvalidTransaction);
}