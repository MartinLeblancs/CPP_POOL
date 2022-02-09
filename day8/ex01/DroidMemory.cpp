/*
** EPITECH PROJECT, 2022
** ex01
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : _Exp(0), _Fingerprint(random())
{

}

DroidMemory::DroidMemory(const DroidMemory &copy) : _Exp(copy._Exp), _Fingerprint(copy._Fingerprint)
{

}

DroidMemory::~DroidMemory()
{

}

size_t DroidMemory::getExp() const
{
    return (_Exp);
}

void DroidMemory::setExp(size_t exp)
{
    _Exp = exp;
}

size_t DroidMemory::getFingerprint() const
{
    return (_Fingerprint);
}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    _Fingerprint = fingerprint;
}

DroidMemory &DroidMemory::operator=(const DroidMemory &copy)
{
    if (&copy != this) {
        _Fingerprint = copy._Fingerprint;
        _Exp = copy._Exp;
    }
    return (*this);
}

DroidMemory &DroidMemory::operator<<(const DroidMemory &copy)
{
    _Exp += copy.getExp();
    _Fingerprint = _Fingerprint xor copy.getFingerprint();

    return (*this);
}

DroidMemory &DroidMemory::operator>>(DroidMemory &copy) const
{
    copy._Exp = _Exp + copy.getExp();
    copy._Fingerprint = copy.getFingerprint() xor _Fingerprint;

    return (copy);
}

DroidMemory &DroidMemory::operator+=(const DroidMemory &copy)
{
    _Exp += copy.getExp();
    _Fingerprint = _Fingerprint xor copy.getFingerprint();

    return (*this);
}

DroidMemory &DroidMemory::operator+=(const size_t &copy)
{
    _Exp += copy;
    _Fingerprint = _Fingerprint xor copy;

    return (*this);
}

DroidMemory &DroidMemory::operator+(const DroidMemory &copy) const
{
    DroidMemory *temp = new DroidMemory();

    temp->_Exp = _Exp + copy.getExp();
    temp->_Fingerprint = _Fingerprint xor copy.getFingerprint();

    return (*temp);
}

DroidMemory &DroidMemory::operator+(const size_t &copy) const
{
    DroidMemory *temp = new DroidMemory();

    temp->_Exp = _Exp + copy;
    temp->_Fingerprint = _Fingerprint xor copy;

    return (*temp);
}

std::ostream &operator<<(std::ostream& streaming, const DroidMemory &copy)
{
    streaming << "DroidMemory '" << copy.getFingerprint() << "', " << copy.getExp();
    return (streaming);
}


