/*
** EPITECH PROJECT, 2022
** paladin
** File description:
** paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name_paladin, int power_paladin) : Peasant(name_paladin, power_paladin),
                                                                       Knight(name_paladin, power_paladin),
                                                                       Enchanter(name_paladin, power_paladin),
                                                                       Priest(name_paladin, power_paladin)


{
    _Name_paladin = name_paladin;
    if (power_paladin > 100)
        _Power_paladin = 100;
    else
        _Power_paladin = power_paladin;
    setHp(100);
    _Hp_paladin = 100;

    std::cout << _Name_paladin << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << _Name_paladin << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return (Paladin::Knight::attack());
}

int Paladin::special()
{
    return(Paladin::Enchanter::special());
}

void Paladin::rest()
{
    Paladin::Priest::rest();
}
