/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** KoalaNurse
*/

#ifndef __KOALA_NURSE__
#define __KOALA_NURSE__

#include "SickKoala.hpp"

class KoalaNurse {
    public:
        KoalaNurse(int id);
        ~KoalaNurse();
        void giveDrug(std::string, SickKoala *);
        void timeCheck(void);
        std::string readReport(std::string file_name);
    private:
    int id_;
    bool time_to_work_;
};

#endif
