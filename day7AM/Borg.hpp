/*
** EPITECH PROJECT, 2022
** day7AM
** File description:
** Borg
*/

#ifndef __BORG__
#define __BORG__


#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Borg
{
    class Ship
    {
        public:
        Ship(int weaponfrequency);
        Ship(int weaponfrequency, int repair);
        ~Ship();
        void setupCore(WarpSystem::Core *core);
        void checkCore();
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
        int getShield();
        void setShield(int shield);
        int getWeaponFrequency();
        void setWeaponFrequency(int frequency);
        short getRepair();
        void setRepair(short repair);
        void fire (Federation::Starfleet::Ship *target);
        void fire (Federation::Ship *target);
        void repair ();
        private:
        private:
            int _side;
            short _maxWarp; 
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;
            int warp;
            Destination d;
            int _shield;
            int _weaponFrequency;
            int _repair;
    };
}

#endif