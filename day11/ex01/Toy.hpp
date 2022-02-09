/*
** EPITECH PROJECT, 2022
** Toy
** File description:
** Toy
*/

#ifndef __TOY__
#define __TOY__

#include "Picture.hpp"
#include <iostream>

class Toy
{
    public:
        enum ToyType {BASIC_TOY, ALIEN};
        Toy();
        Toy(const Toy &toy);
        ~Toy();
        Toy &operator=(const Toy &op);
        Toy(ToyType type, std::string name, std::string filename);
        ToyType getType() const;
        std::string getName() const;
        void setName(std::string name);
        bool setAscii(std::string filename);
        std::string getAscii() const;
    private:
        std::string _name;
        Picture _picture;
        ToyType _type;
};

#endif