/*
** EPITECH PROJECT, 2022
** day7PM
** File description:
** KoalaBot
*/

#include <ostream>
#include <iostream>
#include "KoalaBot.hpp"

KoalaBot::KoalaBot(const std::string &serial)
{
    _serial = serial;
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(const Arms &arms)
{
    _arms = arms;
}

void KoalaBot::setParts(const Legs &legs)
{
    _legs = legs;
}

void KoalaBot::setParts(const Head &head)
{
    _head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    Arms temp;
    temp = _arms;
    _arms = arms;
    arms = temp;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs tmp;
    temp = _legs;
    _legs = legs;
    legs = temp;
}

void KoalaBot::swapParts(Head &head)
{
    Head temp;
    temp = _head;
    _head = head;
    head = temp;
}

void KoalaBot::informations()
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    this->_arms.informations();
    std::cout << std::endl;
    this->_legs.informations();
    std::cout << std::endl;
    this->_head.informations();
    std::cout << std::endl;
}

bool KoalaBot::status()
{
    if (this->_arms.isFunctional() == true && this->_legs.isFunctional() == true && this->_head.isFunctional() == true)
        return (true);
    else 
        return (false);
}


 