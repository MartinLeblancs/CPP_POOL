/*
** EPITECH PROJECT, 2022
** Peasant.hpp
** File description:
** Peasant.hpp
*/

#ifndef __PEASANT__
#define __PEASANT__

#include <ostream>
#include <iostream>
#include "ICharacter.hpp"

class Peasant : public ICharacter
{
    public:
        Peasant(const std::string &name, int power);
        ~Peasant();
        const std::string &getName() const;
        void setPower(int power);
        int getPower() const;
        int getHp() const;
        void setHp(int hp);
        int attack();
        int special();
        void rest();
        void damage(int damage);
    private:
        std::string _Name;
        int _Power;
        int _Hp;
};

#endif