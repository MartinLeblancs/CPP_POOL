/*
** EPITECH PROJECT, 2022
** FruitBox
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    _size = size;
    list = NULL;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
    return (_nbFruits);
}

bool FruitBox::putFruit(Fruit *f)
{
    if (_nbFruits == _size)
        return (false);
    if (list == NULL) {
        list = new FruitNode;
        list->fruit = f;
        list->next = NULL;
        _nbFruits++;
        return (true);
    }
    FruitNode *temp = list;
    while   (temp->next != NULL) {
        temp = temp->next;
    }
    FruitNode *data = new FruitNode;
    data->fruit = f;
    data->next = NULL;
    temp->next = data;
    _nbFruits++;
    return (true);
}

Fruit *FruitBox::pickFruit()
{
    if (list == NULL)
        return (NULL);
    else {
        FruitNode *temp = list;
        list = list->next;
        _nbFruits--;
        return (temp->fruit);
    }
}

void FruitBox::printlist()
{
    while (list != NULL)
    {
        std::cout << list->fruit->getName() << std::endl;
        list = list->next;
    }

}

FruitNode *FruitBox::head() const
{
    if (list == NULL)
        return (NULL);
    return (list);
}
