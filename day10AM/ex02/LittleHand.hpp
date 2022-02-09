/*
** EPITECH PROJECT, 2022
** LittleHand
** File description:
** LittleHand
*/

#include "Coconut.hpp"
#include "FruitBox.hpp"

class LittleHand
{
    public:
        LittleHand();
        ~LittleHand();
        static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
        FruitBox * const * organizeCoconut (Coconut const * const * coconuts);
};