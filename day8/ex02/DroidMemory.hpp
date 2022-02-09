/*
** EPITECH PROJECT, 2022
** ex00
** File description:
** DroidMemory
*/

#ifndef __DROIDMEMORY__
#define __DROIDMEMORY__

#include <ostream>
#include <iostream>
#include <stdlib.h>

class DroidMemory
{
    public:
        DroidMemory();
        DroidMemory(const DroidMemory &copy);
        ~DroidMemory();
        DroidMemory &operator=(const DroidMemory &copy);
        bool operator==(const DroidMemory &copy) const;
        bool operator!=(const DroidMemory &copy) const;
        bool operator<(const DroidMemory &copy) const;
        bool operator<(size_t exp) const;
        bool operator>(const DroidMemory &copy) const;
        bool operator>(size_t exp) const;
        bool operator<=(const DroidMemory &copy) const;
        bool operator<=(size_t exp) const;
        bool operator>=(const DroidMemory &copy) const;
        bool operator>=(size_t exp) const;
        DroidMemory &operator<<(const DroidMemory &copy);
        DroidMemory &operator>>( DroidMemory &copy) const;
        DroidMemory &operator+=(const DroidMemory &copy);
        DroidMemory &operator+=(const size_t &copy);
        DroidMemory &operator+(const DroidMemory &copy) const;
        DroidMemory &operator+(const size_t &copy) const;
        void setFingerprint(size_t fingerprint);
        size_t getFingerprint(void) const;
        void setExp(size_t exp);
        size_t getExp(void) const;
    private:
        size_t _Fingerprint;
        size_t _Exp;

};

std::ostream &operator<<(std::ostream& streaming, const DroidMemory &copy);

#endif