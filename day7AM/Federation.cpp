/*
** EPITECH PROJECT, 2022
** day7AM
** File description:
** Federation
*/


#include <iostream>
#include <ostream>
#include <string>
#include "WarpSystem.hpp"
#include "Federation.hpp"
#include "Borg.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = maxWarp;
    _home = EARTH;
    _shield = 100;

    _location = _home;
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
    if (_photonTorpedo != 0)
        std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::Ship() : _shield(100),
{
    std::cout << "The ship USS Entreprise has been finished." << std::endl;
    std::cout << "It is 289 m  in length and 132 m in width." << std::endl;
    std::cout << "It can go to Warp 6!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{

}

Federation::Ship::Ship(int length, int width, std::string name)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = 1;
    _home = VULCAN;

    _location = _home;
    std::cout << "The independent ship " << _name << " just finished its construction." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{

}

Federation::Starfleet::Captain::Captain(std::string name)
{
    _name = name;
}

Federation::Starfleet::Captain::~Captain()
{
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    _name = name;
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::cout << "USS " ;
    std::cout << _name << ": The core is ";
    if (this->_core->checkReactor()->isStable() == true)
        std::cout << "stable";
    else 
        std::cout << "unstable";
    std::cout << " at the time." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::cout << _name << ": The core is ";
    if (this->_core->checkReactor()->isStable() == true)
        std::cout << "stable";
    else 
        std::cout << "unstable";
    std::cout << " at the time." << std::endl;
}

std::string Federation::Starfleet::Captain::getName()
{
    return (_name);
}

int Federation::Starfleet::Captain::getAge()
{
    return(_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    captain_ = captain;
    std::cout << this->captain_->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    _location = d;
    if ((warp <= _maxWarp) && (d != _location) && (this->_core->checkReactor()->isStable() == true)) 
        return (true);
    else 
        return (false);
}

bool Federation::Ship::move(int warp)
{
    _location = _home;
    if ((warp <= _maxWarp) && (d != _location) && (this->_core->checkReactor()->isStable() == true)) 
        return (true);
    else 
        return (false);
}

bool Federation::Ship::move(Destination d)
{
    _location = d;
    if ((warp <= _maxWarp) && (d != _location) && (this->_core->checkReactor()->isStable() == true)) 
        return (true);
    else 
        return (false);
}

bool Federation::Ship::move()
{
    _location = _home;
    if ((warp <= _maxWarp) && (d != _location) && (this->_core->checkReactor()->isStable() == true)) 
        return (true);
    else 
        return (false);
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    _location = d;
    if ((warp <= _maxWarp) && (d != _location) && (this->_core->checkReactor()->isStable() == true)) 
        return (true);
    else 
        return (false);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    _location = _home;
    if ((warp <= _maxWarp) && (d != _location) && (this->_core->checkReactor()->isStable() == true)) 
        return (true);
    else 
        return (false);
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    _location = d;
    if ((warp <= _maxWarp) && (d != _location) && (this->_core->checkReactor()->isStable() == true)) 
        return (true);
    else 
        return (false);
}

bool Federation::Starfleet::Ship::move()
{
    _location = _home;
    if ((warp <= _maxWarp) && (d != _location) && (this->_core->checkReactor()->isStable() == true)) 
        return (true);
    else 
        return (false);
}

int Federation::Starfleet::Ship::getShield()
{
    return (_shield);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return (_photonTorpedo);
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo -= 1;
    std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (_photonTorpedo != 0) {
        _photonTorpedo -= 1;
        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
    }
    else
        std::cout << _name ": No enough torpedoes to fire, " << this->captain_->getName() << "!" << std::endl;
    if (_photonTorpedo == 0)
        std::cout << _name << ": No more torpedo to fire, " << captain_->getName() << "!" << std::endl
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (_photonTorpedo - torpedoes >= 0) {
        _photonTorpedo -= torpedoes;
        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
        target->_shield -= 50 * torpedoes;
    }
    else
        std::cout << _name ": No enough torpedoes to fire, " << this->captain_->getName() << "!" << std::endl;
    if (_photonTorpedo == 0)
        std::cout << _name << ": No more torpedo to fire, " << captain_->getName() << "!" << std::endl
}
