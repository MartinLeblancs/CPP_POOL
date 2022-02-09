/*
** EPITECH PROJECT, 2022
** day4PM
** File description:
** array_1d_to_2d
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void array_1d_to_2d (const int *array, size_t height, size_t width, int ***res) 
{
    int i = 0;
    int j = 0;
    int count = 0;

    res[0] = malloc(sizeof(int*) * height);
    for (i; i != height; i++)
        res[0][i] = malloc(sizeof(int) * width);
    i = 0;
    j = 0;
    count = 0;
    for (i; i != height; i++) {
        for (j = 0; j != width; j++) {
            res[0][i][j] = array[count];
            count++;
        }
    }
}

void array_2d_free (int **array, size_t height, size_t width)
{
    int i = 0;

    for (int i = 0; i != height; i++)
        free(array[i]);
    free(array);
}