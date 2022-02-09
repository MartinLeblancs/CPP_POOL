/*
** EPITECH PROJECT, 2022
** Buzz
** File description:
** BUZZ
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name) : Toy(BUZZ, name, "buzz.txt")
{
}

Buzz::Buzz(const std::string &name, const std::string &filename) : Toy(BUZZ, name, filename)
{
}

Buzz::Buzz(const Buzz &buzz) : Toy(BUZZ, buzz._name, "")
{
    _picture = buzz._picture;
}

Buzz::~Buzz()
{
}

Buzz &Buzz::operator=(const Buzz &buzz)
{
    _name = buzz._name;
    _type = buzz._type;
    _picture = buzz._picture;

    return (*this);
}

void Buzz::speak(std::string statement)
{
    std::cout << "BUZZ: " << _name << " \"" << statement << "\"" << std::endl;
}