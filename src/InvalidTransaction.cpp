#include "InvalidTransaction.hpp"

InvalidTransaction::InvalidTransaction(const std::string &msg = "Invalid Transaction")
    : message{msg}
{}

const char *InvalidTransaction::what() const noexcept
{
    return message.c_str();
}
