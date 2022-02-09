/*
** EPITECH PROJECT, 2022
** Woody
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name) : Toy(WOODY, name, "woody.txt")
{
}

Woody::Woody(const std::string &name, const std::string &filename) : Toy(WOODY, name, filename)
{
}

Woody::Woody(const Woody &woody) : Toy(WOODY, woody._name, "")
{
    _picture = woody._picture;
}

Woody::~Woody()
{
}

Woody &Woody::operator=(const Woody &woody)
{
    _name = woody._name;
    _type = woody._type;
    _picture = woody._picture;

    return (*this);
}

void Woody::speak(std::string statement)
{
    std::cout << "WOODY: " << _name << " \"" << statement << "\"" << std::endl;
}