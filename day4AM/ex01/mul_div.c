/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** mul_div
*/

void mul_div_long (int a, int b, int *mul, int *div) 
{
    *mul = a * b;

    if (b == 0)
        *div = 42;
    else
        *div = a / b;
}

void mul_div_short(int *a, int *b) 
{
    int nb1 = *a;
    int nb2 = *b;
    if (nb2 == 0)
        *b = 42;
    else 
        *b = (nb1) / (nb2);
    *a = (nb1) * (nb2);
}