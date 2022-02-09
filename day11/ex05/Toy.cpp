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

Toy::Toy(const Toy &toy)
{
    _type = toy.getType();
    _name = toy.getName();
    _picture.data = toy.getAscii();
}

Toy::~Toy()
{
}

Toy &Toy::operator=(const Toy &toy)
{
    _name = toy._name;
    _type = toy._type;
    _picture = toy._picture;

    return (*this);
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
    if (_picture.getPictureFromFile(filename))
        return (true);
    else
    {
        _error.setWhat("bad new illustration");
        _error.setWhere("setAscii");
        _error.setType(Toy::Error::PICTURE);
        return (false);
    }
}
std::string Toy::getAscii() const
{
    return (_picture.data);
}

void Toy::Error::setWhat(std::string what)
{
    _what = what;
}

void Toy::Error::setWhere(std::string where)
{
    _where = where;
}

void Toy::Error::setType(ErrorType type)
{
    this->type = type;
}

void Toy::speak(std::string statement)
{

    std::cout << _name << " \"" << statement << "\"" << std::endl;
}

Toy::Error Toy::getLastError()
{
    return (_error);
}

std::ostream &operator<<(std::ostream &os, const Toy &toy)
{
    os << toy.getName() << std::endl;
    os << toy.getAscii() << std::endl;

    return (os);
}

Toy &Toy::operator<<(const std::string &pic)
{
    _picture.data = pic;
    return (*this);
}

bool Toy::speak_es(std::string statement)
{
    (void) statement;
    _error.setWhat("wrong mode");
    _error.setWhere("speak_es");
    _error.setType(Toy::Error::SPEAK);
    return (false);
}

std::string Toy::Error::what() const
{
    return (_what);
}
std::string Toy::Error::where() const
{
    return (_where);
}
