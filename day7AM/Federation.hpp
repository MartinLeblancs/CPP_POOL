/*
** EPITECH PROJECT, 2022
** day7AM
** File description:
** Federation
*/

#ifndef __FEDERATION__
#define __FEDERATION__

#include <string>
#include "WarpSystem.hpp"
#include "Borg.hpp"
#include "Destination.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Captain
        {
            public:
                Captain(std::string name);
                ~Captain();
                std::string getName();
                int getAge();
                void setAge(int age);
            private:
                std::string _name;
                int _age;
        };
        class Ship 
        {
            public:
                Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
                Ship();
                ~Ship();
                void checkCore();4
                void setupCore(WarpSystem::Core *core);
                void promote(Captain *captain);
                bool move(int warp, Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move();
                int getShield();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *target);
                void fire(int torpedoes, Borg::Ship *target);
            private:
                int _shield;
                int _photonTorpedo;
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Captain *captain_;
                Destination _location;
                Destination _home;
                int warp;
                Destination d;
        };
        class Ensign
        {
            public:
                explicit Ensign(std::string name);
                ~Ensign();
            private:
                std::string _name;
        };
    }   
    class Ship 
    {
        public:
            Ship(int length, int width, std::string name);
            ~Ship();
            void checkCore();
            void setupCore(WarpSystem::Core *core);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            WarpSystem::Core *getCore()
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;
            int warp;
            Destination d;
        };
}

#endif