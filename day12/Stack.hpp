/*
** EPITECH PROJECT, 2022
** Stack
** File description:
** Stack
*/

#ifndef __STACK__
#define __STACK__

#include <stack>
#include <string>
#include <stdexcept>

class Stack
{
    public:
        void push (double value);
        double pop();
        double top() const;
        void add();
        void sub();
        void mul();
        void div();
        class Error : public std::exception
        {
            public:
                Error(const std::string &message);
                const char* what() const throw(){return (this->_message.c_str());};
            private:
                std::string _message;
        };
    private:
        std::stack<double> stack;
};



#endif