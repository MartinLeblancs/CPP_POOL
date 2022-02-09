/*
** EPITECH PROJECT, 2022
** day7PM
** File description:
** Skat
*/

#ifndef __SKAT__
#define __SKAT__

#include <string>

class Skat
{
    public:
        Skat(const std::string &name, int stimPaks);
        Skat();
        ~Skat();
        int &stimPaks();
        const std::string &name();
        void shareStimPaks (int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();
    private:
        std::string _name;
        int _stimPaks;
};

#endif