/*
** EPITECH PROJECT, 2022
** Algorithm
** File description:
** Algorithm
*/

#ifndef __ALGORITHM__
#define __ALGORITHM__

template<typename Type>
void swap(Type &a, Type &b)
{
    Type tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T min (const T &a, const T &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

template<typename T>
T max (const T &a, const T &b)
{
    if (b < a)
        return (a);
    else
        return (b);
}

template<typename T>
T clamp(const T &value, const T &min, const T &max)
{
    if (value < min)
        return (min);
    else if (max < value)
        return (max);
    else
        return (value);
}

#endif