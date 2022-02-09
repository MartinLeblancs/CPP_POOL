/*
** EPITECH PROJECT, 2022
** Paladin.hpp
** File description:
** Paladin.hpp
*/

#ifndef __PALADIN__
#define __PALADIN__

#include "Knight.hpp"
#include "Priest.hpp"

class Paladin : virtual public Knight, virtual public Priest
{
    public:
        Paladin(const std::string &name_paladin, int power_paladin);
        ~Paladin();
        int attack();
        int special();
        void rest();
    private:
        std::string _Name_paladin;
        int _Power_paladin;
        int _Hp_paladin;
};

#endif