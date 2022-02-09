/*
** EPITECH PROJECT, 2022
** FruitBox
** File description:
** FruitBox
*/

#ifndef __FRUITBOX__
#define __FRUITBOX__

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox
{
    public:
        FruitBox(int size);
        ~FruitBox();
        int nbFruits();
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head();
        void printlist();

    private:
        FruitNode *list;
        int _size;
        int _nbFruits;
};

#endif