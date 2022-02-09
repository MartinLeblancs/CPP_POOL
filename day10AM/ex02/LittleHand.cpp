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
            if (lemons.putFruit(fruit) == false)
                temp.putFruit(fruit);
        }
        else if (fruit->getName() == "banana") {
            if (bananas.putFruit(fruit) == false)
                temp.putFruit(fruit);
        }
        else if (fruit->getName() == "lime") {
            if (limes.putFruit(fruit) == false)
                temp.putFruit(fruit);
        }
        else
        {
            temp.putFruit(fruit);
        }
    }
    while ((fruit = temp.pickFruit()))
        unsorted.putFruit(fruit);
}

FruitBox *const *LittleHand::organizeCoconut(const Coconut *const *coconuts)
{

    int i = 0;
    if (!coconuts)
        return (NULL);
    FruitBox **temp;
    while (*coconuts)
    {
        temp[i] = new FruitBox(6);
        for (int j = 0; j < 6 && *coconuts; j++)
            temp[i]->putFruit(*coconuts);
        i++;
    }
    temp[i] = NULL;
    return(temp);
}

int main(void)
{
}