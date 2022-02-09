/*
** EPITECH PROJECT, 2022
** LittleHand
** File description:
** LittleHand
*/

#ifndef __LITTLEHAND__
#define __LITTLEHAND__

#include "FruitBox.hpp"

class LittleHand
{
    public:
    LittleHand();
    ~LittleHand();
    void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
};

#endif