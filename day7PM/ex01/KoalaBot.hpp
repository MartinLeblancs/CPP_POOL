/*
** EPITECH PROJECT, 2022
** day7PM
** File description:
** KoalaBot
*/

#ifndef __KOALABOT__
#define __KOALABOT__

#include <iostream>
#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot(const std::string &serial = "Bob-O1");
        ~KoalaBot();
        void setParts(Arms const &arms);
        void setParts(const Legs &legs);
        void setParts(const Head &head); 
        void swapParts(Arms &arms);
        void swapParts(Legs &legs);
        void swapParts(Head &head);
        void informations();
        bool status();
    private:
        std::string _serial = "Bob-O1";
        Arms _arms;
        Legs _legs;
        Head _head;
};

#endif