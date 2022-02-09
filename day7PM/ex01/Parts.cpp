/*
** EPITECH PROJECT, 2022
** day7PM
** File description:
** Parts
*/

#include "Parts.hpp"

Arms::Arms(const std::string &serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

Arms::~Arms()
{
}

Legs::Legs(const std::string &serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

Legs::~Legs()
{
}

Head::Head(const std::string &serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

Head::~Head()
{   
}

bool Arms::isFunctional()
{
    return (_functional);
}

std::string Arms::serial()
{
    return (_serial);
}

void Arms::informations()
{
    std::cout << "\t[Parts] Arms " << _serial << " status : "; 
    if (this->isFunctional() == true)
        std::cout << "OK";
    else 
        std::cout << "KO";
}
bool Legs::isFunctional()
{
    return(_functional);
}

std::string Legs::serial()
{
    return (_serial);
}

void Legs::informations()
{
    std::cout << "\t[Parts] Legs " << _serial << " status : "; 
    if (this->isFunctional() == true)
        std::cout << "OK";
    else 
        std::cout << "KO";
}
bool Head::isFunctional()
{
    return (_functional);
}

std::string Head::serial()
{
    return (_serial);
}

void Head::informations()
{
    std::cout << "\t[Parts] Head " << _serial << " status : "; 
    if (this->isFunctional() == true)
        std::cout << "OK";
    else 
        std::cout << "KO";
}