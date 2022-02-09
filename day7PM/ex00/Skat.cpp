/*
** EPITECH PROJECT, 2022
** day7PM
** File description:
** Skat
*/

#include <iostream>
#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks)
{
    _name = name;
    _stimPaks = stimPaks;
}

Skat::Skat() : _name("bob"), _stimPaks(15)
{
    
}

Skat::~Skat()
{

}

int &Skat::stimPaks()
{
    return (_stimPaks);
}

const std::string &Skat::name()
{
    return (_name);
}

void Skat::shareStimPaks(int number, int &stock)
{
    stock += number;

    if (number > _stimPaks) {
        std::cout << "Don't be greedy" << std::endl;
    }
    else {
        _stimPaks -= number;
        std::cout << "Keep the change." << std::endl;
    }
}

void Skat::addStimPaks(unsigned int number)
{
    if(number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    else 
        _stimPaks += number;
}

void Skat::useStimPaks()
{
    if (_stimPaks == 0)
        std::cout << "Mediiiiiic" << std::endl;
    else 
    {
        _stimPaks -= 1;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    }
}

void Skat::status()
{
    std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir!" << std::endl;
}