/*
** EPITECH PROJECT, 2022
** Woody
** File description:
** Woody
*/

#ifndef __WOODY__
#define __WOODY__

#include "Toy.hpp"

class Woody : public Toy
{
    public:
    Woody(const std::string &name);
    Woody(const std::string &name, const std::string &filename);
    Woody(const Woody &woody);
    ~Woody();
    Woody &operator=(const Woody &woody);
};

#endif