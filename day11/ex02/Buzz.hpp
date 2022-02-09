/*
** EPITECH PROJECT, 2022
** Buzz
** File description:
** BUZZ
*/

#ifndef __BUZZ__
#define __BUZZ__

#include "Toy.hpp"

class Buzz : public Toy
{
    public:
    Buzz(const std::string &name);
    Buzz(const std::string &name, const std::string &filename);
    Buzz(const Buzz &buzz);
    ~Buzz();
    Buzz &operator=(const Buzz &buzz);
};

#endif