/*
** EPITECH PROJECT, 2022
** Toy
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    _type = BASIC_TOY;
    _name = "toy";
    _picture = Picture();
}

Toy::Toy(ToyType type, std::string name, std::string filename)
{
    _type = type;
    _name = name;
    _picture = Picture(filename);
}

Toy::ToyType Toy::getType() const
{
    return (_type);
}

std::string Toy::getName() const
{
    return (_name);
}

void Toy::setName(std::string name)
{
    _name = name;
}

bool Toy::setAscii(std::string filename)
{
    return (_picture.getPictureFromFile(filename));
}
std::string Toy::getAscii() const
{
    return (_picture.data);
}