/*
** EPITECH PROJECT, 2022
** ex00
** File description:
** Droid
*/

#include <iostream>
#include <ostream>
#include "Droid.hpp"

Droid::Droid(std::string id) : _Id(id), _Energy(50), _Attack(25), _Toughness(15), _Status(new std::string ("Standing by"))
{
    std::cout << "Droid '" << _Id << "' Activated" << std::endl;
}

Droid::Droid() : _Id(""), _Energy(50), _Attack(25), _Toughness(15), _Status(new std::string ("Standing by"))
{
    std::cout << "Droid '' Activated" << std::endl;
}

Droid::~Droid()
{
    delete _Status;
    std::cout << "Droid '" << _Id  << "' Destroyed" << std::endl; 
}

Droid::Droid(const Droid &copy) : _Id(copy.getId()), _Energy(copy.getEnergy()), _Attack(25), _Toughness(15), _Status(new std::string (*copy.getStatus()))
{
    std::cout << "Droid '" << _Id  << "' Activated, Memory Dumped" << std::endl;
}

size_t Droid::getEnergy() const 
{
    return(_Energy);
}

std::string *Droid::getStatus() const 
{
    return(_Status);
}

size_t Droid::getAttack() const 
{
    return(_Attack);
}

size_t Droid::getToughness() const 
{
    return(_Toughness);
}

std::string Droid::getId() const 
{
    return(_Id);
}

void Droid::setEnergy(size_t energy)
{
    _Energy = energy;
}

void Droid::setStatus(std::string *status)
{
    _Status = status;
}

void Droid::setId(std::string id)
{
    _Id = id;
}

Droid &Droid::operator=(const Droid &copy)
{
    if (&copy != this)
    {
        _Id = copy.getId();
        _Energy = copy.getEnergy();
        if (_Status)
            delete _Status;
        _Status = new std::string (*copy.getStatus());
    }

    return(*this);
}

bool Droid::operator==(const Droid &copy) const
{
    return (_Id == copy.getId() || _Status == copy.getStatus() || _Energy == copy.getEnergy());
}

bool Droid::operator!=(const Droid &copy) const
{
    return(_Id != copy.getId() || _Status != copy.getStatus() || _Energy != copy.getEnergy());
}

std::ostream &operator<<(std::ostream &streaming, const Droid &obj)
{
    if (obj.getEnergy() > 100)
        streaming << "Droid '" << obj.getId() << "', " <<  *obj.getStatus() << ", 100";
    else
        streaming << "Droid '" << obj.getId() << "', " <<  *obj.getStatus() << ", " << obj.getEnergy();
    return (streaming);
}

Droid &Droid::operator<<(size_t &energy)
{
    size_t value;

    if (this->_Energy >= 100) {
        this->_Energy = 100;
        return (*this);
    }
    if (this->_Energy + energy >= 100)
        value = 100 - this->_Energy;
    else
        value = energy;
    this->_Energy += value;
    energy -= value;
    return (*this);
}
