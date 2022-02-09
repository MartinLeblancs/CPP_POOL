/*
** EPITECH PROJECT, 2022
** Fruit
** File description:
** Fruit
*/

#ifndef __FRUIT__
#define __FRUIT__

#include <iostream>
#include <string>

class Fruit
{
    public:
        Fruit(const std::string &name, int vitamins);
        ~Fruit();
        int getVitamins();
        std::string getName();

    protected:
        int _vitamins;
        std::string _name ;
};

#endif