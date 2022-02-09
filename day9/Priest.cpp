/*
** EPITECH PROJECT, 2022
** Priest
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name_priest, int power_priest) : Peasant(name_priest, power_priest), Enchanter(name_priest, power_priest)
{
    _Name_priest = name_priest;
    if (power_priest > 100)
        power_priest = 100;
    else
        _Power_priest = power_priest;
    setHp(100);
    _Hp_priest = 100;

    std::cout << _Name_priest << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << _Name_priest << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (getHp() <= 0) {
        setHp(0);
        std::cout << _Name_priest << " is out of combat." << std::endl;
        return;
    }
    setPower(100);
    setHp(100);
    std::cout << _Name_priest << " prays." << std::endl;
}