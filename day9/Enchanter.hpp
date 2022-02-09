/*
** EPITECH PROJECT, 2022
** enchanter.hpp
** File description:
** enchanter.hpp
*/

#ifndef __ENCHANTER__
#define __ENCHANTER__

#include <ostream>
#include <iostream>
#include "Peasant.hpp"

class Enchanter : virtual public Peasant
{
    public:
        Enchanter(const std::string &name_ench, int power_ench);
        ~Enchanter();
        int attack();
        int special();
        void rest();
    private:
        std::string _Name_ench;
        int _Power_ench;
        int _Hp_ench;
};

#endif
