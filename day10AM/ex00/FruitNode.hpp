/*
** EPITECH PROJECT, 2022
** FruitNode
** File description:
** FruitNode
*/

#ifndef __FRUITNODE__
#define __FRUITNODE__

#include "Fruit.hpp"

struct FruitNode
{
    Fruit *fruit;
    struct FruitNode *next;
};

#endif