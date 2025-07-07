#ifndef ACCOUTNOTFOUND_HPP 
#define ACCOUTNOTFOUND_HPP

#include <exception>
#include <string>

class AccoutNotFound : public std::exception{
public:
    AccoutNotFound(const std::string& msg);
    ~AccoutNotFound() noexcept override = default;

    const char* what()const noexcept override;
private:
    std::string messege;
};

#endif