/*
** EPITECH PROJECT, 2022
** Icharacter
** File description:
** Icharacter
*/

#ifndef __ICHARACTER__
#define __ICHARACTER__

#include <string>

class ICharacter
{
    public:
        ICharacter() {};
        virtual ~ICharacter() {};
        virtual const std::string &getName() const = 0;
        virtual int getPower() const = 0;
        virtual int getHp() const = 0;
        virtual int attack() = 0;
        virtual int special() = 0;
        virtual void rest() = 0;
        virtual void damage(int damage) = 0;
};

#endif