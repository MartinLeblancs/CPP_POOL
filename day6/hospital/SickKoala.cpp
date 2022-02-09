/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** SickKoala
*/

#include <iostream>
#include <ostream>
#include <string>
#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{   
    name_ = name;
}

SickKoala::~SickKoala()
{
    bool oui;
    std::cout << "Mr." << this->name_ << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke(void)
{
    std::cout << "Mr." << this->name_ << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string str)
{
    if (str == "Mars") {
        std::cout << "Mr." << name_ << ": Mars, and it kreogs!" << std::endl;
        return (true);
    }
    else if (str == "Kinder") {
        std::cout << "Mr." << name_ << ": There is a toy inside!" << std::endl;
        return (true);
    }
    else {
        std::cout << "Mr." << name_ << ": Goerkreog!" << std::endl;
        return (false);
    }
}

void SickKoala::overDrive(std::string str)
{
    std::cout << "Mr." << name_ << ": ";
    if (str.find("Kreog!") != std::string::npos) {
    str.replace(str.find("Kreog!"), 6, "1337!");
    }
    std::cout << str << std::endl;
}

std::string SickKoala::getName()
{
    return(name_);
}