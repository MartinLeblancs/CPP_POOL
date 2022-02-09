/*
** EPITECH PROJECT, 2022
** ToyStory
** File description:
** ToyStory
*/

#include <iostream>
#include "Toy.hpp"

class ToyStory
{
    void tellMeAStory(const std::string &filename, Toy &toy1, bool Toy::*func1(std::string &str), Toy &toy2, bool Toy::*func2(std::string &str));
};