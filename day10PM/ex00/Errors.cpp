/*
** EPITECH PROJECT, 2022
** errors
** File description:
** errors
*/

#include <iostream>
#include "Errors.hpp"

const char *NasaError::what() const throw()
{
    return (_message.c_str());
}

NasaError::NasaError(std::string const &message, std::string const &component)
{
    _message = message;
    _component = component;
}

std::string const &NasaError::getComponent() const
{
    return (_component);
}

MissionCriticalError::MissionCriticalError(const std::string &message, const std::string &component)
                                          : NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(const std::string &message, const std::string &component)
                                    : NasaError(message, component)
{
}

UserError::UserError(const std::string &message, const std::string &component)
                    : NasaError(message, component)
{
}

CommunicationError::CommunicationError(const std::string &message)
                                      : NasaError(message, "CommunicationDevice")
{
}
