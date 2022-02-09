/*
** EPITECH PROJECT, 2022
** COmmand
** File description:
** Command
*/

#include <map>
#include <iostream>
#include <functional>
#include "Stack.hpp"

class Command
{
    public:
        void registerCommand (const std::string &name, const std::function <void ()> &function);
        void executeCommand(const std::string &name);
        class Error : public std::exception
        {
            public:
            Error(const std::string &message){_message = message;};
            const char* what() const throw(){return (this->_message.c_str());};
            private:
            std::string _message;
        };
    private:
        std::map<std::string, std::function<void()>> _map;
};