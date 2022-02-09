/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** KoalaDoctor
*/

#include <iostream>
#include "SickKoala.hpp"

class KoalaDoctor {
    public:
        KoalaDoctor(std::string name);
        ~KoalaDoctor();
        void diagnose(SickKoala *sickkoala);
        void timeCheck();

    private:
        std::string _name;
        int time_to_work;
};
