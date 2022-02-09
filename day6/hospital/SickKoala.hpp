/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** SickKoala
*/

#ifndef __SICK_KOALA__
#define __SICK_KOALA__

#include <iostream>

class SickKoala {
    public:
        SickKoala(std::string name);
        ~SickKoala();
        void poke(void);
        bool takeDrug(std::string str);
        void overDrive(std::string str);
        std::string getName();
    private:
        std::string name_;
};

#endif