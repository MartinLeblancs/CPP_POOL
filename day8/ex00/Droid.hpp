/*
** EPITECH PROJECT, 2022
** ex00
** File description:
** Droid
*/

#ifndef __DROID__
#define __DROID__

#include <iostream>

class Droid {
    public:
        Droid(std::string serial);
        Droid(const Droid &copy);
        Droid();
        ~Droid();
        
        Droid &operator=(const Droid &copy);
        bool operator==(const Droid &copy) const;
        bool operator!=(const Droid &copy) const;
        Droid &operator<<(size_t &energy);
        size_t getEnergy() const;
        std::string *getStatus() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string getId() const;
        void setEnergy(size_t energy);
        void setStatus(std::string *status);
        void setId(std::string id);
    private:
        std::string _Id;
        size_t _Energy;
        const size_t _Attack;
        const size_t _Toughness;
        std::string *_Status;
};

std::ostream &operator <<(std::ostream &os, const Droid &obj);

#endif