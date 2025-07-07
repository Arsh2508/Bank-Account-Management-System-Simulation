#include "AccountNotFound.hpp"

AccountNotFound::AccountNotFound(const std::string &msg)
    : messege{msg}
{}

const char *AccountNotFound::what() const noexcept
{
    return messege.c_str();
}
