#include "AccountNotFound.hpp"

AccoutNotFound::AccoutNotFound(const std::string &msg)
    : messege{msg}
{}

const char *AccoutNotFound::what() const noexcept
{
    return messege.c_str();
}
