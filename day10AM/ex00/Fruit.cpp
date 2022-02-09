/*
** EPITECH PROJECT, 2022
** Fruit
** File description:
** Fruit
*/

#include <iostream>
#include "Fruit.hpp"

Fruit::Fruit(const std::string &name, int vitamins)
{
    _vitamins = vitamins;
    _name = name;
}

Fruit::~Fruit()
{
}


int Fruit::getVitamins()
{
    return (_vitamins);
}

std::string Fruit::getName()
{
    return (_name);
}