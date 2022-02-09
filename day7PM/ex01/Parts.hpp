/*
** EPITECH PROJECT, 2022
** day7PM
** File description:
** Parts
*/

#ifndef __PARTS__
#define __PARTS__

#include <iostream>

class Arms
{
    public:
        Arms(const std::string &serial = "A-O1", bool functional = true);
        ~Arms();
        bool isFunctional();
        std::string serial();
        void informations();
    private:
        std::string _serial;
        bool _functional;
};

class Legs
{
    public:
        Legs(const std::string &serial = "L-O1", bool functional = true);
        ~Legs();
        bool isFunctional();
        std::string serial();
        void informations();
    private:
        std::string _serial;
        bool _functional;
};

class Head
{
    public:
        Head(const std::string &serial = "H-O1", bool functional = true);
        ~Head();
        bool isFunctional();
        std::string serial();
        void informations();
    private:
        std::string _serial;
        bool _functional;
};

#endif