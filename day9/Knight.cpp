/*
** EPITECH PROJECT, 2022
** Knight.cpp
** File description:
** Knight.cpp
*/

#include "Knight.hpp"

Knight::Knight(const std::string &name_knight, int power_knight) : Peasant(name_knight, power_knight)
{
    _Name_knight = name_knight;
    if (power_knight > 100)
        _Power_knight = 100;
    else
        _Power_knight = power_knight;

    setHp(100);
    _Hp_knight = 100;
    std::cout << _Name_knight << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << _Name_knight << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    int damage = 20;

    if (getHp() <= 0) {
        setHp(0);
        std::cout << _Name_knight << " is out of combat." << std::endl;
        return (0);
    }
    if (getPower() < 10) {
        std::cout << _Name_knight << " is out of power." << std::endl;
        return (0);
    }
    setPower(getPower() - 10);
    std::cout << _Name_knight << " strikes with his sword." << std::endl;

    return (damage);
}

int Knight::special()
{
    int damage = 50;

    if (getHp() <= 0) {
        setHp(0);
        std::cout << _Name_knight << " is out of combat." << std::endl;
        return (0);
    }
    if (getPower() < 30) {
        std::cout << _Name_knight << " is out of power." << std::endl;
        return (0);
    }
    setPower(getPower() - 30);
    std::cout << _Name_knight << " impales his enemy." << std::endl;

    return (damage);
}
void Knight::rest()
{
    if (getHp() <= 0) {
        setHp(0);
        std::cout << _Name_knight << " is out of combat." << std::endl;
        return;
    }
    if (getPower() + 50 > 100)
        setPower(100);
    else
        setPower(getPower() + 50);
    std::cout << _Name_knight << " eats." << std::endl;
}