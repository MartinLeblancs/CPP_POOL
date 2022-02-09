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

        enum ToyType {BASIC_TOY, ALIEN, BUZZ, WOODY};
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
        virtual void speak(std::string statement);
        Toy &operator<<(const std::string &pic);
        virtual bool speak_es(std::string statement);
        class Error
        {
            public:
            enum ErrorType {UNKNOWN, PICTURE, SPEAK};
            std::string what() const ;
            std::string where() const;
            void setWhat(std::string what);
            void setWhere(std::string where);
            void setType(ErrorType type);
            ErrorType type;
            private:
            std::string _what;
            std::string _where;
        };
        Error getLastError();
    protected:
        Error _error;
        std::string _name;
        Picture _picture;
        ToyType _type;
};

std::ostream &operator<<(std::ostream &os, const Toy &toy);


#endif