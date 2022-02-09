/*
** EPITECH PROJECT, 2022
** Buzz
** File description:
** BUZZ
*/

#ifndef __BUZZ__
#define __BUZZ__

#include <iostream>
#include "Toy.hpp"

class Buzz : public Toy
{
    public:
    Buzz(const std::string &name);
    Buzz(const std::string &name, const std::string &filename);
    Buzz(const Buzz &buzz);
    ~Buzz();
    Buzz &operator=(const Buzz &buzz);
    void speak(std::string statement);
    bool speak_es(std::string statement);
};

#endif