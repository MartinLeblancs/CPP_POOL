/*
** EPITECH PROJECT, 2022
** PRiest
** File description:
** Priest
*/

#ifndef __PRIEST__
#define __PRIEST__

#include "Enchanter.hpp"

class Priest : virtual public Enchanter
{
    public:
        Priest(const std::string &name_priest, int power_priest);
        ~Priest();
        void rest();
    private:
        std::string _Name_priest;
        int _Power_priest;
        int _Hp_priest;
};

#endif