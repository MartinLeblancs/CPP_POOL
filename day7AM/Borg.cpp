/*
** EPITECH PROJECT, 2022
** day7AM
** File description:
** Borg
*/

#include <iostream>
#include <ostream>
#include "Borg.hpp"

Borg::Ship::Ship(int weaponfrequency)
{
    _side = 300;
    _maxWarp = 9;
    _shield = 100;
    _weaponFrequency = weaponfrequency;
    _repair = 3;
    _home = UNICOMPLEX;

    _location = _home;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::Ship(int weaponfrequency, int repair)
{
    _side = 300;
    _maxWarp = 9;
    _shield = 100;
    _weaponFrequency = weaponfrequency;
    _repair = repair
    _home = UNICOMPLEX;

    _location = _home;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}

void Borg::Ship::checkCore()
{
    if (this->_core->checkReactor()->isStable() == true)
        std::cout << "Everything is in order." << std::endl;
    else 
        std::cout << "Critical failure imminent" << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    _location = d;
    if ((warp <= _maxWarp) && (d != _location) && (this->_core->checkReactor()->isStable() == true)) 
        return (true);
    else 
        return (false);
}

bool Borg::Ship::move(int warp)
{
    _location = _home;
    if ((warp <= _maxWarp) && (d != _location) && (this->_core->checkReactor()->isStable() == true)) 
        return (true);
    else 
        return (false);
}

bool Borg::Ship::move(Destination d)
{
    _location = d;
    if ((warp <= _maxWarp) && (d != _location) && (this->_core->checkReactor()->isStable() == true)) 
        return (true);
    else 
        return (false);
}

bool Borg::Ship::move()
{
    _location = _home;
    if ((warp <= _maxWarp) && (d != _location) && (this->_core->checkReactor()->isStable() == true)) 
        return (true);
    else 
        return (false);
}

int Borg::Ship::getShield()
{
    return (_shield);
}

void Borg::Ship::setShield(int shield)
{
    _shield = shield;
}

int Borg::Ship::getWeaponFrequency()
{
    return (_weaponFrequency);
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    _weaponFrequency = frequency;
}

short Borg::Ship::getRepair()
{
    return (_repair);
}

void Borg::Ship::setRepair(short repair)
{
    _repair = repair;
}

void Borg::Ship::fire (Federation::Starfleet::Ship *target)
{
    target->_shield -= _weaponFrequency;
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency" << std::endl;
}

void Borg::Ship::fire (Federation::Ship *target)
{
        target->_core->checkReactor()->isStable() = false;
        std::cout << "Firing on target with " << _weaponFrequency << "GW frequency" << std::endl;

}

void Borg::Ship::repair ()
{
    if (_repair > 0) {
        _repair -= 1;
        _shield = 100;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    }
    else
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
}
