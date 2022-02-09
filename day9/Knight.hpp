/*
** EPITECH PROJECT, 2022
** Knight.hpp
** File description:
** Knight.hpp
*/

#ifndef __KNIGHT__
#define __KNIGHT__

#include <ostream>
#include <iostream>
#include "Peasant.hpp"

class Knight : virtual public Peasant
{
    public:
        Knight(const std::string &name_knight, int power);
        ~Knight();
        int attack();
        int special();
        void rest();
    private:
        std::string _Name_knight;
        int _Power_knight;
        int _Hp_knight;
};

#endif
