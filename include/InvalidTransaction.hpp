#ifndef INVALIDTRANSACTION_HPP
#define INVALIDTRANSACTION_HPP

#include <exception>
#include <string>

class InvalidTransaction : public std::exception{
public:
    InvalidTransaction(const std::string& msg);
    ~InvalidTransaction()noexcept override = default;

    const char* what() const noexcept override;
private:
    std::string message;
};

#endif