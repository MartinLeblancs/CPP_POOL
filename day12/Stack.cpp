/*
** EPITECH PROJECT, 2022
** Stack
** File description:
** Stack
*/

#include "Stack.hpp"

Stack::Error::Error(const std::string &message)
{
    _message = message;
}

void Stack::push(double value)
{
    stack.push(value);
}

double Stack::pop()
{
    double save_value = 0;

    if (stack.empty())
        throw Error("Empty stack");
    save_value = top();
    stack.pop();
    return (save_value);
}

double Stack::top() const
{
    if (stack.empty())
        throw Error("Empty stack");
    return (stack.top());
}

void Stack::add()
{
    double value1 = 0;
    double value2 = 0;

    if (stack.size() < 2)
        throw Error("Not enough operands");
    value1 = pop();
    value2 = pop();

    value1 += value2;
    push(value1);
}

void Stack::sub()
{
    double value1 = 0;
    double value2 = 0;

    if (stack.size() < 2)
        throw Error("Not enough operands");
    value1 = pop();
    value2 = pop();

    value1 -= value2;
    push(value1);
}

void Stack::mul()
{
    double value1 = 0;
    double value2 = 0;

    if (stack.size() < 2)
        throw Error("Not enough operands");
    value1 = pop();
    value2 = pop();

    value1 *= value2;
    push(value1);
}

void Stack::div()
{
    double value1 = 0;
    double value2 = 0;

    if (stack.size() < 2)
        throw Error("Not enough operands");

    value1 = pop();
    value2 = pop();

    value1 /= value2;
    push(value1);
}
