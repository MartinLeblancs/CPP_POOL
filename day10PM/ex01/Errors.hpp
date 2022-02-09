#pragma once

#include <string>

class NasaError : public std::exception
{
    public:
    NasaError(std::string const &message,
              std::string const &component = "Unknown");
    std::string const &getComponent() const;
    virtual ~NasaError() throw() {};
    const char* what() const throw(){  return this->_message.c_str(); };
    private:
    std::string _message;
    std::string	_component;
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message, std::string const &component = "Unknown");
        ~MissionCriticalError() throw() {};
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message, std::string const &component = "Unknown");
        ~LifeCriticalError() throw() {};
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message, std::string const &component = "Unknown");
        ~UserError() throw() {};
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
        ~CommunicationError() throw() {};
};
