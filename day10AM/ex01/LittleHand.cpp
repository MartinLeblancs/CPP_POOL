/*
** EPITECH PROJECT, 2022
** LittleHand
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{

}

LittleHand::~LittleHand()
{

}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    FruitBox temp(unsorted.nbFruits());
    Fruit *fruit;
    while ((fruit = unsorted.pickFruit()))
    {
        if (fruit->getName() == "lemon") {
            if (!(lemons.putFruit(fruit)))
                temp.putFruit(fruit);
        }
        else if (fruit->getName() == "banana") {
            if (!(bananas.putFruit(fruit)))
                temp.putFruit(fruit);
        }
        else if (fruit->getName() == "lime") {
            if (!(limes.putFruit(fruit)))
                temp.putFruit(fruit);
        }
        else {
            temp.putFruit(fruit);
        }
    }
    while ((fruit = temp.pickFruit()))
        unsorted.putFruit(fruit);
}