/*
** EPITECH PROJECT, 2022
** enchanter
** File description:
** enchanter
*/

#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string &name_ench, int power_ench) : Peasant(name_ench, power_ench)
{
    _Name_ench = name_ench;
    if (power_ench > 100)
        _Power_ench = 100;
    else
        _Power_ench = power_ench;
    setHp(100);
    _Hp_ench = 100;
    std::cout << _Name_ench << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << _Name_ench << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    int damage = 0;

    if (getHp() <= 0) {
        setHp(0);
        std::cout << _Name_ench << " is out of combat." << std::endl;
        return (0);
    }
    std::cout << _Name_ench << " doesn't know how to fight." << std::endl;

    return (damage);
}

int Enchanter::special()
{
    int damage = 99;

    if (getHp() <= 0) {
        setHp(0);
        std::cout << _Name_ench << " is out of combat." << std::endl;
        return (0);
    }
    if (getPower() < 50) {
        std::cout << _Name_ench << " is out of power." << std::endl;
        return (0);
    }
    setPower(getPower() - 50);
    std::cout << _Name_ench << " casts a fireball." << std::endl;

    return (damage);
}

void Enchanter::rest()
{
    if (getHp() <= 0) {
        setHp(0);
        std::cout << _Name_ench << " is out of combat." << std::endl;
        return;
    }
    setPower(100);
    std::cout << _Name_ench << " meditates." << std::endl;
}