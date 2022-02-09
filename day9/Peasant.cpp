/*
** EPITECH PROJECT, 2022
** Peasant.cpp
** File description:
** Peasant.cpp
*/

#include "Peasant.hpp"

Peasant::Peasant(const std::string &name, int power)
{
    _Name = name;
    _Hp = 100;
    if (power <= 100)
        _Power = power;
    else
        _Power = 100;
    std::cout << _Name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << _Name << " is back to his crops." << std::endl;
}

const std::string &Peasant::getName() const
{
    return(_Name);
}

int Peasant::getPower() const
{
    return (_Power);
}

void Peasant::setPower(int power)
{
    _Power = power;
}

int Peasant::getHp() const
{
    return (_Hp);
}

void Peasant::setHp(int hp)
{
    _Hp = hp;
}

int Peasant::attack()
{
    int damage = 5;

    if (_Hp <= 0) {
        _Hp = 0;
        std::cout << _Name << " is out of combat." << std::endl;
        return (0);
    }
    if (_Power < 10) {
        std::cout << _Name << " is out of power." << std::endl;
        return (0);
    }
    _Power -= 10;
    std::cout << _Name << " tosses a stone." << std::endl;

    return (damage);
}

int Peasant::special()
{
    int damage = 0;

    if (_Hp <= 0) {
        _Hp = 0;
        std::cout << _Name << " is out of combat." << std::endl;
        return (0);
    }
    std::cout << _Name << " doesn't know any special move." << std::endl;

    return (damage);
}

void Peasant::rest()
{
    if (_Hp <= 0) {
        _Hp = 0;
        std::cout << _Name << " is out of combat." << std::endl;
        return;
    }
    if (_Power + 30 > 100)
        _Power = 100;
    else
        _Power += 30;
    std::cout << _Name << " takes a nap." << std::endl;
}

void Peasant::damage(int damage)
{
    _Hp -= damage;
    if (_Hp <= 0) {
        _Hp = 0;
        std::cout << _Name << " is out of combat." << std::endl;
        return;
    }
    std::cout << _Name << " takes " << damage << " damage." << std::endl;
}