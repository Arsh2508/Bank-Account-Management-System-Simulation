#ifndef ACCOUTNOTFOUND_HPP 
#define ACCOUTNOTFOUND_HPP

#include <exception>
#include <string>

class AccountNotFound : public std::exception{
public:
    AccountNotFound(const std::string& msg);
    ~AccountNotFound() noexcept override = default;

    const char* what()const noexcept override;
private:
    std::string messege;
};

#endif